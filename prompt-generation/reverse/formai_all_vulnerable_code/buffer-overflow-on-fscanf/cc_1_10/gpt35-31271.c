//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_PIXELS 10000
#define MAX_SIZE 200

typedef struct {
    int r, g, b;
} pixel;

pixel *pixels;
int width, height;

char ascii_chars[] = {'@', '#', '$', '%', '?', '*', '+', ';', ':', ',', '.', ' '};
char *ascii_image;
int ascii_width, ascii_height;

void *convert_to_ascii(void *arg) {

    int start_idx = *((int*)arg);

    for (int i = start_idx; i < start_idx + MAX_PIXELS; i++) {

        int r = pixels[i].r;
        int g = pixels[i].g;
        int b = pixels[i].b;

        double intensity = 0.299 * r + 0.587 * g + 0.114 * b;
        int char_idx = (intensity / 255) * (sizeof(ascii_chars) / sizeof(ascii_chars[0]));

        ascii_image[(i / width) * ascii_width + (i % width)] = ascii_chars[char_idx];
    }

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {

    FILE *image_file;
    if ((image_file = fopen("input.ppm", "r")) == NULL) {
        printf("Error: Could not open image file.\n");
        return 1;
    }

    char format[3];
    fscanf(image_file, "%s\n", format);

    if (strcmp(format, "P3") != 0) {
        printf("Error: Invalid file format.\n");
        fclose(image_file);
        return 1;
    }

    fscanf(image_file, "%d %d\n", &width, &height);
    pixels = malloc(sizeof(pixel) * width * height);

    for (int i = 0; i < width * height; i++) {
        fscanf(image_file, "%d %d %d", &pixels[i].r, &pixels[i].g, &pixels[i].b);
    }

    fclose(image_file);

    ascii_width = width;
    ascii_height = height;
    ascii_image = malloc(sizeof(char) * ascii_width * ascii_height);

    pthread_t threads[4];
    int thread_args[4] = {0, MAX_PIXELS, MAX_PIXELS*2, MAX_PIXELS*3};

    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, convert_to_ascii, &thread_args[i]);
    }

    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    FILE *output_file;
    if ((output_file = fopen("output.txt", "w")) == NULL) {
        printf("Error: Could not open output file.\n");
        return 1;
    }

    fwrite(ascii_image, sizeof(char), ascii_width * ascii_height, output_file);
    fclose(output_file);

    free(pixels);
    free(ascii_image);

    return 0;
}
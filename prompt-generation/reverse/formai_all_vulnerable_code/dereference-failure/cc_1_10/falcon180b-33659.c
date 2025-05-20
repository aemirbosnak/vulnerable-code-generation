//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24

struct pixel {
    int x, y;
    char c;
};

void print_pixel(struct pixel p) {
    printf("%c", p.c);
}

void print_image(char *image, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%c", image[y * width + x]);
        }
        printf("\n");
    }
}

void generate_ascii_art(char *image, int width, int height, char *output) {
    int num_pixels = 0;
    struct pixel *pixels = malloc(sizeof(struct pixel) * width * height);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int value = image[y * width + x];

            if (value > 127) {
                pixels[num_pixels].x = x;
                pixels[num_pixels].y = y;
                pixels[num_pixels].c = '*';
                num_pixels++;
            }
        }
    }

    for (int i = 0; i < num_pixels; i++) {
        print_pixel(pixels[i]);
    }

    free(pixels);
}

int main() {
    char input_file[100] = "input.bmp";
    char output_file[100] = "output.txt";

    FILE *input = fopen(input_file, "rb");
    FILE *output = fopen(output_file, "w");

    if (input == NULL || output == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fseek(input, 0, SEEK_END);
    int file_size = ftell(input);
    fseek(input, 0, SEEK_SET);

    char *image = malloc(file_size);
    fread(image, file_size, 1, input);

    int width, height;
    fread(&width, sizeof(int), 1, input);
    fread(&height, sizeof(int), 1, input);

    char *output_buffer = malloc(width * height * 4);
    generate_ascii_art(image, width, height, output_buffer);

    fprintf(output, "P6\n%d %d\n255\n", width, height);

    for (int i = 0; i < width * height; i++) {
        fprintf(output, "%c", output_buffer[i]);
    }

    fclose(input);
    fclose(output);

    free(image);
    free(output_buffer);

    return 0;
}
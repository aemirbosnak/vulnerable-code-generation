//MISTRAL-7B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 512
#define HEIGHT 512

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} pixel;

void read_pgm(const char *filename, pixel **image, int *width, int *height) {
    FILE *fp = fopen(filename, "rb");
    char magic_number[3];
    int width_temp, height_temp, max_value;

    fgets(magic_number, sizeof(magic_number), fp);
    sscanf(magic_number, "P5%d%d", width_temp, height_temp);
    *width = width_temp;
    *height = height_temp;

    fgets(magic_number, sizeof(magic_number), fp);
    sscanf(magic_number, "%d", &max_value);

    *image = malloc(*width * *height * sizeof(pixel));
    fread(*image, *width * *height * sizeof(pixel), 1, fp);
    fclose(fp);
}

void write_pgm(const char *filename, const pixel *image, int width, int height) {
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "P5\n%d %d\n255\n", width, height);
    fwrite(image, width * height * sizeof(pixel), 1, fp);
    fclose(fp);
}

void flip_horizontal(pixel *image, int width) {
    for (int y = 0; y < HEIGHT / 2; y++) {
        for (int x = 0; x < WIDTH; x++) {
            pixel temp = image[y * WIDTH + x];
            image[y * WIDTH + x] = image[(HEIGHT - y - 1) * WIDTH + x];
            image[(HEIGHT - y - 1) * WIDTH + x] = temp;
        }
    }
}

void change_brightness(pixel *image, int width, int height, int brightness) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            pixel p = image[y * WIDTH + x];
            p.red += brightness;
            p.green += brightness;
            p.blue += brightness;
            image[y * WIDTH + x] = p;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input.pgm> <output.pgm> <brightness>\n", argv[0]);
        return 1;
    }

    pixel *image;
    int width, height;

    read_pgm(argv[1], &image, &width, &height);

    int brightness = atoi(argv[2]);
    change_brightness(image, width, height, brightness);
    flip_horizontal(image, width);

    write_pgm(argv[3], image, width, height);

    free(image);
    return 0;
}
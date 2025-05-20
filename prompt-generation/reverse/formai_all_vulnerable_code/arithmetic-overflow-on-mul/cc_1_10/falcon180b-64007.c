//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 50
#define CHARACTER_SET ".:*#@&!%"

typedef struct {
    int x, y;
    char character;
    int color;
} Pixel;

void print_pixel(Pixel pixel) {
    printf("%c", pixel.character);
}

void print_image(Pixel *image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            print_pixel(image[i * width + j]);
        }
        printf("\n");
    }
}

int get_color(int r, int g, int b) {
    int color = 0;
    if (r > 127) {
        color += 1;
    }
    if (g > 127) {
        color += 2;
    }
    if (b > 127) {
        color += 4;
    }
    return color;
}

void convert_image(unsigned char *data, int width, int height, Pixel *image) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int index = (i * width + j) * 3;
            int r = data[index];
            int g = data[index + 1];
            int b = data[index + 2];
            image[i * width + j].color = get_color(r, g, b);
        }
    }
}

int main() {
    FILE *file = fopen("image.bmp", "rb");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    fseek(file, 18, SEEK_SET);
    int width, height;
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);

    unsigned char *data = (unsigned char *)malloc(width * height * 3);
    fread(data, width * height * 3, 1, file);

    fclose(file);

    Pixel *image = (Pixel *)malloc(width * height * sizeof(Pixel));
    convert_image(data, width, height, image);

    print_image(image, width, height);

    free(data);
    free(image);

    return 0;
}
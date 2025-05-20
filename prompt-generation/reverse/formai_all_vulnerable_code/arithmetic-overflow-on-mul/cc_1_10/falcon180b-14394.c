//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24
#define CHAR_SET ".:+oxXOdcb@#$%&*-=+<>?/!\"'\\"

struct pixel {
    int x;
    int y;
    int value;
};

void print_pixel(struct pixel pixel) {
    int index = pixel.value % (sizeof(CHAR_SET) - 1);
    printf("%c", CHAR_SET[index]);
}

void print_image(struct pixel *pixels, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            print_pixel(pixels[y * width + x]);
        }
        printf("\n");
    }
}

int main() {
    FILE *input_file;
    input_file = fopen("input.bmp", "rb");

    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    fseek(input_file, 18, SEEK_SET); // skip header
    int width, height;
    fread(&width, sizeof(int), 1, input_file);
    fread(&height, sizeof(int), 1, input_file);

    struct pixel *pixels = malloc(width * height * sizeof(struct pixel));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            fread(&pixels[y * width + x].value, sizeof(int), 1, input_file);
        }
    }

    fclose(input_file);

    print_image(pixels, width, height);

    free(pixels);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24

struct pixel {
    int x;
    int y;
    char ch;
    int color;
};

void print_pixel(struct pixel p) {
    printf("%c", p.ch);
}

void print_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open image file.\n");
        exit(1);
    }

    fseek(fp, 18, SEEK_SET); // Skip header
    int width, height;
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);

    struct pixel *pixels = malloc(width * height * sizeof(struct pixel));
    fread(pixels, sizeof(struct pixel), width * height, fp);

    fclose(fp);

    int max_value = 0;
    for (int i = 0; i < width * height; i++) {
        if (pixels[i].color > max_value) {
            max_value = pixels[i].color;
        }
    }

    printf("\n");
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int value = pixels[y * width + x].color * MAX_HEIGHT / max_value;
            for (int i = 0; i < value; i++) {
                printf("%c", 219);
            }
            for (int i = value; i < MAX_HEIGHT; i++) {
                printf("%c", 32);
            }
        }
        printf("\n");
    }

    free(pixels);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    print_image(argv[1]);

    return 0;
}
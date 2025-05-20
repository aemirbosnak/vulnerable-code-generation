//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 500
#define MAX_HEIGHT 500

char grayscale_map[16] = {' ', '.', ',', ':', ';', 'o', '&', '8', '#', '@', '%', '*', '0', 'U', 'D', 'M'};

int get_intensity(char r, char g, char b) {
    return (r + g + b) / 3;
}

int get_grayscale(char intensity) {
    float scale_factor = 255.0 / (sizeof(grayscale_map) - 1);
    return (int)(intensity / scale_factor);
}

void convert_to_ascii(char image[MAX_HEIGHT][MAX_WIDTH][3], int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int intensity = get_intensity(image[i][j][0], image[i][j][1], image[i][j][2]);
            int grayscale = get_grayscale(intensity);
            putchar(grayscale_map[grayscale]);
        }
        putchar('\n');
    }
}

int main() {
    char filename[] = "image.ppm";
    FILE *fp = fopen(filename, "rb");

    if (fp == NULL) {
        printf("Error opening file");
        return -1;
    }

    char format[3];
    int width, height, max_color;
    char image[MAX_HEIGHT][MAX_WIDTH][3];

    fscanf(fp, "%s %d %d %d", format, &width, &height, &max_color);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < 3; k++) {
                fread(&image[i][j][k], sizeof(char), 1, fp);
            }
        }
    }

    fclose(fp);

    convert_to_ascii(image, height, width);

    return 0;
}
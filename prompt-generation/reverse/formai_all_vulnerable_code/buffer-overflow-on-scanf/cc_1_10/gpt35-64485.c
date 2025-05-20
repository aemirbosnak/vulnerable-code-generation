//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

char ascii_chars[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

void convert_to_ascii(int pixels[MAX_HEIGHT][MAX_WIDTH], int height, int width) {
    float grayscale;
    int ascii_index;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            grayscale = (pixels[i][j] / 255.0) * 9;
            ascii_index = (int) grayscale;
            printf("%c", ascii_chars[ascii_index]);
        }
        printf("\n");
    }
}

int main() {
    int pixels[MAX_HEIGHT][MAX_WIDTH];
    int height, width;
    char filename[100];

    printf("Enter image filename: ");
    scanf("%s", filename);

    FILE* fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Could not open file.\n");
        return 1;
    }

    fscanf(fp, "%d %d", &height, &width);

    if (height > MAX_HEIGHT || width > MAX_WIDTH) {
        printf("Image too large.\n");
        return 1;
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fscanf(fp, "%d", &pixels[i][j]);
        }
    }

    fclose(fp);

    convert_to_ascii(pixels, height, width);

    return 0;
}
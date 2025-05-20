//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 24
#define CHAR_SET ".,:;i1tf+~=!@#$%^&*()_+-=[]{}|;':\",./<>?"

typedef struct {
    int x;
    int y;
    int c;
} Pixel;

void print_image(Pixel *pixels, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%c", CHAR_SET[pixels[y * width + x].c]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp;
    char filename[20];
    printf("Enter the name of the image file: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    fseek(fp, 18, SEEK_SET); // Skip header
    int width, height;
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);

    Pixel *pixels = malloc(width * height * sizeof(Pixel));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            fread(&pixels[y * width + x], sizeof(Pixel), 1, fp);
        }
    }

    fclose(fp);

    print_image(pixels, width, height);

    free(pixels);

    return 0;
}
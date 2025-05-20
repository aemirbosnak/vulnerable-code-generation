//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define MAX_PIXELS (MAX_WIDTH * MAX_HEIGHT)

typedef struct {
    int width;
    int height;
    char **pixels;
} Image;

Image *loadImage(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error loading image file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *data = malloc(size);
    if (data == NULL) {
        printf("Error allocating memory for image data\n");
        exit(1);
    }

    fread(data, size, 1, fp);
    fclose(fp);

    Image *image = malloc(sizeof(Image));
    image->width = *((int *)data);
    image->height = *((int *)(data + sizeof(int)));
    image->pixels = malloc(MAX_PIXELS * sizeof(char *));

    int pixelsCount = image->width * image->height;
    for (int i = 0; i < pixelsCount; i++) {
        int r = *((int *)(data + sizeof(int) * 2 + i * 3));
        int g = *((int *)(data + sizeof(int) * 2 + i * 3 + 1));
        int b = *((int *)(data + sizeof(int) * 2 + i * 3 + 2));
        char color = (r >> 5) * 31 + (g >> 5) * 63 + (b >> 6);
        image->pixels[i] = malloc(3);
        sprintf(image->pixels[i], "%c", color);
    }

    free(data);
    return image;
}

void saveAsciiArt(Image *image, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error saving ASCII art file %s\n", filename);
        exit(1);
    }

    fprintf(fp, "P6\n%d %d\n255\n", image->width, image->height);

    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            char *pixel = image->pixels[i * image->width + j];
            fprintf(fp, "%c", pixel[0]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

int main() {
    Image *image = loadImage("input.png");
    saveAsciiArt(image, "output.txt");

    printf("ASCII art saved to output.txt\n");

    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            printf("%c", image->pixels[i * image->width + j][0]);
        }
        printf("\n");
    }

    for (int i = 0; i < image->height; i++) {
        free(image->pixels[i]);
    }
    free(image->pixels);
    free(image);

    return 0;
}
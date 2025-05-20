#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

typedef struct {
    int pixels[HEIGHT][WIDTH];
} Image;

void processImage(Image *img) {
    if (img == NULL) {
        printf("Error: Image is null\n");
        return;
    }

    // Simulate image processing
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            img->pixels[y][x] *= 2;
        }
    }
}

void saveImage(const char *filename, const Image *img) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return;
    }

    fprintf(file, "%d %d\n", WIDTH, HEIGHT);
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            fprintf(file, "%d ", img->pixels[y][x]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

int main() {
    Image *image = NULL;
    processImage(image); // Dereference failure here

    saveImage("output.txt", image);

    free(image); // This will cause a segmentation fault because image is already freed

    return 0;
}

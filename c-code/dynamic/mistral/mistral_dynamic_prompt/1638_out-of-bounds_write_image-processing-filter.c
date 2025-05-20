#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 256
#define RED 0
#define GREEN 1
#define BLUE 2

void applyFilter(unsigned char* image, int width, int height) {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int index = y * width + x;
            image[index * 3 + RED] += 50;
            image[index * 3 + GREEN] += 50;
            image[index * 3 + BLUE] += 50;

            // Out-of-bounds write vulnerability here
            if (x + 1 < width)
                image[(y * width + x + 1) * 3 + BLUE] = 255; // Overwrite adjacent pixel's blue channel
        }
    }
}

int main(int argc, char* argv[]) {
    unsigned char inputImage[MAX_IMAGE_SIZE * 3];
    unsigned char outputImage[MAX_IMAGE_SIZE * 3];

    int width, height;
    fscanf(stdin, "%d %d\n", &width, &height);

    if (width * height * 3 > MAX_IMAGE_SIZE * 3) {
        fprintf(stderr, "Error: Image too large.\n");
        return 1;
    }

    fread(inputImage, 1, width * height * 3, stdin);
    applyFilter(inputImage, width, height);
    fwrite(outputImage, 1, width * height * 3, stdout);

    return 0;
}

//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random color
void generate_color(int* r, int* g, int* b) {
    *r = rand() % 256;
    *g = rand() % 256;
    *b = rand() % 256;
}

// Function to print the pixel art
void print_pixel_art(int width, int height, int* pixels) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%d ", pixels[y * width + x]);
        }
        printf("\n");
    }
}

// Function to generate a random pixel art
void generate_pixel_art(int width, int height, int* pixels) {
    srand(time(NULL));
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int r, g, b;
            generate_color(&r, &g, &b);
            pixels[y * width + x] = (r << 16) | (g << 8) | b;
        }
    }
}

int main() {
    int width, height;
    printf("Enter the width and height of the pixel art: ");
    scanf("%d %d", &width, &height);

    int* pixels = (int*) malloc(width * height * sizeof(int));
    if (pixels == NULL) {
        printf("Error: could not allocate memory.\n");
        return 1;
    }

    generate_pixel_art(width, height, pixels);
    print_pixel_art(width, height, pixels);

    free(pixels);
    return 0;
}
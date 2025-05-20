//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random number generator

    int width, height, colors, x, y, color;
    printf("Enter the width of the image: ");
    scanf("%d", &width);
    printf("Enter the height of the image: ");
    scanf("%d", &height);
    printf("Enter the number of colors to use: ");
    scanf("%d", &colors);

    // allocate memory for the pixel array
    int **pixels = malloc(height * sizeof(int *));
    for (y = 0; y < height; y++) {
        pixels[y] = malloc(width * sizeof(int));
    }

    // assign random colors to each pixel
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            color = rand() % colors;
            pixels[y][x] = color;
        }
    }

    // print out the pixel values as ASCII art
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            switch (pixels[y][x]) {
                case 0:
                    printf("█");
                    break;
                case 1:
                    printf("▓");
                    break;
                case 2:
                    printf("▒");
                    break;
                case 3:
                    printf("░");
                    break;
                default:
                    printf(" ");
                    break;
            }
        }
        printf("\n");
    }

    // free memory
    for (y = 0; y < height; y++) {
        free(pixels[y]);
    }
    free(pixels);

    return 0;
}
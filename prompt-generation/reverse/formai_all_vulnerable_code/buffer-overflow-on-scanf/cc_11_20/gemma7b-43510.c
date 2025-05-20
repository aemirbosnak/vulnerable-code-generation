//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80

int main() {
    char image[1024];
    printf("Enter image data (separate pixels with spaces): ");
    fgets(image, 1024, stdin);

    int width, height;
    printf("Enter image width: ");
    scanf("%d", &width);

    printf("Enter image height: ");
    scanf("%d", &height);

    int pixels[height][width];
    char ascii_art[height][MAX_WIDTH];

    // Convert image data into pixels
    char *p = image;
    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {
            pixels[h][w] = atoi(p);
            p++;
        }
    }

    // Convert pixels into ASCII art
    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {
            switch (pixels[h][w]) {
                case 0:
                    ascii_art[h][w] = ' ';
                    break;
                case 1:
                    ascii_art[h][w] = '.';
                    break;
                case 2:
                    ascii_art[h][w] = '=';
                    break;
                case 3:
                    ascii_art[h][w] = '#';
                    break;
            }
        }
    }

    // Print ASCII art
    for (int h = 0; h < height; h++) {
        for (int w = 0; w < MAX_WIDTH; w++) {
            printf("%c ", ascii_art[h][w]);
        }
        printf("\n");
    }

    return 0;
}
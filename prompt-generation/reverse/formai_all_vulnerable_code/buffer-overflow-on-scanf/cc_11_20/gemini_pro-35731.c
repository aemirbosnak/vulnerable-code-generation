//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

int main(void) {
    int width, height;
    printf("Enter the width of the image: ");
    scanf("%d", &width);
    printf("Enter the height of the image: ");
    scanf("%d", &height);

    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Error: The image size is too large.\n");
        return 1;
    }

    char image[MAX_WIDTH][MAX_HEIGHT];

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j] = ' ';
        }
    }

    int x1, y1, x2, y2;
    printf("Enter the coordinates of the first point (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of the second point (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    if (x1 < 0 || x1 >= width || y1 < 0 || y1 >= height || x2 < 0 || x2 >= width || y2 < 0 || y2 >= height) {
        printf("Error: The coordinates are out of bounds.\n");
        return 1;
    }

    char character;
    printf("Enter the character to draw with: ");
    scanf(" %c", &character);

    for (int i = y1; i <= y2; i++) {
        for (int j = x1; j <= x2; j++) {
            image[i][j] = character;
        }
    }

    printf("Here is the generated image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}
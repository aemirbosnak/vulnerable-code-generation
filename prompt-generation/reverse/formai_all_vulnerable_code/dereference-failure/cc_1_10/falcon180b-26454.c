//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100
#define MAX_COLOR 255

typedef struct {
    int x;
    int y;
    int color;
} Pixel;

Pixel* createImage(int width, int height) {
    Pixel* image = (Pixel*)malloc(sizeof(Pixel) * width * height);
    for (int i = 0; i < width * height; i++) {
        image[i].x = rand() % width;
        image[i].y = rand() % height;
        image[i].color = rand() % MAX_COLOR;
    }
    return image;
}

void printImage(Pixel* image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf(" %d ", image[(i * width) + j].color);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    Pixel* image = createImage(WIDTH, HEIGHT);
    printf("Original Image:\n");
    printImage(image, WIDTH, HEIGHT);

    int color = 0;
    while (color!= -1) {
        printf("\nEnter color to replace (-1 to stop): ");
        scanf("%d", &color);

        if (color!= -1) {
            int count = 0;
            for (int i = 0; i < WIDTH * HEIGHT; i++) {
                if (image[i].color == color) {
                    image[i].color = 0;
                    count++;
                }
            }
            printf("Replaced %d pixels with color %d.\n", count, color);
        }
    }

    printf("\nFinal Image:\n");
    printImage(image, WIDTH, HEIGHT);

    free(image);
    return 0;
}
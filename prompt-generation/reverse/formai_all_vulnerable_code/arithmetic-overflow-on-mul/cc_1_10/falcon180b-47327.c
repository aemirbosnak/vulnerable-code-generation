//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000
#define MAX_COLORS 256

typedef struct {
    int x, y;
    int r, g, b;
} Pixel;

Pixel *create_image(int width, int height) {
    Pixel *image = (Pixel *)malloc(sizeof(Pixel) * width * height);
    for (int i = 0; i < width * height; i++) {
        image[i].x = i % width;
        image[i].y = i / width;
        image[i].r = rand() % 256;
        image[i].g = rand() % 256;
        image[i].b = rand() % 256;
    }
    return image;
}

void print_image(Pixel *image, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Pixel pixel = image[y * width + x];
            printf("\033[38;2;%d;%d;%dm ", pixel.r, pixel.g, pixel.b);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    int width, height;
    printf("Enter the width and height of the image (max %d): ", MAX_WIDTH);
    scanf("%d %d", &width, &height);

    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Invalid dimensions.\n");
        return 1;
    }

    Pixel *image = create_image(width, height);
    print_image(image, width, height);

    free(image);
    return 0;
}
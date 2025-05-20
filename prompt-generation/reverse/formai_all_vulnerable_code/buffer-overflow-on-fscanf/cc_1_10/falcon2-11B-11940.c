//Falcon2-11B DATASET v1.0 Category: Pixel Art Generator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIXEL_COUNT 100
#define MAX_PIXEL_WIDTH 20

typedef struct {
    int x;
    int y;
    char color;
} Pixel;

void printPixel(Pixel pixel) {
    printf("%d,%d ", pixel.x, pixel.y);
    switch (pixel.color) {
        case 'b':
            printf("blue\n");
            break;
        case 'g':
            printf("green\n");
            break;
        case 'r':
            printf("red\n");
            break;
        default:
            printf("invalid color\n");
            break;
    }
}

void createPixelArt(char* imageName) {
    int width = 0;
    int height = 0;
    Pixel pixels[MAX_PIXEL_COUNT];

    FILE* imageFile = fopen(imageName, "w");

    if (imageFile == NULL) {
        printf("Error opening file.\n");
        return;
    }

    while (fscanf(imageFile, "%d,%d %c\n", &pixels[width].x, &pixels[width].y, &pixels[width].color) == 3) {
        width++;
        if (width == MAX_PIXEL_COUNT) {
            printf("Pixel count exceeded.\n");
            break;
        }
    }

    fclose(imageFile);

    printf("Pixel count: %d\n", width);
    printf("Width: %d\n", MAX_PIXEL_WIDTH);
    printf("Height: %d\n", height);

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            printPixel(pixels[i]);
        }
    }

    printf("\n");
}

int main() {
    char* imageName = "pixelArt.txt";
    createPixelArt(imageName);

    return 0;
}
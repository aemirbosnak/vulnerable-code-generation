//MISTRAL-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 3
#define HEIGHT 3

typedef struct {
    int r;
    int g;
    int b;
} Pixel;

char* get_ascii_char(int value) {
    static char ascii[] = {
        ' ', '.', ':', ';', '=', '>', '<', '?', '@'
    };

    return &ascii[value / 32];
}

void print_pixel(Pixel pixel) {
    printf("%s%s%s ", get_ascii_char(pixel.r),
           get_ascii_char(pixel.g),
           get_ascii_char(pixel.b));
}

void print_image(Pixel image[WIDTH][HEIGHT]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            print_pixel(image[j][i]);
        }
        printf("\n");
    }
}

int main() {
    Pixel image[WIDTH][HEIGHT];

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            scanf("%d%d%d", &image[j][i].r, &image[j][i].g, &image[j][i].b);
        }
    }

    printf("Input image:\n");
    print_image(image);

    printf("\nOutput ASCII art:\n");
    print_image(image);

    return 0;
}
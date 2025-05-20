//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define WIDTH 512
#define HEIGHT 512
#define MAX_HIDDEN_BYTES 10000

typedef struct {
    int x, y;
} Point;

typedef struct {
    int r, g, b;
} Color;

typedef struct {
    Color color;
    bool hidden;
} Pixel;

typedef struct {
    Pixel *pixels;
    int width;
    int height;
} Image;

void generate_random_image(Image *image) {
    srand(time(NULL));
    for (int i = 0; i < image->width * image->height; i++) {
        image->pixels[i].color.r = rand() % 256;
        image->pixels[i].color.g = rand() % 256;
        image->pixels[i].color.b = rand() % 256;
    }
}

void hide_data(Image *image, char *data, int data_length) {
    int hidden_bytes = 0;
    for (int i = 0; i < image->width * image->height && hidden_bytes < MAX_HIDDEN_BYTES; i++) {
        if (!image->pixels[i].hidden) {
            int index = rand() % 3;
            image->pixels[i].color.r += data[hidden_bytes] - '0';
            image->pixels[i].hidden = true;
            hidden_bytes++;
        }
    }
}

void show_image(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            Pixel pixel = image->pixels[(i * image->width) + j];
            printf("%c", pixel.color.r);
        }
        printf("\n");
    }
}

int main() {
    Image image;
    image.pixels = (Pixel *)malloc(sizeof(Pixel) * (WIDTH * HEIGHT));
    image.width = WIDTH;
    image.height = HEIGHT;

    generate_random_image(&image);

    char *data = "This is a secret message.";
    int data_length = strlen(data);

    hide_data(&image, data, data_length);

    printf("Hidden image:\n");
    show_image(&image);

    return 0;
}
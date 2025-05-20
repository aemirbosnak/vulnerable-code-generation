//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

#define WIDTH 512
#define HEIGHT 512

#define MAX_PIXELS (WIDTH * HEIGHT)

typedef struct {
    int red;
    int green;
    int blue;
} pixel_t;

pixel_t* create_image(char* message) {
    pixel_t* pixels = (pixel_t*) malloc(MAX_PIXELS * sizeof(pixel_t));
    memset(pixels, 0, MAX_PIXELS * sizeof(pixel_t));

    int i = 0;
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int index = y * WIDTH + x;

            if (message[i] == '0') {
                pixels[index].red = 0;
                pixels[index].green = 0;
                pixels[index].blue = 0;
            } else {
                pixels[index].red = 255;
                pixels[index].green = 255;
                pixels[index].blue = 255;
            }

            i++;
        }
    }

    return pixels;
}

void save_image(pixel_t* pixels, char* filename) {
    FILE* file = fopen(filename, "wb");

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int index = y * WIDTH + x;

            fputc(pixels[index].red, file);
            fputc(pixels[index].green, file);
            fputc(pixels[index].blue, file);
        }
    }

    fclose(file);
}

int main() {
    srand(time(NULL));

    char* message = "Hello World!";
    pixel_t* pixels = create_image(message);
    save_image(pixels, "image.bmp");

    free(pixels);

    return 0;
}
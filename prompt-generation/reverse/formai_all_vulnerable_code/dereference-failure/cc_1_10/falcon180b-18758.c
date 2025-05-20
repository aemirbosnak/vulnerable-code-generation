//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the image
#define IMAGE_WIDTH 640
#define IMAGE_HEIGHT 480
#define PIXEL_SIZE 1

// Define the color palette
#define BLACK 0
#define WHITE 1
#define RED 2
#define GREEN 3
#define BLUE 4
#define YELLOW 5
#define CYAN 6
#define MAGENTA 7

// Define the image data structure
typedef struct {
    int width;
    int height;
    int* data;
} Image;

// Initialize the image with random pixel values
void init_image(Image* image) {
    srand(time(NULL));
    image->data = (int*)malloc(IMAGE_WIDTH * IMAGE_HEIGHT * sizeof(int));
    for (int y = 0; y < IMAGE_HEIGHT; y++) {
        for (int x = 0; x < IMAGE_WIDTH; x++) {
            int color = rand() % 8; // Choose a random color from the palette
            image->data[y * IMAGE_WIDTH + x] = color;
        }
    }
}

// Print the image to the console
void print_image(Image* image) {
    for (int y = 0; y < IMAGE_HEIGHT; y++) {
        for (int x = 0; x < IMAGE_WIDTH; x++) {
            int color = image->data[y * IMAGE_WIDTH + x];
            switch (color) {
                case BLACK:
                    printf(" ");
                    break;
                case WHITE:
                    printf("*");
                    break;
                case RED:
                    printf("R");
                    break;
                case GREEN:
                    printf("G");
                    break;
                case BLUE:
                    printf("B");
                    break;
                case YELLOW:
                    printf("Y");
                    break;
                case CYAN:
                    printf("C");
                    break;
                case MAGENTA:
                    printf("M");
                    break;
            }
        }
        printf("\n");
    }
}

// Save the image to a PNG file
void save_image(Image* image, char* filename) {
    // TODO: Implement PNG saving logic
}

int main() {
    Image image;
    init_image(&image);
    print_image(&image);
    save_image(&image, "image.png");
    return 0;
}
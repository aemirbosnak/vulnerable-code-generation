//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct image_data {
    int width;
    int height;
    char* pixels;
} image_data;

void print_image(image_data* image) {
    int width = image->width;
    int height = image->height;
    int size = width * height;
    char* pixels = image->pixels;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%c", pixels[y * width + x]);
        }
        printf("\n");
    }
}

image_data* create_image(int width, int height) {
    image_data* image = (image_data*)malloc(sizeof(image_data));
    image->width = width;
    image->height = height;
    image->pixels = (char*)malloc(sizeof(char) * width * height);
    for (int i = 0; i < width * height; i++) {
        image->pixels[i] = '*';
    }
    return image;
}

void clear_image(image_data* image) {
    free(image->pixels);
    free(image);
}

int main() {
    int width, height;
    printf("Enter image width: ");
    scanf("%d", &width);
    printf("Enter image height: ");
    scanf("%d", &height);
    image_data* image = create_image(width, height);
    printf("Original image:\n");
    print_image(image);
    printf("Enter pixel to change (x, y): ");
    int x, y;
    scanf("%d %d", &x, &y);
    if (x < 0 || x >= width || y < 0 || y >= height) {
        printf("Invalid position, cannot change pixel.\n");
    } else {
        image->pixels[y * width + x] = 'X';
        printf("Pixel changed from * to X:\n");
        print_image(image);
        printf("Enter pixel to change (x, y): ");
        x, y;
        scanf("%d %d", &x, &y);
        if (x < 0 || x >= width || y < 0 || y >= height) {
            printf("Invalid position, cannot change pixel.\n");
        } else {
            image->pixels[y * width + x] = 'O';
            printf("Pixel changed from X to O:\n");
            print_image(image);
        }
    }
    clear_image(image);
    printf("Image deleted.\n");
    return 0;
}
//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_IMAGE_SIZE 1000

typedef struct {
    int width;
    int height;
    int max_color;
    int* image;
} image_t;

int main() {
    image_t image;
    int r, g, b;
    int input_color;

    printf("Enter the width of the image: ");
    scanf("%d", &image.width);
    printf("Enter the height of the image: ");
    scanf("%d", &image.height);
    printf("Enter the maximum number of colors: ");
    scanf("%d", &image.max_color);
    image.image = (int*)malloc(image.width * image.height * sizeof(int));

    printf("Enter the pixel values for each color: ");
    for (int i = 0; i < image.max_color; i++) {
        scanf("%d", &r);
        scanf("%d", &g);
        scanf("%d", &b);
        image.image[i * image.width * image.height + image.width * image.height] = r << 16 | g << 8 | b;
    }

    printf("Image data: ");
    for (int i = 0; i < image.width * image.height; i++) {
        printf("%d ", image.image[i]);
    }

    printf("\nEnter the index of the pixel to change: ");
    scanf("%d", &input_color);

    printf("Enter the new pixel values: ");
    scanf("%d %d %d", &r, &g, &b);

    image.image[input_color * image.width * image.height + image.width * image.height] = r << 16 | g << 8 | b;

    printf("Updated image data: ");
    for (int i = 0; i < image.width * image.height; i++) {
        printf("%d ", image.image[i]);
    }

    return 0;
}
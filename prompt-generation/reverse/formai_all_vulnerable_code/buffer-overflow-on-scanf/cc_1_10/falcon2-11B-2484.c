//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

typedef struct {
    int width;
    int height;
    int* image;
} Image;

Image create_image(int width, int height) {
    Image image;
    image.width = width;
    image.height = height;
    image.image = (int*) malloc(width * height * sizeof(int));
    return image;
}

void free_image(Image* image) {
    free(image->image);
    image->image = NULL;
}

void display_image(Image image) {
    int i, j;
    for (i = 0; i < image.width; i++) {
        for (j = 0; j < image.height; j++) {
            printf("%d ", image.image[j * image.width + i]);
        }
        printf("\n");
    }
}

int main() {
    int width, height;
    printf("Enter the width of the image: ");
    scanf("%d", &width);
    printf("Enter the height of the image: ");
    scanf("%d", &height);

    Image image = create_image(width, height);
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            printf("Enter the value of the pixel at position (%d, %d): ", i, j);
            scanf("%d", &image.image[j * width + i]);
        }
    }

    display_image(image);
    printf("\n");

    free_image(&image);
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1000

typedef struct {
    int width;
    int height;
    char *data;
} Image;

Image *create_image(int width, int height) {
    Image *image = (Image *)malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = (char *)malloc(width * height * sizeof(char));
    return image;
}

void destroy_image(Image *image) {
    free(image->data);
    free(image);
}

void set_pixel(Image *image, int x, int y, char value) {
    int offset = (y * image->width + x) * sizeof(char);
    memcpy(image->data + offset, &value, sizeof(char));
}

char get_pixel(Image *image, int x, int y) {
    int offset = (y * image->width + x) * sizeof(char);
    return *(char *)(image->data + offset);
}

void print_image(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            char value = get_pixel(image, x, y);
            printf("%c", value);
        }
        printf("\n");
    }
}

int main() {
    Image *image = create_image(10, 10);
    set_pixel(image, 0, 0, 'X');
    set_pixel(image, 0, 1, 'O');
    set_pixel(image, 1, 0, 'O');
    set_pixel(image, 1, 1, 'X');
    set_pixel(image, 9, 9, 'X');
    set_pixel(image, 9, 8, 'O');
    set_pixel(image, 8, 9, 'O');
    set_pixel(image, 8, 8, 'X');

    print_image(image);

    destroy_image(image);

    return 0;
}
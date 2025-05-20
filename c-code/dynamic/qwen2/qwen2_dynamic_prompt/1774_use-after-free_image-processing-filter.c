#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 256
#define HEIGHT 256

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

Image* create_image(int width, int height) {
    Image *img = (Image*)malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = (unsigned char*)malloc(width * height);
    return img;
}

void process_image(Image *img) {
    // Simulate some image processing
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i] = img->data[i] + 10;
    }
}

void free_image(Image *img) {
    free(img->data);
    img->data = NULL;
}

int main() {
    Image *img = create_image(WIDTH, HEIGHT);
    process_image(img);

    // Use after free vulnerability
    printf("Processing again...\n");
    process_image(img); // This will cause undefined behavior due to use after free

    free_image(img);

    return 0;
}

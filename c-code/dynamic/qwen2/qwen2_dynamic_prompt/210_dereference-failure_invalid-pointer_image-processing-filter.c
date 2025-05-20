#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

typedef struct {
    int data[HEIGHT][WIDTH];
} Image;

void apply_filter(Image *img) {
    int *ptr = NULL;
    ptr = img->data[HEIGHT]; // Invalid pointer access
    for (int i = 0; i < WIDTH; i++) {
        img->data[0][i] += *ptr; // Dereference invalid pointer
    }
}

Image create_image() {
    Image img;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            img.data[i][j] = rand() % 256;
        }
    }
    return img;
}

void print_image(const Image *img) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d ", img->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    Image img = create_image();
    printf("Original Image:\n");
    print_image(&img);
    apply_filter(&img);
    printf("Filtered Image:\n");
    print_image(&img);
    return 0;
}

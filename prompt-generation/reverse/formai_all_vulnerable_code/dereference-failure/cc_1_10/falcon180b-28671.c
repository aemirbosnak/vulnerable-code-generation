//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

typedef struct {
    int width;
    int height;
    int **data;
} Image;

void create_image(Image *img, int width, int height) {
    img->width = width;
    img->height = height;
    img->data = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        img->data[i] = (int *)malloc(width * sizeof(int));
    }
}

void destroy_image(Image *img) {
    for (int i = 0; i < img->height; i++) {
        free(img->data[i]);
    }
    free(img->data);
}

void flip_image(Image *img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width / 2; j++) {
            int temp = img->data[i][j];
            img->data[i][j] = img->data[i][img->width - j - 1];
            img->data[i][img->width - j - 1] = temp;
        }
    }
}

void change_brightness(Image *img, int brightness) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            img->data[i][j] += brightness;
        }
    }
}

void change_contrast(Image *img, int contrast) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            int temp = img->data[i][j];
            img->data[i][j] = ((temp * (256 - contrast)) / 256) + ((contrast * (temp - 128)) / 256);
        }
    }
}

void print_image(Image *img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            printf("%d ", img->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Image img;
    create_image(&img, 10, 10);
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            img.data[i][j] = (i * img.width) + j;
        }
    }
    print_image(&img);
    flip_image(&img);
    print_image(&img);
    change_brightness(&img, 50);
    print_image(&img);
    change_contrast(&img, 200);
    print_image(&img);
    destroy_image(&img);
    return 0;
}
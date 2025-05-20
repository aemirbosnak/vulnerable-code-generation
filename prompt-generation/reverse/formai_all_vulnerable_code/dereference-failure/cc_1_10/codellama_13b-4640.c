//Code Llama-13B DATASET v1.0 Category: Image Editor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000000

typedef struct {
    int width;
    int height;
    int *data;
} Image;

void print_image(Image *img) {
    int i, j;
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            printf("%d ", img->data[i * img->width + j]);
        }
        printf("\n");
    }
}

void rotate_image(Image *img, float angle) {
    int i, j;
    float sin_angle = sin(angle);
    float cos_angle = cos(angle);
    int width = img->width;
    int height = img->height;
    int *data = img->data;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int x = j * cos_angle - i * sin_angle;
            int y = j * sin_angle + i * cos_angle;
            int new_x = round(x);
            int new_y = round(y);
            if (new_x >= 0 && new_x < width && new_y >= 0 && new_y < height) {
                img->data[new_y * width + new_x] = data[i * width + j];
            }
        }
    }
}

void resize_image(Image *img, int new_width, int new_height) {
    int i, j;
    int width = img->width;
    int height = img->height;
    int *data = img->data;
    int *new_data = malloc(new_width * new_height * sizeof(int));

    for (i = 0; i < new_height; i++) {
        for (j = 0; j < new_width; j++) {
            float x = (float)j / new_width * width;
            float y = (float)i / new_height * height;
            int new_x = round(x);
            int new_y = round(y);
            if (new_x >= 0 && new_x < width && new_y >= 0 && new_y < height) {
                new_data[i * new_width + j] = data[new_y * width + new_x];
            }
        }
    }

    free(img->data);
    img->width = new_width;
    img->height = new_height;
    img->data = new_data;
}

void invert_image(Image *img) {
    int i, j;
    int width = img->width;
    int height = img->height;
    int *data = img->data;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            data[i * width + j] = 255 - data[i * width + j];
        }
    }
}

int main() {
    Image img;
    img.width = 5;
    img.height = 5;
    img.data = malloc(img.width * img.height * sizeof(int));
    int i, j;
    for (i = 0; i < img.height; i++) {
        for (j = 0; j < img.width; j++) {
            img.data[i * img.width + j] = 0;
        }
    }

    img.data[0 * img.width + 0] = 255;
    img.data[1 * img.width + 1] = 255;
    img.data[2 * img.width + 2] = 255;
    img.data[3 * img.width + 3] = 255;
    img.data[4 * img.width + 4] = 255;

    print_image(&img);
    rotate_image(&img, 45);
    print_image(&img);
    resize_image(&img, 10, 10);
    print_image(&img);
    invert_image(&img);
    print_image(&img);

    free(img.data);
    return 0;
}
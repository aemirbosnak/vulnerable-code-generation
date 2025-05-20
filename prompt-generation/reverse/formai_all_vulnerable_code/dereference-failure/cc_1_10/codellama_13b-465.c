//Code Llama-13B DATASET v1.0 Category: Image Editor ; Style: Romeo and Juliet
// Romeo and Juliet Image Editor

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel **data;
} Image;

void init_image(Image *img, int width, int height) {
    img->width = width;
    img->height = height;
    img->data = (Pixel **)malloc(height * sizeof(Pixel *));
    for (int i = 0; i < height; i++) {
        img->data[i] = (Pixel *)malloc(width * sizeof(Pixel));
    }
}

void set_pixel(Image *img, int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    img->data[y][x].r = r;
    img->data[y][x].g = g;
    img->data[y][x].b = b;
}

void save_image(Image *img, char *filename) {
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "P6 %d %d 255\n", img->width, img->height);
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            fputc(img->data[i][j].r, fp);
            fputc(img->data[i][j].g, fp);
            fputc(img->data[i][j].b, fp);
        }
    }
    fclose(fp);
}

void print_image(Image *img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            printf("%c%c%c", img->data[i][j].r, img->data[i][j].g, img->data[i][j].b);
        }
        printf("\n");
    }
}

int main() {
    Image img;
    init_image(&img, MAX_WIDTH, MAX_HEIGHT);

    // Set the background color to black
    set_pixel(&img, 0, 0, 0, 0, 0);

    // Draw a red circle in the center of the image
    int radius = 100;
    for (int i = 0; i < radius; i++) {
        int x = MAX_WIDTH / 2 + i;
        int y = MAX_HEIGHT / 2 + i;
        set_pixel(&img, x, y, 255, 0, 0);
    }

    // Save the image to a file
    save_image(&img, "image.ppm");

    // Print the image to the console
    print_image(&img);

    return 0;
}
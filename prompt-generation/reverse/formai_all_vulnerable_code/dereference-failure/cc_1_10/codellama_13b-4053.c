//Code Llama-13B DATASET v1.0 Category: Image Editor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

typedef struct {
    int width;
    int height;
    int** pixels;
} Image;

void create_image(Image* img) {
    img->width = 0;
    img->height = 0;
    img->pixels = NULL;
}

void destroy_image(Image* img) {
    if (img->pixels) {
        for (int i = 0; i < img->height; i++) {
            free(img->pixels[i]);
        }
        free(img->pixels);
    }
    img->width = 0;
    img->height = 0;
    img->pixels = NULL;
}

void set_pixel(Image* img, int x, int y, int value) {
    if (x < 0 || x >= img->width || y < 0 || y >= img->height) {
        return;
    }
    img->pixels[y][x] = value;
}

int get_pixel(Image* img, int x, int y) {
    if (x < 0 || x >= img->width || y < 0 || y >= img->height) {
        return 0;
    }
    return img->pixels[y][x];
}

void save_image(Image* img, const char* filename) {
    FILE* fp = fopen(filename, "wb");
    if (!fp) {
        printf("Error: Unable to open file %s for writing.\n", filename);
        return;
    }

    fprintf(fp, "P6\n");
    fprintf(fp, "%d %d\n", img->width, img->height);
    fprintf(fp, "255\n");

    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int pixel = get_pixel(img, x, y);
            fwrite(&pixel, sizeof(int), 1, fp);
        }
    }

    fclose(fp);
}

void load_image(Image* img, const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: Unable to open file %s for reading.\n", filename);
        return;
    }

    char header[3];
    fread(header, sizeof(char), 3, fp);
    if (strcmp(header, "P6\n") != 0) {
        printf("Error: Invalid file format.\n");
        return;
    }

    int width, height, max_value;
    fscanf(fp, "%d %d\n", &width, &height);
    fscanf(fp, "%d\n", &max_value);

    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Error: Image is too large.\n");
        return;
    }

    img->width = width;
    img->height = height;
    img->pixels = malloc(img->height * sizeof(int*));
    for (int i = 0; i < img->height; i++) {
        img->pixels[i] = malloc(img->width * sizeof(int));
    }

    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int pixel;
            fread(&pixel, sizeof(int), 1, fp);
            set_pixel(img, x, y, pixel);
        }
    }

    fclose(fp);
}

int main() {
    Image img;
    create_image(&img);

    load_image(&img, "input.ppm");
    printf("Image loaded with dimensions: %dx%d\n", img.width, img.height);

    for (int y = 0; y < img.height; y++) {
        for (int x = 0; x < img.width; x++) {
            int pixel = get_pixel(&img, x, y);
            printf("%d ", pixel);
        }
        printf("\n");
    }

    set_pixel(&img, 5, 5, 255);
    printf("Setting pixel (5, 5) to 255.\n");
    printf("New pixel value: %d\n", get_pixel(&img, 5, 5));

    save_image(&img, "output.ppm");
    printf("Image saved to output.ppm.\n");

    destroy_image(&img);

    return 0;
}
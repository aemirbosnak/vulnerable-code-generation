//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int width;
    int height;
    int* pixels;
} Image;

void load_image(const char* filename, Image* image) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening image file.\n");
        return;
    }

    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    rewind(fp);

    image->width = 640;
    image->height = 480;
    image->pixels = (int*)malloc(image->width * image->height * sizeof(int));
    if (image->pixels == NULL) {
        printf("Error allocating memory for image pixels.\n");
        fclose(fp);
        return;
    }

    fread(image->pixels, sizeof(int), image->width * image->height, fp);
    fclose(fp);
}

void save_image(const char* filename, Image* image) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error opening image file.\n");
        return;
    }

    fwrite(image->pixels, sizeof(int), image->width * image->height, fp);
    fclose(fp);
}

void display_image(Image* image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            printf("%d ", image->pixels[y * image->width + x]);
        }
        printf("\n");
    }
}

void change_pixel(Image* image, int x, int y, int new_value) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        printf("Invalid pixel coordinates.\n");
        return;
    }
    image->pixels[y * image->width + x] = new_value;
}

int main() {
    Image image;
    load_image("image.bmp", &image);
    display_image(&image);
    change_pixel(&image, 10, 10, 255);
    save_image("modified_image.bmp", &image);
    return 0;
}
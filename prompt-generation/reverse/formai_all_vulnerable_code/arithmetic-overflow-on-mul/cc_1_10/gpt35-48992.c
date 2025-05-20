//FormAI DATASET v1.0 Category: Image Editor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pixel {
    unsigned char red, green, blue; // RGB value of a pixel
};

struct image {
    int width, height; // Dimensions of the image
    struct pixel *data; // Pointer to the pixel data
};

// Function to read image data from a file
int read_image(char *path, struct image *img) {
    FILE *fp = fopen(path, "rb"); // Open file in binary mode
    if(!fp) {
        printf("ERROR: Could not open file \"%s\"\n", path);
        return 0;
    }
    // Read image header
    char header[54];
    fread(header, sizeof(char), 54, fp);
    // Extract image dimensions
    img->width = *(int*)&header[18];
    img->height = *(int*)&header[22];
    // Allocate memory for pixel data
    img->data = (struct pixel*)malloc(img->width * img->height * sizeof(struct pixel));
    // Read pixel data
    fread(img->data, sizeof(struct pixel), img->width * img->height, fp);
    fclose(fp);
    return 1;
}

// Function to write image data to a file
int write_image(char *path, struct image *img) {
    FILE *fp = fopen(path, "wb"); // Open file in binary mode
    if(!fp) {
        printf("ERROR: Could not open file \"%s\"\n", path);
        return 0;
    }
    // Write image header
    char header[54];
    memset(header, 0, sizeof(header));
    header[0] = 'B';
    header[1] = 'M';
    *(int*)&header[2] = 54 + img->width * img->height * 3;
    *(int*)&header[10] = 54;
    *(int*)&header[14] = 40;
    *(int*)&header[18] = img->width;
    *(int*)&header[22] = img->height;
    *(short*)&header[26] = 1;
    *(short*)&header[28] = 24;
    fwrite(header, sizeof(char), 54, fp);
    // Write pixel data
    fwrite(img->data, sizeof(struct pixel), img->width * img->height, fp);
    fclose(fp);
    return 1;
}

// Function to swap two pixels
void swap_pixels(struct pixel *p1, struct pixel *p2) {
    struct pixel tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

// Function to invert the colors of an image
void invert_colors(struct image *img) {
    for(int i = 0; i < img->width * img->height; i++) {
        img->data[i].red = 255 - img->data[i].red;
        img->data[i].green = 255 - img->data[i].green;
        img->data[i].blue = 255 - img->data[i].blue;
    }
}

// Function to apply a sepia filter to an image
void sepia_filter(struct image *img) {
    for(int i = 0; i < img->width * img->height; i++) {
        int r = img->data[i].red;
        int g = img->data[i].green;
        int b = img->data[i].blue;
        img->data[i].red = (r * 0.393) + (g * 0.769) + (b * 0.189);
        img->data[i].green = (r * 0.349) + (g * 0.686) + (b * 0.168);
        img->data[i].blue = (r * 0.272) + (g * 0.534) + (b * 0.131);
    }
}

// Function to apply a grayscale filter to an image
void grayscale_filter(struct image *img) {
    for(int i = 0; i < img->width * img->height; i++) {
        int r = img->data[i].red;
        int g = img->data[i].green;
        int b = img->data[i].blue;
        int y = 0.299 * r + 0.587 * g + 0.114 * b;
        img->data[i].red = y;
        img->data[i].green = y;
        img->data[i].blue = y;
    }
}

// Function to apply a blur effect to an image
void blur_effect(struct image *img) {
    struct pixel *tmp = (struct pixel*)malloc(img->width * img->height * sizeof(struct pixel));
    memcpy(tmp, img->data, img->width * img->height * sizeof(struct pixel));
    for(int i = 1; i < img->height - 1; i++) {
        for(int j = 1; j < img->width - 1; j++) {
            int r = 0, g = 0, b = 0;
            for(int x = -1; x <= 1; x++) {
                for(int y = -1; y <= 1; y++) {
                    r += tmp[(i + x) * img->width + j + y].red;
                    g += tmp[(i + x) * img->width + j + y].green;
                    b += tmp[(i + x) * img->width + j + y].blue;
                }
            }
            img->data[i * img->width + j].red = r / 9;
            img->data[i * img->width + j].green = g / 9;
            img->data[i * img->width + j].blue = b / 9;
        }
    }
    free(tmp);
}

int main() {
    struct image img;
    if(!read_image("input.bmp", &img))
        return 1;
    // Apply effects
    invert_colors(&img);
    sepia_filter(&img);
    grayscale_filter(&img);
    blur_effect(&img);
    // Save output image
    if(!write_image("output.bmp", &img))
        return 1;
    free(img.data);
    return 0;
}
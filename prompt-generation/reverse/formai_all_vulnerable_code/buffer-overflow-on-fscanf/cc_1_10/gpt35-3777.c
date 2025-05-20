//FormAI DATASET v1.0 Category: Image Editor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

// define image struct
typedef struct {
    int width;
    int height;
    int* pixels;
} Image;

// function to create new image
Image* new_image(int width, int height) {
    Image* img = (Image*)malloc(sizeof(Image));
    int* pixels = (int*)malloc(sizeof(int) * width * height);
    img->width = width;
    img->height = height;
    img->pixels = pixels;
    memset(pixels, 0, sizeof(int) * width * height);
    return img;
}

// function to set pixel color
void set_pixel(Image* img, int x, int y, int color) {
    int i = y * img->width + x;
    if(i >= 0 && i < img->width * img->height) {
        img->pixels[i] = color;
    }
}

// function to get pixel color
int get_pixel(Image* img, int x, int y) {
    int i = y * img->width + x;
    if(i >= 0 && i < img->width * img->height) {
        return img->pixels[i];
    }
    return 0;
}

// function to invert colors of an image
void invert(Image* img) {
    for(int y=0; y<img->height; y++) {
        for(int x=0; x<img->width; x++) {
            int c = get_pixel(img, x, y);
            set_pixel(img, x, y, 255 - c);
        }
    }
}

// function to blur an image using a Gaussian filter
void blur(Image* img) {
    float sigma = 1.0;
    int radius = ceil(3 * sigma);
    float* kernel = (float*)malloc(sizeof(float) * (2 * radius + 1) * (2 * radius + 1));
    float sum = 0.0;
    for(int j=-radius; j<=radius; j++) {
        for(int i=-radius; i<=radius; i++) {
            kernel[(j + radius) * (2 * radius + 1) + (i + radius)] = exp(-(i * i + j * j) / (2 * sigma * sigma));
            sum += kernel[(j + radius) * (2 * radius + 1) + (i + radius)];
        }
    }
    for(int j=0; j<img->height; j++) {
        for(int i=0; i<img->width; i++) {
            float c = 0.0;
            sum = 0.0;
            for(int jj=-radius; jj<=radius; jj++) {
                for(int ii=-radius; ii<=radius; ii++) {
                    int x = i + ii;
                    int y = j + jj;
                    if(x >= 0 && x < img->width && y >= 0 && y < img->height) {
                        float weight = kernel[(jj + radius) * (2 * radius + 1) + (ii + radius)];
                        c += weight * get_pixel(img, x, y);
                        sum += weight;
                    }
                }
            }
            set_pixel(img, i, j, round(c / sum));
        }
    }
    free(kernel);
}

// main function
int main(int argc, char** argv) {
    if(argc < 2) {
        printf("Usage: %s [input file name]\n", argv[0]);
        return 0;
    }
    char* input_filename = argv[1];
    char output_filename[256];
    sprintf(output_filename, "%s.out.ppm", input_filename);

    FILE* input_file = fopen(input_filename, "rb");
    if(input_file == NULL) {
        printf("Error: could not open input file\n");
        return 0;
    }

    char magic_number[3];
    int width, height, max_value;
    fscanf(input_file, "%2s\n%d %d\n%d\n", magic_number, &width, &height, &max_value);
    if(strcmp(magic_number, "P6") != 0) {
        printf("Error: input file is not a P6 PPM image\n");
        fclose(input_file);
        return 0;
    }

    Image* img = new_image(width, height);
    for(int y=0; y<height; y++) {
        for(int x=0; x<width; x++) {
            int r = fgetc(input_file);
            int g = fgetc(input_file);
            int b = fgetc(input_file);
            int c = (r << 16) | (g << 8) | b;
            set_pixel(img, x, y, c);
        }
    }
    fclose(input_file);

    // apply image operations
    invert(img);
    blur(img);

    // save output image
    FILE* output_file = fopen(output_filename, "wb");
    if(output_file == NULL) {
        printf("Error: could not open output file\n");
        free(img->pixels);
        free(img);
        return 0;
    }
    fprintf(output_file, "P6\n%d %d\n%d\n", img->width, img->height, 255);
    for(int y=0; y<img->height; y++) {
        for(int x=0; x<img->width; x++) {
            int c = get_pixel(img, x, y);
            fputc((c >> 16) & 0xFF, output_file);
            fputc((c >> 8) & 0xFF, output_file);
            fputc(c & 0xFF, output_file);
        }
    }
    fclose(output_file);

    // free image memory
    free(img->pixels);
    free(img);

    return 0;
}
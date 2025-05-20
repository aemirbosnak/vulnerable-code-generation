//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *pixels;
} Image;

// Function to flip an image horizontally
void flip_horizontally(Image *img) {
    int i, j;
    Pixel tmp;
    
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width/2; j++) {
            tmp = img->pixels[i * img->width + j];
            img->pixels[i * img->width + j] = img->pixels[i * img->width + (img->width - 1 - j)];
            img->pixels[i * img->width + (img->width - 1 - j)] = tmp;
        }
    }
}

// Function to adjust brightness of an image
void adjust_brightness(Image *img, int value) {
    int i, j;
    Pixel p;
    
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            p = img->pixels[i * img->width + j];
            p.red += value;
            p.green += value;
            p.blue += value;
            img->pixels[i * img->width + j] = p;
        }
    }
}

// Function to adjust contrast of an image
void adjust_contrast(Image *img, float value) {
    int i, j;
    float factor = (259.0 * (value + 255.0)) / (255.0 * (259.0 - value));
    Pixel p;
    
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            p = img->pixels[i * img->width + j];
            p.red = factor * (p.red - 128) + 128;
            p.green = factor * (p.green - 128) + 128;
            p.blue = factor * (p.blue - 128) + 128;
            img->pixels[i * img->width + j] = p;
        }
    }
}

// Function to load an image from a file
Image* load_image(char *filename) {
    Image *img = NULL;
    FILE *fp;
    int w, h, maxval, i, j;
    Pixel p;
    char magic[3];
    
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }
    
    // Read image header
    fscanf(fp, "%s\n%d %d\n%d\n", magic, &w, &h, &maxval);
    if (strcmp(magic, "P6") != 0 || maxval != 255) {
        fprintf(stderr, "Error: invalid image format\n");
        fclose(fp);
        return NULL;
    }
    
    // Allocate memory for image data
    img = (Image*) malloc(sizeof(Image));
    img->width = w;
    img->height = h;
    img->pixels = (Pixel*) malloc(w * h * sizeof(Pixel));
    
    // Read image data
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            fread(&p, sizeof(Pixel), 1, fp);
            img->pixels[i * w + j] = p;
        }
    }
    
    fclose(fp);
    return img;
}

// Function to save an image to a file
void save_image(Image *img, char *filename) {
    FILE *fp;
    int i, j;
    Pixel p;
    
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return;
    }
    
    // Write image header
    fprintf(fp, "P6\n%d %d\n%d\n", img->width, img->height, 255);
    
    // Write image data
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            p = img->pixels[i * img->width + j];
            fwrite(&p, sizeof(Pixel), 1, fp);
        }
    }
    
    fclose(fp);
}

int main(int argc, char **argv) {
    char *input_filename, *output_filename;
    Image *img;
    
    if (argc != 4) {
        fprintf(stderr, "Usage: %s [input file] [output file] [operation]\n", argv[0]);
        fprintf(stderr, "Operations:\n");
        fprintf(stderr, "  -f: flip horizontally\n");
        fprintf(stderr, "  -b [value]: adjust brightness (value can be positive or negative)\n");
        fprintf(stderr, "  -c [value]: adjust contrast (value must be between -255 and 255)\n");
        return 1;
    }
    
    input_filename = argv[1];
    output_filename = argv[2];
    img = load_image(input_filename);
    
    if (img == NULL) {
        exit(1);
    }
    
    if (strcmp(argv[3], "-f") == 0) {
        flip_horizontally(img);
    } else if (strcmp(argv[3], "-b") == 0 && argc == 5) {
        adjust_brightness(img, atoi(argv[4]));
    } else if (strcmp(argv[3], "-c") == 0 && argc == 5) {
        adjust_contrast(img, atof(argv[4]));
    } else {
        fprintf(stderr, "Error: invalid operation\n");
        exit(1);
    }
    
    save_image(img, output_filename);
    free(img->pixels);
    free(img);
    return 0;
}
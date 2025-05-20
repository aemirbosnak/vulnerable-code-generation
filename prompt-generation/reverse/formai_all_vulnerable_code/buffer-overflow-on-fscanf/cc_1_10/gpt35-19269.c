//FormAI DATASET v1.0 Category: Image Editor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel;

typedef struct {
    int width;
    int height;
    pixel *data;
} image;

// function to read image data from a given file
image *read_image(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file \"%s\".\n", filename);
        exit(1);
    }
    char format[3];
    int width, height, max_intensity;
    fscanf(file, "%s\n%d %d\n%d\n", format, &width, &height, &max_intensity);
    if (strcmp(format, "P6") != 0 || max_intensity > 255) {
        fprintf(stderr, "Error: Unsupported image format.\n");
        exit(1);
    }
    image *img = malloc(sizeof(image));
    img->width = width;
    img->height = height;
    img->data = malloc(sizeof(pixel) * width * height);
    fread(img->data, sizeof(pixel), width * height, file);
    fclose(file);
    return img;
}

// function to write image data to a given file
void write_image(image *img, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file \"%s\".\n", filename);
        exit(1);
    }
    fprintf(file, "P6\n%d %d\n%d\n", img->width, img->height, 255);
    fwrite(img->data, sizeof(pixel), img->width * img->height, file);
    fclose(file);
}

// function to invert the colors of an image
void invert_colors(image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].red = 255 - img->data[i].red;
        img->data[i].green = 255 - img->data[i].green;
        img->data[i].blue = 255 - img->data[i].blue;
    }
}

// function to grayscale an image
void grayscale(image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        unsigned char gray = ((unsigned int) img->data[i].red + img->data[i].green + img->data[i].blue) / 3;
        img->data[i].red = gray;
        img->data[i].green = gray;
        img->data[i].blue = gray;
    }
}

// function to blur an image using a simple box blur algorithm
void blur(image *img) {
    pixel *new_data = malloc(sizeof(pixel) * img->width * img->height);
    for (int i = 0; i < img->width * img->height; i++) {
        int r = 0, g = 0, b = 0, count = 0;
        int x = i % img->width;
        int y = i / img->width;
        for (int j = -1; j <= 1; j++) {
            for (int k = -1; k <= 1; k++) {
                if (x + j >= 0 && x + j < img->width && y + k >= 0 && y + k < img->height) {
                    r += img->data[(y + k) * img->width + (x + j)].red;
                    g += img->data[(y + k) * img->width + (x + j)].green;
                    b += img->data[(y + k) * img->width + (x + j)].blue;
                    count++;
                }
            }
        }
        new_data[i].red = r / count;
        new_data[i].green = g / count;
        new_data[i].blue = b / count;
    }
    free(img->data);
    img->data = new_data;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s [function] [input file] [output file]\n", argv[0]);
        exit(1);
    }
    image *img = read_image(argv[2]);
    if (strcmp(argv[1], "invert") == 0) {
        invert_colors(img);
    }
    else if (strcmp(argv[1], "grayscale") == 0) {
        grayscale(img);
    }
    else if (strcmp(argv[1], "blur") == 0) {
        blur(img);
    }
    else {
        fprintf(stderr, "Error: Unsupported function.\n");
        exit(1);
    }
    write_image(img, argv[3]);
    free(img->data);
    free(img);
    return 0;
}
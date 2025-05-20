//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>

// Declare the image structure
typedef struct {
    unsigned char *data;    // Pointer to raw image data
    unsigned int width;     // Image width in pixels
    unsigned int height;    // Image height in pixels
    unsigned int channels;  // Number of color channels (1 or 3)
} Image;

// Function to flip image horizontally
void flip_horizontal(Image *img) {
    size_t row_size = img->width * img->channels;
    unsigned char *tmp = (unsigned char*)malloc(row_size);
    for (unsigned int y = 0; y < img->height; y++) {
        unsigned char *row = img->data + y * row_size;
        for (unsigned int x = 0; x < img->width / 2; x++) {
            memcpy(tmp, row + x * img->channels, img->channels);
            memcpy(row + x * img->channels, row + (img->width - x - 1) * img->channels, img->channels);
            memcpy(row + (img->width - x - 1) * img->channels, tmp, img->channels);
        }
    }
    free(tmp);
}

// Function to adjust image brightness and contrast
void adjust_brightness_contrast(Image *img, float brightness, float contrast) {
    for (unsigned int y = 0; y < img->height; y++) {
        unsigned char *row = img->data + y * img->width * img->channels;
        for (unsigned int x = 0; x < img->width; x++) {
            for (unsigned int c = 0; c < img->channels; c++) {
                unsigned char pixel = row[x * img->channels + c];
                pixel = (unsigned char)(brightness + (float) (pixel - brightness) * contrast);
                row[x * img->channels + c] = pixel;
            }
        }
    }
}

// Function to read image from file
Image read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    int width, height, channels;
    if (fscanf(fp, "P%d\n%d %d\n255\n", &channels, &width, &height) != 3) {
        fprintf(stderr, "Error: Invalid PGM/PPM file format for file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    if (channels != 1 && channels != 3) {
        fprintf(stderr, "Error: Unsupported number of channels %d in file %s\n", channels, filename);
        exit(EXIT_FAILURE);
    }
    Image img;
    img.width = (unsigned int) width;
    img.height = (unsigned int) height;
    img.channels = (unsigned int) channels;
    img.data = (unsigned char*)malloc(img.width * img.height * img.channels);
    if (!img.data) {
        fprintf(stderr, "Error: Unable to allocate memory for image data\n");
        exit(EXIT_FAILURE);
    }
    if (fread(img.data, 1, img.width * img.height * img.channels, fp) != img.width * img.height * img.channels) {
        fprintf(stderr, "Error: Unable to read image data from file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    fclose(fp);
    return img;
}

// Function to write image to file
void write_image(const char *filename, const Image *img) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error: Unable to open file %s for writing\n", filename);
        exit(EXIT_FAILURE);
    }
    fprintf(fp, "P%d\n%d %d\n255\n", img->channels, img->width, img->height);
    if (fwrite(img->data, 1, img->width * img->height * img->channels, fp) != img->width * img->height * img->channels) {
        fprintf(stderr, "Error: Unable to write image data to file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    fclose(fp);
}

int main(int argc, char **argv) {
    // Check command-line arguments
    if (argc != 6) {
        fprintf(stderr, "Usage: %s in-file out-file brightness contrast flip\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    const char *in_file = argv[1];
    const char *out_file = argv[2];
    float brightness = (float) atof(argv[3]);
    float contrast = (float) atof(argv[4]);
    int do_flip = atoi(argv[5]);

    // Read image from file
    Image img = read_image(in_file);

    // Adjust brightness and contrast
    adjust_brightness_contrast(&img, brightness, contrast);

    // Flip image horizontally if needed
    if (do_flip) {
        flip_horizontal(&img);
    }

    // Write image to file
    write_image(out_file, &img);

    // Free image data
    free(img.data);

    return EXIT_SUCCESS;
}
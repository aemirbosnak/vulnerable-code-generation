//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for storing image information
typedef struct {
    unsigned int width;
    unsigned int height;
    unsigned char *data;
} Image;

// Function to load image data from file
Image *loadImage(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    Image *image = (Image *) malloc(sizeof(Image));
    fscanf(fp, "%u %u\n", &image->width, &image->height);
    image->data = (unsigned char *) malloc(image->width * image->height);
    fread(image->data, sizeof(unsigned char), image->width * image->height, fp);
    fclose(fp);
    return image;
}

// Function to save image data to file
void saveImage(Image *image, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    fprintf(fp, "%u %u\n", image->width, image->height);
    fwrite(image->data, sizeof(unsigned char), image->width * image->height, fp);
    fclose(fp);
}

// Function to insert digital watermark in image data
void insertWatermark(Image *image, char *watermark) {
    unsigned int watermark_length = strlen(watermark);
    unsigned int offset = 0;
    for (unsigned int i = 0; i < watermark_length; i++) {
        unsigned int pixel_index = offset % (image->width * image->height);
        image->data[pixel_index] |= watermark[i];
        offset += image->data[pixel_index] % watermark_length;
    }
}

int main() {
    // Load image data from file
    Image *image = loadImage("image.bin");

    // Insert digital watermark in image data
    char *watermark = "This is my digital watermark";
    insertWatermark(image, watermark);

    // Save watermarked image data to file
    saveImage(image, "watermarked_image.bin");

    // Free memory allocated for image data
    free(image->data);
    free(image);

    return 0;
}
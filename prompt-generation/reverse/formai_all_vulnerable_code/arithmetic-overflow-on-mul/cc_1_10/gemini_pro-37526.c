//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char *data;
    int width;
    int height;
} Image;

Image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    // Read the header information.
    unsigned char header[14];
    fread(header, sizeof(header), 1, fp);

    // Check if the file is a BMP file.
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: file %s is not a BMP file\n", filename);
        fclose(fp);
        return NULL;
    }

    // Read the image dimensions.
    int width = *(unsigned short *)(header + 18);
    int height = *(unsigned short *)(header + 22);

    // Allocate memory for the image data.
    Image *image = malloc(sizeof(Image));
    image->data = malloc(width * height * 3);

    // Read the image data.
    fread(image->data, width * height * 3, 1, fp);

    // Close the file.
    fclose(fp);

    // Return the image.
    return image;
}

void save_image(const char *filename, Image *image) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return;
    }

    // Write the header information.
    unsigned char header[14];
    header[0] = 'B';
    header[1] = 'M';
    *(unsigned short *)(header + 2) = 14 + 40 + image->width * image->height * 3;
    *(unsigned short *)(header + 4) = 0;
    *(unsigned short *)(header + 6) = 0;
    *(unsigned short *)(header + 8) = 14 + 40;
    *(unsigned short *)(header + 10) = 40;
    *(unsigned short *)(header + 12) = image->width;
    *(unsigned short *)(header + 14) = image->height;
    *(unsigned short *)(header + 16) = 1;
    *(unsigned short *)(header + 18) = 24;
    *(unsigned int *)(header + 20) = 0;
    *(unsigned int *)(header + 24) = image->width * image->height * 3;
    *(unsigned short *)(header + 28) = 0;
    *(unsigned short *)(header + 30) = 0;
    *(unsigned short *)(header + 32) = 0;
    *(unsigned short *)(header + 34) = 0;
    fwrite(header, sizeof(header), 1, fp);

    // Write the image data.
    fwrite(image->data, image->width * image->height * 3, 1, fp);

    // Close the file.
    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    // Load the input image.
    Image *image = load_image(argv[1]);
    if (!image) {
        return 1;
    }

    // Convert the image to grayscale.
    for (int i = 0; i < image->width * image->height; i++) {
        unsigned char gray = (image->data[i * 3] + image->data[i * 3 + 1] + image->data[i * 3 + 2]) / 3;
        image->data[i * 3] = gray;
        image->data[i * 3 + 1] = gray;
        image->data[i * 3 + 2] = gray;
    }

    // Save the output image.
    save_image(argv[2], image);

    // Free the image data.
    free(image->data);
    free(image);

    return 0;
}
//FormAI DATASET v1.0 Category: Image compression ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Define bitmap header structure
typedef struct {
    unsigned short int type; // Magic identifier
    unsigned int size; // File size in bytes
    unsigned short int reserved1, reserved2;
    unsigned int offset; // Offset to image data
} BITMAPHEADER;

// Define bitmap information header structure
typedef struct {
    unsigned int size; // Header size in bytes
    int width, height; // Width and height of image
    unsigned short int planes;
    unsigned short int bits; // Number of bits per pixel
    unsigned int compression; // Compression type
    unsigned int imagesize; // Image size in bytes
    int xresolution, yresolution; // Pixels per meter
    unsigned int ncolors; // Number of colors
    unsigned int importantcolors; // Important colors
} BITMAPINFOHEADER;

int main() {
    // Define variables
    int width, height, size, x, y;
    unsigned char *image, *compressed;
    BITMAPHEADER header;
    BITMAPINFOHEADER infoheader;

    // Read image file
    FILE *file = fopen("image.bmp", "rb");
    if (!file) {
        printf("Error: could not open image file!\n");
        return 1;
    }

    // Read bitmap header
    fread(&header, sizeof(BITMAPHEADER), 1, file);

    // Read bitmap information header
    fread(&infoheader, sizeof(BITMAPINFOHEADER), 1, file);

    // Validate image format
    if (header.type != 0x4D42 || infoheader.bits != 24) {
        printf("Error: invalid image format!\n");
        fclose(file);
        return 1;
    }

    // Calculate image size
    width = infoheader.width;
    height = infoheader.height;
    size = width * height * 3;

    // Allocate memory for image data
    image = (unsigned char*)malloc(size);
    if (!image) {
        printf("Error: could not allocate memory for image!\n");
        fclose(file);
        return 1;
    }

    // Read image data
    fread(image, size, 1, file);

    // Close file
    fclose(file);

    // Compress image data
    compressed = (unsigned char*)malloc(size);
    if (!compressed) {
        printf("Error: could not allocate memory for compressed image!\n");
        free(image);
        return 1;
    }

    int index = 0;
    unsigned char r, g, b;
    unsigned char last_r = 0, last_g = 0, last_b = 0;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            index = y * width * 3 + x * 3;
            r = image[index];
            g = image[index + 1];
            b = image[index + 2];

            // Apply compression algorithm
            if (r == last_r && g == last_g && b == last_b) {
                compressed[index] = 0x80;
            } else {
                compressed[index] = r;
            }
            if (g == last_g && b == last_b) {
                compressed[index + 1] = 0x80;
            } else {
                compressed[index + 1] = g;
            }
            if (b == last_b) {
                compressed[index + 2] = 0x80;
            } else {
                compressed[index + 2] = b;
            }

            last_r = r;
            last_g = g;
            last_b = b;
        }
    }

    // Save compressed image file
    FILE *outfile = fopen("compressed_image.bmp", "wb");
    if (!outfile) {
        printf("Error: could not create compressed image file!\n");
        fclose(file);
        free(image);
        free(compressed);
        return 1;
    }

    // Write bitmap header
    fwrite(&header, sizeof(BITMAPHEADER), 1, outfile);

    // Write bitmap information header
    fwrite(&infoheader, sizeof(BITMAPINFOHEADER), 1, outfile);

    // Write compressed image data
    fwrite(compressed, size, 1, outfile);

    // Close file
    fclose(outfile);

    // Free memory
    free(image);
    free(compressed);

    printf("Compression complete!\n");

    return 0;
}
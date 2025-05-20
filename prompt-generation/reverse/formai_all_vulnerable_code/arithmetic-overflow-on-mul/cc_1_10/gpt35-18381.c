//FormAI DATASET v1.0 Category: Image Editor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Define pixel struct
typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel;

// Define image struct
typedef struct {
    int width;
    int height;
    pixel *data;
} image;

// Function to create an image
image *create_image(int width, int height) {
    image *img = malloc(sizeof(image));
    img->width = width;
    img->height = height;
    img->data = malloc(sizeof(pixel) * width * height);
    return img;
}

// Function to destroy an image
void destroy_image(image *img) {
    free(img->data);
    free(img);
}

// Function to get the color of a pixel at (x, y)
pixel get_pixel(image *img, int x, int y) {
    return img->data[y * img->width + x];
}

// Function to set the color of a pixel at (x, y)
void set_pixel(image *img, int x, int y, pixel color) {
    img->data[y * img->width + x] = color;
}

// Function to read an image from a file
image *read_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file\n");
        return NULL;
    }

    // Get file size
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Allocate memory for file data
    unsigned char *file_data = malloc(sizeof(unsigned char) * file_size);

    // Read file data
    fread(file_data, sizeof(unsigned char), file_size, fp);
    fclose(fp);

    // Parse header data
    int width = file_data[18] + (file_data[19] << 8);
    int height = file_data[22] + (file_data[23] << 8);

    // Create image
    image *img = create_image(width, height);

    // Parse pixel data
    int offset = file_data[10] + (file_data[11] << 8);
    for (int i = 0; i < width * height; i++) {
        pixel p = {file_data[offset + i * 3], file_data[offset + i * 3 + 1], file_data[offset + i * 3 + 2]};
        img->data[i] = p;
    }

    // Free file data memory
    free(file_data);

    return img;
}

// Function to write an image to a file
void write_image(image *img, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: could not open file\n");
        return;
    }

    // Write header data
    unsigned char header[] = {
        0x42, 0x4D,           // BMP signature
        0x36, 0x00, 0x0E, 0x00,  // File size (54 + width * height * 3)
        0x00, 0x00,           // Reserved
        0x00, 0x00,           // Reserved
        0x36, 0x00, 0x00, 0x00,  // Offset to pixel data
        0x28, 0x00, 0x00, 0x00,  // Header size
        0x00, 0x00, 0x00, 0x02,  // Width
        0x00, 0x00, 0x00, 0x02,  // Height
        0x01, 0x00,           // Color planes
        0x18, 0x00,           // Bits per pixel
        0x00, 0x00, 0x00, 0x00,  // Compression method (no compression)
        0x00, 0x00, 0x0E, 0x00,  // Image size (width * height * 3)
        0x13, 0x0B, 0x00, 0x00,  // X resolution (2835 ppi)
        0x13, 0x0B, 0x00, 0x00,  // Y resolution (2835 ppi)
        0x00, 0x00, 0x00, 0x00,  // Color palette (not used)
        0x00, 0x00, 0x00, 0x00   // Important colors (not used)
    };
    header[18] = img->width & 0xFF;
    header[19] = (img->width >> 8) & 0xFF;
    header[22] = img->height & 0xFF;
    header[23] = (img->height >> 8) & 0xFF;
    fwrite(header, sizeof(unsigned char), 54, fp);

    // Write pixel data
    for (int i = 0; i < img->width * img->height; i++) {
        fwrite(&img->data[i].b, sizeof(unsigned char), 1, fp);
        fwrite(&img->data[i].g, sizeof(unsigned char), 1, fp);
        fwrite(&img->data[i].r, sizeof(unsigned char), 1, fp);
    }

    fclose(fp);
}

int main() {
    // Read image
    image *img = read_image("input.bmp");

    // Process image
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            pixel p = get_pixel(img, x, y);
            // Invert colors
            p.r = 255 - p.r;
            p.g = 255 - p.g;
            p.b = 255 - p.b;
            set_pixel(img, x, y, p);
        }
    }

    // Write image
    write_image(img, "output.bmp");

    // Clean up
    destroy_image(img);
    return 0;
}
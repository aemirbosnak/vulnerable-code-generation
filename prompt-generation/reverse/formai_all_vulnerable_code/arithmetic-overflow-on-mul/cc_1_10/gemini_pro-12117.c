//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Image data structure
typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

// Load an image from a file
Image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }
    
    // Read the image header
    unsigned char header[18];
    fread(header, sizeof(header), 1, file);
    
    // Check if the file is a valid BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: file %s is not a valid BMP file\n", filename);
        fclose(file);
        return NULL;
    }
    
    // Get the image dimensions
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];
    
    // Allocate memory for the image data
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height * 3);
    
    // Read the image data
    fread(image->data, width * height * 3, 1, file);
    
    // Close the file
    fclose(file);
    
    return image;
}

// Save an image to a file
void save_image(const char *filename, Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return;
    }
    
    // Write the image header
    unsigned char header[18] = {
        'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0, 40, 0, 0, 0
    };
    *(int *)&header[18] = image->width;
    *(int *)&header[22] = image->height;
    fwrite(header, sizeof(header), 1, file);
    
    // Write the image data
    fwrite(image->data, image->width * image->height * 3, 1, file);
    
    // Close the file
    fclose(file);
}

// Flip an image horizontally
void flip_image_horizontally(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width / 2; j++) {
            unsigned char temp = image->data[i * image->width * 3 + j * 3];
            image->data[i * image->width * 3 + j * 3] = image->data[i * image->width * 3 + (image->width - j - 1) * 3];
            image->data[i * image->width * 3 + (image->width - j - 1) * 3] = temp;
        }
    }
}

// Flip an image vertically
void flip_image_vertically(Image *image) {
    for (int i = 0; i < image->height / 2; i++) {
        for (int j = 0; j < image->width; j++) {
            unsigned char *top = &image->data[i * image->width * 3 + j * 3];
            unsigned char *bottom = &image->data[(image->height - i - 1) * image->width * 3 + j * 3];
            
            unsigned char temp = *top;
            *top = *bottom;
            *bottom = temp;
        }
    }
}

// Adjust the brightness of an image
void adjust_brightness(Image *image, double brightness) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            for (int k = 0; k < 3; k++) {
                int value = image->data[i * image->width * 3 + j * 3 + k] + brightness;
                if (value < 0) {
                    value = 0;
                } else if (value > 255) {
                    value = 255;
                }
                image->data[i * image->width * 3 + j * 3 + k] = value;
            }
        }
    }
}

// Adjust the contrast of an image
void adjust_contrast(Image *image, double contrast) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            for (int k = 0; k < 3; k++) {
                int value = (image->data[i * image->width * 3 + j * 3 + k] - 128) * contrast + 128;
                if (value < 0) {
                    value = 0;
                } else if (value > 255) {
                    value = 255;
                }
                image->data[i * image->width * 3 + j * 3 + k] = value;
            }
        }
    }
}

// Free the memory allocated for an image
void free_image(Image *image) {
    free(image->data);
    free(image);
}

// Usage: ./image_processing input.bmp output.bmp
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: ./image_processing input.bmp output.bmp\n");
        return 1;
    }
    
    // Load the input image
    Image *image = load_image(argv[1]);
    if (!image) {
        return 1;
    }
    
    // Flip the image horizontally
    flip_image_horizontally(image);
    
    // Adjust the brightness of the image
    adjust_brightness(image, 50);
    
    // Adjust the contrast of the image
    adjust_contrast(image, 1.2);
    
    // Save the output image
    save_image(argv[2], image);
    
    // Free the memory allocated for the image
    free_image(image);
    
    return 0;
}
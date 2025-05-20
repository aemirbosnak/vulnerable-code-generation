//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: Linus Torvalds
// Linux Torvalds style C Image Editor

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define some colors
#define BLACK 0
#define WHITE 255

// Define the image struct
typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

// Load an image from a file
Image *load_image(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        return NULL;
    }

    // Read the header
    unsigned char header[14];
    fread(header, sizeof(header), 1, file);
    if (header[0] != 'B' || header[1] != 'M') {
        return NULL;
    }

    // Read the width and height
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Read the data
    unsigned char *data = malloc(width * height);
    fread(data, width * height, 1, file);
    fclose(file);

    // Create the image struct
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = data;

    return image;
}

// Save an image to a file
void save_image(Image *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        return;
    }

    // Write the header
    unsigned char header[14];
    header[0] = 'B';
    header[1] = 'M';
    *(int *)&header[2] = image->width;
    *(int *)&header[6] = image->height;
    *(int *)&header[10] = 1;
    *(int *)&header[12] = 24;
    fwrite(header, sizeof(header), 1, file);

    // Write the data
    fwrite(image->data, image->width * image->height, 1, file);
    fclose(file);
}

// Invert the colors of an image
void invert_colors(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->data[i] = 255 - image->data[i];
    }
}

// Blur an image
void blur(Image *image) {
    for (int i = 1; i < image->width - 1; i++) {
        for (int j = 1; j < image->height - 1; j++) {
            int sum = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    sum += image->data[(i + k) * image->width + (j + l)];
                }
            }
            image->data[i * image->width + j] = sum / 9;
        }
    }
}

// Sharpen an image
void sharpen(Image *image) {
    for (int i = 1; i < image->width - 1; i++) {
        for (int j = 1; j < image->height - 1; j++) {
            int sum = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    sum += image->data[(i + k) * image->width + (j + l)];
                }
            }
            image->data[i * image->width + j] = sum - 9 * image->data[i * image->width + j];
        }
    }
}

// Edge detection
void edge_detection(Image *image) {
    for (int i = 1; i < image->width - 1; i++) {
        for (int j = 1; j < image->height - 1; j++) {
            int dx = image->data[(i + 1) * image->width + j] - image->data[(i - 1) * image->width + j];
            int dy = image->data[i * image->width + (j + 1)] - image->data[i * image->width + (j - 1)];
            image->data[i * image->width + j] = sqrt(dx * dx + dy * dy);
        }
    }
}

// Main function
int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    // Load the input image
    Image *image = load_image(argv[1]);
    if (image == NULL) {
        printf("Error loading image: %s\n", argv[1]);
        return 1;
    }

    // Apply the filter
    invert_colors(image);
    blur(image);
    sharpen(image);
    edge_detection(image);

    // Save the output image
    save_image(image, argv[2]);
    free(image->data);
    free(image);

    return 0;
}
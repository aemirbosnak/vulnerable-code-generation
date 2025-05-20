//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Image data structure
typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

// Load image from file
Image* load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    // Read header
    unsigned char header[18];
    fread(header, 18, 1, file);

    // Check if file is a BMP
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: file is not a BMP\n");
        fclose(file);
        return NULL;
    }

    // Read width and height
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Allocate memory for image data
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height * 3);

    // Read image data
    fread(image->data, width * height * 3, 1, file);

    // Close file
    fclose(file);

    return image;
}

// Save image to file
void save_image(const char *filename, Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return;
    }

    // Write header
    unsigned char header[18] = {
        'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0, 40, 0, 0, 0
    };
    *(int*)&header[18] = image->width;
    *(int*)&header[22] = image->height;
    fwrite(header, 18, 1, file);

    // Write image data
    fwrite(image->data, image->width * image->height * 3, 1, file);

    // Close file
    fclose(file);
}

// Invert image colors
void invert_colors(Image *image) {
    for (int i = 0; i < image->width * image->height * 3; i++) {
        image->data[i] = 255 - image->data[i];
    }
}

// Apply sepia filter
void sepia_filter(Image *image) {
    for (int i = 0; i < image->width * image->height * 3; i += 3) {
        unsigned char red = image->data[i];
        unsigned char green = image->data[i + 1];
        unsigned char blue = image->data[i + 2];

        // Calculate sepia values
        unsigned char sepiaRed = (red * 0.393) + (green * 0.769) + (blue * 0.189);
        unsigned char sepiaGreen = (red * 0.349) + (green * 0.686) + (blue * 0.168);
        unsigned char sepiaBlue = (red * 0.272) + (green * 0.534) + (blue * 0.131);

        // Clamp values to 0-255
        sepiaRed = sepiaRed > 255 ? 255 : sepiaRed;
        sepiaGreen = sepiaGreen > 255 ? 255 : sepiaGreen;
        sepiaBlue = sepiaBlue > 255 ? 255 : sepiaBlue;

        // Set sepia values
        image->data[i] = sepiaRed;
        image->data[i + 1] = sepiaGreen;
        image->data[i + 2] = sepiaBlue;
    }
}

// Apply grayscale filter
void grayscale_filter(Image *image) {
    for (int i = 0; i < image->width * image->height * 3; i += 3) {
        unsigned char red = image->data[i];
        unsigned char green = image->data[i + 1];
        unsigned char blue = image->data[i + 2];

        // Calculate grayscale value
        unsigned char grayscale = (red + green + blue) / 3;

        // Set grayscale values
        image->data[i] = grayscale;
        image->data[i + 1] = grayscale;
        image->data[i + 2] = grayscale;
    }
}

// Main function
int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_image> <output_image>\n", argv[0]);
        return 1;
    }

    // Load input image
    Image *image = load_image(argv[1]);
    if (!image) {
        return 1;
    }

    // Apply filter
    invert_colors(image);
    sepia_filter(image);
    grayscale_filter(image);

    // Save output image
    save_image(argv[2], image);

    // Free image data
    free(image->data);
    free(image);

    return 0;
}
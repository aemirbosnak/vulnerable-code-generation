//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to represent an image
typedef struct {
    int width;
    int height;
    unsigned char *data; // RGB data (3 bytes per pixel)
} Image;

// Function to load a PPM file
Image* load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: Cannot open image file %s\n", filename);
        return NULL;
    }

    char buffer[16];
    int maxval;
    Image *img = (Image *)malloc(sizeof(Image));

    // Read PPM header
    if (!fgets(buffer, sizeof(buffer), file) || buffer[0] != 'P' || buffer[1] != '6') {
        fclose(file);
        fprintf(stderr, "Error: Invalid PPM file\n");
        free(img);
        return NULL;
    }

    // Read width, height, and max color value
    fscanf(file, "%d %d", &img->width, &img->height);
    fscanf(file, "%d", &maxval);
    fgetc(file); // Read the newline after maxval

    img->data = (unsigned char *)malloc(img->width * img->height * 3);
    fread(img->data, 3, img->width * img->height, file); // Read pixel data

    fclose(file);
    return img;
}

// Function to save an image to a PPM file
void save_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: Cannot save image file %s\n", filename);
        return;
    }

    // Write PPM header
    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, 3, img->width * img->height, file);
    fclose(file);
}

// Function to apply grayscale filter to an image
void apply_grayscale(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        unsigned char r = img->data[i * 3];
        unsigned char g = img->data[i * 3 + 1];
        unsigned char b = img->data[i * 3 + 2];
        
        // Convert to grayscale
        unsigned char gray = (unsigned char)(0.299 * r + 0.587 * g + 0.114 * b);
        img->data[i * 3] = gray;     // R
        img->data[i * 3 + 1] = gray; // G
        img->data[i * 3 + 2] = gray; // B
    }
}

// Function to free image memory
void free_image(Image *img) {
    if (img) {
        free(img->data);
        free(img);
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_image.ppm> <output_image.ppm>\n", argv[0]);
        return 1;
    }

    // Load image
    Image *img = load_image(argv[1]);
    if (!img) {
        return 1;
    }

    // Apply futuristic grayscale filter
    apply_grayscale(img);

    // Save the processed image
    save_image(argv[2], img);

    // Clean up
    free_image(img);
    printf("Image editing operations complete. Output saved to %s\n", argv[2]);

    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Image struct
typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

// Load an image from a file
Image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        return NULL;
    }

    // Read the header
    unsigned char header[14];
    fread(header, sizeof(header), 1, fp);

    // Check if the file is a valid BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fclose(fp);
        return NULL;
    }

    // Read the image dimensions
    int width = (header[18] << 8) | header[19];
    int height = (header[22] << 8) | header[23];

    // Allocate memory for the image data
    unsigned char *data = malloc(width * height * 3);
    if (!data) {
        fclose(fp);
        return NULL;
    }

    // Read the image data
    fread(data, width * height * 3, 1, fp);

    // Close the file
    fclose(fp);

    // Create the image struct
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = data;

    return image;
}

// Free the memory allocated for an image
void free_image(Image *image) {
    free(image->data);
    free(image);
}

// Flip an image horizontally
void flip_horizontal(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width / 2; x++) {
            int left = 3 * (x + y * image->width);
            int right = 3 * ((image->width - 1 - x) + y * image->width);
            unsigned char temp = image->data[left];
            image->data[left] = image->data[right];
            image->data[right] = temp;
        }
    }
}

// Flip an image vertically
void flip_vertical(Image *image) {
    for (int y = 0; y < image->height / 2; y++) {
        for (int x = 0; x < image->width; x++) {
            int top = 3 * (x + y * image->width);
            int bottom = 3 * (x + (image->height - 1 - y) * image->width);
            unsigned char temp = image->data[top];
            image->data[top] = image->data[bottom];
            image->data[bottom] = temp;
        }
    }
}

// Change the brightness of an image
void change_brightness(Image *image, int brightness) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int offset = 3 * (x + y * image->width);
            image->data[offset] = image->data[offset] + brightness;
            image->data[offset + 1] = image->data[offset + 1] + brightness;
            image->data[offset + 2] = image->data[offset + 2] + brightness;
        }
    }
}

// Change the contrast of an image
void change_contrast(Image *image, int contrast) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int offset = 3 * (x + y * image->width);
            image->data[offset] = image->data[offset] * contrast;
            image->data[offset + 1] = image->data[offset + 1] * contrast;
            image->data[offset + 2] = image->data[offset + 2] * contrast;
        }
    }
}

// Save an image to a file
void save_image(const char *filename, Image *image) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        return;
    }

    // Write the header
    unsigned char header[14] = {
        'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0
    };
    fwrite(header, sizeof(header), 1, fp);

    // Write the image dimensions
    int width = image->width;
    int height = image->height;
    unsigned char width_bytes[4] = {
        (width & 0xFF),
        ((width >> 8) & 0xFF),
        ((width >> 16) & 0xFF),
        ((width >> 24) & 0xFF)
    };
    fwrite(width_bytes, sizeof(width_bytes), 1, fp);

    unsigned char height_bytes[4] = {
        (height & 0xFF),
        ((height >> 8) & 0xFF),
        ((height >> 16) & 0xFF),
        ((height >> 24) & 0xFF)
    };
    fwrite(height_bytes, sizeof(height_bytes), 1, fp);

    // Write the number of color planes
    unsigned char planes[2] = {1, 0};
    fwrite(planes, sizeof(planes), 1, fp);

    // Write the number of bits per pixel
    unsigned char bits_per_pixel[2] = {24, 0};
    fwrite(bits_per_pixel, sizeof(bits_per_pixel), 1, fp);

    // Write the compression type
    unsigned char compression[4] = {0, 0, 0, 0};
    fwrite(compression, sizeof(compression), 1, fp);

    // Write the image size
    unsigned char image_size[4] = {0, 0, 0, 0};
    fwrite(image_size, sizeof(image_size), 1, fp);

    // Write the horizontal resolution
    unsigned char horizontal_resolution[4] = {0, 0, 0, 0};
    fwrite(horizontal_resolution, sizeof(horizontal_resolution), 1, fp);

    // Write the vertical resolution
    unsigned char vertical_resolution[4] = {0, 0, 0, 0};
    fwrite(vertical_resolution, sizeof(vertical_resolution), 1, fp);

    // Write the number of colors in the palette
    unsigned char colors_in_palette[4] = {0, 0, 0, 0};
    fwrite(colors_in_palette, sizeof(colors_in_palette), 1, fp);

    // Write the number of important colors
    unsigned char important_colors[4] = {0, 0, 0, 0};
    fwrite(important_colors, sizeof(important_colors), 1, fp);

    // Write the image data
    fwrite(image->data, image->width * image->height * 3, 1, fp);

    // Close the file
    fclose(fp);
}

// Main function
int main() {
    // Load the image
    Image *image = load_image("image.bmp");
    if (!image) {
        return 1;
    }

    // Flip the image horizontally
    flip_horizontal(image);

    // Flip the image vertically
    flip_vertical(image);

    // Change the brightness of the image
    change_brightness(image, 50);

    // Change the contrast of the image
    change_contrast(image, 1.5);

    // Save the image
    save_image("new_image.bmp", image);

    // Free the memory allocated for the image
    free_image(image);

    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    uint8_t r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

Image* load_image(const char *filename);
void save_image(const char *filename, Image *image);
void flip_image(Image *image);
void change_brightness_contrast(Image *image, float brightness, float contrast);
void free_image(Image *image);
void print_image_info(Image *image);

int main() {
    const char *input_file = "input.bmp";
    const char *output_file_flipped = "flipped_output.bmp";
    const char *output_file_brightness_contrast = "brightness_contrast_output.bmp";

    // Load the image from file
    Image *image = load_image(input_file);
    if (!image) {
        fprintf(stderr, "Failed to load image\n");
        return 1;
    }

    print_image_info(image);

    // Flip the image and save it
    flip_image(image);
    save_image(output_file_flipped, image);

    // Change brightness and contrast
    change_brightness_contrast(image, 50, 1.5); // Increase brightness and contrast
    save_image(output_file_brightness_contrast, image);

    // Clean up
    free_image(image);

    return 0;
}

Image* load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    fseek(file, 18, SEEK_SET);
    Image *image = (Image *)malloc(sizeof(Image));
    fread(&image->width, sizeof(int), 1, file);
    fread(&image->height, sizeof(int), 1, file);

    fseek(file, 54, SEEK_SET); // Skip BMP header
    image->data = (Pixel *)malloc(image->width * image->height * sizeof(Pixel));
    fread(image->data, sizeof(Pixel), image->width * image->height, file);

    fclose(file);
    return image;
}

void save_image(const char *filename, Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    // Write a simple BMP header for a 24-bit bitmap
    uint8_t header[54] = {
        'B', 'M', 0, 0, 0, 0, 0, 0, 54, 0, 0, 0,
        0, 0, 0, 0, 1, 0, 24, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    
    int row_size = (image->width * 3 + 3) & (~3);
    int pixel_array_size = row_size * image->height;

    *(int*)&header[2] = 54 + pixel_array_size; // File size
    *(int*)&header[18] = image->width; // Width
    *(int*)&header[22] = image->height; // Height
    *(int*)&header[34] = pixel_array_size; // Pixel array size

    fwrite(header, sizeof(uint8_t), sizeof(header), file);
    fwrite(image->data, sizeof(Pixel), image->width * image->height, file);

    fclose(file);
}

void flip_image(Image *image) {
    int width = image->width;
    int height = image->height;
    for (int y = 0; y < height / 2; y++) {
        for (int x = 0; x < width; x++) {
            // Swap pixels
            Pixel temp = image->data[y * width + x];
            image->data[y * width + x] = image->data[(height - 1 - y) * width + x];
            image->data[(height - 1 - y) * width + x] = temp;
        }
    }
}

void change_brightness_contrast(Image *image, float brightness, float contrast) {
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    
    for (int i = 0; i < image->width * image->height; i++) {
        for (int j = 0; j < 3; j++) {
            uint8_t *channel = (uint8_t *)&image->data[i] + j;
            int new_value = factor * (*channel - 128) + 128 + brightness;

            // Clamp values to [0, 255]
            if (new_value > 255) new_value = 255;
            if (new_value < 0) new_value = 0;

            *channel = (uint8_t)new_value;
        }
    }
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}

void print_image_info(Image *image) {
    printf("Image width: %d\n", image->width);
    printf("Image height: %d\n", image->height);
}
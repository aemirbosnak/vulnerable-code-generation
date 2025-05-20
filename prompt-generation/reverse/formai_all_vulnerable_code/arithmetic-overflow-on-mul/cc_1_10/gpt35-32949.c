//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare function prototypes
void flip_image(unsigned char* image, int width, int height);
void adjust_brightness(unsigned char* image, int width, int height, int delta);
void adjust_contrast(unsigned char* image, int width, int height, float factor);

int main() {
    // Open image file
    FILE* fp;
    fp = fopen("image.raw", "rb");
    if (!fp) {
        printf("Error opening file\n");
        exit(1);
    }

    // Read image size from user
    int width, height;
    printf("Enter image width and height (separated by space): ");
    scanf("%d %d", &width, &height);

    // Calculate size of image buffer and allocate memory
    int size = width * height;
    unsigned char* image_buffer = malloc(size * sizeof(unsigned char));

    // Read image data from file
    fread(image_buffer, sizeof(unsigned char), size, fp);
    fclose(fp);

    // Display original image
    printf("Original image:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", image_buffer[i]);
    }
    printf("\n");

    // Flip image horizontally
    flip_image(image_buffer, width, height);
    printf("Flipped image:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", image_buffer[i]);
    }
    printf("\n");

    // Adjust brightness
    int delta;
    printf("Enter brightness adjustment value (-255 to 255): ");
    scanf("%d", &delta);
    adjust_brightness(image_buffer, width, height, delta);
    printf("Brightness adjusted image:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", image_buffer[i]);
    }
    printf("\n");

    // Adjust contrast
    float factor;
    printf("Enter contrast adjustment factor (0.1 to 10.0): ");
    scanf("%f", &factor);
    adjust_contrast(image_buffer, width, height, factor);
    printf("Contrast adjusted image:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", image_buffer[i]);
    }
    printf("\n");

    // Free memory allocated for image buffer
    free(image_buffer);

    return 0;
}

void flip_image(unsigned char* image, int width, int height) {
    unsigned char* temp_row = malloc(width * sizeof(unsigned char));
    for (int i = 0; i < height; i++) {
        int start = i*width;
        int end = start + width - 1;
        for (int j = start; j < start + width / 2; j++) {
            int k = end - (j - start);
            temp_row[j - start] = image[j];
            image[j] = image[k];
            image[k] = temp_row[j - start];
        }
    }
    free(temp_row);
}

void adjust_brightness(unsigned char* image, int width, int height, int delta) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int value = image[i*width + j] + delta;
            if (value < 0) {
                value = 0;
            } else if (value > 255) {
                value = 255;
            }
            image[i*width + j] = value;
        }
    }
}

void adjust_contrast(unsigned char* image, int width, int height, float factor) {
    float mean = 0.0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            mean += image[i*width + j];
        }
    }
    mean /= (float)(width*height);

    float std_dev = 0.0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std_dev += (image[i*width + j] - mean)*(image[i*width + j] - mean);
        }
    }
    std_dev /= (float)(width*height);
    std_dev = sqrtf(std_dev);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int value = (int)((image[i*width + j] - mean)*factor + mean);
            if (value < 0) {
                value = 0;
            } else if (value > 255) {
                value = 255;
            }
            image[i*width + j] = value;
        }
    }
}
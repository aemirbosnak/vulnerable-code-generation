//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define BLOCK_SIZE 256

// Convert an image to grayscale
void convert_to_grayscale(uint8_t *image, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            uint8_t r = image[3 * x + 0];
            uint8_t g = image[3 * x + 1];
            uint8_t b = image[3 * x + 2];
            uint8_t gray = (r + g + b) / 3;
            image[3 * x + 0] = gray;
            image[3 * x + 1] = gray;
            image[3 * x + 2] = gray;
        }
    }
}

// Find the median of an array
uint8_t find_median(uint8_t *array, int length) {
    uint8_t median;
    int low = 0;
    int high = length - 1;
    while (low < high) {
        int mid = (low + high) / 2;
        if (array[mid] < array[high]) {
            median = array[high];
            high = mid;
        } else {
            median = array[low];
            low = mid + 1;
        }
    }
    return median;
}

// Insert a secret message into an image
void insert_message(uint8_t *image, int width, int height, const char *message) {
    int message_length = strlen(message);
    int num_blocks = (width * height) / BLOCK_SIZE;
    int block_index;
    int block_length;
    int message_index;
    for (int i = 0; i < message_length; i++) {
        block_index = i / num_blocks;
        block_length = BLOCK_SIZE - ((i % num_blocks) * 3);
        message_index = i % num_blocks;
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if (y * width + x >= block_index * BLOCK_SIZE && y * width + x < (block_index + 1) * BLOCK_SIZE) {
                    image[3 * x + message_index] = message[i];
                }
            }
        }
    }
}

int main() {
    FILE *fp;
    uint8_t *image;
    int width, height;

    // Open the image file
    fp = fopen("image.png", "rb");
    if (fp == NULL) {
        printf("Error opening image file.\n");
        return 1;
    }

    // Read the image data
    fread(image, 1, (width * height * 3), fp);
    fclose(fp);

    // Convert the image to grayscale
    convert_to_grayscale(image, width, height);

    // Insert a secret message into the image
    insert_message(image, width, height, "Hello, World!");

    // Write the modified image data back to the file
    fp = fopen("image_stego.png", "wb");
    fwrite(image, 1, (width * height * 3), fp);
    fclose(fp);

    return 0;
}
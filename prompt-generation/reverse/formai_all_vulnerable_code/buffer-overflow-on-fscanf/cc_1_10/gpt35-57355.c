//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Number of bits in the watermark message
#define NUM_BITS 8

// Length of the watermark message in bytes
#define MESSAGE_LEN 6

// Structure to store the watermark message
typedef struct {
    unsigned char message[MESSAGE_LEN];
} Watermark;

// Function to embed the watermark in a given image
void embed_watermark(unsigned char* image, int width, int height, const Watermark* watermark) {
    // Calculate the total number of pixels in the image
    int num_pixels = width * height;

    // Calculate the total number of bits in the watermark message
    int num_watermark_bits = NUM_BITS * MESSAGE_LEN;

    // Check if the image is large enough to embed the entire watermark
    if ((num_pixels * 3) < num_watermark_bits) {
        printf("Error: Image is too small to embed watermark.\n");
        return;
    }

    // Embed the watermark in the image
    int pixel_idx = 0;  // Index of the current pixel
    int bit_idx = 0;    // Index of the current bit in the watermark message

    while (bit_idx < num_watermark_bits) {
        // Get the current byte from the watermark message
        unsigned char byte = watermark->message[bit_idx/NUM_BITS];

        // Get the current bit from the watermark message
        int bit = (byte >> (NUM_BITS - 1 - (bit_idx % NUM_BITS))) & 1;

        // Get the current RGB pixel values from the image
        int red = image[pixel_idx];
        int green = image[pixel_idx+1];
        int blue = image[pixel_idx+2];

        // Embed the bit into the LSB of the blue pixel value
        blue = (blue & 0xFE) | bit;

        // Update the image with the new RGB pixel values
        image[pixel_idx] = red;
        image[pixel_idx+1] = green;
        image[pixel_idx+2] = blue;

        // Move to the next pixel and bit
        pixel_idx += 3;
        bit_idx++;
    }
}

// Function to extract the watermark from a given image
void extract_watermark(const unsigned char* image, int width, int height, Watermark* watermark) {
    // Calculate the total number of pixels in the image
    int num_pixels = width * height;

    // Calculate the total number of bits in the watermark message
    int num_watermark_bits = NUM_BITS * MESSAGE_LEN;

    // Extract the watermark from the image
    int pixel_idx = 0;  // Index of the current pixel
    int bit_idx = 0;    // Index of the current bit in the watermark message

    while (bit_idx < num_watermark_bits) {
        // Get the current blue pixel value from the image
        int blue = image[pixel_idx+2];

        // Extract the LSB of the blue pixel value as the current bit
        int bit = blue & 1;

        // Add the current bit to the watermark message
        watermark->message[bit_idx/NUM_BITS] |= (bit << (NUM_BITS - 1 - (bit_idx % NUM_BITS)));

        // Move to the next pixel and bit
        pixel_idx += 3;
        bit_idx++;
    }
}

int main() {
    // Load the image data from a file
    FILE* fp = fopen("input.ppm", "rb");
    if (!fp) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    // Read the image header
    int width, height, max_val;
    if (fscanf(fp, "P6 %d %d %d", &width, &height, &max_val) < 3) {
        printf("Error: Could not read image header.\n");
        fclose(fp);
        return 1;
    }

    // Allocate memory for the image data
    int num_pixels = width * height;
    unsigned char* image = (unsigned char*) malloc(num_pixels * 3);
    if (!image) {
        printf("Error: Could not allocate memory for image.\n");
        fclose(fp);
        return 1;
    }

    // Read the image data
    if ((int)fread(image, sizeof(unsigned char), num_pixels * 3, fp) < num_pixels * 3) {
        printf("Error: Could not read image data.\n");
        fclose(fp);
        free(image);
        return 1;
    }

    // Close the input file
    fclose(fp);

    // Create the watermark message
    Watermark watermark;
    memcpy(watermark.message, "hello!", MESSAGE_LEN);

    // Embed the watermark in the image
    embed_watermark(image, width, height, &watermark);

    // Output the watermarked image to a file
    fp = fopen("output.ppm", "wb");
    if (!fp) {
        printf("Error: Could not open output file.\n");
        free(image);
        return 1;
    }

    // Write the image header
    fprintf(fp, "P6 %d %d %d ", width, height, max_val);

    // Write the image data
    if ((int)fwrite(image, sizeof(unsigned char), num_pixels * 3, fp) < num_pixels * 3) {
        printf("Error: Could not write image data.\n");
        fclose(fp);
        free(image);
        return 1;
    }

    // Close the output file
    fclose(fp);

    // Extract the watermark from the watermarked image
    Watermark extracted_watermark;
    extract_watermark(image, width, height, &extracted_watermark);

    // Print the extracted watermark
    printf("Extracted Watermark: %s\n", extracted_watermark.message);

    // Free the image data
    free(image);

    return 0;
}
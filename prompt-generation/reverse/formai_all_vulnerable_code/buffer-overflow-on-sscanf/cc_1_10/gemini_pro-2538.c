//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

// Function to embed a watermark into an image
void embed_watermark(uint8_t *image, uint8_t *watermark, int image_width, int image_height, int watermark_width, int watermark_height)
{
    // Calculate the number of bits in the watermark
    int num_bits = watermark_width * watermark_height;

    // Iterate over the pixels in the image
    for (int i = 0; i < image_width * image_height; i++)
    {
        // Get the least significant bit of the pixel
        uint8_t lsb = image[i] & 0x1;

        // If the watermark bit is 1, set the LSB of the pixel to 1
        if (watermark[i / 8] & (1 << (i % 8)))
        {
            image[i] |= 0x1;
        }
        // Otherwise, set the LSB of the pixel to 0
        else
        {
            image[i] &= ~0x1;
        }
    }
}

// Function to extract a watermark from an image
void extract_watermark(uint8_t *image, uint8_t *watermark, int image_width, int image_height, int watermark_width, int watermark_height)
{
    // Iterate over the pixels in the image
    for (int i = 0; i < image_width * image_height; i++)
    {
        // Get the least significant bit of the pixel
        uint8_t lsb = image[i] & 0x1;

        // Set the corresponding bit in the watermark to the LSB of the pixel
        watermark[i / 8] |= (lsb << (i % 8));
    }
}

// Main function
int main(int argc, char **argv)
{
    // Check if the correct number of arguments was provided
    if (argc != 5)
    {
        fprintf(stderr, "Usage: %s <image_file> <watermark_file> <output_file> <watermark_dimensions>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Read the image file
    FILE *image_file = fopen(argv[1], "rb");
    if (image_file == NULL)
    {
        fprintf(stderr, "Error opening image file: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Read the watermark file
    FILE *watermark_file = fopen(argv[2], "rb");
    if (watermark_file == NULL)
    {
        fprintf(stderr, "Error opening watermark file: %s\n", argv[2]);
        return EXIT_FAILURE;
    }

    // Get the dimensions of the watermark
    int watermark_dimensions[2];
    if (sscanf(argv[4], "%dx%d", &watermark_dimensions[0], &watermark_dimensions[1]) != 2)
    {
        fprintf(stderr, "Invalid watermark dimensions: %s\n", argv[4]);
        return EXIT_FAILURE;
    }

    // Allocate memory for the image data
    uint8_t *image_data = malloc(1024 * 1024);
    if (image_data == NULL)
    {
        fprintf(stderr, "Error allocating memory for image data\n");
        return EXIT_FAILURE;
    }

    // Allocate memory for the watermark data
    uint8_t *watermark_data = malloc(watermark_dimensions[0] * watermark_dimensions[1] / 8);
    if (watermark_data == NULL)
    {
        fprintf(stderr, "Error allocating memory for watermark data\n");
        return EXIT_FAILURE;
    }

    // Read the image data into memory
    size_t image_size = fread(image_data, 1, 1024 * 1024, image_file);
    if (image_size == 0)
    {
        fprintf(stderr, "Error reading image data\n");
        return EXIT_FAILURE;
    }

    // Read the watermark data into memory
    size_t watermark_size = fread(watermark_data, 1, watermark_dimensions[0] * watermark_dimensions[1] / 8, watermark_file);
    if (watermark_size == 0)
    {
        fprintf(stderr, "Error reading watermark data\n");
        return EXIT_FAILURE;
    }

    // Embed the watermark into the image
    embed_watermark(image_data, watermark_data, 1024, 1024, watermark_dimensions[0], watermark_dimensions[1]);

    // Write the watermarked image to a file
    FILE *output_file = fopen(argv[3], "wb");
    if (output_file == NULL)
    {
        fprintf(stderr, "Error opening output file: %s\n", argv[3]);
        return EXIT_FAILURE;
    }

    fwrite(image_data, 1, image_size, output_file);

    // Extract the watermark from the image and verify it
    uint8_t *extracted_watermark_data = malloc(watermark_dimensions[0] * watermark_dimensions[1] / 8);
    if (extracted_watermark_data == NULL)
    {
        fprintf(stderr, "Error allocating memory for extracted watermark data\n");
        return EXIT_FAILURE;
    }

    extract_watermark(image_data, extracted_watermark_data, 1024, 1024, watermark_dimensions[0], watermark_dimensions[1]);

    if (memcmp(watermark_data, extracted_watermark_data, watermark_dimensions[0] * watermark_dimensions[1] / 8) != 0)
    {
        fprintf(stderr, "Watermark extraction failed\n");
        return EXIT_FAILURE;
    }

    // Free the allocated memory
    free(image_data);
    free(watermark_data);
    free(extracted_watermark_data);

    return EXIT_SUCCESS;
}
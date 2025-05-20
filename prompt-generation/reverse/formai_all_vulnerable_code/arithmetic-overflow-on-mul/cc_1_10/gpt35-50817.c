//FormAI DATASET v1.0 Category: Image compression ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

/* Function to Calculate Entropy */
float calculate_entropy(int *frequency, int total_pixels)
{
    int i;
    float entropy = 0.0;

    for (i = 0; i < 256; i++)
    {
        if (frequency[i] != 0)
        {
            float probability = (float) frequency[i] / total_pixels;
            entropy += (-probability * log2(probability));
        }
    }

    return entropy;
}

/* Function to Perform Image Compression */
void compress_image(char *input_image_path, char *output_image_path)
{
    FILE *input_file = fopen(input_image_path, "rb");

    // Check if file exists
    if (input_file == NULL)
    {
        printf("File %s does not exist\n", input_image_path);
        return;
    }

    FILE *output_file = fopen(output_image_path, "wb");

    // Read image header
    uint8_t header[54];
    fread(&header, sizeof(uint8_t), 54, input_file);

    // Get image dimensions
    int width = *(int *) &header[18];
    int height = *(int *) &header[22];
    int bit_depth = *(int *) &header[28];

    // Calculate total number of pixels
    int total_pixels = width * height;

    // Initialize frequency array with zeros
    int frequency[256] = {0};

    // Read pixel values and calculate frequency
    int i;
    for (i = 0; i < total_pixels; i++)
    {
        uint8_t pixel;
        fread(&pixel, sizeof(uint8_t), 1, input_file);
        frequency[pixel]++;
    }

    // Calculate entropy
    float entropy = calculate_entropy(frequency, total_pixels);
    printf("Original Image Entropy: %f\n", entropy);

    // Write compressed image header
    fwrite(&header, sizeof(uint8_t), 54, output_file);

    // Write compressed pixel values
    int new_bits_per_pixel = ceil(log2(entropy));
    printf("Bits per pixel after compression: %d\n", new_bits_per_pixel);
    uint8_t compressed_pixel;
    for (i = 0; i < total_pixels; i++)
    {
        uint8_t pixel;
        fread(&pixel, sizeof(uint8_t), 1, input_file);
        compressed_pixel = (uint8_t) ((pixel >> (8 - new_bits_per_pixel)) << (8 - new_bits_per_pixel));
        fwrite(&compressed_pixel, sizeof(uint8_t), 1, output_file);
    }

    printf("Image Compression Complete!\n");

    // Close files
    fclose(input_file);
    fclose(output_file);
}

int main()
{
    char *input_image_path = "input.bmp";
    char *output_image_path = "output.bmp";

    compress_image(input_image_path, output_image_path);

    return 0;
}
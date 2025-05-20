//FormAI DATASET v1.0 Category: Image compression ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Global variables
int width, height, bpp, compression_ratio;

// Function to calculate the compression ratio
void calculate_compression_ratio(int original_size, int compressed_size) {
    float ratio = ((float)compressed_size / (float)original_size) * 100;
    compression_ratio = 100 - (int)ratio;
}

int main() {

    // Read the input image file
    FILE *input_file = fopen("input_image.raw", "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file!\n");
        return 0;
    }

    // Read the header information from the image file
    fread(&width, sizeof(int), 1, input_file);
    fread(&height, sizeof(int), 1, input_file);
    fread(&bpp, sizeof(int), 1, input_file);

    // Calculate the size of the image data
    int image_data_size = width * height * bpp;

    // Allocate memory to store the uncompressed image data
    unsigned char *image_data = (unsigned char*)malloc(image_data_size);

    // Read the uncompressed image data from the file
    fread(image_data, sizeof(unsigned char), image_data_size, input_file);

    // Calculate the original size of the image
    int original_size = ftell(input_file);

    // Close the input file
    fclose(input_file);

    // Perform image compression using any compression algorithm of your choice here

    // ...

    // Calculate the compressed size of the image data
    int compressed_size = image_data_size / 2;

    // Calculate the compression ratio
    calculate_compression_ratio(original_size, compressed_size);

    // Write the compressed image data to a new file
    FILE *output_file = fopen("compressed_image.raw", "wb");
    if (output_file == NULL) {
        printf("Error: Could not create output file!\n");
        return 0;
    }

    // Write the header information to the output file
    fwrite(&width, sizeof(int), 1, output_file);
    fwrite(&height, sizeof(int), 1, output_file);
    fwrite(&bpp, sizeof(int), 1, output_file);

    // Write the compressed image data to the file
    fwrite(image_data, sizeof(unsigned char), compressed_size, output_file);

    // Close the output file
    fclose(output_file);

    // Free the memory allocated for the uncompressed image data
    free(image_data);

    // Print the compression ratio
    printf("Image compression completed successfully!\n");
    printf("Compression ratio: %d%%\n", compression_ratio);

    return 0;
}
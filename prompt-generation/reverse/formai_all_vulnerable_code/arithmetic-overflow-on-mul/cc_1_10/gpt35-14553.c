//FormAI DATASET v1.0 Category: Image Editor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Welcome message
    printf("Welcome to the Visionary Image Editor!\n");

    // Prompt user for input file name
    char in_file_name[100];
    printf("Enter the name of the input file (must be a .bmp file): ");
    scanf("%s", in_file_name);

    // Open input file
    FILE* in_file = fopen(in_file_name, "rb");
    if (!in_file) {
        printf("Error: could not open input file %s\n", in_file_name);
        return 1;
    }

    // Read header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, in_file);

    // Extract image dimensions from header
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Calculate image size in bytes
    int image_size = width * height * 3;

    // Allocate memory for image data
    unsigned char* image_data = (unsigned char*)malloc(image_size);

    // Read image data from file
    fread(image_data, sizeof(unsigned char), image_size, in_file);

    // Close input file
    fclose(in_file);

    // Prompt user for output file name
    char out_file_name[100];
    printf("Enter the name of the output file (must be a .bmp file): ");
    scanf("%s", out_file_name);

    // Open output file
    FILE* out_file = fopen(out_file_name, "wb");
    if (!out_file) {
        printf("Error: could not open output file %s\n", out_file_name);
        free(image_data);
        return 1;
    }

    // Write header to output file
    fwrite(header, sizeof(unsigned char), 54, out_file);

    // Edit image data here to make a visionary image!
    // For example, shift the color values of each pixel 50 units
    for (int i = 0; i < image_size; i += 3) {
        image_data[i] = (image_data[i] + 50) % 256;
        image_data[i+1] = (image_data[i+1] + 50) % 256;
        image_data[i+2] = (image_data[i+2] + 50) % 256;
    }

    // Write edited image data to output file
    fwrite(image_data, sizeof(unsigned char), image_size, out_file);

    // Close output file
    fclose(out_file);

    // Free memory for image data
    free(image_data);

    // Success message
    printf("Image edited successfully and saved to %s!\n", out_file_name);

    return 0;
}
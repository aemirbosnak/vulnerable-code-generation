//FormAI DATASET v1.0 Category: Image Editor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define BMP_HEADER_SIZE 54

int main() {
    FILE *input_file, *output_file;
    char input_filename[50], output_filename[50];
    unsigned char header[BMP_HEADER_SIZE];
    unsigned char *image_data;
    int image_width, image_height, image_size, i, j;

    // Get input filename from user
    printf("Enter input filename (BMP format): ");
    scanf("%s", input_filename);

    // Open input file in binary mode
    input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        printf("Error opening input file!");
        exit(1);
    }

    // Read header
    fread(header, sizeof(unsigned char), BMP_HEADER_SIZE, input_file);

    // Extract image dimensions
    image_width = *((int*)&header[18]);
    image_height = *((int*)&header[22]);

    // Calculate image size
    image_size = image_width * image_height * 3;

    // Allocate memory for image data
    image_data = (unsigned char*)malloc(image_size);

    // Read image data from file
    fread(image_data, sizeof(unsigned char), image_size, input_file);

    // Close input file
    fclose(input_file);

    // Example image manipulation: Invert colors
    for (i = 0; i < image_size; i++) {
        image_data[i] = 255 - image_data[i];
    }

    // Get output filename from user
    printf("Enter output filename (BMP format): ");
    scanf("%s", output_filename);

    // Open output file in binary mode
    output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        printf("Error opening output file!");
        exit(1);
    }

    // Write header to output file
    fwrite(header, sizeof(unsigned char), BMP_HEADER_SIZE, output_file);

    // Write image data to output file
    fwrite(image_data, sizeof(unsigned char), image_size, output_file);

    // Close output file
    fclose(output_file);

    // Free memory
    free(image_data);

    return 0;
}
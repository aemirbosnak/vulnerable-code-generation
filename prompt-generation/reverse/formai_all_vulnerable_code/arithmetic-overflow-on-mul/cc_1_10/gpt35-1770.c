//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_WIDTH 200
#define MAX_HEIGHT 200
#define ASCII_SIZE 95

// Define the ASCII characters used (in ascending order of intensity)
const char* ascii_chars = " .`^\",:;Il!i><~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";

// Define the function signature
void convert_to_ascii(char* image_path);

int main(int argc, char* argv[]) {
    // Check if the correct number of arguments have been provided
    if (argc != 2) {
        printf("Error: Please provide the path to the input image file as the only argument.\n");
        return 1;
    }

    // Pass the image path to the convert_to_ascii function
    convert_to_ascii(argv[1]);

    return 0;
}

void convert_to_ascii(char* image_path) {
    // Define variables
    char ascii_image[MAX_HEIGHT][MAX_WIDTH + 1];
    int image_width = 0, image_height = 0;
    double intensity_ratio = 0.0;
    unsigned char image[MAX_HEIGHT][MAX_WIDTH];
    FILE* input_file;
    FILE* output_file;

    // Open input file for reading
    input_file = fopen(image_path, "rb");
    if (!input_file) {
        printf("Error: Could not open input file.\n");
        return;
    }

    // Read the image width and height
    fseek(input_file, 18, SEEK_SET);
    fread(&image_width, sizeof(int), 1, input_file);
    fread(&image_height, sizeof(int), 1, input_file);

    // Check if the image dimensions are within the allowed limits
    if (image_width > MAX_WIDTH || image_height > MAX_HEIGHT) {
        printf("Error: Image dimensions are too large.\n");
        fclose(input_file);
        return;
    }

    // Read the image data
    fseek(input_file, 54, SEEK_SET);
    fread(image, sizeof(unsigned char), image_width * image_height, input_file);

    // Close the input file
    fclose(input_file);

    // Calculate the intensity ratio
    intensity_ratio = (double)ASCII_SIZE / 256;

    // Generate the ASCII art
    for (int i = 0; i < image_height; i++) {
        for (int j = 0; j < image_width; j++) {
            int index = (int)(image[i][j] * intensity_ratio);
            ascii_image[i][j] = ascii_chars[index];
        }
        ascii_image[i][image_width] = '\0';
    }

    // Open output file for writing
    output_file = fopen("ascii.txt", "w");
    if (!output_file) {
        printf("Error: Could not open output file.\n");
        return;
    }

    // Write the ASCII art to the output file
    for (int i = 0; i < image_height; i++) {
        fprintf(output_file, "%s\n", ascii_image[i]);
    }

    // Close the output file
    fclose(output_file);

    printf("Conversion complete. ASCII art saved to ascii.txt\n");
}
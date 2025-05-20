//FormAI DATASET v1.0 Category: Image compression ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Welcome to the happiest image compression program!\n");
    
    // Ask user for input file name
    char input_file[1000];
    printf("Please enter the name of the input file: ");
    scanf("%s", input_file);
    
    // Open input file
    FILE *fp_input = fopen(input_file, "rb");
    if (fp_input == NULL) {
        printf("Error: Failed to open input file!\n");
        exit(1);
    }

    // Ask user for output file name
    char output_file[1000];
    printf("Please enter the name of the output file: ");
    scanf("%s", output_file);
    
    // Open output file
    FILE *fp_output = fopen(output_file, "wb");
    if (fp_output == NULL) {
        printf("Error: Failed to open output file!\n");
        exit(1);
    }

    // Read input file header and write to output file
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp_input);
    fwrite(header, sizeof(unsigned char), 54, fp_output);

    // Get image dimensions
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Calculate pixel array size
    int size = width * height * 3;

    // Allocate memory for pixel array
    unsigned char* pixels = (unsigned char*)malloc(size);

    // Read pixel array from input file
    fread(pixels, sizeof(unsigned char), size, fp_input);

    // Perform image compression
    for (int i = 0; i < size; i += 3) {
        pixels[i] = pixels[i] / 2;    // Red
        pixels[i + 1] = pixels[i + 1] / 2;    // Green
        pixels[i + 2] = pixels[i + 2] / 2;    // Blue
    }

    // Write compressed pixel array to output file
    fwrite(pixels, sizeof(unsigned char), size, fp_output);

    // Free memory
    free(pixels);

    // Close files
    fclose(fp_input);
    fclose(fp_output);

    printf("Image compression successful!\n");
    printf("Enjoy your newly compressed image!\n");

    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel;

int main() {
    // Open the image file
    FILE *image_file = fopen("image.bmp", "rb");
    if (image_file == NULL) {
        printf("Error opening image file!\n");
        return 1;
    }

    // Read the image header
    unsigned char header[54];
    fread(header, sizeof(header), 1, image_file);

    // Get the image dimensions
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Create a buffer to store the image data
    pixel *image_data = malloc(width * height * sizeof(pixel));
    if (image_data == NULL) {
        printf("Error allocating memory for image data!\n");
        return 1;
    }

    // Read the image data
    fread(image_data, sizeof(pixel), width * height, image_file);

    // Close the image file
    fclose(image_file);

    // Open the text file
    FILE *text_file = fopen("text.txt", "rb");
    if (text_file == NULL) {
        printf("Error opening text file!\n");
        return 1;
    }

    // Get the text file size
    fseek(text_file, 0, SEEK_END);
    long text_file_size = ftell(text_file);
    rewind(text_file);

    // Create a buffer to store the text data
    unsigned char *text_data = malloc(text_file_size);
    if (text_data == NULL) {
        printf("Error allocating memory for text data!\n");
        return 1;
    }

    // Read the text data
    fread(text_data, 1, text_file_size, text_file);

    // Close the text file
    fclose(text_file);

    // Hide the text data in the image data
    for (int i = 0; i < text_file_size; i++) {
        // Get the binary representation of the text character
        unsigned char binary_char = text_data[i];

        // Hide each bit of the binary character in the least significant bit of a pixel
        for (int j = 0; j < 8; j++) {
            // Get the least significant bit of the pixel
            unsigned char lsb = image_data[i * 8 + j].blue & 1;

            // Set the least significant bit of the pixel to the bit of the binary character
            image_data[i * 8 + j].blue = (image_data[i * 8 + j].blue & ~1) | (binary_char & 1);

            // Shift the binary character to the right by 1 bit
            binary_char >>= 1;
        }
    }

    // Open the output image file
    FILE *output_image_file = fopen("output.bmp", "wb");
    if (output_image_file == NULL) {
        printf("Error opening output image file!\n");
        return 1;
    }

    // Write the image header to the output image file
    fwrite(header, sizeof(header), 1, output_image_file);

    // Write the image data to the output image file
    fwrite(image_data, sizeof(pixel), width * height, output_image_file);

    // Close the output image file
    fclose(output_image_file);

    // Free the memory allocated for the image data and the text data
    free(image_data);
    free(text_data);

    printf("Text data successfully hidden in image!\n");

    return 0;
}
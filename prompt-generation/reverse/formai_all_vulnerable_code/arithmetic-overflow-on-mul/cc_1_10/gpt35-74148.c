//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: real-life
#include <stdio.h>

// Define the ASCII characters for different intensity values
const char* ascii_chars[] = { " ", ".", ":", "-", "=", "+", "*", "#", "%", "@" };

// Define the size of the ASCII image
#define ASCII_WIDTH 80
#define ASCII_HEIGHT 40

int main() {
    // Load the image file
    FILE* image_file = fopen("image.bmp", "rb");
    if (!image_file) {
        printf("Error: Failed to open the image file.\n");
        return 1;
    }

    // Read the BMP header to get information about the width and height
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, image_file);

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Make sure the image fits within the ASCII dimensions, otherwise scale it down
    float width_ratio = (float)width / ASCII_WIDTH;
    float height_ratio = (float)height / ASCII_HEIGHT;
    float ratio = width_ratio > height_ratio ? width_ratio : height_ratio;

    if (ratio > 1) {
        width /= ratio;
        height /= ratio;
    }

    // Create a buffer for the image data and read it from the file
    unsigned char* image_data = malloc(width * height * 3);
    fread(image_data, sizeof(unsigned char), width * height * 3, image_file);

    // Close the image file
    fclose(image_file);

    // Convert the image data to ASCII art
    int intensity;
    char ascii_char;
    for (int i = 0; i < ASCII_HEIGHT; i++) {
        for (int j = 0; j < ASCII_WIDTH; j++) {
            // Calculate the position in the image data corresponding to this ASCII character
            int x = j * ratio;
            int y = i * ratio;
            int pos = (y * width + x) * 3;

            // Calculate the intensity value of this pixel
            intensity = (int) (0.2126 * image_data[pos] + 0.7152 * image_data[pos + 1] + 0.0722 * image_data[pos + 2]);

            // Map the intensity value to an ASCII character
            ascii_char = ascii_chars[intensity / 25];

            // Print the character
            printf("%c", ascii_char);
        }
        printf("\n");
    }

    // Free the image data buffer
    free(image_data);

    return 0;
}
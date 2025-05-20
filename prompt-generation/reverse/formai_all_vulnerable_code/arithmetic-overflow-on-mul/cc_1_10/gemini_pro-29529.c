//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// ASCII characters used to represent different shades of gray
char *ascii_chars = " .,-~:;=*#%@";

// Function to convert an RGB pixel value to an ASCII character
char get_ascii_char(int r, int g, int b) {
    // Calculate the average intensity of the pixel
    int intensity = (r + g + b) / 3;

    // Map the intensity to an ASCII character
    int index = (int)round((double)intensity / 255 * (strlen(ascii_chars) - 1));
    return ascii_chars[index];
}

// Function to convert an image to ASCII art
void image_to_ascii_art(const char *image_path, const char *output_path) {
    // Open the image file
    FILE *image_file = fopen(image_path, "rb");
    if (image_file == NULL) {
        perror("Error opening image file");
        return;
    }

    // Read the image header
    int width, height;
    fread(&width, sizeof(int), 1, image_file);
    fread(&height, sizeof(int), 1, image_file);

    // Ensure that the image dimensions are within the limits
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        fprintf(stderr, "Error: Image dimensions exceed maximum allowed size (%dx%d)\n", MAX_WIDTH, MAX_HEIGHT);
        fclose(image_file);
        return;
    }

    // Allocate memory for the image data
    unsigned char *image_data = (unsigned char *)malloc(width * height * 3);
    if (image_data == NULL) {
        perror("Error allocating memory for image data");
        fclose(image_file);
        return;
    }

    // Read the image data
    fread(image_data, 1, width * height * 3, image_file);
    fclose(image_file);

    // Open the output file
    FILE *output_file = fopen(output_path, "w");
    if (output_file == NULL) {
        perror("Error opening output file");
        free(image_data);
        return;
    }

    // Convert the image to ASCII art
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Get the RGB values of the pixel
            int r = image_data[(y * width + x) * 3 + 0];
            int g = image_data[(y * width + x) * 3 + 1];
            int b = image_data[(y * width + x) * 3 + 2];

            // Convert the pixel to an ASCII character
            char ascii_char = get_ascii_char(r, g, b);

            // Write the ASCII character to the output file
            fprintf(output_file, "%c", ascii_char);
        }
        fprintf(output_file, "\n");
    }

    fclose(output_file);
    free(image_data);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_image> <output_ascii>\n", argv[0]);
        return 1;
    }

    image_to_ascii_art(argv[1], argv[2]);

    return 0;
}
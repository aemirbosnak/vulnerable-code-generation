//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: authentic
#include <stdio.h>

// Function to convert greyscale value to corresponding ASCII character
char greyscale_to_ascii(int gs_value) {
    char ascii_char;

    if (gs_value >= 230) {
        ascii_char = '@';
    } else if (gs_value >= 200 && gs_value <= 229) {
        ascii_char = '8';
    } else if (gs_value >= 180 && gs_value <= 199) {
        ascii_char = '&';
    } else if (gs_value >= 160 && gs_value <= 179) {
        ascii_char = 'o';
    } else if (gs_value >= 130 && gs_value <= 159) {
        ascii_char = ':';
    } else if (gs_value >= 100 && gs_value <= 129) {
        ascii_char = '*';
    } else if (gs_value >= 70 && gs_value <= 99) {
        ascii_char = '.';
    } else {
        ascii_char = ' ';
    }

    return ascii_char;
}

int main() {
    // Read image from file
    FILE *image_file;
    image_file = fopen("input_image.bmp", "rb");

    if (image_file == NULL) {
        printf("Unable to open image file\n");
        return 0;
    }

    // Read image header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, image_file);

    // Get image width, height and bit depth
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int bit_depth = *(int*)&header[28];

    // Check if image is 24-bit color and has no compression
    if (bit_depth != 24 || *(int*)&header[30] != 0) {
        printf("Invalid image format\n");
        return 0;
    }

    // Create output file for ASCII art
    FILE *output_file;
    output_file = fopen("output_ascii.txt", "w");

    if (output_file == NULL) {
        printf("Unable to create output file\n");
        return 0;
    }

    // Calculate number of bytes per row in image (divisible by 4)
    int bytes_per_row = (width * 3 + 3) & (~3);

    // Allocate memory for image data
    unsigned char *image_data = (unsigned char*)malloc(bytes_per_row * height);

    if (image_data == NULL) {
        printf("Memory allocation failed\n");
        return 0;
    }

    // Read image data
    fread(image_data, sizeof(unsigned char), bytes_per_row * height, image_file);

    // Loop through image rows and columns
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Calculate starting byte of pixel
            int byte_index = bytes_per_row * i + j * 3;

            // Calculate greyscale value of pixel
            int gs_value = 0.2126 * image_data[byte_index + 2] + 0.7152 * image_data[byte_index + 1] + 0.0722 * image_data[byte_index];

            // Convert greyscale value to ASCII character
            char ascii_char = greyscale_to_ascii(gs_value);

            // Write ASCII character to output file
            fputc(ascii_char, output_file);
        }

        // Write newline character to output file
        fputc('\n', output_file);
    }

    // Free memory and close files
    free(image_data);
    fclose(image_file);
    fclose(output_file);

    return 0;
}
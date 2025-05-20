//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define ASCII_CHARS "@%#*+=-:. " // Characters for shading
#define CHAR_COUNT (sizeof(ASCII_CHARS) - 1)

void grayscale(unsigned char r, unsigned char g, unsigned char b, unsigned char* gray) {
    // Calculate grayscale value using luminosity method
    *gray = (unsigned char)(0.299 * r + 0.587 * g + 0.114 * b);
}

char get_ascii_char(unsigned char gray) {
    return ASCII_CHARS[(gray * CHAR_COUNT) / 256]; // Map gray value to ASCII character
}

void image_to_ascii(const char* input_file, const char* output_file) {
    FILE *fp = fopen(input_file, "rb");
    if (!fp) {
        fprintf(stderr, "Error: Cannot open file %s\n", input_file);
        exit(EXIT_FAILURE);
    }

    // Load the header for a simple PPM (P6) file
    char header[3];
    int width, height, max_color_value;

    fscanf(fp, "%s\n%d %d\n%d\n", header, &width, &height, &max_color_value);
    if (strcmp(header, "P6") != 0) {
        fprintf(stderr, "Error: Unsupported image format, use PPM P6.\n");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        fprintf(stderr, "Error: Image dimensions exceed maximum allowed limits.\n");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    // Read the pixel data
    unsigned char pixel_data[MAX_WIDTH * MAX_HEIGHT * 3];
    fread(pixel_data, 3, width * height, fp);
    fclose(fp);

    // Prepare to write the ASCII output
    FILE *out_fp = fopen(output_file, "w");
    if (!out_fp) {
        fprintf(stderr, "Error: Cannot open file %s\n", output_file);
        exit(EXIT_FAILURE);
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Get the RGB values
            int index = (y * width + x) * 3;
            unsigned char r = pixel_data[index];
            unsigned char g = pixel_data[index + 1];
            unsigned char b = pixel_data[index + 2];
            
            // Convert to grayscale
            unsigned char gray;
            grayscale(r, g, b, &gray);
            
            // Get the corresponding ASCII character
            char ascii_char = get_ascii_char(gray);
            fputc(ascii_char, out_fp);
        }
        fputc('\n', out_fp); // New line after each row
    }

    fclose(out_fp);
    printf("Converted image %s to ASCII art and saved to %s\n", input_file, output_file);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_ppm_file> <output_ascii_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    image_to_ascii(argv[1], argv[2]);
    return EXIT_SUCCESS;
}
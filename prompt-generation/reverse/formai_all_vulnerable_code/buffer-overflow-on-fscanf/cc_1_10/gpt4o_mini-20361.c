//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ASCII_CHARS "@%#*+=-:. "  // Characters used for ASCII art
#define MAX_WIDTH 100   // Maximum width for output

typedef struct {
    unsigned char r, g, b;
} RGB;

// Function declarations
void convert_to_ascii(const char *input_file, const char *output_file, int max_width);
RGB get_pixel(FILE *image, int x, int y, int width);
int brightness(RGB pixel);
char map_brightness_to_ascii(int brightness);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_image.ppm> <output_ascii.txt>\n", argv[0]);
        return 1;
    }

    convert_to_ascii(argv[1], argv[2], MAX_WIDTH);
    return 0;
}

void convert_to_ascii(const char *input_file, const char *output_file, int max_width) {
    FILE *image = fopen(input_file, "rb");
    if (!image) {
        perror("Error opening image file");
        exit(EXIT_FAILURE);
    }

    // Read the header of the PPM file
    char format[3];
    int width, height, max_color;
    fscanf(image, "%s %d %d %d%c", format, &width, &height, &max_color, &format[0]);
    
    if (strcmp(format, "P6") != 0 || max_color != 255) {
        fprintf(stderr, "Invalid PPM format. Only P6 with max color 255 is supported.\n");
        fclose(image);
        exit(EXIT_FAILURE);
    }
    
    // Calculate aspect ratio adjustment
    float aspect_ratio = 0.55; // Aspect ratio for ASCII characters
    float scale = (float)max_width / width;
    int new_height = (int)(height * scale * aspect_ratio);
    
    // Create output file
    FILE *output = fopen(output_file, "w");
    if (!output) {
        perror("Error opening output file");
        fclose(image);
        exit(EXIT_FAILURE);
    }

    // Convert to ASCII
    for (int y = 0; y < new_height; y++) {
        for (int x = 0; x < max_width; x++) {
            // Map x and y to the original pixel coordinates
            int orig_x = (int)(x / scale);
            int orig_y = (int)(y / (scale * aspect_ratio));
            
            if (orig_x < width && orig_y < height) {
                RGB pixel = get_pixel(image, orig_x, orig_y, width);
                int brightness_value = brightness(pixel);
                char ascii_char = map_brightness_to_ascii(brightness_value);
                fprintf(output, "%c", ascii_char);
            }
        }
        fprintf(output, "\n");
    }
    
    // Clean up
    fclose(image);
    fclose(output);
}

RGB get_pixel(FILE *image, int x, int y, int width) {
    RGB pixel;
    fseek(image, 3 + (y * width + x) * 3, SEEK_SET);  // 3 bytes for header
    fread(&pixel, sizeof(RGB), 1, image);
    return pixel;
}

int brightness(RGB pixel) {
    // Using luminosity method
    return (int)(0.21 * pixel.r + 0.72 * pixel.g + 0.07 * pixel.b);
}

char map_brightness_to_ascii(int brightness) {
    int index = (int)(brightness / 255.0 * (strlen(ASCII_CHARS) - 1));
    return ASCII_CHARS[index];
}
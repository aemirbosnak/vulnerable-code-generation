//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80        // Width of the ASCII art
#define HEIGHT 24       // Height of the ASCII art
#define ASCII_CHARS " .:-=+*%@#" // Characters for brightness levels

// Structure to hold pixel data
typedef struct {
    unsigned char r, g, b;
} Pixel;

// Function to read a simple PPM image file
Pixel** read_ppm(const char* filename, int* width, int* height) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Could not open PPM file: %s\n", filename);
        return NULL;
    }

    char buffer[16];
    fgets(buffer, sizeof(buffer), file);
    
    // Identify if the file is P6
    if (strcmp(buffer, "P6\n") != 0) {
        fprintf(stderr, "Not a valid PPM file.\n");
        fclose(file);
        return NULL;
    }

    // Read image size
    fscanf(file, "%d %d", width, height);
    fscanf(file, "%*[\n]"); // Consume the newline 

    // Allocate memory for the pixel array
    Pixel** pixels = (Pixel**)malloc(*height * sizeof(Pixel*));
    for (int i = 0; i < *height; i++) {
        pixels[i] = (Pixel*)malloc(*width * sizeof(Pixel));
    }

    // Read pixel data
    fread(pixels[0], sizeof(Pixel), *width * *height, file);
    fclose(file);
    
    return pixels;
}

// Function to convert a pixel to an ASCII character
char pixel_to_ascii(Pixel pixel) {
    int brightness = (pixel.r + pixel.g + pixel.b) / 3;
    int index = brightness * (strlen(ASCII_CHARS) - 1) / 255;
    return ASCII_CHARS[index];
}

// Function to convert image to ASCII art
void convert_to_ascii(Pixel** pixels, int width, int height) {
    for (int y = 0; y < height; y += height / HEIGHT) {
        for (int x = 0; x < width; x += width / WIDTH) {
            char ascii_char = pixel_to_ascii(pixels[y][x]);
            putchar(ascii_char);
        }
        putchar('\n');
    }
}

// Function to free allocated memory
void free_pixels(Pixel** pixels, int height) {
    for (int i = 0; i < height; i++) {
        free(pixels[i]);
    }
    free(pixels);
}

int main(int argc, char* argv[]) {
    // A grand tale in the command line
    printf("Welcome, noble knight! You have invoked the runes to convert images to ASCII art!\n");
    
    if (argc < 2) {
        fprintf(stderr, "Please provide a PPM image file path.\n");
        return 1;
    }

    const char* filename = argv[1];
    int width, height;

    // Read the PPM image
    Pixel** pixels = read_ppm(filename, &width, &height);
    if (!pixels) {
        return 1;
    }

    printf("The magical transformation shall commence...\n");
    
    // Convert the image to ASCII art
    convert_to_ascii(pixels, width, height);
    
    // Free the allocated memory
    free_pixels(pixels, height);
    
    printf("Alas, the transformation is complete! The ASCII art should grace your sight now!\n");
    
    return 0;
}
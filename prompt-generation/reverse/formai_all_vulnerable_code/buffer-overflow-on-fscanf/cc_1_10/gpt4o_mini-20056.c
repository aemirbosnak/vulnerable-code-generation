//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>

#define WIDTH 80
#define HEIGHT 80
#define MAX_CHARS 100

// Mapping grayscale to ASCII characters
const char ascii_chars[] = "@%#*+=-:. ";
const int ascii_length = sizeof(ascii_chars) - 1;

// Function to convert pixel to grayscale
uint8_t rgb_to_grayscale(uint8_t r, uint8_t g, uint8_t b) {
    return (uint8_t)(0.3 * r + 0.59 * g + 0.11 * b);
}

// Function to load PPM image
uint8_t* load_ppm(const char* filename, int* width, int* height) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "ERROR: Cannot open file %s.\n", filename);
        exit(1);
    }

    char header[3];
    fscanf(file, "%s\n", header);
    if (strcmp(header, "P6") != 0) {
        fprintf(stderr, "ERROR: Unsupported file format. Only P6 PPM is supported.\n");
        fclose(file);
        exit(1);
    }

    fscanf(file, "%d %d\n255\n", width, height);
    
    uint8_t* image = (uint8_t*) malloc(3 * (*width) * (*height));
    fread(image, 3, (*width) * (*height), file);
    fclose(file);
    
    return image;
}

// Function to print ASCII art
void print_ascii_art(uint8_t* img, int width, int height) {
    int x, y;
    for (y = 0; y < height; y += height / HEIGHT) {
        for (x = 0; x < width; x += width / WIDTH) {
            int pixel_index = (y * width + x) * 3;
            uint8_t gray = rgb_to_grayscale(img[pixel_index], img[pixel_index + 1], img[pixel_index + 2]);
            char ascii_char = ascii_chars[(gray * ascii_length) / 256];
            putchar(ascii_char);
        }
        putchar('\n');
    }
}

// Function to generate Cyberpunk-themed banner
void print_cyberpunk_banner() {
    printf("  ________    _________  ________  _______       ___       _________      .______       ________  \n");
    printf(" |  |  |  |  |   _____| |  |  |  ||   |   |     |   |     |   _____|     |   _  \\     |   __  |  \n");
    printf(" |  |  |  |  |  |__     |  |  |  ||   |   |     |   |     |  |__        |  |_)  |    |  |__| |  \n");
    printf(" |  |  |  |  |   __|    |  |  |  ||   |   |     |   |     |   __|       |   ___/     |   __  |  \n");
    printf(" |  |  |  |  |  |____   |  `--'  ||   |___|     |   |     |  |____      |  |         |  |  | |  \n");
    printf(" |__|  |__|  |_______|   \\______/ |_______|      |___|     |_______|     | _|         |__|  |__|  \n");
    printf("                                          Welcome to Cyberpunk ASCII Art Converter!           \n");
}

// Main function
int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image.ppm>\n", argv[0]);
        exit(1);
    }

    print_cyberpunk_banner();

    int width, height;
    uint8_t* image = load_ppm(argv[1], &width, &height);
    
    // Ensure the output size fits the console dimensions
    if (width > 400 || height > 400) {
        fprintf(stderr, "ERROR: Image size exceeds the console dimensions.\n");
        free(image);
        exit(1);
    }

    print_ascii_art(image, width, height);
    free(image);

    return 0;
}
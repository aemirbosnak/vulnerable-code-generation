//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 800
#define MAX_HEIGHT 800

void printAsciiPixel(int r, int g, int b) {
    int brightness = (r + g + b) / 3; // Simple brightness calculation
    char ascii_chars[] = "@%#*+=-:. "; // Decreasing brightness representation
    int index = brightness * (sizeof(ascii_chars) - 1) / 255; // Match brightness to ASCII index

    putchar(ascii_chars[index]);  // Print corresponding ASCII character
}

void convertImageToAscii(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Cannot open input file");
        return;
    }

    char header[3];
    int width, height;
    fscanf(file, "%2s", header);
    if (header[0] != 'P' || header[1] != '6') {
        fprintf(stderr, "Invalid PPM file format. Please use P6 PPM format.\n");
        fclose(file);
        return;
    }
    
    fscanf(file, "%d %d", &width, &height);
    int maxColorValue;
    fscanf(file, "%d", &maxColorValue);
    fgetc(file); // Consume the newline character after maxColorValue

    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        fprintf(stderr, "Image dimensions exceed maximum allowed (%d x %d)\n", MAX_WIDTH, MAX_HEIGHT);
        fclose(file);
        return;
    }

    unsigned char pixel[3]; // RGB pixel
    // Loop through each pixel and print ASCII representation
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            fread(pixel, sizeof(unsigned char), 3, file); // Read RGB values
            printAsciiPixel(pixel[0], pixel[1], pixel[2]); // Print corresponding ASCII
        }
        putchar('\n'); // New line after each row
    }

    fclose(file);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path_to_ppm_image>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("Awesome ASCII Art Generator! 🎨 Here's your art:\n\n");
    convertImageToAscii(argv[1]);
    printf("\nAmazingly done! 🖼️ Enjoy your ASCII art! \n");

    return 0;
}
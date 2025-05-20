//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert image to ASCII art
void image_to_ascii(char* filename, int width, int height) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    // Read header information
    unsigned char header[54];
    fread(header, 1, 54, fp);

    // Check if it's a valid BMP file
    if (header[0]!= 'B' || header[1]!= 'M') {
        printf("Invalid BMP file\n");
        fclose(fp);
        exit(1);
    }

    // Read image data
    unsigned char* data = malloc(width * height);
    fread(data, 1, width * height, fp);
    fclose(fp);

    // Convert image data to ASCII art
    char ascii[width * height];
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = y * width + x;
            int gray = (data[index] + data[index + 1] + data[index + 2]) / 3;
            ascii[index] = '@' + (gray % 6);
        }
    }

    // Print ASCII art
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%c", ascii[y * width + x]);
        }
        printf("\n");
    }
}

int main(int argc, char** argv) {
    if (argc!= 4) {
        printf("Usage: %s <filename> <width> <height>\n", argv[0]);
        return 1;
    }

    int width = atoi(argv[2]);
    int height = atoi(argv[3]);

    image_to_ascii(argv[1], width, height);

    return 0;
}
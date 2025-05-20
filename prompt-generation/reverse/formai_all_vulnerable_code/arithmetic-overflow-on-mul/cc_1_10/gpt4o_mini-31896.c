//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

// Function to calculate grayscale value from RGB
unsigned char rgbToGray(unsigned char r, unsigned char g, unsigned char b) {
    return (unsigned char)(0.299 * r + 0.587 * g + 0.114 * b);
}

// Function to convert a pixel's gray value to corresponding ASCII character
char grayToAscii(unsigned char grayValue) {
    if (grayValue < 26) return '@';  // Dark
    if (grayValue < 52) return '#';
    if (grayValue < 78) return '*';
    if (grayValue < 104) return '+';
    if (grayValue < 130) return '-';
    if (grayValue < 156) return ':';
    if (grayValue < 182) return '.';
    return ' ';  // Light
}

// Structure to hold RGB values
typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

// Function to load a BMP image (headers and basic reading, not a full BMP parser)
Pixel* loadBMP(const char* filename, int* width, int* height) {
    // Opening the file in binary mode
    FILE* f = fopen(filename, "rb");
    if (!f) {
        perror("Error opening file");
        return NULL;
    }

    // Read the BMP header
    unsigned char bmpHeader[54];
    fread(bmpHeader, sizeof(unsigned char), 54, f);

    // Extract width and height from header
    *width = *(int*)&bmpHeader[18];
    *height = *(int*)&bmpHeader[22];

    // Allocate memory for the pixel data
    int size = 3 * (*width) * (*height); // For RGB, 3 bytes per pixel
    Pixel* imageData = (Pixel*)malloc(size);

    // Move to the start of the pixel array
    fseek(f, *(int*)&bmpHeader[10], SEEK_SET);
    fread(imageData, sizeof(Pixel), (*width) * (*height), f);
    fclose(f);

    // Return the image data
    return imageData;
}

// Function to convert BMP image to ASCII art
void convertImageToASCII(Pixel* imageData, int width, int height) {
    FILE* outputFile = fopen("output.txt", "w");
    if (!outputFile) {
        perror("Error opening output file");
        return;
    }

    // Create ASCII art representation
    for (int i = height - 1; i >= 0; i--) {
        for (int j = 0; j < width; j++) {
            Pixel pixel = imageData[i * width + j];
            unsigned char grayValue = rgbToGray(pixel.r, pixel.g, pixel.b);
            char asciiChar = grayToAscii(grayValue);
            fprintf(outputFile, "%c", asciiChar);
        }
        fprintf(outputFile, "\n");
    }

    fclose(outputFile);
}

// Main function to execute the program
int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <image-file.bmp>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int width, height;
    Pixel* imageData = loadBMP(argv[1], &width, &height);
    if (imageData == NULL) {
        return EXIT_FAILURE;
    }

    convertImageToASCII(imageData, width, height);
    printf("ASCII art has been created in output.txt\n");

    free(imageData);
    return EXIT_SUCCESS;
}
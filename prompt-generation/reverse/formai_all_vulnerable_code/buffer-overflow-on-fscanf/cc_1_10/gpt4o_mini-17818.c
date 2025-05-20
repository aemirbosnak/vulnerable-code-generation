//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

// Function declarations
void readPGM(const char *filename, unsigned char image[MAX_HEIGHT][MAX_WIDTH], int *width, int *height);
void printASCIIArt(unsigned char image[MAX_HEIGHT][MAX_WIDTH], int width, int height);
char pixelToChar(unsigned char pixelValue);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pgm_filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    unsigned char image[MAX_HEIGHT][MAX_WIDTH];
    int width, height;

    readPGM(argv[1], image, &width, &height);
    printASCIIArt(image, width, height);

    return EXIT_SUCCESS;
}

void readPGM(const char *filename, unsigned char image[MAX_HEIGHT][MAX_WIDTH], int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    char format[3];
    fscanf(file, "%s", format);
    if (strcmp(format, "P5") != 0) {
        fprintf(stderr, "Unsupported PGM format\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%d %d", width, height);
    int maxGrayValue;
    fscanf(file, "%d", &maxGrayValue);
    fgetc(file); // consume the newline character

    for (int y = 0; y < *height; ++y) {
        fread(image[y], sizeof(unsigned char), *width, file);
    }

    fclose(file);
}

void printASCIIArt(unsigned char image[MAX_HEIGHT][MAX_WIDTH], int width, int height) {
    const char *asciiChars = "@%#*+=-:. ";
    int numChars = strlen(asciiChars);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            char ch = pixelToChar(image[y][x]);
            putchar(ch);
        }
        putchar('\n');
    }
}

char pixelToChar(unsigned char pixelValue) {
    const char *asciiChars = "@%#*+=-:. ";
    int numChars = strlen(asciiChars);
    int index = (pixelValue * (numChars - 1)) / 255; // Scale pixel value to index
    return asciiChars[index];
}
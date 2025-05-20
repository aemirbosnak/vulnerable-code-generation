//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_PIXELS 255
#define ASCII_CHARS "@#S%?*+-. " // List of characters from darkest to lightest

void printAsciiArt(char *fileName);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image.pgm>\n", argv[0]);
        exit(1);
    }

    printAsciiArt(argv[1]);
    
    return 0;
}

void printAsciiArt(char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (!file) {
        perror("Failed to open the file");
        return;
    }

    // Read the PGM header
    char version[3];
    int width, height, maxVal;
    fscanf(file, "%s", version);

    if (strcmp(version, "P2") != 0) {
        fprintf(stderr, "Oops! This isn't a PGM P2 file. It seems like a prank!\n");
        fclose(file);
        return;
    }

    fscanf(file, "%d %d", &width, &height);
    fscanf(file, "%d", &maxVal);

    // Validate the maxVal (not more than 255 because we're into ASCII)
    if (maxVal != MAX_PIXELS) {
        fprintf(stderr, "Oh dear! This image is too fancy for this program (%d). Keep it simple!\n", maxVal);
        fclose(file);
        return;
    }

    printf("Welcome to the ASCII Art Generator!\n");
    printf("Processing image: %s\n", fileName);
    printf("Dimensions: %dx%d\nHere's the art:\n\n", width, height);

    // Convert to ASCII art
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int pixel;
            fscanf(file, "%d", &pixel);

            // Map pixel brightness to ASCII character
            int index = (pixel * (sizeof(ASCII_CHARS) - 1)) / MAX_PIXELS;
            putchar(ASCII_CHARS[index]);
        }
        putchar('\n'); // Newline after each row
    }

    fclose(file);
    printf("\nArt gallery entrance is free! Enjoy your art!\n");
}
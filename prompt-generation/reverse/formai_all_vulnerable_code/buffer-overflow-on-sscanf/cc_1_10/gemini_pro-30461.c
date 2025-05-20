//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Define the maximum width and height of the image
#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// Define the character map for the ASCII art
char *characterMap[] = {
    "  ", ".,", ";;", "+", "XX", "%%", "@@", "##", "$$", "BB",
    "WW", "MM", "QQ", "88", "OO", "**", "AA", "LL", "ZZ", "CC",
    "UU", "JJ", "II", "TT", "FF", "RR", "EE", "DD", "SS", "VV",
    "GG", "NN", "PP", "HH", "KK", "YY", "XX", "bb", "ww", "mm",
    "qq", "88", "oo", "**", "aa", "ll", "zz", "cc", "uu", "jj",
    "ii", "tt", "ff", "rr", "ee", "dd", "ss", "vv", "gg", "nn",
    "pp", "hh", "kk", "yy", "xx", "bb", "ww", "mm", "qq", "88",
    "oo", "**", "aa", "ll", "zz", "cc", "uu", "jj", "ii", "tt",
    "ff", "rr", "ee", "dd", "ss", "vv", "gg", "nn", "pp", "hh",
    "kk", "yy", "xx", "bb", "ww", "mm", "qq", "88", "oo", "**"
};

// Convert an image to ASCII art
char *imageToAscii(char *filename) {
    // Open the image file
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        return NULL;
    }

    // Read the image header
    int width, height;
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);

    // Check if the image is too large
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        fclose(fp);
        return NULL;
    }

    // Allocate memory for the image data
    unsigned char *imageData = malloc(width * height);
    if (imageData == NULL) {
        fclose(fp);
        return NULL;
    }

    // Read the image data
    fread(imageData, sizeof(unsigned char), width * height, fp);

    // Close the image file
    fclose(fp);

    // Convert the image data to ASCII art
    char *asciiArt = malloc(width * height * 3);
    if (asciiArt == NULL) {
        free(imageData);
        return NULL;
    }

    int index = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int brightness = imageData[y * width + x];
            int characterIndex = brightness / 10;
            asciiArt[index++] = characterMap[characterIndex][0];
            asciiArt[index++] = characterMap[characterIndex][1];
            asciiArt[index++] = ' ';
        }
    }

    // Free the image data
    free(imageData);

    // Return the ASCII art
    return asciiArt;
}

// Save the ASCII art to a file
void saveAsciiArt(char *asciiArt, int width, int height, char *filename) {
    // Open the ASCII art file
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        return;
    }

    // Write the ASCII art to the file
    fprintf(fp, "%d %d\n", width, height);
    fwrite(asciiArt, sizeof(char), width * height * 3, fp);

    // Close the ASCII art file
    fclose(fp);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user specified an image file
    if (argc < 2) {
        printf("Usage: %s <image file>\n", argv[0]);
        return 1;
    }

    // Convert the image to ASCII art
    char *asciiArt = imageToAscii(argv[1]);
    if (asciiArt == NULL) {
        printf("Error converting image to ASCII art.\n");
        return 1;
    }

    // Get the width and height of the image
    int width, height;
    sscanf(asciiArt, "%d %d", &width, &height);

    // Save the ASCII art to a file
    saveAsciiArt(asciiArt, width, height, "ascii_art.txt");

    // Free the ASCII art
    free(asciiArt);

    return 0;
}
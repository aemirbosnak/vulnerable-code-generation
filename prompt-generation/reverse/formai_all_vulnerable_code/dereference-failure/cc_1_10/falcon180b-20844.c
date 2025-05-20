//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert image to ASCII art
void image_to_ascii(char *filename, int width, int height) {
    FILE *fp;
    char ch;
    int i, j, k, l, count = 0;

    // Open the image file
    fp = fopen(filename, "rb");

    // Check if file opened successfully
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    // Read the image data
    fseek(fp, 54, SEEK_SET); // Skip header information
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fread(&ch, 1, 1, fp); // Read one byte at a time

            // Convert pixel value to ASCII character
            if (ch == 0) {
                printf("  ");
            } else if (ch < 64) {
                printf(".");
            } else if (ch < 128) {
                printf("-");
            } else if (ch < 192) {
                printf("=");
            } else if (ch < 224) {
                printf("+");
            } else if (ch < 240) {
                printf("*");
            } else if (ch < 248) {
                printf(":");
            } else if (ch < 252) {
                printf(";");
            } else if (ch < 254) {
                printf(",");
            } else if (ch < 256) {
                printf(".");
            }
        }
        printf("\n");
    }

    // Close the image file
    fclose(fp);
}

int main(int argc, char *argv[]) {
    // Check if correct number of arguments are provided
    if (argc!= 4) {
        printf("Usage: %s <filename> <width> <height>\n", argv[0]);
        return 1;
    }

    // Convert image to ASCII art
    image_to_ascii(argv[1], atoi(argv[2]), atoi(argv[3]));

    return 0;
}
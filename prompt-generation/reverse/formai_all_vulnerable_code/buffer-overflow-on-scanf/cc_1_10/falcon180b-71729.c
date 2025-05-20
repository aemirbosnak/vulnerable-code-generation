//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// Function to convert image to ASCII art
void image_to_ascii(char *filename, int width, int height) {
    FILE *file;
    int x, y, c;
    char pixel;
    char ascii_art[MAX_WIDTH * MAX_HEIGHT];
    int ascii_art_index = 0;

    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read in image data
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            fread(&pixel, 1, 1, file);
            if (feof(file)) {
                printf("Error reading file.\n");
                exit(1);
            }
        }
    }

    // Convert image to ASCII art
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            c = (int) pixel * (MAX_WIDTH - 1) / 255;
            ascii_art[ascii_art_index++] = (char) ('@' + c);
        }
        ascii_art[ascii_art_index++] = '\n';
    }

    // Print ASCII art
    printf("%s", ascii_art);

    fclose(file);
}

// Function to prompt user for image filename, width, and height
void get_image_info(char *filename, int *width, int *height) {
    printf("Enter image filename: ");
    scanf("%s", filename);

    printf("Enter image width: ");
    scanf("%d", width);

    printf("Enter image height: ");
    scanf("%d", height);
}

int main() {
    char filename[100];
    int width, height;

    // Prompt user for image filename, width, and height
    get_image_info(filename, &width, &height);

    // Convert image to ASCII art
    image_to_ascii(filename, width, height);

    return 0;
}
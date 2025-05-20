//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 50
#define MAX_HEIGHT 50

// Function to convert RGB values to grayscale intensity
int rgb_to_gray(int r, int g, int b){
    return 0.299*r + 0.587*g + 0.114*b;
}

// Function to map grayscale intensity to ASCII character
char gray_to_ascii(int gray){
    char ascii_char;

    if (gray >= 230) {
        ascii_char = ' ';
    }
    else if (gray >= 200) {
        ascii_char = '.';
    }
    else if (gray >= 180) {
        ascii_char = ':';
    }
    else if (gray >= 160) {
        ascii_char = '*';
    }
    else if (gray >= 130) {
        ascii_char = 'o';
    }
    else if (gray >= 100) {
        ascii_char = '&';
    }
    else if (gray >= 70) {
        ascii_char = '8';
    }
    else if (gray >= 50) {
        ascii_char = '#';
    }
    else {
        ascii_char = '@';
    }

    return ascii_char;
}

int main(int argc, char *argv[]) {
    char image_path[100];

    // Get the path of the input image from the command-line arguments
    if (argc != 2) {
        printf("Usage: %s <path to image file>\n", argv[0]);
        return 1;
    }
    strcpy(image_path, argv[1]);

    FILE *image_file;
    image_file = fopen(image_path, "rb");

    // Get the width and height of the image
    char buffer[256];
    fgets(buffer, sizeof(buffer), image_file);
    int width, height;
    sscanf(buffer, "%d %d", &width, &height);

    // Make sure the image isn't too large
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Image too large. Maximum size is %d x %d.\n", MAX_WIDTH, MAX_HEIGHT);
        return 1;
    }

    // Read RGB values from the image and convert to ASCII characters
    char ascii_image[MAX_HEIGHT][MAX_WIDTH+1];
    int i, j;
    for (i=0; i<height; i++) {
        for (j=0; j<width; j++) {
            int r, g, b;
            fread(&r, sizeof(char), 1, image_file);
            fread(&g, sizeof(char), 1, image_file);
            fread(&b, sizeof(char), 1, image_file);

            int gray = rgb_to_gray(r, g, b);
            char ascii_char = gray_to_ascii(gray);

            ascii_image[i][j] = ascii_char;
        }
        ascii_image[i][width] = '\0'; // Add null terminator to end of each row
    }

    fclose(image_file);

    // Print the ASCII art to the console
    for (i=0; i<height; i++) {
        printf("%s\n", ascii_image[i]);
    }

    return 0;
}
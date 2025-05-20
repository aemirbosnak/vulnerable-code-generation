//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 25

int main(void) {
    // Open the image file
    FILE *image = fopen("image.jpg", "rb");
    if (image == NULL) {
        printf("Error opening image file.\n");
        return 1;
    }

    // Read the image data
    unsigned char *data = malloc(WIDTH * HEIGHT * 3);
    if (data == NULL) {
        printf("Error allocating memory for image data.\n");
        return 1;
    }
    fread(data, 1, WIDTH * HEIGHT * 3, image);

    // Convert the image data to ASCII art
    char *ascii = malloc(WIDTH * HEIGHT * sizeof(char));
    if (ascii == NULL) {
        printf("Error allocating memory for ASCII art.\n");
        return 1;
    }
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        // Calculate the average of the RGB values
        int r = data[i * 3 + 0];
        int g = data[i * 3 + 1];
        int b = data[i * 3 + 2];
        int avg = (r + g + b) / 3;

        // Map the average to an ASCII character
        char c;
        if (avg < 32) {
            c = ' ';
        } else if (avg < 64) {
            c = '.';
        } else if (avg < 96) {
            c = ',';
        } else if (avg < 128) {
            c = ':';
        } else if (avg < 160) {
            c = ';';
        } else if (avg < 192) {
            c = '=';
        } else if (avg < 224) {
            c = '+';
        } else {
            c = '#';
        }

        // Store the ASCII character in the output array
        ascii[i] = c;
    }

    // Print the ASCII art to the console
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        printf("%c", ascii[i]);
        if ((i + 1) % WIDTH == 0) {
            printf("\n");
        }
    }

    // Free the allocated memory
    free(data);
    free(ascii);

    // Close the image file
    fclose(image);

    return 0;
}
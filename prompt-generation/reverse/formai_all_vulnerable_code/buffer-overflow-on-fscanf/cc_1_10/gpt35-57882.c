//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 60

// This function takes a grayscale value and returns the corresponding ASCII character
char intensityToChar(int intensity) {
    if (intensity >= 230) {
        return ' ';
    } else if (intensity >= 200) {
        return '.';
    } else if (intensity >= 180) {
        return '*';
    } else if (intensity >= 160) {
        return ':';
    } else if (intensity >= 130) {
        return 'o';
    } else if (intensity >= 100) {
        return '&';
    } else if (intensity >= 70) {
        return '8';
    } else if (intensity >= 50) {
        return '#';
    } else {
        return '@';
    }
}

int main(void) {
    // Open the image file
    FILE *fp = fopen("image.pgm", "rb");

    // Check if file opening is successful
    if (!fp) {
        printf("Error: could not open file.\n");
        return 1;
    }

    // Parse the header information of the image
    char format[3];
    int width, height, maxVal;
    fscanf(fp, "%s\n%d %d\n%d\n", format, &width, &height, &maxVal);

    // Check if the image format is correct
    if (strcmp(format, "P5")) {
        printf("Error: invalid image format.\n");
        fclose(fp);
        return 1;
    }

    // Check if the image dimensions are valid
    if (width > WIDTH || height > HEIGHT) {
        printf("Error: image is too large.\n");
        fclose(fp);
        return 1;
    }

    // Allocate memory for the image
    unsigned char *image = calloc(width * height, sizeof(unsigned char));

    // Read the image data into a buffer
    fread(image, sizeof(unsigned char), width * height, fp);

    // Close the image file
    fclose(fp);

    // Print the ASCII art version of the image to the console
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = y * width + x;
            int intensity = image[index];
            printf("%c", intensityToChar(intensity));
        }
        printf("\n");
    }

    // Free the memory used by the image buffer
    free(image);

    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25

char *asciiMap = " .,-~:;=!*#$@";

void convertToAscii(char *filename) {
    // Open the image file
    FILE *image = fopen(filename, "rb");
    if (image == NULL) {
        perror("Error opening image file");
        return;
    }

    // Get the image dimensions
    int width, height;
    fscanf(image, "%d %d", &width, &height);

    // Create a buffer to store the image data
    unsigned char *imageData = malloc(width * height * 3);
    if (imageData == NULL) {
        perror("Error allocating memory for image data");
        fclose(image);
        return;
    }

    // Read the image data into the buffer
    fread(imageData, width * height * 3, 1, image);

    // Convert the image data to ASCII characters
    char *asciiImage = malloc(WIDTH * HEIGHT);
    if (asciiImage == NULL) {
        perror("Error allocating memory for ASCII image");
        fclose(image);
        free(imageData);
        return;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Calculate the average RGB value for the pixel
            float r = imageData[(y * width + x) * 3 + 0];
            float g = imageData[(y * width + x) * 3 + 1];
            float b = imageData[(y * width + x) * 3 + 2];
            float avg = (r + g + b) / 3.0;

            // Map the average RGB value to an ASCII character
            int charIndex = (int)(avg / 255.0 * strlen(asciiMap));
            asciiImage[y * WIDTH + x] = asciiMap[charIndex];
        }
    }

    // Print the ASCII image to the console
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", asciiImage[y * WIDTH + x]);
        }
        printf("\n");
    }

    // Free the memory allocated for the image data and the ASCII image
    free(imageData);
    free(asciiImage);

    // Close the image file
    fclose(image);
}

int main() {
    // Convert the image to ASCII
    convertToAscii("image.ppm");

    return 0;
}
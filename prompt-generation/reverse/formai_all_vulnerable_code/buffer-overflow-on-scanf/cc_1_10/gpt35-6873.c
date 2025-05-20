//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

// Function to convert RGB value to grayscale
int rgbToGrayscale(int r, int g, int b) {
    return (0.2989 * r) + (0.5870 * g) + (0.1140 * b);
}

// Function to convert grayscale value to ASCII character
char asciiConverter(int shade) {
    char ascii[] = "@#8&WM*oahkbdpwmZO0QYwxyznbdpqEG$COFJk?|~;:,`^'./<>i!lI;:'\",^`.";
    int increments = sizeof(ascii) / sizeof(ascii[0]);
    int index = ((shade * (increments - 1)) / 255);
    return ascii[index];
}

int main() {
    FILE *imageFile;
    char filename[100];

    // Ask user for image filename
    printf("Enter the filename of the image you want to convert to ASCII art: ");
    scanf("%s", filename);

    // Open the image file in binary read mode
    imageFile = fopen(filename, "rb");

    // Read the header information of the image
    int width = 0, height = 0;
    fseek(imageFile, 18, SEEK_SET);
    fread(&width, sizeof(int), 1, imageFile);
    fread(&height, sizeof(int), 1, imageFile);

    // Print the dimensions of the image
    printf("Image dimensions: %dx%d px\n", width, height);

    // Allocate space for the pixel data of the image
    unsigned char *pixelData = (unsigned char*) malloc (3 * width * height);

    // Read the pixel data of the image
    fseek(imageFile, 54, SEEK_SET);
    fread(pixelData, sizeof(unsigned char), 3 * width * height, imageFile);

    // Close the image file
    fclose(imageFile);

    // Convert the pixel data to ASCII characters and print the result to the console
    for (int y = 0; y < height; y += 2) {
        for (int x = 0; x < width; x++) {
            int r = pixelData[(y * width + x) * 3];
            int g = pixelData[(y * width + x) * 3 + 1];
            int b = pixelData[(y * width + x) * 3 + 2];

            int grayscale = rgbToGrayscale(r, g, b);
            char ascii = asciiConverter(grayscale);
            putchar(ascii);
        }
        putchar('\n');
    }

    // Free the memory allocation for pixel data
    free(pixelData);

    return 0;
}
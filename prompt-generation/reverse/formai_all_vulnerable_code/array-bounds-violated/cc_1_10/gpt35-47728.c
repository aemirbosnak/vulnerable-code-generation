//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: futuristic
#include <stdio.h>

// Function to convert RGB color to grayscale
int rgb_to_grayscale(int r, int g, int b) {
    return (0.2989 * r + 0.5870 * g + 0.1140 * b); // NTSC formula
}

// Function to convert grayscale value to ASCII character
char grayscale_to_ascii(int grayscale) {
    // ASCII characters from darkest to lightest
    char ascii[] = {'@', '#', 'O', 'o', '+', '~', '-', ':', '.', ' '};
    int num_chars = sizeof(ascii) / sizeof(char);
    int range = 255 / (num_chars - 1); // Divide 255 by number of characters
    int index = grayscale / range; // Find index of corresponding ASCII character
    return ascii[index];
}

// Main function
int main() {
    // Open the image file
    FILE *image = fopen("futuristic_image.bmp", "rb");
    if (image == NULL) {
        printf("Unable to open image file.\n");
        return 1;
    }

    // Read the header of the BMP file
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, image);

    // Get image width, height, and data size from header
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int data_size = *(int*)&header[34];

    // Calculate padding of each row of pixel data to ensure 4-byte alignment
    int padding = 0;
    while ((width * 3 + padding) % 4 != 0) {
        padding++;
    }

    // Allocate memory for pixel data
    unsigned char *data = (unsigned char*) malloc(data_size * sizeof(unsigned char));

    // Read the pixel data
    fread(data, sizeof(unsigned char), data_size, image);

    // Close the image file
    fclose(image);

    // Convert RGB pixel data to grayscale and ASCII art
    char asciiart[height][width];
    int i, j, k, grayscale;
    for (i = height - 1; i >= 0; i--) {
        for (j = 0; j < width; j++) {
            k = (i * (width * 3 + padding) + j * 3);
            grayscale = rgb_to_grayscale(data[k+2], data[k+1], data[k]);
            asciiart[i][j] = grayscale_to_ascii(grayscale);
        }
    }

    // Print the ASCII art
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%c", asciiart[i][j]);
        }
        printf("\n");
    }

    // Free memory
    free(data);

    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 640
#define HEIGHT 480

int main(int argc, char *argv[])
{
    // Check usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the image file
    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL)
    {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Read the image header
    unsigned char header[14];
    if (fread(header, 1, 14, fp) != 14)
    {
        perror("fread");
        fclose(fp);
        return EXIT_FAILURE;
    }

    // Check if the image is a BMP file
    if (header[0] != 'B' || header[1] != 'M')
    {
        fprintf(stderr, "Error: not a BMP file\n");
        fclose(fp);
        return EXIT_FAILURE;
    }

    // Get the image width and height
    unsigned int width = *(unsigned int *)(header + 18);
    unsigned int height = *(unsigned int *)(header + 22);

    // Check if the image is the correct size
    if (width != WIDTH || height != HEIGHT)
    {
        fprintf(stderr, "Error: image is not the correct size\n");
        fclose(fp);
        return EXIT_FAILURE;
    }

    // Read the image data
    unsigned char data[WIDTH * HEIGHT * 3];
    if (fread(data, 1, WIDTH * HEIGHT * 3, fp) != WIDTH * HEIGHT * 3)
    {
        perror("fread");
        fclose(fp);
        return EXIT_FAILURE;
    }

    // Close the image file
    fclose(fp);

    // Convert the image data to ASCII art
    char art[WIDTH * HEIGHT];
    for (unsigned int i = 0; i < WIDTH * HEIGHT; i++)
    {
        // Get the RGB values for the pixel
        unsigned char r = data[i * 3];
        unsigned char g = data[i * 3 + 1];
        unsigned char b = data[i * 3 + 2];

        // Convert the RGB values to a grayscale value
        unsigned char gray = (r + g + b) / 3;

        // Convert the grayscale value to an ASCII character
        art[i] = " .,-~:;=!*#$@"[gray / 26];
    }

    // Print the ASCII art to the console
    for (unsigned int i = 0; i < HEIGHT; i++)
    {
        for (unsigned int j = 0; j < WIDTH; j++)
        {
            putchar(art[i * WIDTH + j]);
        }
        putchar('\n');
    }

    return EXIT_SUCCESS;
}
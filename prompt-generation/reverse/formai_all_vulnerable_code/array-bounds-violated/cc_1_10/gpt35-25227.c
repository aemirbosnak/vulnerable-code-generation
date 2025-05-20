//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

const char *ASCII_CHARS = " .,:;i1tfLCG08@";

char image[MAX_HEIGHT][MAX_WIDTH + 1];
char ascii[MAX_HEIGHT][MAX_WIDTH + 1];

/**
 * Loads the image from the specified file into a character array.
 * Returns 1 if successful, or 0 if an error occurred.
 */
int load_image(const char *filename)
{
    FILE *file = fopen(filename, "r");

    // Check if file opened successfully
    if (!file)
    {
        printf("Error: Unable to open file.");
        return 0;
    }

    // Read image line by line
    int height = 0;
    while (fgets(image[height], MAX_WIDTH, file))
    {
        // Remove trailing newline character
        image[height][strlen(image[height]) - 1] = '\0';

        // Check if image dimensions exceed maximum
        if (strlen(image[height]) > MAX_WIDTH)
        {
            printf("Error: Image width exceeds maximum allowed.");
            return 0;
        }
        if (++height > MAX_HEIGHT)
        {
            printf("Error: Image height exceeds maximum allowed.");
            return 0;
        }
    }

    fclose(file);
    return 1;
}

/**
 * Converts the image to ASCII art and stores it in a separate character array.
 */
void convert_to_ascii(int width, int height)
{
    int char_count = strlen(ASCII_CHARS);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int brightness = (int) ((int) image[i][j] * char_count) / 256;
            ascii[i][j] = ASCII_CHARS[brightness];
        }
        ascii[i][width] = '\0';
    }
}

/**
 * Prints the ASCII art to the console.
 */
void print_ascii(int width, int height)
{
    for (int i = 0; i < height; i++)
    {
        printf("%s\n", ascii[i]);
    }
}

int main(int argc, char *argv[])
{
    // Check if filename specified
    if (argc < 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 0;
    }

    // Load image from file
    if (!load_image(argv[1]))
    {
        return 1;
    }

    int width = strlen(image[0]);
    int height = strlen(image);

    // Convert image to ASCII art
    convert_to_ascii(width, height);

    // Print ASCII art to console
    print_ascii(width, height);

    return 0;
}
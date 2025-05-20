//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    This program takes in an image file as input and converts it to ASCII art.
    The converted ASCII art can then be printed to the console or saved to a file.
    The conversion process involves converting each pixel in the image to a corresponding
    ASCII character based on its brightness level.
*/

// Function declarations
char* read_image(char* filename, int* width, int* height);
char brightness_to_char(int brightness);

int main()
{
    // Declare variables
    char* image_data;
    int width, height;

    // Read in image file
    image_data = read_image("sherlock_holmes.jpg", &width, &height);

    // Convert image to ASCII art
    char ascii_art[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Compute brightness of pixel
            int index = i * width + j;
            int r = image_data[index * 3];
            int g = image_data[index * 3 + 1];
            int b = image_data[index * 3 + 2];
            int brightness = (r + g + b) / 3;

            // Store ASCII character in array
            ascii_art[i][j] = brightness_to_char(brightness);
        }
    }

    // Output ASCII art to console
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            putchar(ascii_art[i][j]);
        }
        putchar('\n');
    }

    // Save ASCII art to file
    FILE* file = fopen("sherlock_ascii_art.txt", "w");
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            fputc(ascii_art[i][j], file);
        }
        fputc('\n', file);
    }
    fclose(file);

    // Free memory
    free(image_data);

    return 0;
}

/*
    Reads in an image file and returns its pixel data as a char array.
    Sets the width and height parameters to the width and height of the image, respectively.
*/
char* read_image(char* filename, int* width, int* height)
{
    FILE* file = fopen(filename, "rb");
    if (file == NULL)
    {
        printf("Error: Could not open file: %s\n", filename);
        exit(1);
    }

    // Read header data
    char header[54];
    fread(header, sizeof(char), 54, file);
    *width = *(int*)&header[18];
    *height = *(int*)&header[22];

    // Read pixel data
    int pixel_count = *width * *height;
    char* data = (char*)malloc(pixel_count * 3 * sizeof(char));
    fread(data, sizeof(char), pixel_count * 3, file);
    fclose(file);

    return data;
}

/*
    Converts a brightness value (0-255) to the corresponding ASCII character.
*/
char brightness_to_char(int brightness)
{
    char characters[] = "@OQE0JI()$7>\\/-:,. ";
    int num_chars = strlen(characters);

    // Map brightness to character
    int index = (int)(((float)brightness / 255.0) * (num_chars - 1));
    return characters[index];
}
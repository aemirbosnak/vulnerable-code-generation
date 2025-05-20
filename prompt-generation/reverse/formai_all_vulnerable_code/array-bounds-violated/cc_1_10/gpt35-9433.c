//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: genious
/* This C program converts an image to ASCII art. It takes image file name as input and saves the ASCII art in a text file. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIXEL_VALUE 255
#define ASCII_DIM 70

/* Function to convert pixel values to corresponding ASCII characters */
char ConvertPixelToASCII(unsigned char pixel_value)
{
    char ascii_char;
    int ascii_index;

    /* ASCII characters arranged in decreasing order of darkness */
    const char ASCII_CHARS[] = {' ', '.', '\'', '`', '^', '\"', ',', ':', ';', 'I', 'l', '!', 'i', '>', '<', '~', '+', '_', '-', '?', ']', '[', '}', '{', '1', ')', '(', '|', '\\', '/', 't', 'f', 'j', 'r', 'x', 'n', 'u', 'v', 'c', 'z', 'X', 'Y', 'U', 'J', 'C', 'L', 'Q', '0', 'O', 'Z', 'm', 'w', 'q', 'p', 'd', 'b', 'k', 'h', 'a', 'o', '*', '#', 'M', 'W', '&', '8', '%', 'B', '@'};

    /* Find the index of the corresponding ASCII character in the array */
    ascii_index = (int) ((pixel_value * 64) / (MAX_PIXEL_VALUE + 1)) ;

    /* Handle special case when the pixel value is max */
    if (ascii_index == 64) ascii_index--;

    /* Get the corresponding ASCII character */
    ascii_char = ASCII_CHARS[ascii_index];

    return ascii_char;
}

int main(int argc, char *argv[])
{
    FILE *input_image_file, *output_file;
    char output_file_name[50], format[10];
    unsigned char pixel, image_data[ASCII_DIM][ASCII_DIM];
    int row, col;

    /* Check if file name argument is provided */
    if (argc < 2)
    {
        printf("Error: Missing argument - image file name.\n");
        return -1;
    }

    /* Open the input image file */
    input_image_file = fopen(argv[1], "rb");

    /* Check if input file opened successfully */
    if (input_image_file == NULL)
    {
        printf("Error opening file: %s\n", argv[1]);
        return -1;
    }

    /* Read the image data from input file */
    fread(image_data, sizeof(unsigned char), ASCII_DIM * ASCII_DIM, input_image_file);

    /* Close the input image file */
    fclose(input_image_file);

    /* Open the output file for writing */
    strcpy(output_file_name, argv[1]);
    output_file_name[strlen(output_file_name) - 4] = '\0'; // Remove extension
    sprintf(format, "_ASCII-art.txt"); // Add extension
    strcat(output_file_name, format);

    output_file = fopen(output_file_name, "w");

    /* Check if output file opened successfully */
    if (output_file == NULL)
    {
        printf("Error creating file: %s\n", output_file_name);
        return -1;
    }

    /* Convert each pixel in the image to corresponding ASCII character */
    for (row = 0; row < ASCII_DIM; row++)
    {
        for (col = 0; col < ASCII_DIM; col++)
        {
            pixel = image_data[row][col];
            fprintf(output_file, "%c", ConvertPixelToASCII(pixel)); // Write the ASCII character to the output file
        }
        fprintf(output_file, "\n"); // Write a new line character after each row
    }

    /* Close the output file */
    fclose(output_file);

    printf("Successfully converted image to ASCII art: %s\n", output_file_name);

    return 0;
}
//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Constants
#define MAX_PIXELS 2000
#define MAX_ROW_LEN 10000
#define MAX_ASCII_ART 100000

// Function prototypes
void get_pixel(char image[MAX_PIXELS][MAX_ROW_LEN], int row, int col, int *R, int *G, int *B);
void generate_ascii_art(char image[MAX_PIXELS][MAX_ROW_LEN], int width, int height, char ascii_art[MAX_ASCII_ART], int *ascii_len);

// Main Function
int main()
{
    // Define variables
    char image[MAX_PIXELS][MAX_ROW_LEN];
    int width, height;
    char ascii_art[MAX_ASCII_ART];
    int ascii_len = 0;

    // Open image file
    FILE *fp = fopen("image.txt", "r");

    // Check if file is opened successfully
    if(fp == NULL)
    {
        printf("Failed to open file\n");
        return 0;
    }

    // Read width and height of image
    fscanf(fp, "%d %d", &width, &height);

    // Read image pixel values
    int row = 0;
    while(fgets(image[row], MAX_ROW_LEN, fp) != NULL)
    {
        // Remove newline character at the end of the row
        image[row][strlen(image[row])-1] = '\0';
        row++;
    }

    // Generate ASCII Art from Image
    generate_ascii_art(image, width, height, ascii_art, &ascii_len);

    // Print ASCII Art
    printf("%s\n", ascii_art);

    // Close file
    fclose(fp);

    return 0;
}

// Get RGB values for a given pixel
void get_pixel(char image[MAX_PIXELS][MAX_ROW_LEN], int row, int col, int *R, int *G, int *B)
{
    // Extract the R,G,B values
    sscanf(&image[row][3*col], "%d %d %d", R, G, B);
}

// Generate ASCII Art from Image
void generate_ascii_art(char image[MAX_PIXELS][MAX_ROW_LEN], int width, int height, char ascii_art[MAX_ASCII_ART], int *ascii_len)
{
    // Define variables
    char ascii_symbols[] = { "$@B%8W*M#oahkbdpqwmZO0QCJYXzcvnxs1r:;|()\\/{}[]?!-+~<>i!lI\"^`'. " };
    int num_symbols = strlen(ascii_symbols);
    int row, col, index = 0;
    int R, G, B;

    // Loop through each pixel in the image
    for(row = 0; row < height; row++)
    {
        for(col = 0; col < width; col++)
        {
            // Get RGB values of the pixel
            get_pixel(image, row, col, &R, &G, &B);

            // Calculate grayscale value of pixel
            double gray_value = (0.299*R + 0.587*G + 0.114*B);

            // Calculate index of ASCII symbol based on grayscale value
            int symbol_index = (int)((gray_value/255)*(num_symbols-1));

            // Add ASCII symbol to ASCII Art buffer
            ascii_art[index++] = ascii_symbols[symbol_index];
        }

        // Add newline character at the end of each row
        ascii_art[index++] = '\n';
    }

    // Add null terminator at the end of ASCII Art buffer
    ascii_art[index] = '\0';

    // Set ASCII Art length
    *ascii_len = strlen(ascii_art);
}
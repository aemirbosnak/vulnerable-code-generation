//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the ASCII characters to represent the different shades of gray
char ascii_chars[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

// Function to convert the image to ASCII art
void convert_to_ascii(char *filename) {
    FILE *input_file = fopen(filename, "rb");
    if (input_file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Read the header of the image to get its size
    char header[54];
    fread(header, sizeof(char), 54, input_file);
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Allocate memory for the image data and read it from the file
    int image_size = width * height;
    unsigned char *image_data = (unsigned char*)malloc(image_size);
    fread(image_data, sizeof(char), image_size, input_file);

    // Loop through each pixel of the image and convert it to an ASCII character
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Get the pixel value
            int pixel_value = image_data[i * width + j];

            // Calculate the index of the ASCII character to use
            int ascii_index = (pixel_value * 10) / 255;

            // Print the ASCII character to represent the pixel
            printf("%c", ascii_chars[ascii_index]);
        }
        printf("\n");
    }

    // Free the memory and close the file
    free(image_data);
    fclose(input_file);
}

int main() {
    // Get the filename from the user
    char filename[100];
    printf("Enter the name of the image file: ");
    scanf("%s", filename);

    // Convert the image to ASCII art and print it
    convert_to_ascii(filename);

    return 0;
}
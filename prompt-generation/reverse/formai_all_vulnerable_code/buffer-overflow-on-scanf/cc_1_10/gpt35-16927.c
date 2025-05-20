//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define ASCII characters for the different levels of gray
// In descending order of brightness
const char *gray_scale = " .:`^\",-~:;=!*#$@"; 

// Function to read the image file and convert it to ASCII art
void convert_to_ascii(char *filename)
{
    FILE *file = fopen(filename, "rb");
    if(file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }

    char buffer[16];
    int width, height, max_val;
    // Read the header of the PGM image file
    fscanf(file, "P5\n%d %d\n%d\n", &width, &height, &max_val);

    // Allocate memory for the image data
    unsigned char *image = (unsigned char*)malloc(sizeof(unsigned char) * width * height);
    if(image == NULL) {
        printf("Error: Unable to allocate memory for the image data\n");
        exit(1);
    }

    // Read image data from the file
    fread(image, sizeof(unsigned char), width * height, file);

    // Close the file
    fclose(file);

    // Calculate the size of each cell in the ASCII art image
    float x_ratio = (float)width / 80;
    float y_ratio = (float)height / 80;

    // Loop through each cell in the ASCII art image
    for(int y = 0; y < 80; y++) {
        for(int x = 0; x < 80; x++) {
            // Calculate the coordinates in the original image corresponding to the current cell in the ASCII art image
            int x1 = (int)(x_ratio * x);
            int y1 = (int)(y_ratio * y);

            // Calculate the index of the pixel in the original image corresponding to the current cell in the ASCII art image
            int index = y1 * width + x1;

            // Calculate the level of gray for the current pixel
            float gray = (float)image[index] / max_val;

            // Calculate the ASCII character corresponding to the level of gray
            int ascii_index = (int)(gray * 11.0);

            // Print the ASCII character to the console
            printf("%c", gray_scale[ascii_index]);
        }
        printf("\n");
    }

    // Free the memory allocated for the image data
    free(image);
}

int main()
{
    char filename[100];
    printf("Enter the filename of the image: ");
    scanf("%s", filename);
    convert_to_ascii(filename);
    return 0;
}
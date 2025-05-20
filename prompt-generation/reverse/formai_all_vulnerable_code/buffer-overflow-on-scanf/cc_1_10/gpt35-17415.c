//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 500
#define MAX_HEIGHT 500

// Function to read the image file into a 2D array of pixels
void read_image(char *filename, char image[MAX_HEIGHT][MAX_WIDTH], int *height, int *width) {
    FILE *fptr;
    char c;
    int i = 0, j = 0;
    // Open the image file for reading
    fptr = fopen(filename, "r");

    // Read the height and width of the image
    fscanf(fptr, "%d %d", height, width);

    // Read each character in the image file
    while ((c = fgetc(fptr)) != EOF && i < MAX_HEIGHT) {
        if (c == '\n') {
            // Move to the next row
            i++;
            j = 0;
        } else {
            // Store the pixel in the image array
            image[i][j] = c;
            j++;
        }
    }
    // Close the image file
    fclose(fptr);
}

// Function to convert the image to ASCII art
void convert_to_ascii(char image[MAX_HEIGHT][MAX_WIDTH], int height, int width) {
    // Define the characters used to represent different gray values
    char chars[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};
    int num_chars = 10;

    // Convert each pixel to a character based on its gray value
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Convert the pixel value to a gray value between 0 and 255
            int gray_value = image[i][j];
            // Convert the gray value to an index between 0 and 9
            int index = gray_value * num_chars / 256;
            // Print the character corresponding to the gray value
            printf("%c", chars[index]);
        }
        // Print a newline character at the end of each row
        printf("\n");
    }
}

int main() {
    char filename[50];
    char image[MAX_HEIGHT][MAX_WIDTH];
    int height, width;

    // Get the filename of the image from the user
    printf("Enter the filename of the image you want to convert to ASCII art: ");
    scanf("%s", filename);

    // Read the image file into the image array
    read_image(filename, image, &height, &width);

    // Convert the image to ASCII art and print it to the console
    convert_to_ascii(image, height, width);

    return 0;
}
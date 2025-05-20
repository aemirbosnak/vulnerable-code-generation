//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 500
#define MAX_HEIGHT 500
#define ASCII_PIXELS " .:-=+*#%@"

/**
 * Recursive function to convert each pixel to an ASCII character
 */
void toAscii(int (*image)[MAX_WIDTH], int height, int width, char output[][MAX_WIDTH+1], int row, int col, int scale) {
    // If we reached the end row of the image, we are done
    if (row >= height) {
        return;
    }

    // If we reached the end column of the image row, go to the next row
    if (col >= width + 1) {
        toAscii(image, height, width, output, row+1, 0, scale);
        return;
    }

    // Calculate the index of the ASCII character based on pixel brightness
    int brightness = image[row][col];
    int pixelIndex = brightness / 25;
    
    // Print the ASCII character, scaled based on the variable 'scale'
    int i, j;
    for (i = 0; i < scale; i++) {
        for (j = 0; j < scale; j++) {
            output[row*scale+i][col*scale+j] = ASCII_PIXELS[pixelIndex];
        }
    }

    // Continue to the next pixel
    toAscii(image, height, width, output, row, col+1, scale);
}

/**
 * Main function to read image data and call recursive function to convert to ASCII art
 */
int main() {
    int image[MAX_HEIGHT][MAX_WIDTH];
    char output[MAX_HEIGHT*10][MAX_WIDTH*10+1];

    FILE *fp;
    fp = fopen("image.txt", "r");
    if (fp == NULL) {
        printf("Could not open file.\n");
        return 0;
    }

    // Read the image data from file
    int height, width;
    char line[MAX_WIDTH*10+1];
    if (fgets(line, sizeof(line), fp) != NULL) {
        sscanf(line, "%d %d", &height, &width);
    }
    int i, j;
    for (i = 0; i < height; i++) {
        if (fgets(line, sizeof(line), fp) != NULL) {
            char *str = strtok(line, " ");
            for (j = 0; j < width; j++) {
                int pixel;
                sscanf(str, "%d", &pixel);
                image[i][j] = pixel;
                str = strtok(NULL, " ");
            }
        }
    }
    fclose(fp);

    // Convert the image to ASCII art
    int scale = 6;
    toAscii(image, height, width, output, 0, 0, scale);

    // Print the ASCII art to console
    for (i = 0; i < height*scale; i++) {
        printf("%s\n", output[i]);
    }
    return 0;
}
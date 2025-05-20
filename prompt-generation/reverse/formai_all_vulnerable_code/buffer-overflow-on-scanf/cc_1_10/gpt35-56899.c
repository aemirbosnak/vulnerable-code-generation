//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the dimensions for the output ASCII art */
#define WIDTH 80
#define HEIGHT 60

/* Define the character set to map */
char charSet[] = {' ', '.', '\'', ':', 'o', '&', '8', '#', '@'}; 

/* Define the number of characters in the character set */
const int CHAR_SET_SIZE = sizeof(charSet) / sizeof(char);

int main(int argc, char* argv[]) {
    /* Create a file pointer to open the image file */
    FILE *fp;

    /* Store the name of the image file */
    char fileName[100];

    /* Prompt the user to enter the name of the image file */
    printf("Enter the name of the image file: ");
    scanf("%s", fileName);

    /* Open the image file */
    fp = fopen(fileName, "rb");

    /* If the file doesn't exist, exit the program */
    if (fp == NULL) {
        printf("Error opening file. %s does not exist.\n", fileName);
        return 1;
    }

    /* Read in the header of the BMP image */
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp);

    /* Get the dimensions of the BMP image */
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];
    int padding = 0;

    /* Calculate the padding for each row of the BMP image */
    while ((width * 3 + padding) % 4 != 0) {
        padding++;
    }

    /* Allocate memory for the RGB values of the BMP image */
    unsigned char *rgb = (unsigned char*) malloc(sizeof(unsigned char) * width * height * 3);

    /* Read in the RGB values of the BMP image */
    fread(rgb, sizeof(unsigned char), width * height * 3, fp);

    /* Close the BMP file */
    fclose(fp);

    /* Allocate memory for the output ASCII art */
    char *ascii = (char*) malloc(sizeof(char) * WIDTH * HEIGHT);

    /* Convert RGB values to ASCII art */
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            /* Get the RGB values for the current pixel */
            int red = *(rgb + (i * width + j) * 3 + 2);
            int green = *(rgb + (i * width + j) * 3 + 1);
            int blue = *(rgb + (i * width + j) * 3);

            /* Convert the RGB values to grayscale */
            int gray = (red + green + blue) / 3;

            /* Map the grayscale value to a character in the character set */
            int charIndex = gray * CHAR_SET_SIZE / 256;

            /* Set the value in the ASCII art matrix */
            *(ascii + (i / (height / HEIGHT)) * WIDTH + (j / (width / WIDTH))) = charSet[charIndex];
        }
        *(ascii + (i / (height / HEIGHT)) * WIDTH + WIDTH) = '\n';
    }

    /* Print the output ASCII art */
    printf("%s", ascii);

    /* Free memory */
    free(rgb);
    free(ascii);

    return 0;
}
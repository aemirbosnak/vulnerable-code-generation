//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1000 // Maximum width of the input image
#define MAX_HEIGHT 1000 // Maximum height of the input image

/*
 * A function to check if a file exists
 * Returns 1 if the file exists, 0 otherwise
 */
int isFileExists(const char *fileName) {
    FILE *file;
    if ((file = fopen(fileName, "r"))) {
        fclose(file);
        return 1;
    }
    return 0;
}

/*
 * A function to read the input image into a buffer
 * Returns 0 if successful, -1 otherwise
 */
int readImage(char *fileName, char *buffer, int *width, int *height) {
    if (!isFileExists(fileName)) {
        fprintf(stderr, "Error: File '%s' does not exist\n", fileName);
        return -1;
    }
    
    FILE *fptr;
    int i, j, k;
    char ch[MAX_WIDTH];
    
    fptr = fopen(fileName, "r");
    if (fptr == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'\n", fileName);
        return -1;
    }
    
    fscanf(fptr, "%d %d\n", width, height);
    
    for (i = 0; i < *height; i++) {
        fgets(ch, MAX_WIDTH, fptr);
        k = 0;
        for (j = 0; ch[j]; j++) {
            if (ch[j] != ' ' && ch[j] != '\n') {
                buffer[i * (*width) + k] = ch[j];
                k++;
            }
        }
    }
    
    fclose(fptr);
    return 0;
}

/*
 * A function to convert a pixel (represented as an integer) into its ASCII character representation
 * Returns the corresponding ASCII character
 */
char getAsciiCharacter(int pixel) {
    int asciiPixel = pixel * 255 / 9; // Convert the pixel value to a value between 0 and 255
    if (asciiPixel <= 25) {
        return '@';
    } else if (asciiPixel <= 50) {
        return '#';
    } else if (asciiPixel <= 75) {
        return '&';
    } else if (asciiPixel <= 100) {
        return '*';
    } else if (asciiPixel <= 125) {
        return 'o';
    } else if (asciiPixel <= 150) {
        return ':';
    } else if (asciiPixel <= 175) {
        return '-';
    } else if (asciiPixel <= 200) {
        return ';';
    } else if (asciiPixel <= 225) {
        return '+';
    } else {
        return '\'';
    }
}

/*
 * A function to convert the input image into ASCII art and write it to a file
 * Returns 0 if successful, -1 otherwise
 */
int convertToAsciiArt(char *inputFile, char *outputFile) {
    char buffer[MAX_WIDTH * MAX_HEIGHT];
    int width, height;
    
    if (readImage(inputFile, buffer, &width, &height) != 0) {
        fprintf(stderr, "Error: Could not read input image\n");
        return -1;
    }
    
    FILE *fptr;
    fptr = fopen(outputFile, "w");
    if (fptr == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'\n", outputFile);
        return -1;
    }
    
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int pixel = buffer[i * width + j] - '0'; // Convert the pixel value to an integer
            fprintf(fptr, "%c", getAsciiCharacter(pixel)); // Write the corresponding ASCII character to file
        }
        fprintf(fptr, "\n"); // Write a newline character at the end of each row
    }
    
    fclose(fptr);
    return 0;
}

int main() {
    printf("Enter the file name of the input image: ");
    char inputFile[100];
    scanf("%s", inputFile);
    
    printf("Enter the file name of the output file: ");
    char outputFile[100];
    scanf("%s", outputFile);
    
    if (convertToAsciiArt(inputFile, outputFile) != 0) {
        printf("Error: Failed to convert image to ASCII art\n");
        return -1;
    }
    
    printf("Conversion successful. ASCII art saved in file '%s'\n", outputFile);
    return 0;
}
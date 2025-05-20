//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_WIDTH 80
#define MAX_HEIGHT 60
#define ASCII_PIXELS "@#Oo*+;:. "

// Function Prototypes
void inputImage(int pixels[][MAX_WIDTH], int *width, int *height);
void convertToAscii(int pixels[][MAX_WIDTH], char ascii[][MAX_WIDTH], int width, int height);
void outputAscii(char ascii[][MAX_WIDTH], int width, int height);

// Main Function
int main() {
    int pixels[MAX_HEIGHT][MAX_WIDTH];
    char ascii[MAX_HEIGHT][MAX_WIDTH];
    int width, height;
    
    inputImage(pixels, &width, &height);
    convertToAscii(pixels, ascii, width, height);
    outputAscii(ascii, width, height);
    
    return 0;
}

// Function Definitions
void inputImage(int pixels[][MAX_WIDTH], int *width, int *height) {
    char filename[100];
    FILE *file;
    
    printf("Enter the filename of the image: ");
    scanf("%s", filename);
    
    file = fopen(filename, "r");
    
    if (file == NULL) {
        printf("Error opening file.");
        exit(1);
    }
    
    fscanf(file, "%d %d", width, height);
    
    for (int i = 0; i < *height; i++) {
        for (int j = 0; j < *width; j++) {
            fscanf(file, "%d", &pixels[i][j]);
        }
    }
    
    fclose(file);
}

void convertToAscii(int pixels[][MAX_WIDTH], char ascii[][MAX_WIDTH], int width, int height) {
    int grayscale;
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            grayscale = pixels[i][j] / 3;
            ascii[i][j] = ASCII_PIXELS[grayscale];
        }
    }
}

void outputAscii(char ascii[][MAX_WIDTH], int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", ascii[i][j]);
        }
        printf("\n");
    }
}
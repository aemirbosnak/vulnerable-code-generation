//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 120
#define MAX_HEIGHT 60

// Color structure to hold RGB values
typedef struct {
    int r;
    int g;
    int b;
} Color;

// This function determines which ASCII character to use based on the pixel's grayscale value
char get_char(int gray_value) {
    char characters[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};
    int num_chars = sizeof(characters) / sizeof(char);
    int index = gray_value / (255 / num_chars);
    return characters[index];
}

int main() {
    char file_name[100];
    printf("Enter the name of the file you want to convert: ");
    scanf("%s", file_name);
    FILE* input_file = fopen(file_name, "rb");
    if (input_file == NULL) {
        printf("Error: could not open file %s.\n", file_name);
        return 1;
    }
    // Read the image header (we only need the width and height)
    char header[54]; // BMP header is always 54 bytes long
    fread(header, sizeof(char), 54, input_file);
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    // Make sure the image is not too wide or too tall
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Error: image is too large.\n");
        return 1;
    }
    // Allocate memory for the RGB values of each pixel
    Color* pixels = malloc(width * height * sizeof(Color));
    memset(pixels, 0, width * height * sizeof(Color));
    // Read the RGB values of each pixel into memory
    int padding = (4 - (width * 3) % 4) % 4; // BMPs are padded so each row is a multiple of 4 bytes long
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int index = (i * width) + j;
            fread(&pixels[index], sizeof(Color), 1, input_file);
        }
        // Ignore padding bytes at the end of each row
        fseek(input_file, padding, SEEK_CUR);
    }
    fclose(input_file);
    // Convert the RGB values to grayscale values (0-255)
    int grayscale[width * height];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int index = (i * width) + j;
            grayscale[index] = (pixels[index].r + pixels[index].g + pixels[index].b) / 3;
        }
    }
    free(pixels);
    // Print the ASCII art to the terminal
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int index = (i * width) + j;
            printf("%c", get_char(grayscale[index]));
        }
        printf("\n");
    }
    return 0;
}
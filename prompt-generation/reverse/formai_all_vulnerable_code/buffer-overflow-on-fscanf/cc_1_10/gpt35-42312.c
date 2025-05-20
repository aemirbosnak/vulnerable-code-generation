//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define ASCII_RANGE 256

char asciiset[ASCII_RANGE] = {' ', '.', ',', ':', ';', '+', '*', '?', '%', '#', '@'};

/**
 * Function to load image data from a given file
 */
void load_image(char* filename, int img[MAX_HEIGHT][MAX_WIDTH], int* height, int* width) {
    FILE* fp;
    int pixel;

    fp = fopen(filename, "r");
    fscanf(fp, "%d %d", height, width);

    for (int i = 0; i < *height; i++) {
        for (int j = 0; j < *width; j++) {
            fscanf(fp, "%d", &pixel);
            img[i][j] = pixel;
        }
    }

    fclose(fp);
}

/**
 * Function to convert an integer pixel to ASCII character
 */
char pixel_to_ascii(int pixel) {
    int range = ASCII_RANGE / sizeof(asciiset);
    int index = pixel / range;
    return asciiset[index];
}

/**
 * Function to convert an image to ASCII art
 */
void convert_to_ascii(int img[MAX_HEIGHT][MAX_WIDTH], int height, int width, char asciiart[MAX_HEIGHT][MAX_WIDTH]) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            asciiart[i][j] = pixel_to_ascii(img[i][j]);
        }
    }
}

/**
 * Function to print the ASCII art to console
 */
void print_asciiart(char asciiart[MAX_HEIGHT][MAX_WIDTH], int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", asciiart[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int img[MAX_HEIGHT][MAX_WIDTH];
    char asciiart[MAX_HEIGHT][MAX_WIDTH];
    int height, width;
    
    load_image("test_image.txt", img, &height, &width);
    convert_to_ascii(img, height, width, asciiart);
    print_asciiart(asciiart, height, width);
    
    return 0;
}
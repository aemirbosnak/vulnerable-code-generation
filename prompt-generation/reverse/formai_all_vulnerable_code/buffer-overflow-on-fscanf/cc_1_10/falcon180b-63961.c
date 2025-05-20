//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <limits.h>

#define WIDTH 80 // width of the image
#define HEIGHT 25 // height of the image
#define CHAR_SET ".,:;i1tT-+\"#%@*+=-:. " // characters to be used in ASCII art

// function to print the ASCII art
void print_ascii_art(char image[HEIGHT][WIDTH]) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", CHAR_SET[image[i][j]]);
        }
        printf("\n");
    }
}

// function to load the image file
void load_image(char image[HEIGHT][WIDTH], char filename[]) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s.\n", filename);
        exit(1);
    }

    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            fscanf(fp, "%c", &image[i][j]);
        }
    }

    fclose(fp);
}

// function to convert the image to ASCII art
void convert_to_ascii_art(char image[HEIGHT][WIDTH]) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            int gray_value = (int) round(0.2989 * image[i][j] + 0.5870 * image[i][j] + 0.1140 * image[i][j]);
            image[i][j] = CHAR_SET[gray_value % 62];
        }
    }
}

int main() {
    srand(time(0));

    char image[HEIGHT][WIDTH];
    load_image(image, "image.bmp");

    convert_to_ascii_art(image);

    printf("Original image:\n");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", image[i][j]);
        }
        printf("\n");
    }

    printf("\nASCII art:\n");
    print_ascii_art(image);

    return 0;
}
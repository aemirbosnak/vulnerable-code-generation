//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIXEL_VALUE 255
#define MAX_ASCII_VALUE 69

char ascii_chars[MAX_ASCII_VALUE + 1] = {
    '@', '#', 'S', '%', '?', '*', '+', ';', ':', ',', '.',
    ' ', '\'', '`', '^', '~', '-', '_', '|', '(', ')', '{',
    '}', '[', ']', '1', '0', 'i', '!', 'l', 'I', '/', '\\',
    '<', '>', 'r', 'c', 'v', 'u', 'n', 'x', 'z', 'j', 'f',
    't', 'L', 'C', 'J', 'Y', 'X', 'Z', '2', '3', '4', '5'
};

void print_ascii_art(int *pixels, int width, int height) {

    int pixel_value, ascii_index, i, j;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            pixel_value = pixels[i * width + j];
            ascii_index = (int)((pixel_value / (float)(MAX_PIXEL_VALUE)) * MAX_ASCII_VALUE);
            printf("%c", ascii_chars[ascii_index]);
        }
        printf("\n");
    }
}

int main() {

    int i, j, num_pixels;
    int *pixels;
    char file_name[256], magic_number[3];
    FILE *fp;

    printf("Enter file name: ");
    scanf("%s", file_name);

    fp = fopen(file_name, "rb");

    if (fp == NULL) {
        printf("Unable to open file!\n");
        return 1;
    }

    fscanf(fp, "%s", magic_number);

    if (strcmp(magic_number, "P5") != 0) {
        printf("Incorrect file format!\n");
        return 1;
    }

    int width, height, max_val;
    fscanf(fp, "%d%d%d", &width, &height, &max_val);

    num_pixels = width * height;

    pixels = (int *) malloc(num_pixels * sizeof(int));

    if (pixels == NULL) {
        printf("Memory allocation error!");
        fclose(fp);
        return 1;
    }

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            pixels[i * width + j] = fgetc(fp);
        }
    }

    fclose(fp);

    print_ascii_art(pixels, width, height);

    free(pixels);

    return 0;
}
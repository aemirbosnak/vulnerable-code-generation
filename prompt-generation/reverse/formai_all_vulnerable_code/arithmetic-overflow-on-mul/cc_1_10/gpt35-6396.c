//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert_to_ascii(char *, int, int);

int main(int argc, char **argv) {

    if(argc < 2) {
        printf("Usage: ./ascii_art_converter image_file\n");
        return -1;
    }

    char *file_name;
    file_name = argv[1];

    FILE *fp;
    fp = fopen(file_name, "rb");

    if(fp == NULL) {
        printf("Failed to open image file.\n");
        return -1;
    }

    int width, height;

    fseek(fp, 18, SEEK_SET);
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);

    printf("Width: %d\nHeight: %d\n", width, height);

    convert_to_ascii(file_name, width, height);

    fclose(fp);
    return 0;
}

void convert_to_ascii(char *file, int width, int height) {

    FILE *fp;
    fp = fopen(file, "rb");

    fseek(fp, 54, SEEK_SET);

    char r, g, b;
    int i = 0;

    while(i < width * height) {
        fread(&b, sizeof(char), 1, fp);
        fread(&g, sizeof(char), 1, fp);
        fread(&r, sizeof(char), 1, fp);

        // Convert to grayscale
        int gray = (int)(0.299 * r + 0.587 * g + 0.114 * b);

        // Determine ASCII character
        char ascii_char;

        if(gray >= 230) {
            ascii_char = '.';
        } else if(gray >= 200) {
            ascii_char = '*';
        } else if(gray >= 170) {
            ascii_char = ':';
        } else if(gray >= 140) {
            ascii_char = 'o';
        } else if(gray >= 110) {
            ascii_char = '&';
        } else if(gray >= 80) {
            ascii_char = '8';
        } else if(gray >= 50) {
            ascii_char = '#';
        } else {
            ascii_char = '@';
        }

        printf("%c", ascii_char);
        i++;

        if(i % width == 0) {
            printf("\n");
        }
    }

    fclose(fp);
}
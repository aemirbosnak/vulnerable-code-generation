//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ASCII_ART_WIDTH 80
#define ASCII_ART_HEIGHT 24
#define CHAR_SET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()_+-=[]{}|;:,.<>?"
#define ASCII_ART_FILE "ascii_art.txt"

void generate_ascii_art(char *filename, int width, int height) {
    FILE *fp;
    char ch;
    int row, col;

    fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }

    printf("Generating ASCII art...\n");

    for (row = 0; row < height; row++) {
        for (col = 0; col < width; col++) {
            ch = CHAR_SET[rand() % strlen(CHAR_SET)];

            fprintf(fp, "%c", ch);
        }

        fprintf(fp, "\n");
    }

    fclose(fp);

    printf("ASCII art generated successfully!\n");
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <width> <height>\n", argv[0]);
        exit(1);
    }

    int width = atoi(argv[1]);
    int height = atoi(argv[2]);

    if (width <= 0 || height <= 0) {
        printf("Error: Width and height must be greater than zero.\n");
        exit(1);
    }

    printf("Generating ASCII art with width %d and height %d...\n", width, height);

    generate_ascii_art(ASCII_ART_FILE, width, height);

    return 0;
}
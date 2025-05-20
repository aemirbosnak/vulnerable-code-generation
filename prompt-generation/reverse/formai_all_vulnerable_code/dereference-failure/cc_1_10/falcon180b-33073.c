//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80
#define ASCII_ART_COLOR ".,-~:;=!*#@"

// Function to convert an image to ASCII art
void image_to_ascii_art(char *filename, int width, int height) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    unsigned char *data = (unsigned char *) malloc(width * height * 3);
    if (data == NULL) {
        printf("Error: Could not allocate memory\n");
        exit(1);
    }

    int bytes_read = fread(data, 1, width * height * 3, fp);
    if (bytes_read!= width * height * 3) {
        printf("Error: Could not read data from file\n");
        exit(1);
    }

    fclose(fp);

    int max_value = 0;
    for (int i = 0; i < width * height; i++) {
        if (data[i * 3] > max_value) {
            max_value = data[i * 3];
        }
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = y * width + x;
            int r = data[index * 3] * 255 / max_value;
            int g = data[index * 3 + 1] * 255 / max_value;
            int b = data[index * 3 + 2] * 255 / max_value;

            int ascii_index = ((r * 30 + g * 59 + b * 11) / 100) % 58;

            printf("%c", ASCII_ART_COLOR[ascii_index]);
        }
        printf("\n");
    }

    free(data);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <filename> <width> <height>\n", argv[0]);
        return 1;
    }

    int width = atoi(argv[2]);
    int height = atoi(argv[3]);

    image_to_ascii_art(argv[1], width, height);

    return 0;
}
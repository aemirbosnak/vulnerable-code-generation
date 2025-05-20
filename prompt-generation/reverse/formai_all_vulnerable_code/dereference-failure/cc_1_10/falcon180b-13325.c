//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert image to ASCII art
void image_to_ascii(char* filename, int width, int height) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'.\n", filename);
        exit(1);
    }

    int size = width * height;
    unsigned char* data = (unsigned char*)malloc(size * 3);
    fread(data, size * 3, 1, fp);
    fclose(fp);

    // Convert RGB values to grayscale
    for (int i = 0; i < size; i++) {
        int r = data[i * 3];
        int g = data[i * 3 + 1];
        int b = data[i * 3 + 2];
        int gray = (r + g + b) / 3;
        data[i * 3] = gray;
        data[i * 3 + 1] = gray;
        data[i * 3 + 2] = gray;
    }

    // Convert image data to ASCII art
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = y * width + x;
            int value = data[index * 3];

            if (value < 128) {
                printf(" ");
            } else if (value < 192) {
                printf("*");
            } else if (value < 224) {
                printf("*");
            } else if (value < 240) {
                printf("*");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }

    free(data);
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <filename> <width> <height>\n", argv[0]);
        return 1;
    }

    char* filename = argv[1];
    int width = atoi(argv[2]);
    int height = atoi(argv[3]);

    image_to_ascii(filename, width, height);

    return 0;
}
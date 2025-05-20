//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80 // Maximum width of the output ASCII art
#define MAX_HEIGHT 40 // Maximum height of the output ASCII art

int main(int argc, char *argv[]) {
    FILE *fp;
    char *image_path;
    char image[MAX_HEIGHT][MAX_WIDTH];
    int width, height, pixel_size;

    if (argc != 2) {
        printf("Usage: %s image_path", argv[0]);
        return 1;
    }

    image_path = argv[1];

    fp = fopen(image_path, "rb");
    if (!fp) {
        printf("Error: could not open image file %s", image_path);
        return 1;
    }

    // Read the header information from the image file
    char header[54];
    fread(header, sizeof(char), 54, fp);
    width = *(int*)&header[18];
    height = *(int*)&header[22];
    pixel_size = *(int*)&header[28]/8;

    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Error: image dimensions too large");
        return 1;
    }

    // Read the image data into memory
    unsigned char data[height][width][pixel_size];
    fread(data, sizeof(unsigned char), height*width*pixel_size, fp);
    fclose(fp);

    // Convert the image data into ASCII art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int r = data[i][j][2];
            int g = data[i][j][1];
            int b = data[i][j][0];
            int gray = (r + g + b) / 3;
            if (gray < 30) {
                image[i][j] = '@';
            } else if (gray < 70) {
                image[i][j] = '#';
            } else if (gray < 120) {
                image[i][j] = 'x';
            } else if (gray < 170) {
                image[i][j] = '-';
            } else if (gray < 220) {
                image[i][j] = '.';
            } else {
                image[i][j] = ' ';
            }
        }
    }

    // Print out the ASCII art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}
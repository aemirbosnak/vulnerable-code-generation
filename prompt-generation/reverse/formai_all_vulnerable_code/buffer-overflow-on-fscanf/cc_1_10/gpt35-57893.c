//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_WIDTH 300
#define MAX_HEIGHT 300

void convertImageToAscii(char image[][MAX_WIDTH], int height, int width, char *filename)
{
    FILE *file;

    file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    char asciiChars[] = {'@', '#', '8', '&', 'o', ':', '*', '.', ' '};
    uint8_t numChars = 9;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int pixel = image[i][j];
            int index = pixel * numChars / 255;
            fputc(asciiChars[index], file);
        }
        fputc('\n', file);
    }

    fclose(file);
}

int main()
{
    char image[MAX_HEIGHT][MAX_WIDTH];
    int height = 0, width = 0;

    // Read image from file and store in image array
    FILE *fp = fopen("image.ppm", "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    char buf[16];

    // Read image format
    fgets(buf, sizeof(buf), fp);

    // Read image dimensions
    fscanf(fp, "%d %d", &width, &height);

    // Read image depth
    fgets(buf, sizeof(buf), fp);

    // Read image data
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fscanf(fp, "%hhu", &image[i][j]);
        }
    }

    fclose(fp);

    // Convert image to ascii art
    convertImageToAscii(image, height, width, "ascii.txt");

    printf("Image converted to ASCII art\n");

    return 0;
}
//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH  80
#define MAX_HEIGHT 80

int main(int argc, char **argv) {

    FILE* fp;
    unsigned char image[MAX_HEIGHT][MAX_WIDTH];
    int height, width, scale;

    // check if file path is provided
    if (argc != 2) {
        printf("Please provide file path e.g. ./image_converter image.pgm\n");
        return 1;
    }

    // open the file in binary mode
    fp = fopen(argv[1], "rb");
    if (!fp) {
        printf("Could not read image file\n");
        return 1;
    }

    // read the magic number
    char magic[3];
    if (!fgets(magic, sizeof magic, fp)) {
        printf("Could not read magic number\n");
        return 1;
    }

    // read the comments
    char line[100];
    while (fgets(line, sizeof line, fp)[0] == '#') {
        // ignore the comments
    }

    // read the width, height and scale
    char* pEnd;
    width = strtol(line, &pEnd, 10);
    height = strtol(pEnd, &pEnd, 10);
    scale = strtol(pEnd, &pEnd, 10);

    // read the pixel values
    int count = 0;
    while (fread(&image[count / width][count % width], sizeof(unsigned char), 1, fp)) {
        count++;
    }

    // close the file
    fclose(fp);

    // prepare the ASCII art
    char ascii[MAX_HEIGHT][MAX_WIDTH + 1];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            char c = ' ';
            if (image[i][j] < (scale / 3)) {
                c = '#';
            } else if (image[i][j] < ((2 * scale / 3))) {
                c = '+';
            } else if (image[i][j] < scale) {
                c = '.';
            }
            ascii[i][j] = c;
        }
        ascii[i][width] = '\0';
    }

    // print the ASCII art
    for (int i = 0; i < height; i++) {
        printf("%s\n", ascii[i]);
    }

    return 0;
}
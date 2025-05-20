//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 80
#define MAX_PIXEL_VALUE 255

// converts a pixel value into a corresponding ASCII character
char get_ascii_char(int value) {
    const char ascii_chars[] = " .:-=+*#%@";
    int char_count = strlen(ascii_chars);
    int step = MAX_PIXEL_VALUE / (char_count - 1);
    int index = value / step;
    return ascii_chars[index];
}

// prints the image as ASCII art to the console
void print_ascii_image(int image[MAX_HEIGHT][MAX_WIDTH], int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int pixel_value = image[i][j];
            char ascii_char = get_ascii_char(pixel_value);
            printf("%c", ascii_char);
        }
        printf("\n");
    }
}

// reads the image data from a PGM file
int read_pgm_image(char *filename, int image[MAX_HEIGHT][MAX_WIDTH], int *height, int *width) {
    FILE *fp;
    char buffer[256];
    int pixel_value;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file\n");
        return 0;
    }

    // read header
    fgets(buffer, 256, fp);
    if (strcmp(buffer, "P5\n") != 0) {
        printf("Error: invalid file format\n");
        fclose(fp);
        return 0;
    }

    // skip comments
    fgets(buffer, 256, fp);
    while (buffer[0] == '#') {
        fgets(buffer, 256, fp);
    }

    // read height and width
    sscanf(buffer, "%d %d", height, width);
    if (*height > MAX_HEIGHT || *width > MAX_WIDTH) {
        printf("Error: image size is too big\n");
        fclose(fp);
        return 0;
    }

    // read maximum pixel value
    fgets(buffer, 256, fp);
    sscanf(buffer, "%d", &pixel_value);
    if (pixel_value > MAX_PIXEL_VALUE) {
        printf("Error: pixel value is too big\n");
        fclose(fp);
        return 0;
    }

    // read image data
    for (int i = 0; i < *height; i++) {
        for (int j = 0; j < *width; j++) {
            fread(&pixel_value, sizeof(unsigned char), 1, fp);
            image[i][j] = pixel_value;
        }
    }

    fclose(fp);
    return 1;
}

int main(int argc, char *argv[]) {
    int image[MAX_HEIGHT][MAX_WIDTH];
    int height, width;
    char *filename;

    // get filename from command line argument
    if (argc != 2) {
        printf("Error: please provide a filename\n");
        return 1;
    } else {
        filename = argv[1];
    }

    // read image from file
    if (!read_pgm_image(filename, image, &height, &width)) {
        return 1;
    }

    // print image as ASCII art
    print_ascii_image(image, height, width);

    return 0;
}
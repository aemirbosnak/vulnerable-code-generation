//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the dimensions of the ASCII art
#define WIDTH 80
#define HEIGHT 60

// define the maximum intensity value
#define MAX_INTENSITY 255

// define the ASCII characters used in the art
#define CHARACTERS " .:-=+*#%@"

// define the length of the characters string
#define CHARACTERS_LEN strlen(CHARACTERS)

// define a struct to hold the pixel values
typedef struct {
    int r;
    int g;
    int b;
} Pixel;

// define a function to read a PPM file and return the pixel array
Pixel* readPPM(char* filename, int* width, int* height) {
    FILE* fp;
    char format[3];
    int maxval;

    // open the PPM file for reading
    if ((fp = fopen(filename, "rb")) == NULL) {
        fprintf(stderr, "Error: cannot open file %s\n", filename);
        exit(1);
    }

    // read the PPM header
    fscanf(fp, "%s\n", format);
    if (strcmp(format, "P6") != 0) {
        fprintf(stderr, "Error: wrong file format %s\n", format);
        exit(1);
    }
    fscanf(fp, "%d %d\n", width, height);
    fscanf(fp, "%d\n", &maxval);
    if (maxval > MAX_INTENSITY) {
        fprintf(stderr, "Error: maximum intensity exceeds %d\n", MAX_INTENSITY);
        exit(1);
    }

    // allocate the pixel array
    Pixel* pixels = (Pixel*) malloc((*width) * (*height) * sizeof(Pixel));

    // read the pixel values
    int i;
    for (i = 0; i < (*width) * (*height); i++) {
        pixels[i].r = fgetc(fp);
        pixels[i].g = fgetc(fp);
        pixels[i].b = fgetc(fp);
    }

    // close the file
    fclose(fp);

    // return the pixel array
    return pixels;
}

// define a function to convert the pixel values to ASCII characters
void convertPixelsToAscii(Pixel* pixels, char* ascii, int width, int height) {
    int i, j, k;
    int index;
    int intensity;

    // loop over the pixels
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            // calculate the index of the current pixel
            index = i * width + j;

            // calculate the intensity of the current pixel
            intensity = (pixels[index].r + pixels[index].g + pixels[index].b) / 3;

            // calculate the index of the ASCII character to use
            k = (int)((double)(intensity * CHARACTERS_LEN) / MAX_INTENSITY);

            // set the ASCII character in the output array
            ascii[index] = CHARACTERS[k];
        }
        ascii[(i+1)*width] = '\n'; // add a newline character at the end of each row
    }
    ascii[width*height] = '\0'; // add a null terminator at the end of the string
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char* filename = argv[1];
    int width, height;
    Pixel* pixels = readPPM(filename, &width, &height);

    char ascii[WIDTH * HEIGHT];
    convertPixelsToAscii(pixels, ascii, width, height);

    printf("%s", ascii);

    free(pixels);
    return 0;
}
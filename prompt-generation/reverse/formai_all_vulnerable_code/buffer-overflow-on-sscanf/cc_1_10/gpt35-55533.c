//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_WIDTH 200
#define MAX_HEIGHT 200

char convertPixel(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
void convertImage(char* filename);

int main(int argc, char* argv[]) {
    if(argc < 2) {
        printf("Error: Input image filename not provided.\n");
        exit(EXIT_FAILURE);
    }

    char* filename = argv[1];
    convertImage(filename);
    return 0;
}

char convertPixel(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    if(a < 128) return ' ';

    static char greyscale[] = {'@', '#', '8', '&', 'o', ':', '*', '.', ' ', ' '};
    uint8_t intensity = (uint8_t)(0.2126*r + 0.7152*g + 0.0722*b);
    uint8_t index = ((intensity + 25) * 10) / 256;
    return greyscale[index];
}

void convertImage(char* filename) {
    FILE* imageFile = fopen(filename, "rb");

    if(!imageFile) {
        printf("Error: Could not open image file %s.\n", filename);
        exit(EXIT_FAILURE);
    }

    char magic[3];
    fread(magic, 1, 2, imageFile);
    magic[2] = '\0';

    if(strcmp(magic, "P6")) {
        printf("Error: Input file is not a valid P6 PPM image file.\n");
        fclose(imageFile);
        exit(EXIT_FAILURE);
    }

    char infoLine[70];
    char* next = fgets(infoLine, 70, imageFile);

    if(infoLine[0] != '#') { 
        printf("Warning: Input file does not contain a comment.\n"); 
    }

    uint32_t width, height, maxVal;
    sscanf(next, "%u %u\n%u", &width, &height, &maxVal);

    if(width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Error: Input image dimensions exceed maximum allowed size %dx%d.\n", MAX_WIDTH, MAX_HEIGHT);
        fclose(imageFile);
        exit(EXIT_FAILURE);
    }

    uint8_t pixel[3];
    uint32_t i, j, k;
    char ascii[MAX_HEIGHT][MAX_WIDTH+1];
    memset(ascii, ' ', MAX_HEIGHT * (MAX_WIDTH+1));

    for(j = 0; j < height; j++) {
        for(i = 0; i < width; i++) {
            fread(pixel, 1, 3, imageFile);

            k = (j * (MAX_WIDTH+1)) + i;
            ascii[j][i] = convertPixel(pixel[0], pixel[1], pixel[2], 255);
        }
    }

    fclose(imageFile);

    for(j = 0; j < height; j++) {
        ascii[j][width] = '\n';
        ascii[j][width+1] = '\0';
        printf("%s", ascii[j]);
    }

    return;
}
//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 60

// Futuristic styles
#define STYLE_1 "XO+*^:. "
#define STYLE_2 "MA@MB#M8&W%B$NWM"
#define STYLE_3 "[]}{)(/\\><|_\\~"

// Convert RGB to grayscale
int rgb2gray(int r, int g, int b){
    return (r * 0.21 + g * 0.72 + b * 0.07);
}

// Convert grayscale value to ASCII character
char gray2char(int grayvalue, const char* style){
    int len = strlen(style);
    int idx = grayvalue * (len - 1) / 255;
    return style[idx];
}

int main(int argc, char* argv[]){
    if(argc < 2){
        printf("Usage: %s image.ppm\n", argv[0]);
        return 0;
    }

    FILE* fp = fopen(argv[1], "rb");
    if(fp == NULL){
        printf("Error: cannot open file %s\n", argv[1]);
        return 0;
    }

    // Read PPM header
    char header[3], type[2];
    int width, height, maxval;
    fscanf(fp, "%2s\n", header);
    fscanf(fp, "%c%c\n", &type[0], &type[1]);
    fscanf(fp, "%d %d\n", &width, &height);
    fscanf(fp, "%d\n", &maxval);

    // Check if file format is correct
    if(strcmp(header, "P6") != 0 || strcmp(type, " ") != 0 || maxval != 255){
        printf("Error: invalid PPM file format\n");
        fclose(fp);
        return 0;
    }

    // Allocate memory for image data
    unsigned char* img = (unsigned char*) malloc(width * height * 3);
    if(img == NULL){
        printf("Error: memory allocation failed\n");
        fclose(fp);
        return 0;
    }

    // Read image data from file
    fread(img, 1, width * height * 3, fp);
    fclose(fp);

    // Convert image to ASCII art
    char art[WIDTH * HEIGHT + HEIGHT + 1];
    memset(art, 0, WIDTH * HEIGHT + HEIGHT + 1);

    int i, j, k, grayvalue;
    for(i = 0; i < height; i++){
        for(j = 0; j < width; j++){
            k = (i * width + j) * 3;
            grayvalue = rgb2gray(img[k], img[k+1], img[k+2]);
            art[i * (WIDTH + 1) + j] = gray2char(grayvalue, STYLE_1);
        }
        art[i * (WIDTH + 1) + j] = '\n';
    }
    art[HEIGHT * (WIDTH + 1)] = '\0';

    // Print ASCII art
    printf("%s\n", art);

    // Free memory
    free(img);

    return 0;
}
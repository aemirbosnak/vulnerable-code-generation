//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void convertToASCII(char imageFile[]);

int main() {
    char imageFile[100];
    printf("Enter the image filename: ");
    fgets(imageFile, 100, stdin);
    // Remove newline character from fgets
    imageFile[strcspn(imageFile, "\n")] = 0;
    convertToASCII(imageFile);
    return 0;
}

void convertToASCII(char imageFile[]) {
    FILE *fp;
    fp = fopen(imageFile, "rb");

    if(fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp);

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    int imageSize = width * height;
    unsigned char *imageData = malloc(sizeof(unsigned char) * imageSize);

    fread(imageData, sizeof(unsigned char), imageSize, fp);

    fclose(fp);

    printf("Image dimensions: %dx%d\n", width, height);
    printf("ASCII conversion:\n");

    for(int i = 0; i < imageSize; i++) {
        int grayScale = 255 - imageData[i];
        char character = ' ';
        if(grayScale >= 0 && grayScale <= 25) {
            character = ' ';
        } else if(grayScale >= 26 && grayScale <= 50) {
            character = '.';
        } else if(grayScale >= 51 && grayScale <= 75) {
            character = ':';
        } else if(grayScale >= 76 && grayScale <= 100) {
            character = '-';
        } else if(grayScale >= 101 && grayScale <= 125) {
            character = '=';
        } else if(grayScale >= 126 && grayScale <= 150) {
            character = '+';
        } else if(grayScale >= 151 && grayScale <= 175) {
            character = '*';
        } else if(grayScale >= 176 && grayScale <= 200) {
            character = '#';
        } else if(grayScale >= 201 && grayScale <= 225) {
            character = '%';
        } else if(grayScale >= 226 && grayScale <= 250) {
            character = '@';
        } else {
            character = '@';
        }
        printf("%c", character);
        if((i+1) % width == 0) {
            printf("\n");
        }
    }

    free(imageData);
}
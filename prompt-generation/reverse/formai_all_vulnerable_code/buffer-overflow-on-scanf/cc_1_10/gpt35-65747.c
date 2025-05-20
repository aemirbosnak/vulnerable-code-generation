//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WIDTH 80
#define HEIGHT 60

char getAsciiChar(int val) {
    char asciiChars[] = {' ','.','\'',':','o','&','8','#','%','@'};
    return asciiChars[val/25];
}

int convertToGrayScale(unsigned char red, unsigned char green, unsigned char blue) {
    return (int)(0.21*red + 0.72*green + 0.07*blue);
}

void convertImageToAscii(unsigned char *imageData, char *asciiData, int imgWidth, int imgHeight) {

    int imgIndex = 0;
    int asciiIndex = 0;

    for(int i=0; i<imgHeight; i++) {
        for(int j=0; j<imgWidth; j++) {
            unsigned char red = imageData[imgIndex];
            unsigned char green = imageData[imgIndex+1];
            unsigned char blue = imageData[imgIndex+2];

            int grayScale = convertToGrayScale(red, green, blue);
            asciiData[asciiIndex] = getAsciiChar(grayScale);

            imgIndex += 3;
            asciiIndex++;
        }
        asciiData[asciiIndex] = '\n';
        asciiIndex++;
    }
    asciiData[asciiIndex] = '\0';
}

int main() {
    FILE *fp;
    char fileName[50];
    char asciiData[WIDTH * HEIGHT + HEIGHT];
    unsigned char imageData[WIDTH * HEIGHT * 3];

    printf("Enter the name of the image file (including extension): ");
    scanf("%s", fileName);

    fp = fopen(fileName, "rb");

    if (fp == NULL) {
        printf("File not found.\n");
        return -1;
    }

    fseek(fp, 54, SEEK_SET);
    fread(imageData, WIDTH * HEIGHT * 3, 1, fp);
    fclose(fp);

    convertImageToAscii(imageData, asciiData, WIDTH, HEIGHT);
    printf("%s", asciiData);

    return 0;
}
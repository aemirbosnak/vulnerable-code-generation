//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

char* getAsciiChar(int value) {
    char asciiChar[] = "$@B%8WM#*oahkbdpwmZO0QCJYXzcvnxrjft/\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";
    // Cryptic style ASCII characters

    int length = strlen(asciiChar);
    int index = (int)(((double)value / 255) * (length - 1));

    return &asciiChar[index];
}

void convertToAscii(char* imagePath) {
    FILE* fp = fopen(imagePath, "rb");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    unsigned char image[MAX_WIDTH][MAX_HEIGHT];
    char asciiImage[MAX_WIDTH][MAX_HEIGHT];

    int width, height;

    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);

    fread(image, sizeof(unsigned char), width * height, fp);

    fclose(fp);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            asciiImage[i][j] = *getAsciiChar(image[i][j]);
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", asciiImage[i][j]);
        }

        printf("\n");
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <image path>\n", argv[0]);
        return 1;
    }

    convertToAscii(argv[1]);
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25
#define CHAR_SET_SIZE 58

char char_set[CHAR_SET_SIZE] = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";

void print_image(char image[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", char_set[image[i][j]]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp;
    char filename[100];
    printf("Enter the name of the image file: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fseek(fp, 18, SEEK_SET); // skip header
    unsigned char header[6];
    fread(header, 1, 6, fp);

    int width = header[0] * 256 + header[1];
    int height = header[2] * 256 + header[3];

    char image[HEIGHT][WIDTH];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fread(&image[i][j], 1, 1, fp);
        }
    }

    fclose(fp);

    print_image(image);

    return 0;
}
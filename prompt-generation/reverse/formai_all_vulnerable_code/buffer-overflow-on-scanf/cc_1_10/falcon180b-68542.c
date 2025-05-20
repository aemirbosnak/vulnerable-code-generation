//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 60
#define CHAR_SET_SIZE 96

char char_set[CHAR_SET_SIZE] = "!\"#$%&'()*+,-./0123456789:;<=>? @ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";

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
    char filename[20];
    printf("Enter the name of the image file: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    fseek(fp, 18, SEEK_SET); // skip header
    unsigned char header[4];
    fread(header, 1, 4, fp);

    int width = header[0] * 0x100 + header[1];
    int height = header[2] * 0x100 + header[3];

    char image[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            fseek(fp, 54 + i * width + j, SEEK_SET);
            unsigned char pixel;
            fread(&pixel, 1, 1, fp);
            image[i][j] = pixel;
        }
    }

    fclose(fp);

    print_image(image);

    return 0;
}
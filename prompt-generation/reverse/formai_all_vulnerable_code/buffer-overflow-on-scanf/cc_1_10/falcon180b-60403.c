//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80 // width of the ASCII art
#define HEIGHT 50 // height of the ASCII art

void print_ascii_art(char *ascii_art) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (ascii_art[i * WIDTH + j] == '1') {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void convert_image_to_ascii_art(char *filename, char *ascii_art) {
    FILE *fp;
    unsigned char c;
    int i, j;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Cannot open image file.\n");
        exit(1);
    }

    fseek(fp, 54, SEEK_SET); // skip header of BMP file
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            fread(&c, 1, 1, fp);
            ascii_art[i * WIDTH + j] = (c > 128)? '1' : '0';
        }
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    char filename[100], ascii_art[HEIGHT * WIDTH];

    printf("Enter the name of the image file: ");
    scanf("%s", filename);

    convert_image_to_ascii_art(filename, ascii_art);

    printf("\nASCII art:\n");
    print_ascii_art(ascii_art);

    return 0;
}
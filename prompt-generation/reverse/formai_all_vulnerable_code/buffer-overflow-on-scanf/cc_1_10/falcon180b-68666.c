//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define WIDTH 80
#define HEIGHT 25
#define CHARACTER_SET "./:;=+*#@"

int main() {
    FILE *fp;
    char filename[100];
    int width, height, i, j, k, pixel, character;
    unsigned char *image;

    printf("Enter the filename of the image: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fseek(fp, 18, SEEK_SET); // Skip header
    fread(&width, 4, 1, fp);
    fread(&height, 4, 1, fp);
    fclose(fp);

    image = (unsigned char *) malloc(width * height);
    fp = fopen(filename, "rb");
    fseek(fp, 18, SEEK_SET);
    fread(image, width * height, 1, fp);
    fclose(fp);

    printf("Enter the character set (default is %s): ", CHARACTER_SET);
    scanf("%s", CHARACTER_SET);

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            pixel = 0;
            for (k = 0; k < 3; k++) {
                pixel += image[i * width + j] >> (8 - k * 2) & 3;
            }
            character = CHARACTER_SET[pixel % strlen(CHARACTER_SET)];
            printf("%c", character);
        }
        printf("\n");
    }

    free(image);

    return 0;
}
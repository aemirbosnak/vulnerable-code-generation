//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25
#define CHAR_SET ".,-+*0123456789ABCDEF"

// Convert a pixel value to an ASCII character
char pixel_to_ascii(int pixel) {
    return CHAR_SET[pixel % 16];
}

// Read an image file and convert it to ASCII art
void image_to_ascii(FILE *fp, char *filename, int width, int height) {
    int i, j, k;
    int pixel;
    char line[MAX_WIDTH + 1];
    char *ptr = (char *)malloc(width * height * sizeof(char));

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    if (filesize!= width * height * 3) {
        printf("Error: Invalid image file format.\n");
        exit(1);
    }

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fread(&pixel, 3, 1, fp);
            pixel = (pixel >> 16) & 0xFF;
            memcpy(ptr + i * width + j, &pixel, sizeof(int));
        }
    }

    fclose(fp);

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            pixel = *(int *) (ptr + i * width + j);
            for (k = 0; k < 3; k++) {
                line[j * 3 + k] = pixel_to_ascii(pixel >> (8 - (2 - k) * 4) & 0xF);
            }
        }
        line[width * 3 - 1] = '\0';
        printf("%s\n", line);
    }

    free(ptr);
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <image_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Error: Cannot open input file.\n");
        return 1;
    }

    char *output_file = argv[2];
    FILE *ofp = fopen(output_file, "w");
    if (ofp == NULL) {
        printf("Error: Cannot open output file.\n");
        fclose(fp);
        return 1;
    }

    image_to_ascii(fp, output_file, MAX_WIDTH, MAX_HEIGHT);

    fclose(fp);
    fclose(ofp);

    return 0;
}
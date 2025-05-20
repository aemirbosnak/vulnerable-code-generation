//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 50

typedef struct {
    char *data;
    int width;
    int height;
} Image;

void loadImage(Image *img, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open image file.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    img->data = malloc(size);
    fread(img->data, size, 1, fp);

    fclose(fp);

    int headerSize = 54; // BMP file header size in bytes
    char *header = img->data;
    img->width = *(int *)&header[18];
    img->height = *(int *)&header[22];
}

void saveASCII(Image *img, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    int padding = (4 - (img->width % 4)) % 4;
    int rowSize = img->width + padding;
    int totalRows = (img->height + 1) / 2;

    for (int y = 0; y < totalRows; y++) {
        int rowStart = y * rowSize;
        for (int x = 0; x < rowSize; x++) {
            int pixelIndex = (y * img->width + x) * 3;
            char color = img->data[pixelIndex];

            if (color == 0) {
                fprintf(fp, " ");
            } else if (color == 1) {
                fprintf(fp, ".");
            } else {
                fprintf(fp, "X");
            }
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input.bmp output.txt\n", argv[0]);
        return 1;
    }

    Image img;
    loadImage(&img, argv[1]);
    saveASCII(&img, argv[2]);

    printf("Conversion complete.\n");
    return 0;
}
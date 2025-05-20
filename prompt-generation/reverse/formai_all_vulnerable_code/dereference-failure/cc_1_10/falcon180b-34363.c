//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000
#define ASCII_CHARS ".,-~:;=!*#@"

typedef struct {
    int width, height;
    unsigned char *data;
} Image;

Image* loadImage(const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    unsigned char* data = malloc(size);
    fread(data, size, 1, fp);
    fclose(fp);

    int width, height, channels;
    unsigned char* pixel = data;
    if (data[0] == 'B' && data[1] == 'M') {
        width = *(int*)pixel;
        height = *(int*)(pixel + 4);
        channels = *(int*)(pixel + 8);
        pixel += 10;
    } else if (data[0] == 'P' && data[1] == 'N' && data[2] == 'G') {
        width = *(int*)pixel;
        height = *(int*)(pixel + 4);
        channels = *(int*)(pixel + 8);
        pixel += 13;
    } else {
        printf("Error: Unsupported file format\n");
        exit(1);
    }

    if (channels!= 3) {
        printf("Error: Image must be RGB\n");
        exit(1);
    }

    Image* img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = data;

    return img;
}

void freeImage(Image* img) {
    free(img->data);
    free(img);
}

void printASCII(const Image* img, FILE* fp) {
    int x, y;
    for (y = 0; y < img->height; y++) {
        for (x = 0; x < img->width; x++) {
            int r = img->data[y * img->width * 3 + x * 3];
            int g = img->data[y * img->width * 3 + x * 3 + 1];
            int b = img->data[y * img->width * 3 + x * 3 + 2];

            int brightness = (r + g + b) / 3;
            if (brightness < 0) brightness = 0;
            if (brightness > 8) brightness = 8;

            fprintf(fp, "%c", ASCII_CHARS[brightness]);
        }
        fprintf(fp, "\n");
    }
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        printf("Usage: %s input.png output.txt\n", argv[0]);
        exit(1);
    }

    Image* img = loadImage(argv[1]);
    FILE* fp = fopen(argv[2], "w");
    if (!fp) {
        printf("Error: Could not open file %s\n", argv[2]);
        exit(1);
    }

    printASCII(img, fp);
    fclose(fp);

    freeImage(img);
    return 0;
}
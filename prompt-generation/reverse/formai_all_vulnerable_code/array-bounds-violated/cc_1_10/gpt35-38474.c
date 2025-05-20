//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const char charPalette[] = " .-'`:!1+*abcdefghijklmnopqrstuvwxyz<>/(){}[]|\\\"^_o#";
// The above is a gradient of character symbols to represent light to dark pixels

struct Image {
    unsigned int width;
    unsigned int height;
    unsigned char *pixels;
};

void printAsciiArt(struct Image *img) {
    for (unsigned int y = 0; y < img->height; y++) {
        for (unsigned int x = 0; x < img->width; x++) {
            unsigned char pixel = img->pixels[y * img->width + x];
            unsigned char symbolIndex = pixel / (255 / (sizeof(charPalette) - 1));
            printf("%c", charPalette[symbolIndex]);
        }
        printf("\n");
    }
}

struct Image* readBinaryImage(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    
    if (!fp) return NULL;
    
    unsigned int width;
    unsigned int height;
    fread(&width, sizeof(unsigned int), 1, fp);
    fread(&height, sizeof(unsigned int), 1, fp);
    
    struct Image *img = malloc(sizeof(struct Image));
    if (!img) return NULL;
    img->width = width;
    img->height = height;
    
    img->pixels = malloc(img->width * img->height);
    if (!img->pixels) {
        free(img);
        return NULL;
    }

    fread(img->pixels, sizeof(unsigned char), img->width * img->height, fp);
    fclose(fp);
    return img;   
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <binary image file>\n", argv[0]);
        return 1;
    }

    struct Image *img = readBinaryImage(argv[1]);
    if (!img) {
        printf("Could not read image file.\n");
        return 1;
    }
    
    printAsciiArt(img);
    
    free(img->pixels);
    free(img);
    return 0;
}
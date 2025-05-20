//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24
#define CHARACTER_SET "./:;=+<>iI!@#$%^&*()_+~`{}[]|\\:;\"'<>,.?/~"

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

Image loadImage(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Failed to open file '%s'\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    unsigned char *data = malloc(size);
    if (data == NULL) {
        printf("Error: Failed to allocate memory for image data\n");
        exit(1);
    }

    fread(data, size, 1, fp);
    fclose(fp);

    Image image = {
       .width = 0,
       .height = 0,
       .data = data
    };

    return image;
}

void printASCIIArt(Image image) {
    for (int y = 0; y < image.height; y++) {
        for (int x = 0; x < image.width; x++) {
            int pixel = (int) image.data[y * image.width + x];
            printf("%c", CHARACTER_SET[pixel % strlen(CHARACTER_SET)]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        exit(1);
    }

    Image image = loadImage(argv[1]);
    if (image.width == 0 || image.height == 0) {
        printf("Error: Invalid image format\n");
        exit(1);
    }

    printASCIIArt(image);

    free(image.data);
    return 0;
}
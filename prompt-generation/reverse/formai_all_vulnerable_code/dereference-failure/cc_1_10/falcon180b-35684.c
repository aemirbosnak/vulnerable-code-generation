//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // maximum size of image

typedef struct {
    int width;
    int height;
    char *data;
} Image;

// load image from file
Image *loadImage(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *data = malloc(size);
    if (data == NULL) {
        printf("Error: could not allocate memory for image data\n");
        exit(1);
    }

    fread(data, 1, size, fp);
    fclose(fp);

    Image *image = malloc(sizeof(Image));
    image->width = size;
    image->height = 1;
    image->data = data;

    return image;
}

// save image to file
void saveImage(Image *image, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: could not open file '%s' for writing\n", filename);
        exit(1);
    }

    fwrite(image->data, 1, image->width, fp);
    fclose(fp);
}

// print image to console
void printImage(Image *image) {
    for (int x = 0; x < image->width; x++) {
        printf("%c", image->data[x]);
    }
    printf("\n");
}

// main program
int main() {
    Image *image = loadImage("example.txt");

    printf("Image loaded:\n");
    printImage(image);

    printf("Image edited:\n");

    // edit the image data here
    image->data[0] = '!';

    printf("Image saved:\n");
    saveImage(image, "example_edited.txt");

    free(image->data);
    free(image);

    return 0;
}
//FormAI DATASET v1.0 Category: Image compression ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Image {
    char format[3];
    int width;
    int height;
    int maxColourValue;
    int **pixelMatrix;
};

typedef struct Image IMAGE;

IMAGE *readImage(char *fileName) {
    FILE *imageFile;
    IMAGE *img = (IMAGE *) malloc(sizeof(IMAGE));
    char buffer[128];
    int i, j;

    imageFile = fopen(fileName, "r");
    if(imageFile == NULL) {
        printf("Failed to open image file.\n");
        exit(1);
    }

    fgets(img->format, 3, imageFile);
    fgets(buffer, 128, imageFile);

    while(buffer[0] == '#') {
        fgets(buffer, 128, imageFile);
    }

    sscanf(buffer, "%d %d", &img->width, &img->height);
    fgets(buffer, 128, imageFile);
    sscanf(buffer, "%d", &img->maxColourValue);

    img->pixelMatrix = (int **) malloc(sizeof(int *) * img->height);
    for(i=0; i<img->height; i++) {
        img->pixelMatrix[i] = (int *) malloc(sizeof(int) * img->width);
        for(j=0; j<img->width; j++) {
            img->pixelMatrix[i][j] = fgetc(imageFile);
        }
    }

    fclose(imageFile);

    return img;
}

void writeImage(IMAGE *img, char *output) {
    FILE *imageFile;
    int i, j;

    imageFile = fopen(output, "w");
    if(imageFile == NULL) {
        printf("Failed to open output file.\n");
        exit(1);
    }

    fprintf(imageFile, "%s\n", img->format);
    fprintf(imageFile, "%d %d\n", img->width, img->height);
    fprintf(imageFile, "%d\n", img->maxColourValue);

    for(i=0; i<img->height; i++) {
        for(j=0; j<img->width; j++) {
            fputc(img->pixelMatrix[i][j], imageFile);
        }
    }

    fclose(imageFile);
}

void compressImage(char *input, char *output) {
    IMAGE *img = readImage(input);
    int i, j, value, average;
    char buffer[128];

    for(i=0; i<img->height; i++) {
        for(j=0; j<img->width; j++) {
            value = img->pixelMatrix[i][j];
            average = ((i>0 ? img->pixelMatrix[i-1][j] : 0)
                     + (i<img->height-1 ? img->pixelMatrix[i+1][j] : 0)
                     + (j>0 ? img->pixelMatrix[i][j-1] : 0)
                     + (j<img->width-1 ? img->pixelMatrix[i][j+1] : 0)) / 4;
            img->pixelMatrix[i][j] = (value - average) + 128;
        }
    }

    writeImage(img, output);
    printf("Image compression successful!\n");

    free(img);
}

int main() {
    char input[128], output[128];

    printf("Enter the name of image file to be compressed: ");
    fgets(input, 128, stdin);
    input[strlen(input)-1] = '\0';

    printf("Enter the name of output file: ");
    fgets(output, 128, stdin);
    output[strlen(output)-1] = '\0';

    compressImage(input, output);

    return 0;
}
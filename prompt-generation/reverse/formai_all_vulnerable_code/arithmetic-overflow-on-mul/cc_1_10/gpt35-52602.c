//FormAI DATASET v1.0 Category: Image Editor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// define image struct to hold image data
typedef struct Image {
    int width;
    int height;
    int* pixels;
} Image;

// function to read image from file
void read_image(Image* img, char* filename) {
    FILE* fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error: could not open file %s.\n", filename);
        exit(1);
    }
    fscanf(fp, "%d %d", &img->width, &img->height);
    img->pixels = (int*) malloc(img->width * img->height * sizeof(int));
    for(int i = 0; i < img->width * img->height; i++) {
        fscanf(fp, "%d", img->pixels + i);
    }
    fclose(fp);
}

// function to write image to file
void write_image(Image* img, char* filename) {
    FILE* fp = fopen(filename, "w");
    if(fp == NULL) {
        printf("Error: could not open file %s.\n", filename);
        exit(1);
    }
    fprintf(fp, "%d %d\n", img->width, img->height);
    for(int i = 0; i < img->width * img->height; i++) {
        fprintf(fp, "%d ", *(img->pixels + i));
        if((i+1) % img->width == 0) {
            fprintf(fp, "\n");
        }
    }
    fclose(fp);
}

int main(int argc, char* argv[]) {
    if(argc != 3) {
        printf("Error: usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }
    Image img;
    read_image(&img, argv[1]);
    printf("Image dimensions: %d x %d\n", img.width, img.height);
    printf("Image data:\n");
    for(int i = 0; i < img.width * img.height; i++) {
        printf("%d ", *(img.pixels + i));
        if((i+1) % img.width == 0) {
            printf("\n");
        }
    }
    write_image(&img, argv[2]);
    free(img.pixels);
    return 0;
}
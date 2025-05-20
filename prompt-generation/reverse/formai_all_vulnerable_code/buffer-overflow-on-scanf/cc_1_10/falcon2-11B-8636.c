//Falcon2-11B DATASET v1.0 Category: Image to ASCII art converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct _Image {
    int width;
    int height;
    char **data;
} Image;

void freeImage(Image *img) {
    free(img->data);
    free(img);
}

void printImage(Image img) {
    for(int i = 0; i < img.width; i++) {
        for(int j = 0; j < img.height; j++) {
            printf("%s", img.data[i][j]);
        }
        printf("\n");
    }
}

void createAsciiArt(Image img) {
    for(int i = 0; i < img.width; i++) {
        for(int j = 0; j < img.height; j++) {
            if(img.data[i][j]!= '\0') {
                char ascii_char;
                ascii_char = img.data[i][j];
                printf("%s", ascii_char);
            }
        }
        printf("\n");
    }
}

int main() {
    char input_file[100];
    printf("Enter the path of input image file: ");
    scanf("%s", input_file);
    FILE *fp = fopen(input_file, "r");
    Image img;
    img.width = 0;
    img.height = 0;
    img.data = NULL;
    fscanf(fp, "%d %d", &img.width, &img.height);
    img.data = (char**)malloc(img.height * sizeof(char*));
    for(int i = 0; i < img.height; i++) {
        img.data[i] = (char*)malloc(img.width * sizeof(char));
        fscanf(fp, "%s", img.data[i]);
    }
    printf("Image converted to ASCII art.\n");
    createAsciiArt(img);
    printf("ASCII art saved in %s.\n", input_file);
    return 0;
}
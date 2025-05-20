//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25
#define CHAR_SET ".:-=+*#@"

void print_image(char *image, int width, int height) {
    int i, j;
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            printf("%c", CHAR_SET[(int)image[i * width + j] / 32]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp;
    char filename[100];
    char *image;
    int width, height, i;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");
    if(fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    width = ftell(fp) / 3;
    height = ftell(fp) / (3 * width);

    rewind(fp);
    image = (char *)malloc(ftell(fp));
    fread(image, 1, ftell(fp), fp);
    fclose(fp);

    printf("Width: %d\n", width);
    printf("Height: %d\n", height);

    print_image(image, width, height);

    free(image);

    return 0;
}
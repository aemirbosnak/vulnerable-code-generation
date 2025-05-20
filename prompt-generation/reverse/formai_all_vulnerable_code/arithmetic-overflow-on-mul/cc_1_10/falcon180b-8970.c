//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25
#define CHAR_SET "~!@#$%^&*()_+-={}|[]\\:;\"'<>,.?/~`"

void print_image(char *image, int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%c", image[i * width + j]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp;
    char *image = NULL;
    int width, height, i, j;

    fp = fopen("image.bmp", "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fseek(fp, 18, SEEK_SET);
    fread(&width, 4, 1, fp);
    fread(&height, 4, 1, fp);

    image = malloc(3 * width * height);
    if (image == NULL) {
        printf("Error allocating memory.\n");
        exit(1);
    }

    fseek(fp, 54, SEEK_SET);
    fread(image, 3 * width * height, 1, fp);
    fclose(fp);

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int r = image[i * width * 3 + j * 3] / 8;
            int g = image[i * width * 3 + j * 3 + 1] / 8;
            int b = image[i * width * 3 + j * 3 + 2] / 8;

            int index = (r * 7 + g * 3 + b) % 58;
            image[i * width * 3 + j * 3] = CHAR_SET[index];
            image[i * width * 3 + j * 3 + 1] = CHAR_SET[index];
            image[i * width * 3 + j * 3 + 2] = CHAR_SET[index];
        }
    }

    print_image(image, width, height);

    free(image);
    return 0;
}
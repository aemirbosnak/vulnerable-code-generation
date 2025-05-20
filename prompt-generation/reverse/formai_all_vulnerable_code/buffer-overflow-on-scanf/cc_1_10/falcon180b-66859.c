//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25
#define PIXEL_SIZE 2

void print_ascii_art(char *image, int width, int height) {
    int i, j;
    for (i = 0; i < height; ++i) {
        for (j = 0; j < width; ++j) {
            printf("%c", image[i * width + j]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp;
    char filename[100];
    printf("Enter the name of the image file: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *image = malloc(filesize);
    fread(image, filesize, 1, fp);
    fclose(fp);

    int width, height;
    FILE *header = fopen("header.bin", "wb");
    fwrite(image, 18, 1, header);
    fclose(header);

    FILE *data = fopen("data.bin", "wb");
    fwrite(image + 18, filesize - 18, 1, data);
    fclose(data);

    printf("Width: %d\n", *(int*)image);
    printf("Height: %d\n", *(int*)(image + 4));

    print_ascii_art(image + 18, *(int*)image, *(int*)(image + 4));

    free(image);
    return 0;
}
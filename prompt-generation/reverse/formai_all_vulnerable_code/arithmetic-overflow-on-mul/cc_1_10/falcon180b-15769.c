//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25
#define CHARSET_SIZE 256

typedef struct {
    char ascii;
    int r, g, b;
} Color;

Color charset[CHARSET_SIZE];

void init_charset() {
    int i;
    for (i = 0; i < CHARSET_SIZE; i++) {
        charset[i].ascii = i;
        charset[i].r = i % 6 * 51;
        charset[i].g = i % 6 * 51;
        charset[i].b = i % 6 * 51;
    }
}

void print_image(char* data, int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%c", charset[(int)data[(i * width + j) * 3]].ascii);
        }
        printf("\n");
    }
}

int main() {
    FILE* fp;
    char filename[20];
    int width, height, bpp;
    char* data;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: File not found!\n");
        exit(1);
    }

    fseek(fp, 18, SEEK_SET);
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);
    fread(&bpp, sizeof(int), 1, fp);

    if (bpp!= 24) {
        printf("Error: Only 24-bit BMP files are supported!\n");
        exit(1);
    }

    data = malloc(width * height * 3);
    fread(data, sizeof(char), width * height * 3, fp);

    fclose(fp);

    init_charset();

    print_image(data, width, height);

    free(data);

    return 0;
}
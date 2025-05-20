//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 100
#define HEIGHT 50
#define CHAR_SET_SIZE 96

char char_set[CHAR_SET_SIZE] = "./:-=+*#%@&";

void print_image(char image[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            printf("%c", char_set[image[y][x]]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp;
    char filename[20];
    printf("Enter the name of the image file: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int width, height, size;
    fseek(fp, 18, SEEK_SET);
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);
    fread(&size, sizeof(int), 1, fp);

    char image[HEIGHT][WIDTH];
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            fseek(fp, 54 + y * size + x * 3, SEEK_SET);
            unsigned char r, g, b;
            fread(&r, sizeof(unsigned char), 1, fp);
            fread(&g, sizeof(unsigned char), 1, fp);
            fread(&b, sizeof(unsigned char), 1, fp);
            int value = (r + g + b) / 3;
            image[y][x] = value % CHAR_SET_SIZE;
        }
    }

    fclose(fp);
    print_image(image);

    return 0;
}
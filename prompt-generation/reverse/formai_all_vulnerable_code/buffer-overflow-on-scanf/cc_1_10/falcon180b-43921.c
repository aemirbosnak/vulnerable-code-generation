//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 100
#define HEIGHT 50
#define CHAR_SET_SIZE 58

char char_set[CHAR_SET_SIZE] = "!\"#$%&'()*+,-./0123456789:;<=>? @ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";

void print_image(int *image, int width, int height) {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            printf("%c", char_set[image[y * width + x]]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp;
    char filename[20];
    int width, height, depth;
    int *image = NULL;
    int max_value = 0;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    fseek(fp, 18, SEEK_SET); // Skip header
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);
    fread(&depth, sizeof(int), 1, fp);

    if (depth!= 24) {
        printf("Error: image must be 24-bit color.\n");
        exit(1);
    }

    image = malloc(width * height * sizeof(int));
    if (image == NULL) {
        printf("Error: could not allocate memory.\n");
        exit(1);
    }

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int value;
            fread(&value, sizeof(int), 1, fp);
            if (value > max_value) {
                max_value = value;
            }
            image[y * width + x] = value;
        }
    }

    fclose(fp);

    int threshold = max_value / CHAR_SET_SIZE;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int value = image[y * width + x];
            int index = value / threshold;
            image[y * width + x] = index;
        }
    }

    print_image(image, width, height);

    free(image);

    return 0;
}
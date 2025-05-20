//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

char grayscale[10] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

struct image {
    int width;
    int height;
    int pixels[MAX_HEIGHT][MAX_WIDTH];
};

typedef struct image Image;

Image read_image(char *filename) {
    Image img;
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("Error: File not found!\n");
        exit(1);
    }
    fscanf(f, "%d %d", &img.width, &img.height);
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            fscanf(f, "%d", &img.pixels[i][j]);
        }
    }
    fclose(f);
    return img;
}

void write_ascii(Image img) {
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            int index = img.pixels[i][j] / 25;
            printf("%c", grayscale[index]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Error: Missing file name parameter!\n");
        return 1;
    }
    Image img = read_image(argv[1]);
    write_ascii(img);
    return 0;
}
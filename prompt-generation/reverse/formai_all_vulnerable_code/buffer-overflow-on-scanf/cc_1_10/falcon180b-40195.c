//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

typedef struct {
    int x;
    int y;
    char symbol;
} Point;

void print_point(Point p) {
    printf("%c", p.symbol);
}

void print_row(Point *row, int width) {
    for (int i = 0; i < width; i++) {
        print_point(row[i]);
    }
    printf("\n");
}

void print_image(Point *image, int width, int height) {
    for (int i = 0; i < height; i++) {
        print_row(image + i * width, width);
    }
}

int main() {
    char filename[100];
    printf("Enter the filename of the image: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int width, height;
    fscanf(fp, "%d %d", &width, &height);

    Point *image = malloc(sizeof(Point) * width * height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fscanf(fp, "%c", &image[i * width + j].symbol);
        }
    }

    fclose(fp);

    print_image(image, width, height);

    free(image);

    return 0;
}
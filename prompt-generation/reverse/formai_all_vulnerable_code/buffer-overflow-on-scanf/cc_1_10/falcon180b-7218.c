//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 24

char image[HEIGHT][WIDTH];

void load_image(char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Could not open image file.\n");
        exit(1);
    }

    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        fread(image[i], WIDTH, 1, file);
    }

    fclose(file);
}

void print_ascii_art(int x, int y, int value) {
    if (value == 0) {
        printf("  ");
    } else if (value == 1) {
        printf("██");
    } else if (value == 2) {
        printf("  █");
    } else if (value == 3) {
        printf("█  █");
    } else if (value == 4) {
        printf("███");
    } else if (value == 5) {
        printf("  ██");
    } else if (value == 6) {
        printf("█  ██");
    } else if (value == 7) {
        printf("████");
    } else {
        printf("  ");
    }
}

int main() {
    char filename[100];
    printf("Enter image filename: ");
    scanf("%s", filename);

    load_image(filename);

    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            int value = image[i][j] / 16;
            print_ascii_art(j * 3, i * 2, value);
        }
    }

    return 0;
}
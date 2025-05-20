//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

void print_art(char *art, int width, int height) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (art[i * width + j] == '1') {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void generate_art(char *art, int width, int height) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            art[i * width + j] = rand() % 2? '1' : '0';
        }
    }
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <width> <height>\n", argv[0]);
        return 1;
    }

    int width = atoi(argv[1]);
    int height = atoi(argv[2]);

    if (width <= 0 || height <= 0 || width > MAX_WIDTH || height > MAX_HEIGHT) {
        fprintf(stderr, "Invalid width and/or height\n");
        return 1;
    }

    char *art = calloc(height, width);
    if (art == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        return 1;
    }

    generate_art(art, width, height);
    print_art(art, width, height);

    free(art);
    return 0;
}
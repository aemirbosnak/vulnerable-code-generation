//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 3
#define HEIGHT 3

typedef struct {
    int r, g, b;
} pixel;

pixel image[WIDTH][HEIGHT];

void load_image(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("fopen");
        exit(1);
    }

    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            fscanf(fp, "%d %d %d", &image[i][j].r, &image[i][j].g, &image[i][j].b);
        }
    }

    fclose(fp);
}

void save_image(char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        perror("fopen");
        exit(1);
    }

    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            fprintf(fp, "%d %d %d\n", image[i][j].r, image[i][j].g, image[i][j].b);
        }
    }

    fclose(fp);
}

void brighten(int amount) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            image[i][j].r = fmin(255, image[i][j].r + amount);
            image[i][j].g = fmin(255, image[i][j].g + amount);
            image[i][j].b = fmin(255, image[i][j].b + amount);
        }
    }
}

void darken(int amount) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            image[i][j].r = fmax(0, image[i][j].r - amount);
            image[i][j].g = fmax(0, image[i][j].g - amount);
            image[i][j].b = fmax(0, image[i][j].b - amount);
        }
    }
}

void invert() {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            image[i][j].r = 255 - image[i][j].r;
            image[i][j].g = 255 - image[i][j].g;
            image[i][j].b = 255 - image[i][j].b;
        }
    }
}

void grayscale() {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            int gray = (image[i][j].r + image[i][j].g + image[i][j].b) / 3;
            image[i][j].r = gray;
            image[i][j].g = gray;
            image[i][j].b = gray;
        }
    }
}

void main() {
    load_image("image.txt");

    brighten(50);
    save_image("brightened.txt");

    darken(50);
    save_image("darkened.txt");

    invert();
    save_image("inverted.txt");

    grayscale();
    save_image("grayscale.txt");
}
//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel;

pixel image[WIDTH][HEIGHT];

void flip_image() {
    for (int i = 0; i < WIDTH / 2; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            pixel temp = image[i][j];
            image[i][j] = image[WIDTH - i - 1][j];
            image[WIDTH - i - 1][j] = temp;
        }
    }
}

void change_brightness(int brightness) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            image[i][j].red += brightness;
            image[i][j].green += brightness;
            image[i][j].blue += brightness;
        }
    }
}

void change_contrast(int contrast) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            image[i][j].red = (image[i][j].red - 128) * contrast + 128;
            image[i][j].green = (image[i][j].green - 128) * contrast + 128;
            image[i][j].blue = (image[i][j].blue - 128) * contrast + 128;
        }
    }
}

void save_image(char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "P3\n%d %d\n255\n", WIDTH, HEIGHT);

    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            fprintf(fp, "%d %d %d ", image[i][j].red, image[i][j].green, image[i][j].blue);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

int main() {
    // Load image from file
    FILE *fp = fopen("image.ppm", "rb");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[256];
    fgets(line, sizeof(line), fp);  // Read magic number
    fgets(line, sizeof(line), fp);  // Read width and height
    int width, height;
    sscanf(line, "%d %d", &width, &height);
    fgets(line, sizeof(line), fp);  // Read max value

    // Allocate memory for image data
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            fscanf(fp, "%d %d %d", &image[i][j].red, &image[i][j].green, &image[i][j].blue);
        }
    }

    fclose(fp);

    // Flip image horizontally
    flip_image();

    // Change brightness
    change_brightness(30);

    // Change contrast
    change_contrast(1.5);

    // Save image to file
    save_image("new_image.ppm");

    return 0;
}
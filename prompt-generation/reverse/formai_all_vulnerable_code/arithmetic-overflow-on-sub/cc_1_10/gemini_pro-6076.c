//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024
unsigned char image[MAX_HEIGHT][MAX_WIDTH];
int width, height;

void load_image(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("fopen");
        exit(1);
    }

    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);
    fread(image, sizeof(unsigned char), width * height, file);
    fclose(file);
}

void save_image(char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("fopen");
        exit(1);
    }

    fwrite(&width, sizeof(int), 1, file);
    fwrite(&height, sizeof(int), 1, file);
    fwrite(image, sizeof(unsigned char), width * height, file);
    fclose(file);
}

void invert_image() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j] = 255 - image[i][j];
        }
    }
}

void grayscale_image() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char gray = (image[i][j] + image[i][j] + image[i][j]) / 3;
            image[i][j] = gray;
        }
    }
}

void blur_image() {
    unsigned char new_image[MAX_HEIGHT][MAX_WIDTH];

    for (int i = 1; i < height - 1; i++) {
        for (int j = 1; j < width - 1; j++) {
            int sum = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    sum += image[i + k][j + l];
                }
            }
            new_image[i][j] = sum / 9;
        }
    }

    memcpy(image, new_image, sizeof(unsigned char) * width * height);
}

void sharpen_image() {
    unsigned char new_image[MAX_HEIGHT][MAX_WIDTH];

    for (int i = 1; i < height - 1; i++) {
        for (int j = 1; j < width - 1; j++) {
            int sum = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    sum += image[i + k][j + l];
                }
            }
            new_image[i][j] = sum - 9 * image[i][j];
        }
    }

    memcpy(image, new_image, sizeof(unsigned char) * width * height);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_image> <output_image>\n", argv[0]);
        return 1;
    }

    load_image(argv[1]);
    invert_image();
    grayscale_image();
    blur_image();
    sharpen_image();
    save_image(argv[2]);

    return 0;
}
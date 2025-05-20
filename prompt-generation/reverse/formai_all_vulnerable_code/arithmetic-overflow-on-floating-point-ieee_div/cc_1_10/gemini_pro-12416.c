//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IMG_WIDTH  256
#define IMG_HEIGHT 256

typedef struct {
    unsigned char r, g, b;
} pixel_t;

pixel_t img[IMG_HEIGHT][IMG_WIDTH];

void load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fread(img, sizeof(pixel_t), IMG_WIDTH * IMG_HEIGHT, fp);
    fclose(fp);
}

void save_image(const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fwrite(img, sizeof(pixel_t), IMG_WIDTH * IMG_HEIGHT, fp);
    fclose(fp);
}

void blur_image(float sigma) {
    float kernel[5][5];
    float sum = 0.0f;

    // Create a Gaussian kernel
    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            kernel[i + 2][j + 2] = exp(-(i * i + j * j) / (2 * sigma * sigma)) / (2 * M_PI * sigma * sigma);
            sum += kernel[i + 2][j + 2];
        }
    }

    // Normalize the kernel
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            kernel[i][j] /= sum;
        }
    }

    // Apply the kernel to the image
    pixel_t new_img[IMG_HEIGHT][IMG_WIDTH];
    for (int i = 0; i < IMG_HEIGHT; i++) {
        for (int j = 0; j < IMG_WIDTH; j++) {
            float r = 0.0f, g = 0.0f, b = 0.0f;
            for (int k = -2; k <= 2; k++) {
                for (int l = -2; l <= 2; l++) {
                    int x = j + k, y = i + l;
                    if (x >= 0 && x < IMG_WIDTH && y >= 0 && y < IMG_HEIGHT) {
                        r += kernel[k + 2][l + 2] * img[y][x].r;
                        g += kernel[k + 2][l + 2] * img[y][x].g;
                        b += kernel[k + 2][l + 2] * img[y][x].b;
                    }
                }
            }
            new_img[i][j].r = (unsigned char)r;
            new_img[i][j].g = (unsigned char)g;
            new_img[i][j].b = (unsigned char)b;
        }
    }

    // Copy the new image into the original image
    for (int i = 0; i < IMG_HEIGHT; i++) {
        for (int j = 0; j < IMG_WIDTH; j++) {
            img[i][j] = new_img[i][j];
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_image> <output_image> [sigma]\n", argv[0]);
        exit(1);
    }

    load_image(argv[1]);

    float sigma = 1.0f;
    if (argc >= 4) {
        sigma = atof(argv[3]);
    }

    blur_image(sigma);

    save_image(argv[2]);

    return 0;
}
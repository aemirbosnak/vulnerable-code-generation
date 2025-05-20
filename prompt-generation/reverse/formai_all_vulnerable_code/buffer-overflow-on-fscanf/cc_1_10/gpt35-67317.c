//FormAI DATASET v1.0 Category: Image Editor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 2000 // Max size of image
#define MAX_FILTER 31 // Max size of filter

// Function prototypes
void loadPPM(char filename[], int image[MAX_SIZE][MAX_SIZE], int *height, int *width);
void savePPM(char filename[], int image[MAX_SIZE][MAX_SIZE], int height, int width);
void brightness(int image[MAX_SIZE][MAX_SIZE], int height, int width, int value);
void contrast(int image[MAX_SIZE][MAX_SIZE], int height, int width, float value);
void grayscale(int image[MAX_SIZE][MAX_SIZE], int height, int width);
void sepia(int image[MAX_SIZE][MAX_SIZE], int height, int width);
void flipHorizontal(int image[MAX_SIZE][MAX_SIZE], int height, int width);
void flipVertical(int image[MAX_SIZE][MAX_SIZE], int height, int width);
void negative(int image[MAX_SIZE][MAX_SIZE], int height, int width);
void blur(int image[MAX_SIZE][MAX_SIZE], int height, int width, int filterSize);
void sharpen(int image[MAX_SIZE][MAX_SIZE], int height, int width, int filterSize);

int main() {
    int image[MAX_SIZE][MAX_SIZE]; // 2D array to store image data
    int height, width; // Image height and width

    char filename[30] = "input.ppm";
    loadPPM(filename, image, &height, &width);

    // Apply image processing effects
    brightness(image, height, width, 50);
    contrast(image, height, width, 1.5);
    grayscale(image, height, width);
    sepia(image, height, width);
    flipHorizontal(image, height, width);
    flipVertical(image, height, width);
    negative(image, height, width);
    blur(image, height, width, 3);
    sharpen(image, height, width, 5);

    strcpy(filename, "output.ppm");
    savePPM(filename, image, height, width);

    printf("Image processing complete!\n");
    return 0;
}

/**
 * Loads a PPM image file and stores it in the given 2D array.
 */
void loadPPM(char filename[], int image[MAX_SIZE][MAX_SIZE], int *height, int *width) {
    FILE *fp;
    int maxValue;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: file not found.\n");
        exit(EXIT_FAILURE);
    }

    char type[3];
    fscanf(fp, "%s", type);
    if (strcmp(type, "P3") != 0) {
        printf("Error: file format not supported.\n");
        exit(EXIT_FAILURE);
    }

    fscanf(fp, "%d %d\n", width, height);
    fscanf(fp, "%d\n", &maxValue);

    for (int i = 0; i < *height; i++) {
        for (int j = 0; j < *width; j++) {
            int r, g, b;
            fscanf(fp, "%d %d %d ", &r, &g, &b);
            image[i][j] = (r << 16) + (g << 8) + b; // Pack RGB values into a single integer
        }
    }

    fclose(fp);
}

/**
 * Saves the given 2D array as a PPM image file.
 */
void savePPM(char filename[], int image[MAX_SIZE][MAX_SIZE], int height, int width) {
    FILE *fp;

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: file not found.\n");
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "P3\n");
    fprintf(fp, "%d %d\n", width, height);
    fprintf(fp, "255\n");

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int color = image[i][j];
            int r = (color >> 16) & 0xFF;
            int g = (color >> 8) & 0xFF;
            int b = color & 0xFF;
            fprintf(fp, "%d %d %d ", r, g, b);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

/**
 * Increases or decreases the brightness of the image by the given value.
 */
void brightness(int image[MAX_SIZE][MAX_SIZE], int height, int width, int value) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int color = image[i][j];
            int r = (color >> 16) & 0xFF;
            int g = (color >> 8) & 0xFF;
            int b = color & 0xFF;

            r += value;
            g += value;
            b += value;

            // Clamp values to 0-255 range
            r = r > 255 ? 255 : r < 0 ? 0 : r;
            g = g > 255 ? 255 : g < 0 ? 0 : g;
            b = b > 255 ? 255 : b < 0 ? 0 : b;

            image[i][j] = (r << 16) + (g << 8) + b;
        }
    }
}

/**
 * Increases or decreases the contrast of the image by the given value.
 */
void contrast(int image[MAX_SIZE][MAX_SIZE], int height, int width, float value) {
    float factor = (259 * (value + 255)) / (255 * (259 - value));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int color = image[i][j];
            int r = (color >> 16) & 0xFF;
            int g = (color >> 8) & 0xFF;
            int b = color & 0xFF;

            r = factor * (r - 128) + 128;
            g = factor * (g - 128) + 128;
            b = factor * (b - 128) + 128;

            // Clamp values to 0-255 range
            r = r > 255 ? 255 : r < 0 ? 0 : r;
            g = g > 255 ? 255 : g < 0 ? 0 : g;
            b = b > 255 ? 255 : b < 0 ? 0 : b;

            image[i][j] = (r << 16) + (g << 8) + b;
        }
    }
}

/**
 * Converts the image to grayscale.
 */
void grayscale(int image[MAX_SIZE][MAX_SIZE], int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int color = image[i][j];
            int r = (color >> 16) & 0xFF;
            int g = (color >> 8) & 0xFF;
            int b = color & 0xFF;

            // Calculate grayscale value using weighted average
            int gray = 0.21 * r + 0.72 * g + 0.07 * b;

            image[i][j] = (gray << 16) + (gray << 8) + gray;
        }
    }
}

/**
 * Applies a sepia filter to the image.
 */
void sepia(int image[MAX_SIZE][MAX_SIZE], int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int color = image[i][j];
            int r = (color >> 16) & 0xFF;
            int g = (color >> 8) & 0xFF;
            int b = color & 0xFF;

            // Calculate new values using sepia formula
            int tr = (int)(0.393 * r + 0.769 * g + 0.189 * b);
            int tg = (int)(0.349 * r + 0.686 * g + 0.168 * b);
            int tb = (int)(0.272 * r + 0.534 * g + 0.131 * b);

            // Clamp values to 0-255 range
            tr = tr > 255 ? 255 : tr < 0 ? 0 : tr;
            tg = tg > 255 ? 255 : tg < 0 ? 0 : tg;
            tb = tb > 255 ? 255 : tb < 0 ? 0 : tb;

            image[i][j] = (tr << 16) + (tg << 8) + tb;
        }
    }
}

/**
 * Flips the image horizontally.
 */
void flipHorizontal(int image[MAX_SIZE][MAX_SIZE], int height, int width) {
    int temp[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j] = temp[i][width - j - 1];
        }
    }
}

/**
 * Flips the image vertically.
 */
void flipVertical(int image[MAX_SIZE][MAX_SIZE], int height, int width) {
    int temp[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j] = temp[height - i - 1][j];
        }
    }
}

/**
 * Inverts the colors of the image.
 */
void negative(int image[MAX_SIZE][MAX_SIZE], int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int color = image[i][j];
            int r = (color >> 16) & 0xFF;
            int g = (color >> 8) & 0xFF;
            int b = color & 0xFF;

            // Invert colors
            r = 255 - r;
            g = 255 - g;
            b = 255 - b;

            image[i][j] = (r << 16) + (g << 8) + b;
        }
    }
}

/**
 * Applies a Gaussian blur filter to the image.
 */
void blur(int image[MAX_SIZE][MAX_SIZE], int height, int width, int filterSize) {
    int filter[MAX_FILTER][MAX_FILTER];
    int halfSize = filterSize / 2;

    // Create Gaussian filter
    for (int i = 0; i < filterSize; i++) {
        for (int j = 0; j < filterSize; j++) {
            float x = i - halfSize;
            float y = j - halfSize;
            float exponent = -(x * x + y * y) / (2 * 1.0 * 1.0);
            float value = (1.0 / (2 * 3.14159 * 1.0)) * exp(exponent);
            filter[i][j] = (int) value;
        }
    }

    // Normalize filter
    int sum = 0;
    for (int i = 0; i < filterSize; i++) {
        for (int j = 0; j < filterSize; j++) {
            sum += filter[i][j];
        }
    }

    for (int i = 0; i < filterSize; i++) {
        for (int j = 0; j < filterSize; j++) {
            filter[i][j] /= sum;
        }
    }

    // Apply filter to image
    int temp[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = halfSize; i < height - halfSize; i++) {
        for (int j = halfSize; j < width - halfSize; j++) {
            int sumR = 0, sumG = 0, sumB = 0;
            for (int ki = 0; ki < filterSize; ki++) {
                for (int kj = 0; kj < filterSize; kj++) {
                    int color = temp[i + ki - halfSize][j + kj - halfSize];
                    sumR += (color >> 16) & 0xFF * filter[ki][kj];
                    sumG += (color >> 8) & 0xFF * filter[ki][kj];
                    sumB += color & 0xFF * filter[ki][kj];
                }
            }
            image[i][j] = (sumR << 16) + (sumG << 8) + sumB;
        }
    }
}

/**
 * Applies a sharpen filter to the image.
 */
void sharpen(int image[MAX_SIZE][MAX_SIZE], int height, int width, int filterSize) {
    int filter[MAX_FILTER][MAX_FILTER];
    int halfSize = filterSize / 2;

    // Create sharpen filter
    for (int i = 0; i < filterSize; i++) {
        for (int j = 0; j < filterSize; j++) {
            if (i == halfSize && j == halfSize) {
                filter[i][j] = 2;
            } else {
                filter[i][j] = -1;
            }
        }
    }

    // Apply filter to image
    int temp[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = halfSize; i < height - halfSize; i++) {
        for (int j = halfSize; j < width - halfSize; j++) {
            int sumR = 0, sumG = 0, sumB = 0;
            for (int ki = 0; ki < filterSize; ki++) {
                for (int kj = 0; kj < filterSize; kj++) {
                    int color = temp[i + ki - halfSize][j + kj - halfSize];
                    sumR += (color >> 16) & 0xFF * filter[ki][kj];
                    sumG += (color >> 8) & 0xFF * filter[ki][kj];
                    sumB += color & 0xFF * filter[ki][kj];
                }
            }
            // Clamp values to 0-255 range
            sumR = sumR > 255 ? 255 : sumR < 0 ? 0 : sumR;
            sumG = sumG > 255 ? 255 : sumG < 0 ? 0 : sumG;
            sumB = sumB > 255 ? 255 : sumB < 0 ? 0 : sumB;

            image[i][j] = (sumR << 16) + (sumG << 8) + sumB;
        }
    }
}
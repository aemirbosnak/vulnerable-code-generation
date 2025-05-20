//FormAI DATASET v1.0 Category: Image Editor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

/**
 * This program takes an input image and applies various mathematical 
 * transformations to it, resulting in a unique edited image.
 */

// Function to read image file and store pixel values in a 2D array
void readImageFile(char *filename, int **imageArray, int *rows, int *columns) {
    FILE *file = fopen(filename, "r");

    if (!file) {
        printf("Error: Unable to open input image file!\n");
        exit(1);
    }

    fscanf(file, "%d %d", rows, columns);

    *imageArray = (int*) malloc((*rows) * (*columns) * sizeof(int));

    for (int i = 0; i < (*rows) * (*columns); i++) {
        fscanf(file, "%d", (*imageArray) + i);
    }

    fclose(file);
}

// Function to write pixel values to output image file
void writeImageFile(char *filename, int **imageArray, int rows, int columns) {
    FILE *file = fopen(filename, "w");

    if (!file) {
        printf("Error: Unable to open output image file!\n");
        exit(1);
    }

    fprintf(file, "%d %d\n", rows, columns);

    for (int i = 0; i < rows * columns; i++) {
        fprintf(file, "%d ", (*imageArray)[i]);
        if (i % columns == columns - 1) fprintf(file, "\n");
    }

    fclose(file);
}

// Function to apply a negative transformation to the image
void applyNegative(int **imageArray, int rows, int columns) {
    for (int i = 0; i < rows * columns; i++) {
        (*imageArray)[i] = 255 - (*imageArray)[i];
    }
}

// Function to apply a logarithmic transformation to the image
void applyLogarithmic(int **imageArray, int rows, int columns) {
    double c = 255 / log10(1 + 255);

    for (int i = 0; i < rows * columns; i++) {
        (*imageArray)[i] = (int)(c * log10((*imageArray)[i] + 1));
    }
}

// Function to apply a power transformation to the image
void applyPower(int **imageArray, int rows, int columns, double gamma) {
    double c = 255 / pow(255, gamma);

    for (int i = 0; i < rows * columns; i++) {
        (*imageArray)[i] = (int)(c * pow((*imageArray)[i], gamma));
    }
}

// Function to apply a discrete Fourier transform to the image
void applyDFT(int **imageArray, int rows, int columns) {
    double real, imag;
    int k, l;
    int *newArray = (int*) malloc(rows * columns * sizeof(int));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            real = imag = 0;

            for (int x = 0; x < rows; x++) {
                for (int y = 0; y < columns; y++) {
                    k = x * i;
                    l = y * j;
                    real += (*imageArray)[x * columns + y] * cos(2 * PI * (k + l) / (double)(rows + columns));
                    imag -= (*imageArray)[x * columns + y] * sin(2 * PI * (k + l) / (double)(rows + columns));
                }
            }

            newArray[i * columns + j] = sqrt(real * real + imag * imag) / (rows * columns);
        }
    }

    *imageArray = newArray;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_image> <output_image>\n", argv[0]);
        exit(1);
    }

    int rows, columns;
    int *imageArray;

    readImageFile(argv[1], &imageArray, &rows, &columns);

    // Apply various transformations to the image
    applyNegative(&imageArray, rows, columns);
    applyLogarithmic(&imageArray, rows, columns);
    applyPower(&imageArray, rows, columns, 0.5);
    applyDFT(&imageArray, rows, columns);

    writeImageFile(argv[2], &imageArray, rows, columns);

    free(imageArray);
    return 0;
}
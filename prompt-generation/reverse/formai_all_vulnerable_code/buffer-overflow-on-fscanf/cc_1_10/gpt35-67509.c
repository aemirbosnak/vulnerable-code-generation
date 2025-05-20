//FormAI DATASET v1.0 Category: Image compression ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IMAGE_SIZE 1024
#define MAX_PIXEL_VALUE 255

struct Image {
    int width;
    int height;
    int **pixels;
};

void printImage(struct Image img) {
    for(int i = 0; i < img.height; i++) {
        for(int j = 0; j < img.width; j++) {
            printf("%d ", img.pixels[i][j]);
        }
        printf("\n");
    }
}

struct Image loadImage(char *filename) {
    FILE *file;

    file = fopen(filename, "r");

    struct Image img;

    fscanf(file, "%d", &img.width);
    fscanf(file, "%d", &img.height);

    img.pixels = (int **) malloc(sizeof(int *) * img.height);
    for(int i = 0; i < img.height; i++) {
        img.pixels[i] = (int *) malloc(sizeof(int) * img.width);
        for(int j = 0; j < img.width; j++) {
            fscanf(file, "%d", &img.pixels[i][j]);
        }
    }

    fclose(file);

    return img;
}

void saveImage(struct Image img, char *filename) {
    FILE *file;

    file = fopen(filename, "w");

    fprintf(file, "%d\n%d\n", img.width, img.height);

    for(int i = 0; i < img.height; i++) {
        for(int j = 0; j < img.width; j++) {
            fprintf(file, "%d ", img.pixels[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

struct Image compressImage(struct Image img, int quality) {
    struct Image compressedImg;
    compressedImg.width = img.width;
    compressedImg.height = img.height;

    int **dctCoefficients = (int **) malloc(sizeof(int *) * img.height);
    for(int i = 0; i < img.height; i++) {
        dctCoefficients[i] = (int *) malloc(sizeof(int) * img.width);
    }

    // perform 2D DCT for each 8x8 block of the image
    for(int i = 0; i < img.height; i += 8) {
        for(int j = 0; j < img.width; j += 8) {
            for(int u = 0; u < 8; u++) {
                for(int v = 0; v < 8; v++) {
                    double cu = u == 0 ? 1.0 / sqrt(2) : 1;
                    double cv = v == 0 ? 1.0 / sqrt(2) : 1;
                    double sum = 0;

                    for(int x = 0; x < 8; x++) {
                        for(int y = 0; y < 8; y++) {
                            sum += img.pixels[i + x][j + y] * cos(((2 * x + 1) * u * M_PI) / 16) * cos(((2 * y + 1) * v * M_PI) / 16);
                        }
                    }

                    dctCoefficients[i + u][j + v] = round(((cu * cv) / 4.0) * sum);
                }
            }
        }
    }

    // set quality level by scaling down high frequency coefficients
    double scalar = 5000.0 / quality;

    for(int i = 0; i < img.height; i += 8) {
        for(int j = 0; j < img.width; j += 8) {
            for(int u = 0; u < 8; u++) {
                for(int v = 0; v < 8; v++) {
                    if((u + v) >= quality) {
                        dctCoefficients[i + u][j + v] /= (int) scalar;
                    }
                }
            }
        }
    }

    // perform inverse 2D DCT for each 8x8 block of the image
    compressedImg.pixels = (int **) malloc(sizeof(int *) * img.height);
    for(int i = 0; i < img.height; i++) {
        compressedImg.pixels[i] = (int *) malloc(sizeof(int) * img.width);
    }

    for(int i = 0; i < img.height; i += 8) {
        for(int j = 0; j < img.width; j += 8) {
            for(int x = 0; x < 8; x++) {
                for(int y = 0; y < 8; y++) {
                    double sum = 0;

                    for(int u = 0; u < 8; u++) {
                        for(int v = 0; v < 8; v++) {
                            double cu = u == 0 ? 1.0 / sqrt(2) : 1;
                            double cv = v == 0 ? 1.0 / sqrt(2) : 1;

                            if((u + v) >= quality) {
                                continue;
                            }

                            sum += ((cu * cv) / 4.0) * dctCoefficients[i + u][j + v] * cos(((2 * x + 1) * u * M_PI) / 16) * cos(((2 * y + 1) * v * M_PI) / 16);
                        }
                    }

                    int pixelValue = round(sum + 128);
                    pixelValue = pixelValue < 0 ? 0 : pixelValue;
                    pixelValue = pixelValue > MAX_PIXEL_VALUE ? MAX_PIXEL_VALUE : pixelValue;
                    compressedImg.pixels[i + x][j + y] = pixelValue;
                }
            }
        }
    }

    // deallocate memory
    for(int i = 0; i < img.height; i++) {
        free(dctCoefficients[i]);
    }
    free(dctCoefficients);

    return compressedImg;
}

int main() {
    struct Image img = loadImage("inputimage.txt");
    printf("Original Image:\n");
    printImage(img);

    struct Image compressedImg = compressImage(img, 50);
    printf("Compressed Image:\n");
    printImage(compressedImg);

    saveImage(compressedImg, "compressedimage.txt");

    // deallocate memory
    for(int i = 0; i < img.height; i++) {
        free(img.pixels[i]);
        free(compressedImg.pixels[i]);
    }
    free(img.pixels);
    free(compressedImg.pixels);

    return 0;
}
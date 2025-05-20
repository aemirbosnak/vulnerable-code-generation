//FormAI DATASET v1.0 Category: Image compression ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_COLOR 255
#define BLOCK_SIZE 8

// Function for image compression using DCT
void compress_image(int width, int height, int** image) {
    int i, j, k, l, u, v;
    int dct_matrix[BLOCK_SIZE][BLOCK_SIZE];
    int dct_values[BLOCK_SIZE][BLOCK_SIZE];
    double c_u, c_v, sum;

    // Iterate through the image in 8x8 blocks
    for (i = 0; i < height; i += BLOCK_SIZE) {
        for (j = 0; j < width; j += BLOCK_SIZE) {

            // Compute DCT values for each block
            for (u = 0; u < BLOCK_SIZE; u++) {
                for (v = 0; v < BLOCK_SIZE; v++) {
                    if (u == 0) c_u = 1.0 / sqrt(2);
                    else c_u = 1.0;
                    if (v == 0) c_v = 1.0 / sqrt(2);
                    else c_v = 1.0;

                    sum = 0.0;
                    for (k = 0; k < BLOCK_SIZE; k++) {
                        for (l = 0; l < BLOCK_SIZE; l++) {
                            sum += image[i + k][j + l] * cos((2 * k + 1) * u * M_PI / 16) * cos((2 * l + 1) * v * M_PI / 16);
                        }
                    }
                    dct_values[u][v] = round((c_u * c_v * sum) / 4);
                }
            }

            // Set low-frequency coefficients to zero for compression
            for (u = 0; u < BLOCK_SIZE; u++) {
                for (v = 0; v < BLOCK_SIZE; v++) {
                    if (u + v > 10) dct_values[u][v] = 0;
                }
            }

            // Compute inverse DCT and store compressed image
            for (k = 0; k < BLOCK_SIZE; k++) {
                for (l = 0; l < BLOCK_SIZE; l++) {
                    sum = 0.0;
                    for (u = 0; u < BLOCK_SIZE; u++) {
                        for (v = 0; v < BLOCK_SIZE; v++) {
                            if (u == 0) c_u = 1.0 / sqrt(2);
                            else c_u = 1.0;
                            if (v == 0) c_v = 1.0 / sqrt(2);
                            else c_v = 1.0;

                            sum += c_u * c_v * dct_values[u][v] * cos((2 * k + 1) * u * M_PI / 16) * cos((2 * l + 1) * v * M_PI / 16);
                        }
                    }
                    dct_matrix[k][l] = round(sum / 4);
                }
            }

            // Store compressed image in original image matrix
            for (k = 0; k < BLOCK_SIZE; k++) {
                for (l = 0; l < BLOCK_SIZE; l++) {
                    image[i + k][j + l] = dct_matrix[k][l];
                }
            }
        }
    }

    // Write compressed image to file
    FILE* fp = fopen("compressed_image.txt", "w");
    fprintf(fp, "%d %d\n", width, height);
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fprintf(fp, "%d ", image[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

// Function for reading image from file
int** read_image(char* filename, int* width, int* height) {
    int i, j;
    FILE* fp = fopen(filename, "r");
    fscanf(fp, "%d %d\n", width, height);
    int** image = (int**)malloc((*height) * sizeof(int*));
    for (i = 0; i < *height; i++) {
        image[i] = (int*)malloc((*width) * sizeof(int));
        for (j = 0; j < *width; j++) {
            fscanf(fp, "%d ", &image[i][j]);
        }
    }
    fclose(fp);
    return image;
}

// Main function
int main() {
    int width, height;
    int** image = read_image("image.txt", &width, &height);
    compress_image(width, height, image);
    return 0;
}
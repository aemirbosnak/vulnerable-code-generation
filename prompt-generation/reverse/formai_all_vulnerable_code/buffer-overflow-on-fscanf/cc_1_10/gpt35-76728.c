//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BLOCK_SIZE 8
#define WATERMARK_SIZE 8

// DCT matrix
float C[BLOCK_SIZE][BLOCK_SIZE];
float CT[BLOCK_SIZE][BLOCK_SIZE];

// Watermark image
int watermark[WATERMARK_SIZE][WATERMARK_SIZE] = {
    {1, 0, 1, 1, 0, 1, 0, 1},
    {0, 1, 1, 0, 1, 0, 1, 1},
    {0, 0, 1, 0, 1, 1, 0, 1},
    {0, 1, 0, 1, 1, 1, 1, 0},
    {1, 1, 0, 1, 0, 0, 1, 1},
    {0, 1, 1, 1, 0, 1, 1, 0},
    {1, 0, 1, 0, 1, 0, 1, 1},
    {1, 1, 0, 1, 0, 1, 0, 1}
};

// Image blocks
int blocks[512][512];

// Function prototypes
void init_dct_matrix();
void init_blocks();
void embed_watermark();
void extract_watermark();

int main()
{
    init_dct_matrix();
    init_blocks();
    embed_watermark();
    extract_watermark();
    return 0;
}

// Initialize DCT matrix
void init_dct_matrix()
{
    int i, j;
    float alpha, beta;

    for (i = 0; i < BLOCK_SIZE; i++) {
        alpha = (i == 0) ? sqrt(1.0 / BLOCK_SIZE) : sqrt(2.0 / BLOCK_SIZE);
        for (j = 0; j < BLOCK_SIZE; j++) {
            beta  = (j == 0) ? sqrt(1.0 / BLOCK_SIZE) : sqrt(2.0 / BLOCK_SIZE);
            C[i][j]  = alpha * beta * cos(((2.0 * i + 1.0) * j * M_PI) / (2.0 * BLOCK_SIZE));
            CT[j][i] = C[i][j];
        }
    }
}

// Initialize image blocks
void init_blocks()
{
    int i, j, x, y;
    FILE *fp;

    // Load image data
    fp = fopen("image.dat", "r");
    for (i = 0; i < 512; i++) {
        for (j = 0; j < 512; j++) {
            fscanf(fp, "%d", &blocks[i][j]);
        }
    }
    fclose(fp);

    // Partition image into blocks
    for (i = 0; i < 512; i += BLOCK_SIZE) {
        for (j = 0; j < 512; j += BLOCK_SIZE) {
            // Transform block using DCT matrix
            for (x = i; x < i + BLOCK_SIZE; x++) {
                for (y = j; y < j + BLOCK_SIZE; y++) {
                    blocks[x][y] *= C[x % BLOCK_SIZE][y % BLOCK_SIZE];
                }
            }
        }
    }
}

// Embed watermark into image
void embed_watermark()
{
    int i, j, x, y, index, bit;
    float coef;

    // Embed watermark into blocks
    for (i = 0; i < 512; i += BLOCK_SIZE) {
        for (j = 0; j < 512; j += BLOCK_SIZE) {
            // Find maximum coefficient
            coef = 0.0;
            for (x = i; x < i + BLOCK_SIZE; x++) {
                for (y = j; y < j + BLOCK_SIZE; y++) {
                    if (blocks[x][y] > coef) {
                        coef = blocks[x][y];
                    }
                }
            }
            // Embed watermark bits into lowest frequency coefficients
            index = 0;
            for (x = i; x < i + BLOCK_SIZE; x++) {
                for (y = j; y < j + BLOCK_SIZE; y++) {
                    if (blocks[x][y] == coef) {
                        bit = (index < WATERMARK_SIZE) ? watermark[index / WATERMARK_SIZE][index % WATERMARK_SIZE] : 0;
                        blocks[x][y] += bit * (coef / 4.0);
                        index++;
                    }
                }
            }
        }
    }

    // Save watermarked image data
    FILE *fp = fopen("watermarked.dat", "w");
    for (i = 0; i < 512; i++) {
        for (j = 0; j < 512; j++) {
            fprintf(fp, "%d ", blocks[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

// Extract watermark from image
void extract_watermark()
{
    int i, j, x, y, index, bit;
    float coef, threshold;

    // Load watermarked image data
    FILE *fp = fopen("watermarked.dat", "r");
    for (i = 0; i < 512; i++) {
        for (j = 0; j < 512; j++) {
            fscanf(fp, "%d", &blocks[i][j]);
        }
    }
    fclose(fp);

    // Extract watermark from blocks
    index = 0;
    for (i = 0; i < 512; i += BLOCK_SIZE) {
        for (j = 0; j < 512; j += BLOCK_SIZE) {
            // Find maximum coefficient
            coef = 0.0;
            for (x = i; x < i + BLOCK_SIZE; x++) {
                for (y = j; y < j + BLOCK_SIZE; y++) {
                    if (blocks[x][y] > coef) {
                        coef = blocks[x][y];
                    }
                }
            }
            // Set threshold
            threshold = coef / 4.0;
            // Extract watermark bits from lowest frequency coefficients
            for (x = i; x < i + BLOCK_SIZE; x++) {
                for (y = j; y < j + BLOCK_SIZE; y++) {
                    if (blocks[x][y] >= threshold) {
                        bit = (index < WATERMARK_SIZE) ? watermark[index / WATERMARK_SIZE][index % WATERMARK_SIZE] : 0;
                        if (bit != (int)((blocks[x][y] - threshold) / threshold)) {
                            printf("Watermark verification failed!\n");
                            return;
                        }
                        index++;
                    }
                }
            }
        }
    }
    printf("Watermark verification successful!\n");
}
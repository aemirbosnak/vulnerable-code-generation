//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512
#define MAX_VALUE 255
#define THRESHOLD 128
#define BLOCK_SIZE 8
#define NUM_BLOCKS (WIDTH / BLOCK_SIZE) * (HEIGHT / BLOCK_SIZE)
#define NUM_ROWS (HEIGHT / BLOCK_SIZE)
#define NUM_COLS (WIDTH / BLOCK_SIZE)

typedef struct {
    int row;
    int col;
    int value;
} block_t;

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <image_in> <image_out>\n", argv[0]);
        return 1;
    }

    FILE *fp_in = fopen(argv[1], "rb");
    if (fp_in == NULL) {
        printf("Error: cannot open input file.\n");
        return 1;
    }

    FILE *fp_out = fopen(argv[2], "wb");
    if (fp_out == NULL) {
        printf("Error: cannot open output file.\n");
        return 1;
    }

    int num_blocks = NUM_BLOCKS;
    block_t *blocks = malloc(num_blocks * sizeof(block_t));

    int row, col, i;
    for (row = 0; row < NUM_ROWS; row++) {
        for (col = 0; col < NUM_COLS; col++) {
            blocks[i].row = row;
            blocks[i].col = col;

            int sum = 0;
            for (int j = 0; j < BLOCK_SIZE; j++) {
                for (int k = 0; k < BLOCK_SIZE; k++) {
                    sum += (int)fgetc(fp_in);
                }
            }

            blocks[i].value = sum / (BLOCK_SIZE * BLOCK_SIZE);

            if (blocks[i].value > THRESHOLD) {
                blocks[i].value = MAX_VALUE;
            } else if (blocks[i].value < THRESHOLD - 1) {
                blocks[i].value = 0;
            }

            i++;
        }
    }

    for (i = 0; i < num_blocks; i++) {
        fprintf(fp_out, "%d %d %d\n", blocks[i].row, blocks[i].col, blocks[i].value);
    }

    fclose(fp_in);
    fclose(fp_out);

    printf("Watermarking completed.\n");

    return 0;
}
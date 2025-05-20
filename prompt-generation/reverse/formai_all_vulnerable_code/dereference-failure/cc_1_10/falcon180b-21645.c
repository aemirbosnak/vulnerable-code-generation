//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define WIDTH 512
#define HEIGHT 512
#define BLOCK_SIZE 16
#define NUM_BLOCKS (WIDTH / BLOCK_SIZE) * (HEIGHT / BLOCK_SIZE)
#define MAX_IMAGE_SIZE (NUM_BLOCKS * BLOCK_SIZE * BLOCK_SIZE)

void add_watermark(unsigned char* image, int watermark_size, char* watermark) {
    int x, y;
    for (y = 0; y < HEIGHT; y += BLOCK_SIZE) {
        for (x = 0; x < WIDTH; x += BLOCK_SIZE) {
            int index = (y / BLOCK_SIZE) * WIDTH / BLOCK_SIZE + x / BLOCK_SIZE;
            int watermark_index = (index % watermark_size) * BLOCK_SIZE / watermark_size;
            int offset = (index % watermark_size) * BLOCK_SIZE / watermark_size * BLOCK_SIZE;
            for (int i = 0; i < BLOCK_SIZE; i++) {
                for (int j = 0; j < BLOCK_SIZE; j++) {
                    if (watermark[watermark_index] == '1') {
                        image[(y + i) * WIDTH + x + j] ^= 0xff;
                    }
                    watermark_index++;
                    if (watermark_index == watermark_size) {
                        watermark_index = 0;
                    }
                }
            }
        }
    }
}

int main() {
    srand(time(NULL));
    unsigned char* image = malloc(MAX_IMAGE_SIZE);
    memset(image, 0, MAX_IMAGE_SIZE);
    int watermark_size = rand() % (WIDTH / BLOCK_SIZE) + 1;
    char* watermark = malloc(watermark_size * 2 + 1);
    memset(watermark, '0', watermark_size * 2 + 1);
    for (int i = 0; i < watermark_size; i++) {
        watermark[i * 2] = rand() % 2 == 0? '0' : '1';
    }
    add_watermark(image, watermark_size, watermark);
    FILE* fp = fopen("watermarked.bmp", "wb");
    fwrite(image, 1, MAX_IMAGE_SIZE, fp);
    fclose(fp);
    printf("Watermarked image saved as watermarked.bmp\n");
    return 0;
}
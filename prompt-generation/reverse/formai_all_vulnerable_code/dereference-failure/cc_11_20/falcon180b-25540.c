//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define W 512
#define H 512
#define BITS 8

int main() {

    FILE *in, *out;
    unsigned char *img, *watermark, *temp, *ptr;
    int i, j, k, count = 0, size;

    in = fopen("input.bmp", "rb");
    if (in == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    fseek(in, 18, SEEK_SET);
    fread(&size, sizeof(int), 1, in);

    img = malloc(size);
    watermark = malloc(size);

    fread(img, sizeof(unsigned char), size, in);
    fclose(in);

    for (i = 0; i < size; i++) {
        watermark[i] = (unsigned char) rand() % BITS;
    }

    out = fopen("output.bmp", "wb");
    if (out == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }

    fwrite("BM", sizeof(char), 2, out);
    fwrite(&size, sizeof(int), 1, out);

    temp = malloc(size);
    ptr = temp;

    for (i = 0; i < H; i++) {
        for (j = 0; j < W; j++) {
            for (k = 0; k < BITS; k++) {
                if ((img[(i * W + j) * 3 + k / 8] & (1 << (7 - k % 8))) == 0 && watermark[count] == 1) {
                    img[(i * W + j) * 3 + k / 8] |= (1 << (7 - k % 8));
                } else if ((img[(i * W + j) * 3 + k / 8] & (1 << (7 - k % 8))) == 0 && watermark[count] == 0) {
                    img[(i * W + j) * 3 + k / 8] &= ~(1 << (7 - k % 8));
                }
                count++;
                if (count == size) {
                    count = 0;
                }
            }
        }
    }

    fwrite(img, sizeof(unsigned char), size, out);

    free(img);
    free(watermark);
    free(temp);

    fclose(out);

    printf("Watermarking completed successfully!\n");

    return 0;
}
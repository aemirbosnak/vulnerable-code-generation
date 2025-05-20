//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAR_WIDTH 8
#define CHAR_HEIGHT 12

int main(int argc, char *argv[]) {
    FILE *fp;
    unsigned char header[54];
    int width, height, i, j, k, l, x, y, count;
    unsigned char *data;

    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Error: Cannot open input file.\n");
        exit(1);
    }

    fread(header, 1, 54, fp);
    if (memcmp(header, "BM", 2)!= 0) {
        printf("Error: Input file is not a valid BMP file.\n");
        exit(1);
    }

    width = *(int *)&header[18];
    height = *(int *)&header[22];

    data = malloc(width * height);
    if (data == NULL) {
        printf("Error: Cannot allocate memory.\n");
        exit(1);
    }

    fseek(fp, 54, SEEK_SET);
    fread(data, 1, width * height, fp);
    fclose(fp);

    fp = fopen(argv[2], "w");
    if (fp == NULL) {
        printf("Error: Cannot open output file.\n");
        exit(1);
    }

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            count = 0;
            for (k = 0; k < CHAR_HEIGHT; k++) {
                for (l = 0; l < CHAR_WIDTH; l++) {
                    x = j * CHAR_WIDTH + l;
                    y = i * CHAR_HEIGHT + k;
                    if ((x >= 0) && (x < width) && (y >= 0) && (y < height)) {
                        if (data[y * width + x] < 128) {
                            fprintf(fp, " ");
                        } else {
                            fprintf(fp, "X");
                        }
                    } else {
                        fprintf(fp, " ");
                    }
                }
            }
        }
        fprintf(fp, "\n");
    }

    fclose(fp);

    free(data);

    return 0;
}
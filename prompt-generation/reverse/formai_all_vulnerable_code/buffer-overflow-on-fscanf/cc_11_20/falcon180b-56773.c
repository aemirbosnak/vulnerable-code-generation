//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[]) {

    int i, j, k, l, n, m, p, q, count = 0, sum = 0;
    int image[100][100], watermark[10][10], result[100][100];

    FILE *fp;
    fp = fopen("image.txt", "r");

    if (fp == NULL) {
        printf("Error: File not found\n");
        exit(1);
    }

    for (i = 0; i < 100; i++) {
        for (j = 0; j < 100; j++) {
            fscanf(fp, "%d", &image[i][j]);
        }
    }

    fclose(fp);

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            watermark[i][j] = rand() % 256;
        }
    }

    for (i = 0; i < 100; i++) {
        for (j = 0; j < 100; j++) {
            sum = 0;
            for (k = -1; k <= 1; k++) {
                for (l = -1; l <= 1; l++) {
                    n = i + k;
                    m = j + l;
                    if (n >= 0 && n < 100 && m >= 0 && m < 100) {
                        sum += image[n][m];
                    }
                }
            }

            if (sum >= 128) {
                result[i][j] = watermark[count % 10][0];
            } else {
                result[i][j] = image[i][j];
            }

            count++;
        }
    }

    fp = fopen("watermark.txt", "w");

    if (fp == NULL) {
        printf("Error: File not found\n");
        exit(1);
    }

    for (i = 0; i < 100; i++) {
        for (j = 0; j < 100; j++) {
            fprintf(fp, "%d ", result[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);

    return 0;
}
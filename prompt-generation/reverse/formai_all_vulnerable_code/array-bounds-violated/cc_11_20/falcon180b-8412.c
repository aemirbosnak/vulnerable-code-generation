//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 101

int main() {
    int image[MAX][MAX], n, m, c, d, s, k, sum = 0, count = 0;
    int gs, gd, bs, bd;
    FILE *fp;
    char ch;
    printf("Enter the size of the image: ");
    scanf("%d%d", &n, &m);
    printf("Enter the image elements:\n");
    for (c = 0; c < n; c++) {
        for (d = 0; d < m; d++) {
            do {
                ch = getchar();
            } while (ch!= '0' && ch!= '1');
            if (ch == '0')
                image[c][d] = 0;
            else
                image[c][d] = 1;
        }
        getchar();
    }
    printf("Enter the size of the kernel: ");
    scanf("%d%d", &gs, &gd);
    printf("Enter the size of the block: ");
    scanf("%d%d", &bs, &bd);
    fp = fopen("result.txt", "w");
    if (fp == NULL) {
        printf("Cannot create file\n");
        exit(0);
    }
    for (k = gs; k < n - gd; k++) {
        for (s = gd; s < m - bd; s++) {
            sum = 0;
            for (c = 0; c < gs; c++) {
                for (d = 0; d < gd; d++) {
                    if (image[k + c][s + d] == 1) {
                        count++;
                    }
                }
            }
            if (count >= (gs * gd) / 2) {
                for (c = 0; c < bs; c++) {
                    for (d = 0; d < bd; d++) {
                        if (image[k + c][s + d] == 1) {
                            image[k + c][s + d] = 0;
                        } else {
                            image[k + c][s + d] = 1;
                        }
                    }
                }
            }
        }
    }
    for (c = 0; c < n; c++) {
        for (d = 0; d < m; d++) {
            fprintf(fp, "%d ", image[c][d]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    return 0;
}
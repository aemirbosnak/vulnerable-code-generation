//Falcon-180B DATASET v1.0 Category: Data mining ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, k;
    int data[10][10];
    int n, m;
    int max_val, min_val, sum = 0;
    int count = 0;
    int avg;
    char filename[50];
    FILE *fp;

    printf("Enter the name of the data file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fscanf(fp, "%d %d", &n, &m);

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            fscanf(fp, "%d", &data[i][j]);
        }
    }

    fclose(fp);

    max_val = data[0][0];
    min_val = data[0][0];

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (data[i][j] > max_val) {
                max_val = data[i][j];
            }

            if (data[i][j] < min_val) {
                min_val = data[i][j];
            }

            sum += data[i][j];
        }
    }

    avg = sum / (n * m);

    printf("Max value: %d\n", max_val);
    printf("Min value: %d\n", min_val);
    printf("Average value: %.2f\n", avg);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 1000

int main() {
    int i, j, n;
    double x[N], y[N], sum = 0;
    FILE *fp;

    // Open the input file
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: Cannot open input file\n");
        exit(1);
    }

    // Read the data from the input file
    for (i = 0; i < N; i++) {
        fscanf(fp, "%lf", &x[i]);
        y[i] = sin(x[i]);
    }

    // Close the input file
    fclose(fp);

    // Perform FFT on the data
    for (n = 0; n < N; n++) {
        sum = 0;
        for (i = 0; i < N; i++) {
            sum += y[i] * cos(2 * M_PI * i * n / N);
        }
        y[n] = sum;
    }

    // Write the results to the output file
    fp = fopen("output.txt", "w");
    if (fp == NULL) {
        printf("Error: Cannot open output file\n");
        exit(1);
    }

    for (i = 0; i < N; i++) {
        fprintf(fp, "%lf\n", y[i]);
    }

    // Close the output file
    fclose(fp);

    return 0;
}
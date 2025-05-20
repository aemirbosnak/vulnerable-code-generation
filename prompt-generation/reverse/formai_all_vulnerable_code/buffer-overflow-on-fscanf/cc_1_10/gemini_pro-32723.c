//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    // Check arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open input and output files
    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }
    FILE *output = fopen(argv[2], "w");
    if (output == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Read input file
    int n, m;
    fscanf(input, "%d %d", &n, &m);
    double *x = malloc(n * sizeof(double));
    double *y = malloc(m * sizeof(double));
    for (int i = 0; i < n; i++) {
        fscanf(input, "%lf", &x[i]);
    }
    for (int i = 0; i < m; i++) {
        fscanf(input, "%lf", &y[i]);
    }
    fclose(input);

    // Compute inner product
    double inner_product = 0.0;
    for (int i = 0; i < n; i++) {
        inner_product += x[i] * y[i];
    }

    // Write output file
    fprintf(output, "%lf\n", inner_product);
    fclose(output);

    // Free memory
    free(x);
    free(y);

    return EXIT_SUCCESS;
}
//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define SIZE 1024

int main(int argc, char *argv[]) {
    FILE *in, *out;
    int i, j, k, l;
    double data[SIZE][SIZE];
    double avg[SIZE];
    double std[SIZE];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        exit(1);
    }

    in = fopen(argv[1], "r");
    if (in == NULL) {
        fprintf(stderr, "Error opening input file.\n");
        exit(1);
    }

    out = fopen(argv[2], "w");
    if (out == NULL) {
        fprintf(stderr, "Error opening output file.\n");
        exit(1);
    }

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            fscanf(in, "%lf", &data[i][j]);
        }
    }

    for (i = 0; i < SIZE; i++) {
        avg[i] = 0.0;
        std[i] = 0.0;
    }

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            avg[i] += data[i][j];
        }
    }

    for (i = 0; i < SIZE; i++) {
        avg[i] /= SIZE;
    }

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            std[i] += (data[i][j] - avg[i]) * (data[i][j] - avg[i]);
        }
    }

    for (i = 0; i < SIZE; i++) {
        std[i] = sqrt(std[i] / (SIZE - 1));
    }

    for (i = 0; i < SIZE; i++) {
        fprintf(out, "%lf %lf\n", avg[i], std[i]);
    }

    fclose(in);
    fclose(out);

    return 0;
}
//MISTRAL-7B DATASET v1.0 Category: Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VALUES 1000

double data[MAX_VALUES];
int n_values = 0;

void read_data_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    double value;
    while (fscanf(file, "%lf", &value) == 1) {
        data[n_values++] = value;
        if (n_values >= MAX_VALUES) {
            fprintf(stderr, "Too many values in file\n");
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
}

double mean(double *data, int n) {
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += data[i];
    }
    return sum / n;
}

double standard_deviation(double *data, int n) {
    double m = mean(data, n);
    double sum_squares = 0;

    for (int i = 0; i < n; ++i) {
        sum_squares += pow(data[i] - m, 2);
    }

    return sqrt(sum_squares / (n - 1));
}

void print_statistics(const char *filename) {
    read_data_from_file(filename);

    printf("File: %s\n", filename);
    printf("Number of values: %d\n", n_values);
    printf("Mean: %.6f\n", mean(data, n_values));
    printf("Standard deviation: %.6f\n", standard_deviation(data, n_values));
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    print_statistics(argv[1]);

    return EXIT_SUCCESS;
}
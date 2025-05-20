//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

int main(void) {
    int n, m;
    printf("Enter the number of rows and columns for the matrix: ");
    scanf("%d %d", &n, &m);

    int matrix[MAX_SIZE][MAX_SIZE];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum += matrix[i][j];
        }
    }

    double mean = (double) sum / (n * m);
    printf("Mean: %.2f\n", mean);

    double variance = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            variance += pow((matrix[i][j] - mean), 2);
        }
    }
    variance /= (n * m);
    printf("Variance: %.2f\n", variance);

    double std_deviation = sqrt(variance);
    printf("Standard Deviation: %.2f\n", std_deviation);

    int max = matrix[0][0];
    int min = matrix[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
        }
    }
    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);

    return 0;
}
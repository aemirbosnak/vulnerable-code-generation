//FormAI DATASET v1.0 Category: Matrix operations ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(0));

    // Generate a random 3x3 matrix
    int matrix[3][3] = {
        {rand() % 10, rand() % 10, rand() % 10},
        {rand() % 10, rand() % 10, rand() % 10},
        {rand() % 10, rand() % 10, rand() % 10}
    };

    printf("Original Matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Calculate the determinant of the matrix
    int det = matrix[0][0] * matrix[1][1] * matrix[2][2] +
              matrix[0][1] * matrix[1][2] * matrix[2][0] +
              matrix[0][2] * matrix[1][0] * matrix[2][1] -
              matrix[0][2] * matrix[1][1] * matrix[2][0] -
              matrix[0][0] * matrix[1][2] * matrix[2][1] -
              matrix[0][1] * matrix[1][0] * matrix[2][2];

    printf("\nDeterminant: %d\n", det);

    // Find the transpose of the matrix
    int transpose[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    printf("\nTranspose:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    // Find the inverse of the matrix
    int inverse[3][3];
    int a = matrix[0][0], b = matrix[0][1], c = matrix[0][2];
    int d = matrix[1][0], e = matrix[1][1], f = matrix[1][2];
    int g = matrix[2][0], h = matrix[2][1], i = matrix[2][2];
    int det_inverted = 1.0 / (a * (e*i-f*h) - b * (d*i-f*g) + c * (d*h-e*g));

    inverse[0][0] = det_inverted * (e*i - f*h);
    inverse[0][1] = det_inverted * (c*h - b*i);
    inverse[0][2] = det_inverted * (b*f - c*e);
    inverse[1][0] = det_inverted * (f*g - d*i);
    inverse[1][1] = det_inverted * (a*i - c*g);
    inverse[1][2] = det_inverted * (c*d - a*f);
    inverse[2][0] = det_inverted * (d*h - e*g);
    inverse[2][1] = det_inverted * (b*g - a*h);
    inverse[2][2] = det_inverted * (a*e - b*d);

    printf("\nInverse:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", inverse[i][j]);
        }
        printf("\n");
    }

    return 0;
}
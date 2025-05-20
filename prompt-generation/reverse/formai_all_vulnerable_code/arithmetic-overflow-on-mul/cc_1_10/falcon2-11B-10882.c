//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3
#define NUM_ELEMENTS 9

int main() {
    srand(time(NULL)); // initialize random number generator

    // create a random matrix of size ROWS x COLS
    int matrix[ROWS][COLS] = {
        {rand(), rand(), rand()},
        {rand(), rand(), rand()},
        {rand(), rand(), rand()}
    };

    // print the matrix
    printf("Random Matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // transpose the matrix
    int transposedMatrix[COLS][ROWS] = {
        {matrix[0][0], matrix[0][1], matrix[0][2]},
        {matrix[1][0], matrix[1][1], matrix[1][2]},
        {matrix[2][0], matrix[2][1], matrix[2][2]}
    };

    // print the transposed matrix
    printf("Transposed Matrix:\n");
    for (int j = 0; j < COLS; j++) {
        for (int i = 0; i < ROWS; i++) {
            printf("%d ", transposedMatrix[j][i]);
        }
        printf("\n");
    }

    // multiply the matrix by a scalar
    int scalar = rand() % 100; // generate a random scalar between 0 and 99

    int productMatrix[COLS][ROWS] = {
        {scalar * transposedMatrix[0][0], scalar * transposedMatrix[0][1], scalar * transposedMatrix[0][2]},
        {scalar * transposedMatrix[1][0], scalar * transposedMatrix[1][1], scalar * transposedMatrix[1][2]},
        {scalar * transposedMatrix[2][0], scalar * transposedMatrix[2][1], scalar * transposedMatrix[2][2]}
    };

    // print the product matrix
    printf("Product Matrix:\n");
    for (int j = 0; j < COLS; j++) {
        for (int i = 0; i < ROWS; i++) {
            printf("%d ", productMatrix[j][i]);
        }
        printf("\n");
    }

    // return 0 to indicate successful execution
    return 0;
}
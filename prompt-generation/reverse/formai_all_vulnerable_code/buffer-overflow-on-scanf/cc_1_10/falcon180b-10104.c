//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define MAX_VALUE 100

int main() {
    int matrix[ROWS][COLS];
    int i, j, choice;

    // Initialize the matrix with random values
    srand(time(NULL));
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % MAX_VALUE;
        }
    }

    // Display the matrix
    printf("The matrix:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Add two matrices\n");
        printf("2. Multiply two matrices\n");
        printf("3. Transpose the matrix\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add two matrices
                break;
            case 2:
                // Multiply two matrices
                break;
            case 3:
                // Transpose the matrix
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
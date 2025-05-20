//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUMBER 1000000
#define MAGIC_NUMBER 42

void print_matrix(int matrix[10][10]);
void print_number(int number);

int main() {
    int matrix[10][10];
    int i, j, k;
    int number;

    // Initialize the matrix with random numbers
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            matrix[i][j] = rand() % MAX_NUMBER;
        }
    }

    // Print the matrix
    print_matrix(matrix);

    // Ask the user to enter a number
    printf("Enter a number: ");
    scanf("%d", &number);

    // Check if the number is magic
    if (number == MAGIC_NUMBER) {
        printf("Congratulations! You found the magic number!\n");
    } else {
        printf("Bummer! The number you entered is not magic :(\n");
    }

    // Print the matrix again, with the numbers in reverse order
    print_matrix(matrix);

    return 0;
}

void print_matrix(int matrix[10][10]) {
    int i, j;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void print_number(int number) {
    printf("%d ", number);
}
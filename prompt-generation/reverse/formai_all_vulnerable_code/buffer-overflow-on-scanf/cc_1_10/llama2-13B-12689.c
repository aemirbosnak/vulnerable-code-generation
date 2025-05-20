//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 10
#define MIN_VALUE 1
#define MAX_VALUE 100

// Function to generate a random number between min and max
int random_number(int min, int max) {
    return (rand() % (max - min)) + min;
}

// Function to print the table
void print_table(int rows, int cols, int values[]) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%3d", values[i * cols + j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols, i, j, value;
    srand(time(NULL));

    // Ask user for row and column count
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    // Allocate memory for the table
    int *values = malloc(rows * cols * sizeof(int));

    // Generate random values for the table
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            value = random_number(MIN_VALUE, MAX_VALUE);
            values[i * cols + j] = value;
        }
    }

    // Print the table
    print_table(rows, cols, values);

    // Free memory
    free(values);

    return 0;
}
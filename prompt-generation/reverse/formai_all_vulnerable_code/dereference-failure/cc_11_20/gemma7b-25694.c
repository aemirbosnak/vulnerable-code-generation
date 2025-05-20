//Gemma-7B DATASET v1.0 Category: Data mining ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the main function
int main() {

    // Allocate memory for a matrix
    int **matrix = (int **)malloc(5 * sizeof(int *));
    for (int i = 0; i < 5; i++) {
        matrix[i] = (int *)malloc(10 * sizeof(int));
    }

    // Initialize the matrix
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            matrix[i][j] = 0;
        }
    }

    // Get the data
    FILE *file = fopen("data.txt", "r");
    char line[1024];
    while (fgets(line, 1024, file) != NULL) {
        // Parse the line
        char *words = strtok(line, " ");
        int i = 0;
        while (words[i] != NULL) {
            int number = atoi(words[i]);
            matrix[number][0]++;
            i++;
        }
    }

    // Calculate the frequency of each item
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            matrix[i][j] = matrix[i][j] / 100 * 100;
        }
    }

    // Print the results
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < 5; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
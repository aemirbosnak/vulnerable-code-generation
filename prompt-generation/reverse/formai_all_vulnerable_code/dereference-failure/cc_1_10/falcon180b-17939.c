//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print the given pattern
void printPattern(int rows, int cols, char pattern[rows][cols]) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%c", pattern[i][j]);
        }
        printf("\n");
    }
}

// Function to generate a random pattern
void generateRandomPattern(int rows, int cols, char pattern[rows][cols]) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            pattern[i][j] = rand() % 10 + '0'; // Generates a random number from 0 to 9
        }
    }
}

int main() {
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Allocate memory dynamically for the pattern
    char **pattern = (char **)malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        pattern[i] = (char *)malloc(cols * sizeof(char));
    }

    // Generate a random pattern
    generateRandomPattern(rows, cols, *pattern);

    // Print the pattern
    printPattern(rows, cols, *pattern);

    // Free the dynamically allocated memory
    for (int i = 0; i < rows; i++) {
        free(pattern[i]);
    }
    free(pattern);

    return 0;
}
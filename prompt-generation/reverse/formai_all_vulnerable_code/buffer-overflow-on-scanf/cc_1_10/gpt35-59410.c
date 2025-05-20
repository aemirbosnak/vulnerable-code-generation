//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Function to generate Fibonacci sequence up to n
void generateFibonacci(int n) {
    int first = 0, second = 1, next;
    printf("\nFibonacci Sequence Up To %d:\n", n);

    for (int i = 1; i <= n; ++i) {
        printf("%d, ", first); // Print current number
        next = first + second; // Calculate next number
        first = second;
        second = next;
    }
}

// Function to generate visual representation of Fibonacci sequence
void visualizeFibonacci(int n) {
    int first = 0, second = 1, next, maxLength = 1, rowCount = 0, colCount = 0, colIndex = 0;
    char** matrix = (char**)malloc(sizeof(char*) * n);

    // Calculate maximum length of number in sequence for formatting purposes
    for (int i = 1; i <= n; ++i) {
        next = first + second; // Calculate next number
        first = second;
        second = next;
        int tempLength = snprintf(NULL, 0, "%d", first); // Get length of number
        if (tempLength > maxLength) maxLength = tempLength; // Update maxLength if needed
    }

    first = second = 1;

    // Populate matrix with Fibonacci sequence numbers
    for (int i = 0; i < n; ++i) {
        matrix[rowCount] = (char*)malloc(sizeof(char) * maxLength);
        sprintf(matrix[rowCount], "%d", first); // Convert number to string and add to matrix

        next = first + second; // Calculate next number
        first = second;
        second = next;

        colIndex++;
        if (colIndex == n) { // Move to next row
            colIndex = 0;
            rowCount++;
        }
    }

    // Print matrix
    printf("\nVisual Representation Of Fibonacci Sequence Up To %d:\n", n);

    for (int i = 0; i <= rowCount; ++i) {
        int columnCount = n - colCount;
        for (int j = 0; j < columnCount; ++j) {
            printf("%*s", maxLength, matrix[i * n + j]); // Print number with appropriate spacing
        }
        colCount += columnCount;
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < n; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    generateFibonacci(n);
    visualizeFibonacci(n);

    return 0;
}
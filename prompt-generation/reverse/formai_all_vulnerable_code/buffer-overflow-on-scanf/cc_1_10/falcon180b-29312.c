//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: expert-level
#include <stdio.h>

#define MAX 10

// Function to print the given pattern
void printPattern(int arr[MAX][MAX], int rows, int cols) {
    int i, j;

    // Loop through all rows
    for (i = 0; i < rows; i++) {
        // Loop through all columns
        for (j = 0; j < cols; j++) {
            // Print the current element
            printf("%d ", arr[i][j]);
        }

        // Move to the next line
        printf("\n");
    }
}

// Function to fill the given pattern with random numbers
void fillPattern(int arr[MAX][MAX], int rows, int cols) {
    int i, j;

    // Loop through all rows
    for (i = 0; i < rows; i++) {
        // Loop through all columns
        for (j = 0; j < cols; j++) {
            // Fill the current element with a random number between 0 and 9
            arr[i][j] = rand() % 10;
        }
    }
}

// Main function
int main() {
    int rows, cols;

    // Get the number of rows and columns from the user
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Initialize the pattern with random numbers
    int pattern[MAX][MAX];
    fillPattern(pattern, rows, cols);

    // Print the original pattern
    printf("Original pattern:\n");
    printPattern(pattern, rows, cols);

    // Reverse the pattern
    int revPattern[MAX][MAX];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            revPattern[i][j] = pattern[rows - i - 1][j];
        }
    }

    // Print the reversed pattern
    printf("\nReversed pattern:\n");
    printPattern(revPattern, rows, cols);

    return 0;
}
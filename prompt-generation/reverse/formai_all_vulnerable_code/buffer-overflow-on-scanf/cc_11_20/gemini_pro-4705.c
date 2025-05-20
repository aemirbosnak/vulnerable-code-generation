//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    int n;
    printf("Enter the size of the pattern: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE) {
        printf("Invalid size. Please enter a number between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    // Create a 2D array to store the pattern
    int pattern[n][n];

    // Initialize the pattern with zeros
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pattern[i][j] = 0;
        }
    }

    // Set the main diagonal to 1s
    for (int i = 0; i < n; i++) {
        pattern[i][i] = 1;
    }

    // Set the secondary diagonal to 1s
    for (int i = 0; i < n; i++) {
        pattern[i][n - i - 1] = 1;
    }

    // Set the top and bottom rows to 1s
    for (int i = 0; i < n; i++) {
        pattern[0][i] = 1;
        pattern[n - 1][i] = 1;
    }

    // Set the left and right columns to 1s
    for (int i = 0; i < n; i++) {
        pattern[i][0] = 1;
        pattern[i][n - 1] = 1;
    }

    // Print the pattern
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", pattern[i][j]);
        }
        printf("\n");
    }

    return 0;
}
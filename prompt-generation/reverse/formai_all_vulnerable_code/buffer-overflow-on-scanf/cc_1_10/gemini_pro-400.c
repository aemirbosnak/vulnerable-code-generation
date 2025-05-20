//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of rows and columns
#define MAX_ROWS 100
#define MAX_COLUMNS 100

// Define the 'paranoid' types
typedef int paranoid_int;
typedef char paranoid_char;
typedef double paranoid_double;

// Define the macros to perform 'paranoid' operations
#define PARANOID_ADD(a, b) ((a) + (b))
#define PARANOID_SUB(a, b) ((a) - (b))
#define PARANOID_MUL(a, b) ((a) * (b))
#define PARANOID_DIV(a, b) ((a) / (b))

// Define the 'paranoid' functions
paranoid_int paranoid_max(paranoid_int a, paranoid_int b) {
    return (a > b) ? a : b;
}

paranoid_int paranoid_min(paranoid_int a, paranoid_int b) {
    return (a < b) ? a : b;
}

paranoid_double paranoid_sqrt(paranoid_double a) {
    return (a >= 0) ? sqrt(a) : -1;
}

// Define the 'paranoid' pattern printing function
void paranoid_pattern_printing(paranoid_int n) {
    // Paranoid checks for invalid input
    if (n <= 0) {
        printf("Invalid input: n must be a positive integer\n");
        return;
    }
    if (n > MAX_ROWS || n > MAX_COLUMNS) {
        printf("Invalid input: n must be less than or equal to %d\n", MAX_ROWS);
        return;
    }

    // Paranoid initialization of the matrix
    paranoid_char matrix[MAX_ROWS][MAX_COLUMNS];
    for (paranoid_int i = 0; i < MAX_ROWS; i++) {
        for (paranoid_int j = 0; j < MAX_COLUMNS; j++) {
            matrix[i][j] = ' ';
        }
    }

    // Paranoid pattern printing logic
    for (paranoid_int i = 0; i < n; i++) {
        for (paranoid_int j = 0; j < n; j++) {
            if (i == j) {
                matrix[i][j] = '*';
            } else if (i + j == n - 1) {
                matrix[i][j] = '*';
            } else if (i == n / 2) {
                matrix[i][j] = '*';
            } else if (j == n / 2) {
                matrix[i][j] = '*';
            }
        }
    }

    // Paranoid printing of the matrix
    for (paranoid_int i = 0; i < n; i++) {
        for (paranoid_int j = 0; j < n; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Paranoid input of the number of rows and columns
    paranoid_int n;
    printf("Enter the number of rows and columns (must be a positive integer less than or equal to %d): ", MAX_ROWS);
    scanf("%d", &n);

    // Paranoid printing of the pattern
    paranoid_pattern_printing(n);

    return 0;
}
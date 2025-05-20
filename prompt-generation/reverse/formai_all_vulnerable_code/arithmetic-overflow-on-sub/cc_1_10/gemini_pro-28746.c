//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Function to print a triangle of asterisks
void print_triangle(int n) {
    // Iterate over each row
    for (int i = 0; i < n; i++) {
        // Print the correct number of spaces for the current row
        for (int j = 0; j < n - i - 1; j++) {
            printf(" ");
        }

        // Print the correct number of asterisks for the current row
        for (int j = 0; j < 2 * i + 1; j++) {
            printf("*");
        }

        // Move to the next line
        printf("\n");
    }
}

// Function to print a diamond of asterisks
void print_diamond(int n) {
    // Print the upper half of the diamond
    print_triangle(n);

    // Print the lower half of the diamond
    for (int i = n - 2; i >= 0; i--) {
        // Print the correct number of spaces for the current row
        for (int j = 0; j < n - i - 1; j++) {
            printf(" ");
        }

        // Print the correct number of asterisks for the current row
        for (int j = 0; j < 2 * i + 1; j++) {
            printf("*");
        }

        // Move to the next line
        printf("\n");
    }
}

// Function to print a hollow triangle of asterisks
void print_hollow_triangle(int n) {
    // Iterate over each row
    for (int i = 0; i < n; i++) {
        // Print the correct number of spaces for the current row
        for (int j = 0; j < n - i - 1; j++) {
            printf(" ");
        }

        // Print the correct number of asterisks for the current row
        for (int j = 0; j < 2 * i + 1; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == 2 * i) {
                printf("*");
            } else {
                printf(" ");
            }
        }

        // Move to the next line
        printf("\n");
    }
}

// Function to print a hollow diamond of asterisks
void print_hollow_diamond(int n) {
    // Print the upper half of the hollow diamond
    print_hollow_triangle(n);

    // Print the lower half of the hollow diamond
    for (int i = n - 2; i >= 0; i--) {
        // Print the correct number of spaces for the current row
        for (int j = 0; j < n - i - 1; j++) {
            printf(" ");
        }

        // Print the correct number of asterisks for the current row
        for (int j = 0; j < 2 * i + 1; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == 2 * i) {
                printf("*");
            } else {
                printf(" ");
            }
        }

        // Move to the next line
        printf("\n");
    }
}

// Main function
int main() {
    // Get the input from the user
    int n;
    printf("Enter the size of the pattern: ");
    scanf("%d", &n);

    // Print the triangle of asterisks
    printf("\nTriangle of asterisks:\n");
    print_triangle(n);

    // Print the diamond of asterisks
    printf("\nDiamond of asterisks:\n");
    print_diamond(n);

    // Print the hollow triangle of asterisks
    printf("\nHollow triangle of asterisks:\n");
    print_hollow_triangle(n);

    // Print the hollow diamond of asterisks
    printf("\nHollow diamond of asterisks:\n");
    print_hollow_diamond(n);

    return 0;
}
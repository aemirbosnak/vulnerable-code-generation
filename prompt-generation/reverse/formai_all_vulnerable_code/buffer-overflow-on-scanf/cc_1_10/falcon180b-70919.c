//Falcon-180B DATASET v1.0 Category: Recursive ; Style: calm
#include <stdio.h>

// Function to print the pattern
void printPattern(int n) {
    if (n == 0) {
        printf("\n");
        return;
    }
    // Print the first half of the pattern
    for (int i = 0; i < n; i++) {
        printf(" ");
    }
    // Print the second half of the pattern
    for (int i = 0; i < n; i++) {
        printf("*");
    }
    printf("\n");
}

// Recursive function to print the pyramid pattern
void pyramidPattern(int n) {
    // Base case
    if (n == 0) {
        return;
    }
    // Print the first half of the pattern
    for (int i = 0; i < n; i++) {
        printf(" ");
    }
    // Print the middle row of the pattern
    for (int i = 0; i < n - 1; i++) {
        printf("*");
    }
    printf("\n");
    // Recursive call for the next level of the pyramid
    pyramidPattern(n - 1);
}

int main() {
    int n;
    printf("Enter the number of levels in the pyramid pattern: ");
    scanf("%d", &n);
    // Check for invalid input
    if (n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 0;
    }
    // Call the recursive function to print the pyramid pattern
    pyramidPattern(n);
    return 0;
}
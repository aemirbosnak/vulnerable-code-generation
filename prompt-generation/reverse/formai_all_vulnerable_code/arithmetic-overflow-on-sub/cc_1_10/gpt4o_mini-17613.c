//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: curious
#include <stdio.h>

// Function to print a particular pattern based on the user's choice
void printPattern(int n, char choice) {
    switch (choice) {
        case 'A':
            // Printing a right angled triangle
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= i; j++) {
                    printf("* ");
                }
                printf("\n");
            }
            break;
        case 'B':
            // Printing a pyramid pattern
            for (int i = 0; i < n; i++) {
                for (int j = n - i; j > 1; j--) {
                    printf(" ");
                }
                for (int k = 0; k <= i; k++) {
                    printf("* ");
                }
                printf("\n");
            }
            break;
        case 'C':
            // Printing an inverted triangle
            for (int i = n; i >= 1; i--) {
                for (int j = 1; j <= i; j++) {
                    printf("* ");
                }
                printf("\n");
            }
            break;
        case 'D':
            // Printing a diamond pattern
            for (int i = 1; i <= n; i++) {
                for (int j = n-i; j > 0; j--) {
                    printf(" ");
                }
                for (int k = 1; k <= (2*i - 1); k++) {
                    printf("*");
                }
                printf("\n");
            }
            for (int i = n-1; i >= 1; i--) {
                for (int j = n-i; j > 0; j--) {
                    printf(" ");
                }
                for (int k = 1; k <= (2*i - 1); k++) {
                    printf("*");
                }
                printf("\n");
            }
            break;
        default:
            printf("Invalid choice! Please select A, B, C, or D.\n");
            break;
    }
}

// Function to display the menu for pattern selection
void displayMenu() {
    printf("Pattern Printing Menu:\n");
    printf("A: Right angled triangle\n");
    printf("B: Pyramid\n");
    printf("C: Inverted triangle\n");
    printf("D: Diamond\n");
}

int main() {
    int n;
    char choice;

    // Display the options to the user
    displayMenu();

    // Asking for the desired size of the pattern
    printf("Enter the size of the pattern (n): ");
    scanf("%d", &n);

    // Asking for the user's choice of pattern
    printf("Enter your choice of pattern (A/B/C/D): ");
    scanf(" %c", &choice);

    // Calling the printPattern function based on user's input
    printPattern(n, choice);

    return 0;
}
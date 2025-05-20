//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: relaxed
#include <stdio.h>

// Function to print a pattern based on user's choice
void printPattern(int choice, int n) {
    switch (choice) {
        case 1:
            // Print a right-angled triangle
            printf("Right-Angled Triangle Pattern:\n");
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= i; j++) {
                    printf("* ");
                }
                printf("\n");
            }
            break;

        case 2:
            // Print a pyramid
            printf("Pyramid Pattern:\n");
            for (int i = 1; i <= n; i++) {
                for (int j = n; j > i; j--) {
                    printf(" ");
                }
                for (int j = 1; j <= (2 * i - 1); j++) {
                    printf("*");
                }
                printf("\n");
            }
            break;

        case 3:
            // Print a diamond
            printf("Diamond Pattern:\n");
            for (int i = 1; i <= n; i++) {
                for (int j = n; j > i; j--) {
                    printf(" ");
                }
                for (int j = 1; j <= (2 * i - 1); j++) {
                    printf("*");
                }
                printf("\n");
            }
            for (int i = n - 1; i >= 1; i--) {
                for (int j = n; j > i; j--) {
                    printf(" ");
                }
                for (int j = 1; j <= (2 * i - 1); j++) {
                    printf("*");
                }
                printf("\n");
            }
            break;

        case 4:
            // Print an inverted pyramid
            printf("Inverted Pyramid Pattern:\n");
            for (int i = n; i >= 1; i--) {
                for (int j = 1; j <= n - i; j++) {
                    printf(" ");
                }
                for (int j = 1; j <= (2 * i - 1); j++) {
                    printf("*");
                }
                printf("\n");
            }
            break;

        case 5:
            // Print a hollow square
            printf("Hollow Square Pattern:\n");
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (i == 1 || i == n || j == 1 || j == n) {
                        printf("* ");
                    } else {
                        printf("  ");
                    }
                }
                printf("\n");
            }
            break;

        case 6:
            // Print a number triangle
            printf("Number Triangle Pattern:\n");
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= i; j++) {
                    printf("%d ", j);
                }
                printf("\n");
            }
            break;

        case 7:
            // Print a Fibonacci pattern
            printf("Fibonacci Pattern:\n");
            int a = 0, b = 1, c;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= i; j++) {
                    printf("%d ", a);
                    c = a + b;
                    a = b;
                    b = c;
                }
                printf("\n");
            }
            break;

        case 8:
            // Print a star pattern with character input
            printf("Character Star Pattern:\n");
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= i; j++) {
                    printf("%c ", 'A' + i - 1);
                }
                printf("\n");
            }
            break;

        default:
            printf("Invalid choice! Please select a valid pattern.\n");
    }
}

int main() {
    int choice, n;

    // Welcome message
    printf("Welcome to the Creative Pattern Printing Program!\n");
    printf("What pattern would you like to print?\n");
    printf("1. Right-Angled Triangle\n");
    printf("2. Pyramid\n");
    printf("3. Diamond\n");
    printf("4. Inverted Pyramid\n");
    printf("5. Hollow Square\n");
    printf("6. Number Triangle\n");
    printf("7. Fibonacci Pattern\n");
    printf("8. Character Star Pattern\n");
    printf("Please enter your choice (1-8): ");
    scanf("%d", &choice);
    
    // Prompt for number of rows
    printf("Enter the number of rows (n): ");
    scanf("%d", &n);

    // Print the selected pattern
    printPattern(choice, n);

    printf("\nThank you for using the pattern printing program!\n");
    printf("Feel free to experiment with different patterns.\n");

    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

void printPattern(int n) {
    if (n <= 0) {
        printf("Always a chance for improvement, but... this is not valid.\n");
        return;
    }

    // Upper part of the pattern
    for (int i = 1; i <= n; i++) {
        char ch = 'A';
        
        // Print leading spaces
        for (int j = i; j < n; j++) {
            printf(" ");
        }

        // Print characters
        for (int k = 1; k <= i; k++) {
            putchar(ch);
            ch++;
        }

        printf("\n");
    }

    // Lower part of the pattern
    for (int i = n - 1; i >= 1; i--) {
        char ch = 'A';

        // Print leading spaces
        for (int j = n; j > i; j--) {
            printf(" ");
        }

        // Print characters
        for (int k = 1; k <= i; k++) {
            putchar(ch);
            ch++;
        }

        printf("\n");
    }
}

int main() {
    int n;

    printf("Welcome to the paranoid pattern printer!\n");
    printf("Enter the height of the pyramid (1-26 characters): ");
    if (scanf("%d", &n) == 0 || n < 1 || n > 26) {
        printf("That's suspicious! Only numbers from 1 to 26 are allowed.\n");
        return 1;
    }
    
    printf("Proceeding to print the pattern...\n");
    
    // Let’s perform a double-check on the input
    if (n > 0 && n <= 26) {
        printPattern(n);
    } else {
        printf("Something seems off... reverting operations.\n");
        return 1;
    }

    printf("Pattern printed successfully. But... did it really happen?\n");

    // Cleaning up is critical, even when there's nothing to clean in this case.
    n = 0;

    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: shocked
#include <stdio.h>

// Function to print a weird pattern that leaves you speechless!
void printShockPattern(int n) {
    int i, j, space;

    // Upper part of the pattern
    for (i = 1; i <= n; i++) {
        // Print leading spaces
        for (space = 1; space <= n - i; space++) {
            printf(" ");
        }
        
        // Print increasing numbers
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }

        // Print decreasing numbers
        for (j = i - 1; j >= 1; j--) {
            printf("%d ", j);
        }

        printf("\n");
    }

    // Lower part of the pattern
    for (i = n - 1; i >= 1; i--) {
        // Print leading spaces
        for (space = 1; space <= n - i; space++) {
            printf(" ");
        }
        
        // Print increasing numbers
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }

        // Print decreasing numbers
        for (j = i - 1; j >= 1; j--) {
            printf("%d ", j);
        }

        printf("\n");
    }
}

// Function to print a weird zigzag pattern!
void printZigZag(int n) {
    int row, col;

    for (row = 1; row <= n; row++) {
        for (col = 1; col <= n; col++) {
            // Create staggered output
            if ((row + col) % 2 == 0) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

// Wow! Am I seeing a new shape? Let's generate a diamond too!
void printDiamond(int n) {
    int i, j, space;

    // Upper triangle
    for (i = 1; i <= n; i++) {
        for (space = 1; space <= n - i; space++) {
            printf(" ");
        }

        for (j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }

        printf("\n");
    }

    // Lower inverted triangle
    for (i = n - 1; i >= 1; i--) {
        for (space = 1; space <= n - i; space++) {
            printf(" ");
        }

        for (j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }

        printf("\n");
    }
}

// O-M-G! Let's create an unforgettable hourglass pattern!
void printHourglass(int n) {
    int i, j;

    // Upper part
    for (i = n; i >= 1; i--) {
        for (j = 1; j <= (2 * n - 1); j++) {
            if (j >= (n - i + 1) && j <= (n + i - 1)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Lower part
    for (i = 2; i <= n; i++) {
        for (j = 1; j <= (2 * n - 1); j++) {
            if (j >= (n - i + 1) && j <= (n + i - 1)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// The main function, where the magic begins!
int main() {
    int n;

    printf("Enter the height for the patterns: ");
    scanf("%d", &n);
    
    // Prepare to be amazed!
    printf("\nShock Pattern:\n");
    printShockPattern(n);
    
    printf("\nZigzag Pattern:\n");
    printZigZag(n);
    
    printf("\nDiamond Pattern:\n");
    printDiamond(n);
    
    printf("\nHourglass Pattern:\n");
    printHourglass(n);
    
    printf("\nA thrilling experience, wasn't it?\n");

    return 0;
}
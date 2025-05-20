//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: synchronous
#include <stdio.h>

void printDiamond(int n) {
    int space, stars;
    
    // Print the upper part of the diamond
    for (int i = 1; i <= n; i++) {
        for (space = n; space > i; space--) {
            printf(" ");
        }
        for (stars = 1; stars <= (2 * i - 1); stars++) {
            printf("*");
        }
        printf("\n");
    }
    
    // Print the lower part of the diamond
    for (int i = n - 1; i >= 1; i--) {
        for (space = n; space > i; space--) {
            printf(" ");
        }
        for (stars = 1; stars <= (2 * i - 1); stars++) {
            printf("*");
        }
        printf("\n");
    }
}

void printReversePyramid(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = n; j > i; j--) {
            printf(" ");
        }
        for (int k = 1; k <= (2 * i - 1); k++) {
            printf("X");
        }
        printf("\n");
    }
}

void printFractalTriangle(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = n; j > i; j--) {
            printf(" ");
        }
        for (int k = 0; k <= i; k++) {
            printf("* ");
        }
        printf("\n");
    }
}

int main() {
    int choice, size;
    
    printf("Welcome to the Pattern Printing Program!\n");
    
    while (1) {
        printf("Choose a pattern to print:\n");
        printf("1. Diamond Pattern\n");
        printf("2. Reverse Pyramid Pattern\n");
        printf("3. Fractal Triangle Pattern\n");
        printf("4. Exit\n");
        
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        
        if (choice == 4) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }
        
        printf("Enter the size (number of rows): ");
        scanf("%d", &size);
        
        switch (choice) {
            case 1:
                printf("\nDiamond Pattern:\n");
                printDiamond(size);
                break;
            case 2:
                printf("\nReverse Pyramid Pattern:\n");
                printReversePyramid(size);
                break;
            case 3:
                printf("\nFractal Triangle Pattern:\n");
                printFractalTriangle(size);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    }
    
    return 0;
}
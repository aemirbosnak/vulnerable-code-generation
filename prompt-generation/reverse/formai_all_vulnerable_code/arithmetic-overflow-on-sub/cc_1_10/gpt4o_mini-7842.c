//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: realistic
#include <stdio.h>

void printDiamond(int n) {
    int space, i, j;
    
    // Top diamond half
    for(i = 0; i < n; i++) {
        for(space = 0; space < n - i - 1; space++)
            printf(" ");
        for(j = 0; j <= i; j++)
            printf("* ");
        printf("\n");
    }

    // Bottom diamond half
    for(i = n - 2; i >= 0; i--) {
        for(space = 0; space < n - i - 1; space++)
            printf(" ");
        for(j = 0; j <= i; j++)
            printf("* ");
        printf("\n");
    }
}

void printPyramid(int height) {
    int i, j, space;

    for(i = 0; i < height; i++) {
        for(space = 0; space < height - i - 1; space++)
            printf(" ");
        for(j = 0; j < 2 * i + 1; j++)
            printf("*");
        printf("\n");
    }
}

void printMenu() {
    printf("Choose a pattern to print:\n");
    printf("1. Diamond Pattern\n");
    printf("2. Pyramid Pattern\n");
    printf("3. Both Patterns\n");
    printf("4. Exit\n");
}

int main() {
    int choice, height;

    printf("Welcome to Pattern Printer!\n");
    printf("Enter the height for the patterns: ");
    scanf("%d", &height);

    while(1) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nDiamond Pattern:\n");
                printDiamond(height);
                break;
            case 2:
                printf("\nPyramid Pattern:\n");
                printPyramid(height);
                break;
            case 3:
                printf("\nDiamond Pattern:\n");
                printDiamond(height);
                printf("\nPyramid Pattern:\n");
                printPyramid(height);
                break;
            case 4:
                printf("Exiting the program. Thank you for using Pattern Printer!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
        printf("\n");
    }
    return 0;
}
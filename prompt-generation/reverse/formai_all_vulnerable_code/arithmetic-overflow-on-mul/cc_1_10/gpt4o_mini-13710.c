//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: introspective
#include <stdio.h>

void printDiamond(int n) {
    // Print upper triangle
    for (int i = 1; i <= n; i++) {
        // Print leading spaces
        for (int j = i; j < n; j++)
            printf(" ");
        // Print stars
        for (int j = 1; j <= (2 * i - 1); j++)
            printf("*");
        printf("\n");
    }

    // Print lower triangle
    for (int i = n - 1; i >= 1; i--) {
        // Print leading spaces
        for (int j = n; j > i; j--)
            printf(" ");
        // Print stars
        for (int j = 1; j <= (2 * i - 1); j++)
            printf("*");
        printf("\n");
    }
}

void printHollowDiamond(int n) {
    // Print upper hollow triangle
    for (int i = 1; i <= n; i++) {
        // Print leading spaces
        for (int j = i; j < n; j++)
            printf(" ");
        // Print stars and spaces
        for (int j = 1; j <= (2 * i - 1); j++) {
            if (j == 1 || j == (2 * i - 1) || i == n) 
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }

    // Print lower hollow triangle
    for (int i = n - 1; i >= 1; i--) {
        // Print leading spaces
        for (int j = n; j > i; j--)
            printf(" ");
        // Print stars and spaces
        for (int j = 1; j <= (2 * i - 1); j++) {
            if (j == 1 || j == (2 * i - 1) || i == 1) 
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void printBorderedDiamond(int n) {
    // Print upper bordered triangle
    for (int i = 1; i <= n; i++) {
        // Print leading spaces
        for (int j = i; j < n; j++)
            printf(" ");
        // Print stars
        for (int j = 1; j <= (2 * i - 1); j++) {
            if (j == 1 || j == (2 * i - 1) || i == n) 
                printf("*");
            else
                printf("-");
        }
        printf("\n");
    }

    // Print lower bordered triangle
    for (int i = n - 1; i >= 1; i--) {
        // Print leading spaces
        for (int j = n; j > i; j--)
            printf(" ");
        // Print stars
        for (int j = 1; j <= (2 * i - 1); j++) {
            if (j == 1 || j == (2 * i - 1) || i == 1) 
                printf("*");
            else
                printf("-");
        }
        printf("\n");
    }
}

void displayPatterns() {
    int choice, n;

    do {
        printf("\nDiamond Pattern Printer\n");
        printf("1. Print Solid Diamond\n");
        printf("2. Print Hollow Diamond\n");
        printf("3. Print Bordered Diamond\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of rows for the solid diamond: ");
                scanf("%d", &n);
                printDiamond(n);
                break;

            case 2:
                printf("Enter the number of rows for the hollow diamond: ");
                scanf("%d", &n);
                printHollowDiamond(n);
                break;

            case 3:
                printf("Enter the number of rows for the bordered diamond: ");
                scanf("%d", &n);
                printBorderedDiamond(n);
                break;

            case 4:
                printf("Exiting the program. Thank you for using the Diamond Pattern Printer!\n");
                break;

            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 4);
}

int main() {
    displayPatterns();
    return 0;
}
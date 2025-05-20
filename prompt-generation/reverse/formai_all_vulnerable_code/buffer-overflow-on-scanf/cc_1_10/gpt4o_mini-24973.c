//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: configurable
#include <stdio.h>

void printTriangle(int height) {
    printf("\nTriangle Pattern:\n");
    for (int i = 1; i <= height; i++) {
        for (int j = i; j < height; j++)
            printf(" ");
        for (int k = 1; k <= (2 * i - 1); k++)
            printf("*");
        printf("\n");
    }
}

void printSquare(int size) {
    printf("\nSquare Pattern:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printDiamond(int height) {
    printf("\nDiamond Pattern:\n");
    // Top half
    for (int i = 1; i <= height; i++) {
        for (int j = i; j < height; j++)
            printf(" ");
        for (int k = 1; k <= (2 * i - 1); k++)
            printf("*");
        printf("\n");
    }
    // Bottom half
    for (int i = height - 1; i >= 1; i--) {
        for (int j = height; j > i; j--)
            printf(" ");
        for (int k = 1; k <= (2 * i - 1); k++)
            printf("*");
        printf("\n");
    }
}

void displayMenu() {
    printf("\nPattern Printing Menu:\n");
    printf("1. Print Triangle\n");
    printf("2. Print Square\n");
    printf("3. Print Diamond\n");
    printf("4. Exit\n");
    printf("Choose an option (1-4): ");
}

int main() {
    int choice, size;

    do {
        displayMenu();
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 3) {
            printf("Enter the size (height/length): ");
            scanf("%d", &size);

            switch (choice) {
                case 1:
                    if (size > 0)
                        printTriangle(size);
                    else
                        printf("Size must be a positive integer.\n");
                    break;
                case 2:
                    if (size > 0)
                        printSquare(size);
                    else
                        printf("Size must be a positive integer.\n");
                    break;
                case 3:
                    if (size > 0)
                        printDiamond(size);
                    else
                        printf("Size must be a positive integer.\n");
                    break;
            }
        } else if (choice != 4) {
            printf("Invalid choice. Please choose again.\n");
        }

    } while (choice != 4);

    printf("Thank you for using the pattern printing program! Goodbye!\n");
    return 0;
}
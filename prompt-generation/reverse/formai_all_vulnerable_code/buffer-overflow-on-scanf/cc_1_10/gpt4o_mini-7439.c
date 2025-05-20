//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: active
#include <stdio.h>

void printDiamond(int n) {
    int space, i, j;

    // Upper part of the diamond
    for (i = 0; i < n; i++) {
        for (space = 0; space < n - i - 1; space++)
            printf(" ");
        for (j = 0; j < 2 * i + 1; j++)
            printf("*");
        printf("\n");
    }

    // Lower part of the diamond
    for (i = n - 2; i >= 0; i--) {
        for (space = 0; space < n - i - 1; space++)
            printf(" ");
        for (j = 0; j < 2 * i + 1; j++)
            printf("*");
        printf("\n");
    }
}

void printBorder(int length) {
    for (int i = 0; i < length; i++) {
        printf("#");
    }
    printf("\n");
}

void displayInstructions() {
    printf("Welcome to the Diamond Star Pattern Generator!\n");
    printf("You will be prompted to enter the height of the diamond.\n");
    printf("Please enter a positive integer to proceed.\n");
}

int main() {
    int height;

    displayInstructions();
    printf("Enter the height of the diamond: ");
    scanf("%d", &height);

    if (height <= 0) {
        printf("Invalid input! Height must be a positive integer.\n");
        return 1;
    }

    int borderLength = height * 2 + 1; // Calculate border length based on height
    printBorder(borderLength);
    
    printDiamond(height);
    
    printBorder(borderLength);

    printf("Thank you for using the Diamond Star Pattern Generator!\n");
    return 0;
}
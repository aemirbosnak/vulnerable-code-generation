//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: Dennis Ritchie
#include <stdio.h>

void printSpaces(int n) {
    for (int i = 0; i < n; i++) {
        printf(" ");
    }
}

void printStar(int n) {
    for (int i = 0; i < n; i++) {
        printf("* ");
    }
}

void printDiamond(int size) {
    // Print upper part of the diamond
    for (int i = 0; i < size; i++) {
        printSpaces(size - i - 1);
        printStar(i + 1);
        printf("\n");
    }
    // Print lower part of the diamond
    for (int i = size - 1; i > 0; i--) {
        printSpaces(size - i);
        printStar(i);
        printf("\n");
    }
}

void printPattern(int rows) {
    for (int i = 1; i <= rows; i++) {
        printDiamond(i);
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the number of rows for the largest diamond: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Please enter a number greater than 0.\n");
        return 1;
    }

    printf("\nPrinting unique diamond patterns:\n\n");
    printPattern(n);

    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: light-weight
#include <stdio.h>

void printUpperDiamond(int height) {
    for (int i = 0; i < height; i++) {
        // Print leading spaces
        for (int j = height - i; j > 1; j--) {
            printf(" ");
        }
        // Print stars
        for (int j = 0; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printLowerDiamond(int height) {
    for (int i = height - 1; i > 0; i--) {
        // Print leading spaces
        for (int j = height - i; j > 0; j--) {
            printf(" ");
        }
        // Print stars
        for (int j = 0; j < i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printBorder(int height) {
    for (int i = 0; i < height + 1; i++) {
        printf("* ");
    }
    printf("\n");
}

int main() {
    int height;

    printf("Enter the height of the diamond (number of rows): ");
    scanf("%d", &height);

    if (height <= 0) {
        printf("Height must be a positive integer.\n");
        return 1;
    }

    // Print top border
    printBorder(height);
    // Print upper part of the diamond
    printUpperDiamond(height);
    // Print lower part of the diamond
    printLowerDiamond(height);
    // Print bottom border
    printBorder(height);

    return 0;
}
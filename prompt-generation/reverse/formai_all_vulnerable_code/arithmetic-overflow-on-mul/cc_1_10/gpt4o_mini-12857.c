//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: real-life
#include <stdio.h>

void printStarLine(int n) {
    for (int i = 0; i < n; i++)
        printf("*");
    printf("\n");
}

void printSpaces(int n) {
    for (int i = 0; i < n; i++)
        printf(" ");
}

void printTree(int height) {
    int width = height * 2 - 1;

    for (int i = 1; i <= height; i++) {
        int starCount = i * 2 - 1; // number of stars on the current row
        int spaces = (width - starCount) / 2; // number of leading spaces

        printSpaces(spaces);
        printStarLine(starCount);
    }

    // Print the trunk of the tree
    int trunkHeight = height / 3; // Trunk height relative to tree height
    int trunkWidth = height / 3 + 1; // Trunk width

    for (int j = 0; j < trunkHeight; j++) {
        int trunkSpaces = (width - trunkWidth) / 2;
        printSpaces(trunkSpaces);
        printStarLine(trunkWidth);
    }

    // Print the decorations (optional)
    int decorations = height / 2; // Number of decorations
    for (int k = 0; k < decorations; k++) {
        int pos = (rand() % width) + 1; // Random position for decoration
        printSpaces(pos);
        printf("O\n"); // Print decoration at random position
    }
}

int main() {
    int height;

    printf("Enter the height of the Christmas tree: ");
    while (1) {
        scanf("%d", &height);
        if (height > 4) {
            break;
        } else {
            printf("Height should be greater than 4. Please enter again: ");
        }
    }

    printf("\n\n");
    printTree(height);

    printf("\nMerry Christmas and Happy New Year!\n");
    return 0;
}
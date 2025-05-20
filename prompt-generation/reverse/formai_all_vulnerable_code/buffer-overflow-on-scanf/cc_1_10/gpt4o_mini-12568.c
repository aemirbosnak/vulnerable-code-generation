//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: surprised
#include <stdio.h>

void printSpaces(int count) {
    for (int i = 0; i < count; i++) {
        printf(" ");
    }
}

void printStars(int count) {
    for (int i = 0; i < count; i++) {
        printf("*");
    }
}

void printPattern(int lines) {
    int maxStars = (lines * 2) - 1;

    // Upper part of the pattern
    for (int i = 1; i <= lines; i++) {
        printSpaces(lines - i);
        printStars(i * 2 - 1);
        printf("\n");
    }

    // Lower part of the pattern
    for (int i = lines - 1; i >= 1; i--) {
        printSpaces(lines - i);
        printStars(i * 2 - 1);
        printf("\n");
    }
}

void printSurprisePattern(int lines) {
    int height = lines * 2 + 1;
    int width = height;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == lines) {
                printf("@");
            } else if (j == width / 2) {
                printf("|");
            } else if (i < lines) {
                if (j >= lines - i && j <= width - (lines - i) - 1) {
                    printf("*");
                } else {
                    printf(" ");
                }
            } else {
                if (j >= i - lines + 1 && j <= width - (i - lines + 1) - 1) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

int main() {
    int lines;

    printf("Welcome to the Surprising Star Pattern Generator!\n");
    printf("Please enter the number of lines for your pattern (e.g., 5): ");
    scanf("%d", &lines);

    if (lines < 1) {
        printf("Number of lines must be at least 1.\n");
        return 1;
    }

    printf("\nHere’s your stunning pattern:\n\n");
    printPattern(lines);

    printf("\nAnd here’s an unexpected twist to the pattern:\n\n");
    printSurprisePattern(lines);

    printf("\nHope you enjoyed this surprise! :) \n");
    
    return 0;
}
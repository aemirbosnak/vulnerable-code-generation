//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: invasive
#include <stdio.h>

void print_pyramid(int height) {
    int i, j, space;

    for (i = 0; i < height; i++) {
        // Printing spaces for pyramid shape
        for (space = 0; space < height - i - 1; space++) {
            printf(" ");
        }
        // Print the characters in increasing order
        for (j = 0; j <= i; j++) {
            printf("%c ", 'A' + j);
        }
        // Print the characters in decreasing order
        for (j = i - 1; j >= 0; j--) {
            printf("%c ", 'A' + j);
        }
        printf("\n");
    }
}

void print_inverted_pyramid(int height) {
    int i, j, space;

    for (i = height; i > 0; i--) {
        // Printing spaces for inverted pyramid shape
        for (space = height - i; space > 0; space--) {
            printf(" ");
        }
        // Print the characters in increasing order
        for (j = 0; j < i; j++) {
            printf("%c ", 'A' + j);
        }
        // Print the characters in decreasing order
        for (j = i - 2; j >= 0; j--) {
            printf("%c ", 'A' + j);
        }
        printf("\n");
    }
}

void print_diamond(int height) {
    int i, j, space;
    
    // Upper part of diamond
    for (i = 0; i < height; i++) {
        for (space = height - i - 1; space > 0; space--) {
            printf(" ");
        }
        for (j = 0; j <= i; j++) {
            printf("%c ", 'A' + j);
        }
        for (j = i - 1; j >= 0; j--) {
            printf("%c ", 'A' + j);
        }
        printf("\n");
    }
    // Lower part of diamond
    for (i = height - 2; i >= 0; i--) {
        for (space = height - i - 1; space > 0; space--) {
            printf(" ");
        }
        for (j = 0; j <= i; j++) {
            printf("%c ", 'A' + j);
        }
        for (j = i - 1; j >= 0; j--) {
            printf("%c ", 'A' + j);
        }
        printf("\n");
    }
}

int main() {
    int height;

    // User input for the height of the patterns
    printf("Enter the height of the pyramid (1-26): ");
    scanf("%d", &height);

    // Verification of the entered height
    if (height < 1 || height > 26) {
        printf("Height must be between 1 and 26!\n");
        return 1;
    }

    printf("\nPyramid Pattern:\n");
    print_pyramid(height);
    
    printf("\nInverted Pyramid Pattern:\n");
    print_inverted_pyramid(height);
    
    printf("\nDiamond Pattern:\n");
    print_diamond(height);
    
    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: sophisticated
#include <stdio.h>

void print_pyramid(int n) {
    // Upper pyramid
    for (int i = 0; i < n; i++) {
        // Print spaces
        for (int j = 0; j < n - i - 1; j++) {
            printf(" ");
        }
        // Print stars
        for (int k = 0; k < (2 * i + 1); k++) {
            printf("*");
        }
        printf("\n");
    }
}

void print_inverted_pyramid(int n) {
    // Lower inverted pyramid
    for (int i = n - 1; i >= 0; i--) {
        // Print spaces
        for (int j = 0; j < n - i - 1; j++) {
            printf(" ");
        }
        // Print stars
        for (int k = 0; k < (2 * i + 1); k++) {
            printf("*");
        }
        printf("\n");
    }
}

void print_reversed_pyramid(int n) {
    // Reversed left-aligned pyramid
    for (int i = n; i > 0; i--) {
        // Print stars
        for (int j = 0; j < i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void print_numbers(int n) {
    // Number pyramid
    for (int i = 1; i <= n; i++) {
        // Print spaces
        for (int j = 0; j < n - i; j++) {
            printf(" ");
        }
        // Print numbers
        for (int k = 1; k <= i; k++) {
            printf("%d ", k);
        }
        printf("\n");
    }
}

void print_diamond(int n) {
    // Diamond pattern
    print_pyramid(n);        // Upper part
    print_inverted_pyramid(n); // Lower part
}

void print_hollow_square(int n) {
    // Hollow square pattern
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void print_diamond_square(int n) {
    // Diamond in square
    print_hollow_square(n);
    print_diamond(n / 2);
}

int main() {
    int n;
    printf("Enter the number of rows for pyramid patterns: ");
    scanf("%d", &n);

    printf("\nPyramid Pattern:\n");
    print_pyramid(n);

    printf("\nInverted Pyramid Pattern:\n");
    print_inverted_pyramid(n);

    printf("\nReversed Left-aligned Pyramid Pattern:\n");
    print_reversed_pyramid(n);

    printf("\nNumber Pyramid Pattern:\n");
    print_numbers(n);

    printf("\nDiamond Pattern:\n");
    print_diamond(n);

    printf("\nHollow Square Pattern:\n");
    print_hollow_square(n);

    printf("\nDiamond in Square Pattern:\n");
    print_diamond_square(n);

    return 0;
}
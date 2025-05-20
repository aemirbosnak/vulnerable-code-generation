//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: creative
#include <stdio.h>

// Define a macro to print a single pattern element
#define PRINT_ELEMENT(x) { \
    if (x > 0) { \
        putchar(x % 2 == 0 ? '(' : ')'); \
    } \
}

// Define a function to print a pattern
void print_pattern(int n) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            PRINT_ELEMENT(i * j);
        }
        putchar('\n');
    }
}

int main() {
    int n;

    // Ask the user for the number of patterns to print
    printf("Enter the number of patterns to print: ");
    scanf("%d", &n);

    // Print the patterns
    for (int i = 0; i < n; i++) {
        print_pattern(i);
    }

    return 0;
}

// Define a pattern that prints a spiral
void print_spiral(int n) {
    int i, j;

    // Start at the top left corner
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            PRINT_ELEMENT(i * j);
        }
        putchar('\n');
    }

    // Move down and to the right
    for (i = n - 1; i > -1; i--) {
        for (j = 0; j < n; j++) {
            PRINT_ELEMENT(i * j);
        }
        putchar('\n');
    }
}

// Define a pattern that prints a zigzag
void print_zigzag(int n) {
    int i, j;

    // Start at the top left corner
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            PRINT_ELEMENT(i * j);
        }
        putchar('\n');
    }

    // Move down and to the right, then back up and to the left
    for (i = n - 1; i > -1; i--) {
        for (j = 0; j < n; j++) {
            PRINT_ELEMENT(i * j);
        }
        putchar('\n');
    }
}
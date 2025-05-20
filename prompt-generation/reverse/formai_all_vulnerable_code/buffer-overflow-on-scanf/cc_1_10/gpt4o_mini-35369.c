//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: Claude Shannon
#include <stdio.h>

void print_symbol(int count, char symbol) {
    for (int i = 0; i < count; i++) {
        putchar(symbol);
    }
}

void generate_pattern(int rows) {
    for (int i = 1; i <= rows; i++) {
        print_symbol(i * 2, '*'); 
        putchar('\n');  // Pattern 1: Increasing number of stars
    }

    printf("\n"); // Gap between patterns

    for (int i = rows; i > 0; i--) {
        print_symbol(i * 2, '#'); 
        putchar('\n');  // Pattern 2: Decreasing number of hashes
    }

    printf("\n"); // Gap between patterns

    for (int i = 1; i <= rows; i++) {
        for (int j = 0; j < rows - i; j++) {
            putchar(' '); // Printing spaces for alignment
        }
        print_symbol(2 * i - 1, '$'); 
        putchar('\n');  // Pattern 3: Pyramid of dollar signs
    }
    
    printf("\n"); // Gap between patterns

    for (int i = 1; i <= rows; i++) {
        for (int j = 0; j < i; j++) {
            putchar(' '); // Printing spaces for alignment
        }
        print_symbol((rows - i) * 2 + 1, '@'); 
        putchar('\n');  // Pattern 4: Inverted pyramid of at symbols
    }
    
    printf("\n"); // Gap between patterns

    for (int i = 1; i <= rows; i++) {
        print_symbol(rows, '*');  // Printing row of stars
        putchar('\n');            // New line after each row
        print_symbol(rows - i, ' '); // Printing spaces for internal pattern
    }
    
    printf("\n"); // Final gap after all patterns
}

int main() {
    int rows;

    printf("Enter the number of rows for the pattern: ");
    scanf("%d", &rows);

    if (rows <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    generate_pattern(rows);

    printf("Patterns generated successfully!\n");
    return 0;
}
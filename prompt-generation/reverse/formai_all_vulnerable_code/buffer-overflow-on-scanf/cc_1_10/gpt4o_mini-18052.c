//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: genius
#include <stdio.h>

void print_star_pattern(int n) {
    int i, j;

    // Upper part of the pattern
    for (i = 1; i <= n; i++) {
        // Print leading spaces
        for (j = n; j > i; j--) {
            printf("  ");
        }

        // Print stars and numbers
        for (j = 1; j <= i; j++) {
            printf("* "); // Print star
        }
        for (j = 1; j < i; j++) {
            printf("%d ", i + j); // Print numbers
        }
        
        printf("\n");
    }

    // Lower part of the pattern
    for (i = n - 1; i >= 1; i--) {
        // Print leading spaces
        for (j = n; j > i; j--) {
            printf("  ");
        }

        // Print stars and numbers
        for (j = 1; j <= i; j++) {
            printf("* "); // Print star
        }
        for (j = 1; j < i; j++) {
            printf("%d ", i + j); // Print numbers
        }
        
        printf("\n");
    }
}

int main() {
    int rows;

    printf("Enter the number of rows for the pattern (1-10): ");
    scanf("%d", &rows);

    // Limit for maximum pattern size
    if (rows < 1 || rows > 10) {
        printf("Please enter a valid number of rows (between 1 and 10).\n");
        return 1;
    }

    printf("\nGenerated Pattern:\n");
    print_star_pattern(rows);

    return 0;
}
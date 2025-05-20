//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: intelligent
#include <stdio.h>

void print_pyramid(int rows) {
    int i, j, k;

    // Loop for each row
    for (i = 1; i <= rows; i++) {
        // Print spaces
        for (j = i; j < rows; j++) {
            printf(" ");
        }
        
        // Print numbers in ascending order
        for (k = 1; k <= i; k++) {
            printf("%d ", k);
        }

        // Print special character in middle
        printf("# ");

        // Print numbers in descending order
        for (k = i; k >= 1; k--) {
            printf("%d ", k);
        }

        printf("\n"); // Move to the next line
    }
}

void print_reverse_pyramid(int rows) {
    int i, j, k;

    // Loop for each row
    for (i = rows; i >= 1; i--) {
        // Print spaces
        for (j = rows; j > i; j--) {
            printf(" ");
        }

        // Print numbers in ascending order
        for (k = 1; k <= i; k++) {
            printf("%d ", k);
        }
        
        // Print special character in middle
        printf("# ");

        // Print numbers in descending order
        for (k = i; k >= 1; k--) {
            printf("%d ", k);
        }

        printf("\n"); // Move to the next line
    }
}

int main() {
    int rows;

    // Get user input
    printf("Enter number of rows for the pyramid (1-20): ");
    scanf("%d", &rows);

    if (rows < 1 || rows > 20) {
        printf("Please enter a valid number of rows between 1 and 20.\n");
        return 1; // Exit with an error code
    }

    // Print the pyramid
    printf("\nPyramid Pattern:\n");
    print_pyramid(rows);

    // Print the reverse pyramid
    printf("\nReverse Pyramid Pattern:\n");
    print_reverse_pyramid(rows);

    return 0; // Program executed successfully
}
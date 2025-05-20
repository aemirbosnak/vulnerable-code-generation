//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 20
#define MAX_COLS 40

// Function to print the header of the pattern
void print_header(char ch, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%c", ch);
    }
    printf("\n");
}

// Function to print the body of the pattern
void print_body(int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("*");
        }
        printf("\n");
    }
}

// Function to print the footer of the pattern
void print_footer(char ch, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%c", ch);
    }
    printf("\n");
}

int main() {
    int rows, cols;
    char ch;

    // Get user input for number of rows and columns
    printf("Enter the number of rows (1-20): ");
    scanf("%d", &rows);
    printf("Enter the number of columns (1-40): ");
    scanf("%d", &cols);

    // Validate user input
    if (rows < 1 || rows > MAX_ROWS || cols < 1 || cols > MAX_COLS) {
        printf("Invalid input. Please enter a number between 1 and %d.\n", MAX_ROWS * MAX_COLS);
        return 1;
    }

    // Get user input for character to use in pattern
    printf("Enter the character to use in the pattern: ");
    scanf(" %c", &ch);

    // Print the pattern
    print_header(ch, rows);
    print_body(rows * cols);
    print_footer(ch, rows);

    return 0;
}
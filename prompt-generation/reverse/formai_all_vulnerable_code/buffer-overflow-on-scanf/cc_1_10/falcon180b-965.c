//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 20
#define MAX_COLS 40

// Function to print a pattern of asterisks
void print_asterisks(int num_rows, int num_cols) {
    int i, j;
    for (i = 0; i < num_rows; i++) {
        for (j = 0; j < num_cols; j++) {
            printf("*");
        }
        printf("\n");
    }
}

// Function to print a pattern of numbers
void print_numbers(int num_rows, int num_cols) {
    int i, j;
    for (i = 0; i < num_rows; i++) {
        for (j = 0; j < num_cols; j++) {
            printf("%d", i * num_cols + j + 1);
        }
        printf("\n");
    }
}

// Function to print a pattern of letters
void print_letters(int num_rows, int num_cols) {
    int i, j;
    char letter = 'A';
    for (i = 0; i < num_rows; i++) {
        for (j = 0; j < num_cols; j++) {
            printf("%c", letter);
            if (letter == 'Z') {
                letter = 'A';
            } else {
                letter++;
            }
        }
        printf("\n");
    }
}

int main() {
    int num_rows, num_cols;

    // Get user input for number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &num_rows);
    printf("Enter the number of columns: ");
    scanf("%d", &num_cols);

    // Validate user input
    if (num_rows <= 0 || num_rows > MAX_ROWS || num_cols <= 0 || num_cols > MAX_COLS) {
        printf("Invalid input. Please enter a number between 1 and %d for rows, and between 1 and %d for columns.\n", MAX_ROWS, MAX_COLS);
        return 1;
    }

    // Print patterns
    printf("\nPattern of asterisks:\n");
    print_asterisks(num_rows, num_cols);
    printf("\n\nPattern of numbers:\n");
    print_numbers(num_rows, num_cols);
    printf("\n\nPattern of letters:\n");
    print_letters(num_rows, num_cols);

    return 0;
}
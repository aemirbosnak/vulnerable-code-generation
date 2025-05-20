//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to print a pattern of asterisks
void print_pattern(int num_rows, int num_cols) {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            if (i % 2 == j % 2) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Function to print a diamond shape
void print_diamond(int num_rows) {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_rows; j++) {
            if (i == j) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int num_rows, num_cols;

    // Get the number of rows and columns from the user
    printf("Enter the number of rows: ");
    scanf("%d", &num_rows);
    printf("Enter the number of columns: ");
    scanf("%d", &num_cols);

    // Print a diamond shape
    print_diamond(num_rows);

    // Print a pattern of asterisks
    print_pattern(num_rows, num_cols);

    return 0;
}
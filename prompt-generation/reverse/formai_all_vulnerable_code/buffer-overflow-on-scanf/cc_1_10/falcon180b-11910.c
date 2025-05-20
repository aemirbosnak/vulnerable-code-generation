//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_PATTERN_LENGTH 100
#define MAX_ROWS 1000
#define MAX_COLS 1000

// Function prototypes
void generate_pattern(char pattern[MAX_PATTERN_LENGTH], int rows, int cols);
void print_pattern(char pattern[MAX_PATTERN_LENGTH], int rows, int cols);

int main() {
    int rows, cols;
    char pattern[MAX_PATTERN_LENGTH];

    // Get user input for number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Generate the pattern
    generate_pattern(pattern, rows, cols);

    // Print the pattern
    print_pattern(pattern, rows, cols);

    return 0;
}

// Generates a pattern of alternating characters
void generate_pattern(char pattern[MAX_PATTERN_LENGTH], int rows, int cols) {
    int i, j;
    char current_char = 'A';

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (i % 2 == 0 && j % 2 == 0) {
                pattern[i*cols+j] = current_char;
            } else if (i % 2 == 1 && j % 2 == 0) {
                pattern[i*cols+j] = 'B';
            } else if (i % 2 == 0 && j % 2 == 1) {
                pattern[i*cols+j] = 'C';
            } else {
                pattern[i*cols+j] = 'D';
            }

            current_char++;
        }
    }
}

// Prints the pattern
void print_pattern(char pattern[MAX_PATTERN_LENGTH], int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%c ", pattern[i*cols+j]);
        }
        printf("\n");
    }
}
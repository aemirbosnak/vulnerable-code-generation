//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ROWS 50
#define MAX_COLS 80

// Function to print the pattern
void print_pattern(int rows, int cols) {
    int i, j;
    char ch = '*';

    // Loop through each row
    for (i = 0; i < rows; i++) {
        // Loop through each column
        for (j = 0; j < cols; j++) {
            // Print the character
            printf("%c", ch);
        }

        // Move to the next line
        printf("\n");
    }
}

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random pattern
void generate_pattern(int rows, int cols) {
    int i, j;
    char ch;

    // Loop through each row
    for (i = 0; i < rows; i++) {
        // Loop through each column
        for (j = 0; j < cols; j++) {
            // Generate a random character
            ch = rand_num(0, 9) + '0';

            // Print the character
            printf("%c", ch);
        }

        // Move to the next line
        printf("\n");
    }
}

int main() {
    int rows, cols;

    // Get the number of rows and columns from the user
    printf("Enter the number of rows (1-50): ");
    scanf("%d", &rows);

    printf("Enter the number of columns (1-80): ");
    scanf("%d", &cols);

    // Check for valid input
    if (rows < 1 || rows > MAX_ROWS || cols < 1 || cols > MAX_COLS) {
        printf("Invalid input! Please enter valid values.\n");
        return 1;
    }

    // Print the pattern
    print_pattern(rows, cols);

    return 0;
}
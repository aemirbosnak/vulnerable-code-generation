//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: genious
#include <stdio.h>

#define MAX_ROWS 50
#define MAX_COLS 50

// Function to print the pattern
void printPattern(int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

// Function to generate a random number between min and max (inclusive)
int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    int rows, cols;

    // Get user input for number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Validate user input
    if (rows <= 0 || cols <= 0 || rows > MAX_ROWS || cols > MAX_COLS) {
        printf("Invalid input! Please enter values between 1 and %d.\n", MAX_ROWS * MAX_COLS);
        return 0;
    }

    // Generate random pattern
    int pattern[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            pattern[i][j] = randInt(0, 2);
        }
    }

    // Print the pattern
    printf("\nRandom pattern:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (pattern[i][j] == 0) {
                printf("* ");
            } else if (pattern[i][j] == 1) {
                printf("+ ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }

    return 0;
}
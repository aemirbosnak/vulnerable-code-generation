//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 20
#define MAX_COLS 20

// Function to print a pattern
void print_pattern(int rows, int cols) {
    // Initialize the pattern
    int pattern[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            pattern[i][j] = -1;
        }
    }

    // Generate the pattern
    int x = 0, y = 0, dir = 0;
    while (x < rows && y < cols) {
        if (dir == 0) {
            y++;
        } else if (dir == 1) {
            x++;
        } else if (dir == 2) {
            x--;
        } else {
            y--;
        }
        pattern[x][y] = 1;
        dir = (dir + 1) % 4;
    }

    // Print the pattern
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (pattern[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    printf("Enter the number of rows (1-20): ");
    scanf("%d", &rows);
    printf("Enter the number of columns (1-20): ");
    scanf("%d", &cols);

    // Validate input
    if (rows < 1 || rows > MAX_ROWS || cols < 1 || cols > MAX_COLS) {
        printf("Invalid input!\n");
        return 1;
    }

    // Print the pattern
    print_pattern(rows, cols);

    return 0;
}
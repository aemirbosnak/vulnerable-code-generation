//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 20
#define MAX_COLS 50

// Function to draw a heart pattern
void drawHeart(int row, int col, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if ((i - row) * (i - row) + (j - col) * (j - col) <= rows * rows) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Function to generate a random color
char* getRandomColor() {
    char colors[] = {'r', 'g', 'b', 'y', 'p', 'c','m'};
    return colors[rand() % 7];
}

// Function to set the background color of the console
void setBackgroundColor(char color) {
    printf("\33[48;2;%d;%d;%dm", rand() % 8 + 30, rand() % 6 + 40, rand() % 6 + 100);
}

// Function to print a random pattern
void printPattern(int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%c", getRandomColor());
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int rows, cols;

    // Get the number of rows and columns from the user
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Check if the input is valid
    if (rows <= 0 || cols <= 0 || rows > MAX_ROWS || cols > MAX_COLS) {
        printf("Invalid input. Please enter a number between 1 and %d.\n", MAX_ROWS * MAX_COLS);
        return 0;
    }

    // Print the pattern
    setBackgroundColor('w');
    printf(" ");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c", getRandomColor());
        }
        printf("\n");
    }

    // Draw a heart pattern
    drawHeart(rows / 2, cols / 2, rows, cols);

    return 0;
}
//FormAI DATASET v1.0 Category: Pattern printing ; Style: standalone
#include <stdio.h>

// Function to print the pattern
void printPattern(int n)
{
    int height = n;
    int width = n;
    int matrix[height][width];

    int currentRow = 0;
    int currentCol = 0;
    int num = 1;

    while (num <= n * n) {
        // Move right, set current row element and increment column index
        while (currentCol < width && !matrix[currentRow][currentCol]) {
            matrix[currentRow][currentCol++] = num++;
        }
        currentCol--;
        currentRow++;

        // Move down, set current column element and increment row index
        while (currentRow < height && !matrix[currentRow][currentCol]) {
            matrix[currentRow++][currentCol] = num++;
        }
        currentRow--;
        currentCol--;

        // Move left, set current row element and decrement column index
        while (currentCol >= 0 && !matrix[currentRow][currentCol]) {
            matrix[currentRow][currentCol--] = num++;
        }
        currentCol++;
        currentRow--;

        // Move up, set current column element and decrement row index
        while (currentRow >= 0 && !matrix[currentRow][currentCol]) {
            matrix[currentRow--][currentCol] = num++;
        }
        currentRow++;
        currentCol++;
    }

    // Print the matrix
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Check if input is greater than 0
    if (n <= 0) {
        printf("Invalid input value.");
        return 0;
    }

    // Print the pattern
    printPattern(n);

    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: mind-bending
// Delve into the depths of enigmatic data, where patterns dance like shadows and insights emerge from the cosmic void.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the dimensions of our mind-bending matrix
#define ROWS 7
#define COLUMNS 13

// Construct our cosmic data matrix
int matrix[ROWS][COLUMNS] = {
    {0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1}
};

// Embark on our journey of discovery
int main() {

    // Initialize our cosmic variables
    int row, column, sum;

    // Traverse the rows and columns of our enigmatic matrix
    for (row = 0; row < ROWS; row++) {
        for (column = 0; column < COLUMNS; column++) {
            // Calculate the sum of each row
            sum += matrix[row][column];
        }

        // Ponder upon the wisdom of each row's sum
        printf("Row %d: Sum %d\n", row, sum);

        // Reset the sum for the next row
        sum = 0;
    }

    // Contemplate the columns and their cosmic secrets
    for (column = 0; column < COLUMNS; column++) {
        for (row = 0; row < ROWS; row++) {
            // Calculate the sum of each column
            sum += matrix[row][column];
        }

        // Marvel at the insights from each column's sum
        printf("Column %d: Sum %d\n", column, sum);

        // Reset the sum for the next column
        sum = 0;
    }

    // Float through the ethereal realm of data, seeking hidden truths
    int maxRowSum = 0, maxRowIndex = -1;
    int maxColumnSum = 0, maxColumnIndex = -1;

    // Find the row with the greatest sum, its cosmic gatekeeper
    for (row = 0; row < ROWS; row++) {
        sum = 0;

        for (column = 0; column < COLUMNS; column++) {
            sum += matrix[row][column];
        }

        // Update the cosmic guardians if a new king or queen emerges
        if (sum > maxRowSum) {
            maxRowSum = sum;
            maxRowIndex = row;
        }
    }

    // Now, turn our gaze to the columns, seeking the mightiest
    for (column = 0; column < COLUMNS; column++) {
        sum = 0;

        for (row = 0; row < ROWS; row++) {
            sum += matrix[row][column];
        }

        // Crown the column with the highest sum as the cosmic overlord
        if (sum > maxColumnSum) {
            maxColumnSum = sum;
            maxColumnIndex = column;
        }
    }

    // Proclaim the cosmic guardians of our data realm
    printf("Row %d wields the greatest sum: %d\n", maxRowIndex, maxRowSum);
    printf("Column %d stands tall, its sum reaching: %d\n", maxColumnIndex, maxColumnSum);

    return 0;
}
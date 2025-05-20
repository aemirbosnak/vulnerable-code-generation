//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: multivariable
#include <stdio.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 5

bool search2D(int arr[ROWS][COLS], int value, int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        if (arr[row][col] == value) {
            return true;
        }

        if (arr[row][col + 1] && arr[row][col + 1] != value) {
            return search2D(arr, value, row, col + 1);
        }

        if (col > 0) {
            return search2D(arr, value, row, col - 1);
        }

        if (row < ROWS - 1) {
            return search2D(arr, value, row + 1, 0);
        }
    }

    return false;
}

int main() {
    int arr[ROWS][COLS] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int value;
    printf("Enter the value to search: ");
    scanf("%d", &value);

    bool result = search2D(arr, value, 0, 0);

    if (result) {
        printf("Value found at row %d, column %d.\n", (int) ((value - 1) / COLS) + 1, (int) ((value - 1) % COLS) + 1);
    } else {
        printf("Value not found.\n");
    }

    return 0;
}
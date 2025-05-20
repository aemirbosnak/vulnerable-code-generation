//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main() {

    char arr[9][9]; // 2D array to hold the Sudoku puzzle

    int i, j, k, count = 0; // Variables for iteration and counting

    printf("Enter the Sudoku puzzle:\n");

    for(i = 0; i < 9; i++) {
        for(j = 0; j < 9; j++) {
            scanf("%c", &arr[i][j]); // Reading the puzzle from user input
        }
    }

    for(i = 0; i < 9; i++) {
        for(j = 0; j < 9; j++) {

            if(arr[i][j]!= '.') { // Checking for empty cells

                int value = arr[i][j] - '0'; // Converting the character to integer

                for(k = 0; k < 9; k++) {

                    if(i == k && j == k) { // Checking the same row
                        continue;
                    }

                    if(i == k) { // Checking the same column
                        if(arr[k][j] == value) {
                            printf("Error! Same value %d found in same column.\n", value);
                            return 0;
                        }
                    }

                    if(j == k) { // Checking the same box
                        int box_row = (i - i % 3) + k % 3;
                        int box_col = (j - j % 3) + k % 3;

                        if(arr[box_row][box_col] == value) {
                            printf("Error! Same value %d found in same box.\n", value);
                            return 0;
                        }
                    }
                }

                count++; // Incrementing the count of filled cells
            }
        }
    }

    if(count == 81) { // Checking if all cells are filled
        printf("Congratulations! The Sudoku puzzle is valid.\n");
    } else {
        printf("Error! The Sudoku puzzle is invalid.\n");
    }

    return 0;
}
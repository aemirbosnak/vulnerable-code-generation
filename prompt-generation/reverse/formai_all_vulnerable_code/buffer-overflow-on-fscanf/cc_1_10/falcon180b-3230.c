//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Function to print the 2D array
void print_array(int arr[9][9]) {
    int i, j;
    for(i=0; i<9; i++) {
        for(j=0; j<9; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a given number is valid in a given row
int is_valid_row(int arr[9][9], int row, int num) {
    int i;
    for(i=0; i<9; i++) {
        if(arr[row][i] == num) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a given number is valid in a given column
int is_valid_col(int arr[9][9], int col, int num) {
    int i;
    for(i=0; i<9; i++) {
        if(arr[i][col] == num) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a given number is valid in a given 3x3 box
int is_valid_box(int arr[9][9], int row, int col, int num) {
    int i, j;
    for(i=row-row%3; i<row+row%3; i++) {
        for(j=col-col%3; j<col+col%3; j++) {
            if(arr[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to solve the Sudoku puzzle recursively
int solve_sudoku(int arr[9][9], int row, int col) {
    if(row == 8) {
        return 1;
    }
    col++;
    if(col == 9) {
        return solve_sudoku(arr, row+1, 0);
    }
    if(arr[row][col]!= 0) {
        return solve_sudoku(arr, row, col+1);
    }
    for(int num=1; num<=9; num++) {
        if(is_valid_row(arr, row, num) && is_valid_col(arr, col, num) && is_valid_box(arr, row-row%3, col-col%3, num)) {
            arr[row][col] = num;
            if(solve_sudoku(arr, row, col+1)) {
                return 1;
            }
        }
    }
    arr[row][col] = 0;
    return 0;
}

// Main function to read the Sudoku puzzle from a file and solve it
int main() {
    FILE *fp;
    int arr[9][9];
    char ch;
    int i, j;
    fp = fopen("sudoku.txt", "r");
    if(fp == NULL) {
        printf("Error opening file\n");
        exit(0);
    }
    for(i=0; i<9; i++) {
        for(j=0; j<9; j++) {
            fscanf(fp, "%c", &ch);
            if(ch == '0') {
                arr[i][j] = 0;
            }
            else {
                arr[i][j] = ch-'1';
            }
        }
    }
    fclose(fp);
    printf("Original Sudoku puzzle:\n");
    print_array(arr);
    solve_sudoku(arr, 0, 0);
    printf("\n\nSolved Sudoku puzzle:\n");
    print_array(arr);
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ROWS 9
#define MAX_COLS 9
#define MAX_SUBGRIDS 9

int rows[MAX_ROWS][MAX_COLS];
int cols[MAX_COLS][MAX_COLS];
int subgrids[MAX_SUBGRIDS][MAX_COLS];

bool isValid(int row, int col, int num) {
    for(int i=0; i<col; i++) {
        if(rows[row][i] == num) {
            return false;
        }
    }
    for(int i=row; i<MAX_ROWS; i+=3) {
        for(int j=0; j<col; j+=3) {
            if(subgrids[i/3][j/3] == num) {
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(int row, int col) {
    if(col == MAX_COLS) {
        col = 0;
        row++;
        if(row == MAX_ROWS) {
            return;
        }
    }
    if(rows[row][col] == 0) {
        for(int i=1; i<=MAX_COLS; i++) {
            if(isValid(row, col, i)) {
                rows[row][col] = i;
                cols[col][i-1] = true;
                subgrids[row/3][col/3] = i;
                solveSudoku(row, col+1);
                if(col == MAX_COLS) {
                    return;
                }
                rows[row][col] = 0;
                cols[col][i-1] = false;
                subgrids[row/3][col/3] = 0;
            }
        }
    } else {
        solveSudoku(row, col+1);
    }
}

int main() {
    int i, j, num;
    for(i=0; i<MAX_ROWS; i++) {
        for(j=0; j<MAX_COLS; j++) {
            scanf("%d", &rows[i][j]);
            if(rows[i][j] == 0) {
                break;
            }
        }
        if(j == MAX_COLS) {
            return 0;
        }
    }
    solveSudoku(0, 0);
    for(i=0; i<MAX_ROWS; i++) {
        for(j=0; j<MAX_COLS; j++) {
            printf("%d ", rows[i][j]);
        }
        printf("\n");
    }
    return 0;
}
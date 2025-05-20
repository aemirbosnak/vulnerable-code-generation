//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

#define N 9
#define M 9
#define MAX_VALUE 9

int board[M][N];
int value[M][N];

int isValid(int row, int col, int num) {
    for(int i=0; i<N; i++) {
        if(value[row][i] == num) {
            return 0;
        }
    }
    for(int j=0; j<M; j++) {
        if(value[j][col] == num) {
            return 0;
        }
    }
    int box_row = (row/3)*3;
    int box_col = (col/3)*3;
    for(int i=box_row; i<box_row+3; i++) {
        for(int j=box_col; j<box_col+3; j++) {
            if(value[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

void backtrack(int row, int col) {
    if(row == M) {
        for(int i=0; i<M; i++) {
            for(int j=0; j<N; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
        exit(0);
    }
    if(col == N) {
        row++;
        col = 0;
    }
    if(isValid(row, col, value[row][col]+1)) {
        value[row][col]++;
        backtrack(row, col+1);
    } else {
        value[row][col] = 0;
        backtrack(row, col);
    }
}

int main() {
    int i, j;
    for(i=0; i<M; i++) {
        for(j=0; j<N; j++) {
            printf("Enter the value for (%d, %d): ", i+1, j+1);
            scanf("%d", &board[i][j]);
            if(board[i][j] < 1 || board[i][j] > MAX_VALUE) {
                printf("Invalid input! Please enter a number between 1 and %d.\n", MAX_VALUE);
                exit(0);
            }
        }
    }
    int count = 0;
    for(i=0; i<M; i++) {
        for(j=0; j<N; j++) {
            if(board[i][j] == 0) {
                count++;
            }
        }
    }
    if(count!= (M*N - 81)) {
        printf("Invalid input! Please enter a valid Sudoku puzzle.\n");
        exit(0);
    }
    backtrack(0, 0);
    return 0;
}
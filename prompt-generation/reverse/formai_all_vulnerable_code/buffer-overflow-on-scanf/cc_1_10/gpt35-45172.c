//FormAI DATASET v1.0 Category: Sudoku solver ; Style: immersive
#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

int board[SIZE][SIZE];

bool validate_board(int row, int col, int num){
    int i, j;
    /* Check row and column */
    for(i = 0; i < SIZE; i++){
        if(board[row][i] == num || board[i][col] == num)
            return false;
    }
    /* Check 3 x 3 box */
    int row_start = (row / 3) * 3;
    int col_start = (col / 3) * 3;
    for(i = row_start; i < row_start + 3; i++){
        for(j = col_start; j < col_start + 3; j++){
            if(board[i][j] == num)
                return false;
        }
    }
    return true;
}

bool solve_board(){
    int row, col, num;
    for(row = 0; row < SIZE; row++){
        for(col = 0; col < SIZE; col++){
            /* Empty cell found, try to fill it */
            if(board[row][col] == 0){
                for(num = 1; num <= SIZE; num++){
                    if(validate_board(row, col, num)){
                        board[row][col] = num;
                        if(solve_board())
                            return true;
                        else
                            board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void print_board(){
    int i, j;
    printf("Board:\n");
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    /* Initialize board */
    int i, j;
    printf("Enter board:\n");
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            scanf("%d", &board[i][j]);
        }
    }
    /* Solve board */
    if(solve_board())
        print_board();
    else
        printf("No solution found!\n");
    return 0;
}
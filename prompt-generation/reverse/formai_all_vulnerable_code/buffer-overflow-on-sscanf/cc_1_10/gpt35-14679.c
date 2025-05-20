//FormAI DATASET v1.0 Category: Memory Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initializeBoard(int board[][COLS])
{
    int i, j, count = 1;
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLS; j++){
            board[i][j] = count++;
        }
    }
}

void shuffleBoard(int board[][COLS])
{
    int i, j, temp;
    srand(time(NULL));
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLS; j++){
            int row = rand() % ROWS;
            int col = rand() % COLS;
            temp = board[i][j];
            board[i][j] = board[row][col];
            board[row][col] = temp;
        }
    }
}

void printBoard(int board[][COLS], int showNumbers)
{
    int i, j;
    printf("\n");
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLS; j++){
            if(showNumbers == 0 && board[i][j] != ROWS * COLS){
                printf("%3c", '.');
            }
            else{
                printf("%3d", board[i][j]);
            }
        }
        printf("\n");
    }
}

void getMove(int *row, int *col)
{
    char input[10];
    printf("Enter row number and column number: ");
    fgets(input, 10, stdin);
    sscanf(input, "%d %d", row, col);
}

int isMoveValid(int board[][COLS], int row, int col)
{
    if(row >= 0 && row < ROWS && col >= 0 && col < COLS && board[row][col] == ROWS * COLS){
        return 1;
    }
    else{
        return 0;
    }
}

int isGameOver(int board[][COLS])
{
    int i, j, count = 1;
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLS; j++){
            if(board[i][j] != count && board[i][j] != ROWS * COLS){
                return 0;
            }
            count++;
        }
    }
    return 1;
}

int main()
{
    int board[ROWS][COLS];
    int row, col, tempRow, tempCol, moves = 0;
    initializeBoard(board);
    shuffleBoard(board);
    printBoard(board, 0);
    while(!isGameOver(board)){
        getMove(&row, &col);
        if(isMoveValid(board, row, col)){
            tempRow = -1;
            tempCol = -1;
            // search for empty tile
            int i, j;
            for(i = 0; i < ROWS; i++){
                for(j = 0; j < COLS; j++){
                    if(board[i][j] == ROWS * COLS){
                        tempRow = i;
                        tempCol = j;
                        break;
                    }
                }
                if(tempRow != -1){
                    break;
                }
            }
            // swap tiles
            board[tempRow][tempCol] = board[row][col];
            board[row][col] = ROWS * COLS;
            moves++;
            printBoard(board, 0);
        }
        else{
            printf("Invalid move. Try again.\n");
        }
    }
    printf("Congratulations! You solved the puzzle in %d moves.\n", moves);
    return 0;
}
//FormAI DATASET v1.0 Category: Table Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void printBoard(char board[ROWS][COLS]);
int getRow();
int getCol();
void computerMove(char board[ROWS][COLS]);
int checkWin(char board[ROWS][COLS], char symbol);

int main(){
    char board[ROWS][COLS] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    char player = 'X';
    int moves = 0;

    printf("Welcome to the C Table Game!\n");
    printBoard(board);

    while(moves < 9){
        int row = getRow();
        int col = getCol();

        if(board[row][col] != 'X' && board[row][col] != 'O'){
            board[row][col] = player;

            if(checkWin(board, player) == 1){
                printf("Player %c wins!\n", player);
                printBoard(board);
                return 0;
            }

            moves++;
            player = (player == 'X') ? 'O' : 'X';

            if(moves != 9){
                computerMove(board);

                if(checkWin(board, player) == 1){
                    printf("Player %c wins!\n", player);
                    printBoard(board);
                    return 0;
                }

                moves++;
                player = (player == 'X') ? 'O' : 'X';
            }
        }
        printBoard(board);
    }

    printf("It's a tie!\n");
    return 0;
}


void printBoard(char board[ROWS][COLS]){
    printf("\n");
    printf("\t %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int getRow(){
    int row = -1;
    while(row < 0 || row > 2){
        printf("Enter row (0-2): ");
        scanf("%d", &row);
    }
    return row;
}

int getCol(){
    int col = -1;
    while(col < 0 || col > 2){
        printf("Enter column (0-2): ");
        scanf("%d", &col);
    }
    return col;
}

void computerMove(char board[ROWS][COLS]){
    int row, col;

    srand(time(NULL));
    row = rand() % 3;
    col = rand() % 3;

    while(board[row][col] == 'X' || board[row][col] == 'O'){
        row = rand() % 3;
        col = rand() % 3;
    }

    printf("Computer selects %d %d\n", row, col);
    board[row][col] = 'O';
}

int checkWin(char board[ROWS][COLS], char symbol){
    int i;

    for(i = 0; i < 3; i++){
        if(board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol){
            return 1;
        }
        if(board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol){
            return 1;
        }
    }

    if(board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol){
        return 1;
    }
    if(board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol){
        return 1;
    }

    return 0;
}
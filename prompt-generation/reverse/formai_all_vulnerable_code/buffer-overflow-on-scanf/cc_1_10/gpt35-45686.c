//FormAI DATASET v1.0 Category: Table Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void initializeBoard(int board[ROWS][COLS]);
void displayBoard(int board[ROWS][COLS]);
int checkWin(int board[ROWS][COLS], int player);
int getComputerMove(int board[ROWS][COLS], int computer);
int getPlayerMove(int board[ROWS][COLS], int player);
void playGame(int board[ROWS][COLS]);

int main()
{
    int board[ROWS][COLS];
    initializeBoard(board);
    playGame(board);
    return 0;
}

void initializeBoard(int board[ROWS][COLS])
{
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

void displayBoard(int board[ROWS][COLS])
{
    int i, j;
    printf("  1 2 3\n");
    for(i = 0; i < ROWS; i++) {
        printf("%d ", i + 1);
        for(j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(int board[ROWS][COLS], int player)
{
    int i, j, win = 0;
    char p = '-';
    if(player == 1) {
        p = 'X';
    } else if(player == 2) {
        p = 'O';
    }
    for(i = 0; i < ROWS; i++) {
        if(board[i][0] == p && board[i][1] == p && board[i][2] == p) {
            win = 1;
            break;
        }
    }
    for(j = 0; j < COLS; j++) {
        if(board[0][j] == p && board[1][j] == p && board[2][j] == p) {
            win = 1;
            break;
        }
    }
    if(board[0][0] == p && board[1][1] == p && board[2][2] == p) {
        win = 1;
    }
    if(board[0][2] == p && board[1][1] == p && board[2][0] == p) {
        win = 1;
    }
    return win;
}

int getPlayerMove(int board[ROWS][COLS], int player)
{
    int row, col, valid = 0;
    char p = '-';
    if(player == 1) {
        p = 'X';
    } else if(player == 2) {
        p = 'O';
    }
    while(!valid) {
        printf("Player %d, enter row (1-3) and column (1-3) separated by a space: ", player);
        scanf("%d %d", &row, &col);
        row--;
        col--;
        if(row >= 0 && row < ROWS && col >= 0 && col < COLS && board[row][col] == '-') {
            board[row][col] = p;
            valid = 1;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
    return checkWin(board, player);
}

int getComputerMove(int board[ROWS][COLS], int computer)
{
    int row, col, valid = 0;
    char p = '-';
    if(computer == 1) {
        p = 'X';
    } else if(computer == 2) {
        p = 'O';
    }
    while(!valid) {
        row = rand() % ROWS;
        col = rand() % COLS;
        if(board[row][col] == '-') {
            board[row][col] = p;
            valid = 1;
        }
    }
    return checkWin(board, computer);
}

void playGame(int board[ROWS][COLS])
{
    int player = 1, computer = 2, turn = 1, win = 0;
    srand(time(NULL));
    printf("C Table Game: Tic Tac Toe\n");
    printf("Player 1 is X, and Player 2 is O. Player 1 goes first.\n\n");
    while(!win && turn <= 9) {
        displayBoard(board);
        if(player == 1) {
            win = getPlayerMove(board, player);
        } else {
            win = getComputerMove(board, player);
        }
        if(win) {
            printf("Player %d wins!\n", player);
            displayBoard(board);
            break;
        }
        if(turn == 9) {
            printf("It's a tie!\n");
            displayBoard(board);
            break;
        }
        player = player == 1 ? 2 : 1;
        turn++;
    }
}
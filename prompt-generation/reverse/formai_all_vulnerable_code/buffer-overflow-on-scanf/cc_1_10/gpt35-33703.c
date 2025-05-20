//FormAI DATASET v1.0 Category: Table Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void init_board(char board[ROWS][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = '-';
        }
    }
}

void print_board(char board[ROWS][COLS]) {
    printf("-------------\n");
    for(int i=0; i<ROWS; i++) {
        printf("| ");
        for(int j=0; j<COLS; j++) {
            printf("%c | ", board[i][j]);
        }
        printf("\n-------------\n");
    }
}

void update_board(char board[ROWS][COLS], int row, int col, char symbol) {
    board[row][col] = symbol;
}

int check_winner(char board[ROWS][COLS]) {
    // check rows
    for(int i=0; i<ROWS; i++) {
        if(board[i][0] != '-' && board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return 1; // game won by player 1
        }
        if(board[i][0] != '-' && board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return 2; // game won by player 2
        }
    }
    // check columns
    for(int j=0; j<COLS; j++) {
        if(board[0][j] != '-' && board[0][j] == board[1][j] && board[0][j] == board[2][j]) {
            return 1; // game won by player 1
        }
        if(board[0][j] != '-' && board[0][j] == board[1][j] && board[0][j] == board[2][j]) {
            return 2; // game won by player 2
        }
    }
    // check diagonals
    if(board[0][0] != '-' && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return 1; // game won by player 1
    }
    if(board[0][0] != '-' && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return 2; // game won by player 2
    }
    if(board[0][2] != '-' && board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return 1; // game won by player 1
    }
    if(board[0][2] != '-' &&board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return 2; // game won by player 2
    }
    return 0;
}

int main() {
    char board[ROWS][COLS];
    init_board(board);
    srand(time(NULL));
    int player = 1;
    printf("Player 1: X\n");
    printf("Player 2: O\n");
    printf("\n");
    while(1) {
        print_board(board);
        int row, col;
        printf("Player %d, enter row and column number (1-3) to place your symbol (%c): ", player, (player==1) ? 'X' : 'O');
        scanf("%d %d", &row, &col);
        row--; col--; // adjust for 0-based indexing
        if(row < 0 || row >= ROWS || col < 0 || col >= COLS || board[row][col] != '-') {
            printf("Invalid move! Try again.\n");
            continue;
        }
        update_board(board, row, col, (player==1) ? 'X' : 'O');
        int winner = check_winner(board);
        if(winner) {
            printf("Player %d wins!\n", winner);
            print_board(board);
            break;
        }
        int empty_spots = 0;
        for(int i=0; i<ROWS; i++) {
            for(int j=0; j<COLS; j++) {
                if(board[i][j] == '-') {
                    empty_spots++;
                }
            }
        }
        if(empty_spots == 0) {
            printf("It's a tie!\n");
            print_board(board);
            break;
        }
        player = (player==1) ? 2 : 1;
    }
    printf("Game over!\n");
    return 0;
}
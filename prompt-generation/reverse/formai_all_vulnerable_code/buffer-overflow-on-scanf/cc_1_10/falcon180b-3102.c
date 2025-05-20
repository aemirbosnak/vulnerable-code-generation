//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3
#define PLAYERS 2

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win(char board[BOARD_SIZE][BOARD_SIZE], char player) {
    // Check horizontal lines
    for(int i=0; i<BOARD_SIZE; i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    // Check vertical lines
    for(int j=0; j<BOARD_SIZE; j++) {
        if(board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1;
        }
    }

    // Check diagonals
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    return 0;
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }

    int player = 0;
    while(1) {
        system("clear");
        print_board(board);

        int x, y;
        printf("Player %d's turn. Enter your move: ", player + 1);
        scanf("%d%d", &x, &y);

        if(x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board[x][y] == '-') {
            board[x][y] = (player == 0? 'X' : 'O');

            if(check_win(board, player == 0? 'X' : 'O')) {
                printf("Player %d wins!\n", player + 1);
                break;
            }

            player =!player;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

int board[BOARD_SIZE][BOARD_SIZE];

void initialize_board() {
    int i, j;

    for(i=0; i<BOARD_SIZE; i++) {
        for(j=0; j<BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

void display_board() {
    int i, j;

    for(i=0; i<BOARD_SIZE; i++) {
        for(j=0; j<BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int check_winner() {
    int i, j;

    // Check horizontal lines
    for(i=0; i<BOARD_SIZE; i++) {
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2]) {
            if(board[i][0]!=0) {
                return board[i][0];
            }
        }
    }

    // Check vertical lines
    for(i=0; i<BOARD_SIZE; i++) {
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i]) {
            if(board[0][i]!=0) {
                return board[0][i];
            }
        }
    }

    // Check diagonal lines
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]) {
        if(board[0][0]!=0) {
            return board[0][0];
        }
    }

    if(board[0][2]==board[1][1] && board[1][1]==board[2][0]) {
        if(board[0][2]!=0) {
            return board[0][2];
        }
    }

    return 0;
}

// TODO: Implement the AI move

int main() {
    int player = 1, i, j, move, winner;

    initialize_board();

    while(1) {
        printf("Player %d, enter a move: ", player);

        scanf("%d", &move);

        i = (move-1) / BOARD_SIZE;
        j = (move-1) % BOARD_SIZE;

        if(board[i][j]!=0) {
            printf("Illegal move!\n");
            continue;
        }

        board[i][j] = player;

        display_board();

        winner = check_winner();

        if(winner!=0) {
            printf("Congratulations! Player %d is the winner!\n", winner);
            break;
        }

        player = (player==1) ? 2 : 1;
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Checkers Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
} Piece;

void print_board(Piece board[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j].row == 1) {
                printf("X ");
            } else if (board[i][j].row == 2) {
                printf("O ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

int check_winner(Piece board[8][8]) {
    for (int i = 0; i < 8; i++) {
        if ((board[i][0].row == board[i][1].row && board[i][1].row == board[i][2].row) ||
            (board[0][i].row == board[1][i].row && board[1][i].row == board[2][i].row)) {
            return board[i][0].row;
        }
    }
    if ((board[0][0].row == board[1][1].row && board[1][1].row == board[2][2].row) ||
        (board[0][2].row == board[1][1].row && board[1][1].row == board[2][0].row)) {
        return board[0][0].row;
    }
    return 0;
}

int main() {
    Piece board[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j].row = -1;
        }
    }
    int player = 1;
    int choice;
    while (player!= 0) {
        system("clear");
        print_board(board);
        printf("Player %d's turn.\n", player);
        printf("Enter your move (row and column): ");
        scanf("%d%d", &choice, &choice);
        int row = choice / 3;
        int col = choice % 3;
        if (board[row][col].row!= -1) {
            printf("Invalid move.\n");
            continue;
        }
        board[row][col].row = player;
        player = (player == 1)? 2 : 1;
        if (check_winner(board)!= 0) {
            printf("Player %d wins!\n", player);
            break;
        }
    }
    return 0;
}
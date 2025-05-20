//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win(char board[BOARD_SIZE][BOARD_SIZE]) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    int player = 1;
    int choice;

    while (1) {
        system("clear");
        print_board(board);
        printf("\nPlayer %d's turn.\n", player);

        printf("Enter your move (1-9): ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 9) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (board[row][col]!= 'X' && board[row][col]!= 'O') {
            board[row][col] = (player == 1)? 'X' : 'O';
            player = (player == 1)? 2 : 1;

            if (check_win(board)) {
                printf("\nPlayer %d wins!\n", player);
                break;
            }
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}
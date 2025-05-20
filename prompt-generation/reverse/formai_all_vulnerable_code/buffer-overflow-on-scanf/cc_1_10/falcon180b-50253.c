//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: futuristic
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

int is_valid_move(char board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
    if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == '\0') {
        return 1;
    } else {
        return 0;
    }
}

int check_winner(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if ((board[i][0]!= '\0' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i]!= '\0' && board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return 1;
        }
    }

    if (board[0][0]!= '\0' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    } else if (board[0][2]!= '\0' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE] = { {'0', '1', '2'}, {'3', '4', '5'}, {'6', '7', '8'} };
    int player = 1;
    int choice;
    int valid_move = 0;

    while (1) {
        system("clear");
        print_board(board);
        printf("\nPlayer %d's turn.\n", player);

        valid_move = 0;
        while (!valid_move) {
            printf("Enter your move (row and column): ");
            scanf("%d%d", &choice, &choice);
            if (is_valid_move(board, choice, choice)) {
                board[choice][choice] = (player % 2 == 0)? 'X' : 'O';
                valid_move = 1;
            } else {
                printf("Invalid move. Try again.\n");
            }
        }

        if (check_winner(board)) {
            printf("\nPlayer %d wins!\n", player);
            break;
        } else if (player % 2 == 0) {
            player++;
        } else {
            player--;
        }
    }

    return 0;
}
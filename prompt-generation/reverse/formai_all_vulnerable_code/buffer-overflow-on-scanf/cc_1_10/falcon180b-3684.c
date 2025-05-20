//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

char board[SIZE][SIZE] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };

void print_board() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win() {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    return 0;
}

int main() {
    srand(time(NULL));
    int player = rand() % 2;
    int choice;

    while (1) {
        system("clear");
        print_board();
        printf("\nPlayer %d's turn.\n", player + 1);
        printf("Enter your move: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 9) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (board[row][col]!= 'X' && board[row][col]!= 'O') {
            if (player == 0)
                board[row][col] = 'X';
            else
                board[row][col] = 'O';

            if (check_win()) {
                printf("\nPlayer %d wins!\n", player + 1);
                break;
            }

            player =!player;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}
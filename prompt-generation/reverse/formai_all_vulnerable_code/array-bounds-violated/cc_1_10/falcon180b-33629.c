//Falcon-180B DATASET v1.0 Category: Table Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

void print_board(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int check_winner(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2]!= 0) {
            return board[i][2];
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i]!= 0) {
            return board[2][i];
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2]!= 0) {
        return board[2][2];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0]!= 0) {
        return board[2][0];
    }
    return 0;
}

int main() {
    srand(time(NULL));
    int board[SIZE][SIZE] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int player = 1;
    int choice;
    int valid_choice = 0;

    while (player!= 0) {
        system("clear");
        printf("Player 1: X, Player 2: O\n");
        printf("Player %d's turn\n", player);
        print_board(board);
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice >= 1 && choice <= SIZE * SIZE && board[choice / SIZE][choice % SIZE] == 0) {
            board[choice / SIZE][choice % SIZE] = player;
            valid_choice = 1;
        } else {
            printf("Invalid choice\n");
        }
        if (valid_choice) {
            if (check_winner(board)!= 0) {
                printf("Player %d wins!\n", player);
                break;
            } else if (player == 1) {
                player = 2;
            } else {
                player = 1;
            }
        } else {
            player =!player;
        }
    }
    return 0;
}
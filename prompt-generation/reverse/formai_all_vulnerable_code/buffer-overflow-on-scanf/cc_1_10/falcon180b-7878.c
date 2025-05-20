//Falcon-180B DATASET v1.0 Category: Table Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3
#define MAX_VALUE 10

void print_board(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int board[ROWS][COLS];
    int player = 1;
    int choice;
    int valid_choice;
    int flag = 0;
    srand(time(NULL));

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % MAX_VALUE;
        }
    }

    while (!flag) {
        printf("Player %d's turn:\n", player);
        print_board(board);
        printf("Enter your choice (row, column): ");
        scanf("%d %d", &choice, &valid_choice);

        if (choice >= 0 && choice < ROWS && valid_choice >= 0 && valid_choice < COLS) {
            if (board[choice][valid_choice] == 0) {
                board[choice][valid_choice] = player;
                player = (player == 1)? 2 : 1;
            } else {
                printf("Invalid move! Try again.\n");
            }
        } else {
            printf("Invalid choice! Try again.\n");
        }

        flag = check_winner(board);
    }

    printf("Game over! Player %d wins!\n", player);

    return 0;
}

int check_winner(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    for (int j = 0; j < COLS; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}
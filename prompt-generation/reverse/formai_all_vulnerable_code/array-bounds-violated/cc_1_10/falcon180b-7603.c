//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

int main() {
    int board[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int player = 1;
    int choice;
    int flag = 0;

    srand(time(0));

    while (flag == 0) {
        system("clear");
        printf("Player 1's Turn\n");
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice > 9 || choice < 1) {
            printf("Invalid choice. Try again.\n");
        } else if (board[choice / 3 - 1][choice % 3 - 1]!= 0) {
            printf("Sorry, that spot is already taken.\n");
        } else {
            board[choice / 3 - 1][choice % 3 - 1] = player;
            player++;

            if (player > 2) {
                player = 1;
            }

            if (check_win(board, player)) {
                printf("\nPlayer %d wins!\n", player);
                flag = 1;
            } else if (is_board_full(board)) {
                printf("\nIt's a tie.\n");
                flag = 1;
            }
        }
    }

    return 0;
}

int check_win(int board[ROWS][COLS], int player) {
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    for (int j = 0; j < COLS; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1;
        }
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    return 0;
}

int is_board_full(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 0) {
                return 0;
            }
        }
    }

    return 1;
}
//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void init_board(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = -1;
        }
    }
}

int get_random_number() {
    return rand() % 8;
}

int check_win(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3]) {
            return 1;
        }
    }

    for (int j = 0; j < COLS; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[2][j] == board[3][j]) {
            return 1;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3]) {
        return 1;
    }

    if (board[0][3] == board[1][2] && board[1][2] == board[2][1] && board[2][1] == board[3][0]) {
        return 1;
    }

    return 0;
}

int main() {
    srand(time(NULL));

    int board[ROWS][COLS];
    init_board(board);

    int player = 1;
    int choice;
    int flag = 0;

    while (flag == 0) {
        printf("\nPlayer %d's turn\n", player);
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice >= 0 && choice < 8 && board[player-1][choice] == -1) {
            board[player-1][choice] = player;
            player++;

            if (player > 2) {
                player = 1;
            }

            if (check_win(board)) {
                printf("\nPlayer %d wins!\n", player-1);
                flag = 1;
            }
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
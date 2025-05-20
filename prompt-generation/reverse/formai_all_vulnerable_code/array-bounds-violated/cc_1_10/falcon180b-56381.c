//Falcon-180B DATASET v1.0 Category: Table Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_board(int board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win(int board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
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

int main() {
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int player = 1;
    int move_count = 0;
    int win_count = 0;
    int choice;

    srand(time(NULL));
    printf("Player 1: X, Player 2: O\n");

    while (1) {
        system("clear");
        printf("Player %d's turn.\n", player);
        printf("Enter your move (1-9): ");
        scanf("%d", &choice);
        move_count++;

        if (choice < 1 || choice > 9) {
            printf("Invalid move.\n");
            continue;
        }

        if (board[choice/3][choice%3]!= 0) {
            printf("Spot taken.\n");
            continue;
        }

        board[choice/3][choice%3] = (player == 1)? 1 : 2;
        player = (player == 1)? 2 : 1;

        if (check_win(board)) {
            printf("Player %d wins!\n", player);
            win_count++;
            break;
        } else if (move_count == 9) {
            printf("Tie game.\n");
            break;
        }
    }

    print_board(board);

    return 0;
}
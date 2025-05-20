//Falcon-180B DATASET v1.0 Category: Table Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_board(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win(char board[3][3], char player) {
    // Check horizontal lines
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    // Check vertical lines
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1;
        }
    }

    // Check diagonal lines
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    return 0;
}

void play_game(char board[3][3]) {
    int player = 1;
    int choice;

    while (1) {
        system("clear");
        print_board(board);
        printf("Player %d's turn\n", player);
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 9) {
            printf("Invalid choice, try again.\n");
            continue;
        }

        if (board[choice / 3][choice % 3]!= 'X' && board[choice / 3][choice % 3]!= 'O') {
            board[choice / 3][choice % 3] = (player == 1)? 'X' : 'O';
            player++;

            if (check_win(board, player == 1? 'X' : 'O')) {
                printf("Player %d wins!\n", player);
                break;
            }
        } else {
            printf("Invalid choice, try again.\n");
        }
    }
}

int main() {
    srand(time(NULL));
    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

    play_game(board);

    return 0;
}
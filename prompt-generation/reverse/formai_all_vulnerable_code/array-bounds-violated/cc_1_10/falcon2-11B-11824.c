//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
int player = 1; // 1 for X, 2 for O
int turn = 0; // 0 for X, 1 for O
int win_count = 0;

void print_board() {
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("   |   |   \n");
    printf("-----+-----+-----\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("   |   |   \n");
    printf("   |   |   \n");
}

void play_game() {
    printf("Player %d's turn.\n", player);
    int choice;
    do {
        print_board();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (board[choice / 3][choice % 3]!= 0) {
            printf("Invalid move. Choose a free cell.\n");
        } else {
            board[choice / 3][choice % 3] = player;
            if (check_win()) {
                printf("Player %d wins!\n", player);
                win_count++;
            } else {
                player = (player == 1)? 2 : 1;
            }
        }
    } while (player!= 0);
    if (win_count == 0) {
        printf("It's a tie!\n");
    }
}

int check_win() {
    int i, j;
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0]!= 0) {
            return board[i][0];
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i]!= 0) {
            return board[0][i];
        }
    }
    for (i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i]!= 0) {
            return board[0][i];
        }
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0]!= 0) {
            return board[i][0];
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));
    int choice;
    do {
        printf("Play a game of Tic Tac Toe? (y/n) ");
        scanf("%c", &choice);
    } while (choice!= 'y' && choice!= 'n');
    if (choice == 'n') {
        exit(0);
    }
    int win = 0;
    do {
        play_game();
        print_board();
        printf("Play again? (y/n) ");
        scanf("%c", &choice);
    } while (choice == 'y');
    printf("Thanks for playing!\n");
    return 0;
}
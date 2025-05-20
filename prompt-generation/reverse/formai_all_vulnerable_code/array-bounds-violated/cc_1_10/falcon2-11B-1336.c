//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

int board[ROWS][COLS];
int player;

void display_board() {
    int i, j;
    printf("   |   |   \n");
    for (i = 0; i < ROWS; i++) {
        printf("%d|%d|%d \n", board[i][0], board[i][1], board[i][2]);
        printf("   |   |   \n");
    }
}

int check_winner() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
        if (board[i][0] == board[i][COLS - 1] && board[i][COLS - 1] == board[i][COLS]) {
            return board[i][0];
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
        if (board[0][i] == board[COLS - 1][i] && board[COLS - 1][i] == board[COLS][i]) {
            return board[0][i];
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    return 0;
}

int get_move(int player) {
    int i, j;
    printf("Player %d, enter row and column: ", player);
    scanf("%d%d", &i, &j);
    while (i < 0 || i > ROWS - 1 || j < 0 || j > COLS - 1) {
        printf("Invalid move. Please enter row and column: ");
        scanf("%d%d", &i, &j);
    }
    board[i][j] = player;
    display_board();
    return i * COLS + j;
}

int main() {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }
    player = 1;
    printf("Welcome to Tic Tac Toe!\n");
    printf("Player 1 is X, Player 2 is O.\n");
    while (1) {
        if (player == 1) {
            printf("Player 1, enter row and column: ");
            int move = get_move(1);
            board[move / COLS][move % COLS] = 1;
            if (check_winner() == 1) {
                printf("Player 1 wins!\n");
                break;
            }
            if (check_winner() == 2) {
                printf("Player 2 wins!\n");
                break;
            }
            player = 2;
        }
        else if (player == 2) {
            printf("Player 2, enter row and column: ");
            int move = get_move(2);
            board[move / COLS][move % COLS] = 2;
            if (check_winner() == 1) {
                printf("Player 2 wins!\n");
                break;
            }
            if (check_winner() == 2) {
                printf("Player 1 wins!\n");
                break;
            }
            player = 1;
        }
        else {
            printf("Invalid move. Please enter row and column: ");
            int move = get_move(0);
        }
    }
    return 0;
}
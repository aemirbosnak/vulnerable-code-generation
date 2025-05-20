//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the board as a 2D array of integers
int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

// Function to print the board
void print_board(void) {
    printf("---------\n");
    for (int i = 0; i < 3; i++) {
        printf("%d | %d | %d\n", board[i][0], board[i][1], board[i][2]);
        printf("---------\n");
    }
    printf("---------\n");
}

// Function to check if the game is over
int game_over(void) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0]!= 0) {
            printf("Player 1 wins!\n");
            return 1;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i]!= 0) {
            printf("Player 2 wins!\n");
            return 2;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0]!= 0) {
        printf("Player 1 wins!\n");
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2]!= 0) {
        printf("Player 2 wins!\n");
        return 2;
    }
    return 0;
}

// Function to make a move
void make_move(int player, int position) {
    if (game_over()) {
        return;
    }
    board[position / 3][position % 3] = player;
    print_board();
    if (game_over()) {
        printf("%d wins!\n", player);
        return;
    }
}

// Function to play the game
int play_game(int player) {
    int position;
    int winner;
    while (!game_over()) {
        printf("%d, make a move (1-9): ", player);
        scanf("%d", &position);
        if (position > 9 || position < 1) {
            printf("Invalid move, try again.\n");
            continue;
        }
        make_move(player, position - 1);
        winner = play_game(!player);
        if (winner!= 0) {
            return winner;
        }
    }
    return 0;
}

int main(void) {
    srand(time(NULL));
    int player = 1;
    while (1) {
        printf("Player %d, make a move (1-9): ", player);
        scanf("%d", &player);
        if (player > 9 || player < 1) {
            printf("Invalid move, try again.\n");
            continue;
        }
        if (play_game(player)) {
            break;
        }
    }
    return 0;
}
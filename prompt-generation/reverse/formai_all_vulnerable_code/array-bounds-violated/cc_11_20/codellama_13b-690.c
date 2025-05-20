//Code Llama-13B DATASET v1.0 Category: Tic Tac Toe AI ; Style: happy
// Tic Tac Toe AI in a happy style
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board and the players
char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};
char player1 = 'X', player2 = 'O';

// Define the game logic
void print_board() {
    printf(" 1 | 2 | 3\n");
    printf("---------\n");
    printf(" 4 | 5 | 6\n");
    printf("---------\n");
    printf(" 7 | 8 | 9\n");
}

void play_game() {
    int move;
    char player;

    // Game loop
    while (1) {
        // Print the board
        print_board();

        // Player 1 makes a move
        player = player1;
        move = rand() % 9 + 1;
        board[move / 3][move % 3] = player;
        printf("Player 1 (%c) made a move.\n", player);

        // Check for win
        if (board[0][0] == board[0][1] && board[0][1] == board[0][2]) {
            printf("Player 1 wins!\n");
            break;
        } else if (board[1][0] == board[1][1] && board[1][1] == board[1][2]) {
            printf("Player 1 wins!\n");
            break;
        } else if (board[2][0] == board[2][1] && board[2][1] == board[2][2]) {
            printf("Player 1 wins!\n");
            break;
        } else if (board[0][0] == board[1][0] && board[1][0] == board[2][0]) {
            printf("Player 1 wins!\n");
            break;
        } else if (board[0][1] == board[1][1] && board[1][1] == board[2][1]) {
            printf("Player 1 wins!\n");
            break;
        } else if (board[0][2] == board[1][2] && board[1][2] == board[2][2]) {
            printf("Player 1 wins!\n");
            break;
        } else if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            printf("Player 1 wins!\n");
            break;
        } else if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            printf("Player 1 wins!\n");
            break;
        }

        // Player 2 makes a move
        player = player2;
        move = rand() % 9 + 1;
        board[move / 3][move % 3] = player;
        printf("Player 2 (%c) made a move.\n", player);

        // Check for win
        if (board[0][0] == board[0][1] && board[0][1] == board[0][2]) {
            printf("Player 2 wins!\n");
            break;
        } else if (board[1][0] == board[1][1] && board[1][1] == board[1][2]) {
            printf("Player 2 wins!\n");
            break;
        } else if (board[2][0] == board[2][1] && board[2][1] == board[2][2]) {
            printf("Player 2 wins!\n");
            break;
        } else if (board[0][0] == board[1][0] && board[1][0] == board[2][0]) {
            printf("Player 2 wins!\n");
            break;
        } else if (board[0][1] == board[1][1] && board[1][1] == board[2][1]) {
            printf("Player 2 wins!\n");
            break;
        } else if (board[0][2] == board[1][2] && board[1][2] == board[2][2]) {
            printf("Player 2 wins!\n");
            break;
        } else if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            printf("Player 2 wins!\n");
            break;
        } else if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            printf("Player 2 wins!\n");
            break;
        }
    }
}

int main() {
    srand(time(NULL));
    play_game();
    return 0;
}
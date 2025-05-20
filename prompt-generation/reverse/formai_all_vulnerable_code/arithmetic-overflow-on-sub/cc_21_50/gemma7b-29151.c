//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

int main() {
    int player1_num, player2_num;
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int game_over = 0;

    printf("Welcome to the C Periodic Table Quiz!\n");
    printf("Enter your player number (1 or 2): ");
    scanf("%d", &player1_num);

    printf("Enter your player number (1 or 2): ");
    scanf("%d", &player2_num);

    // Game loop
    while (!game_over) {
        int move;

        printf("It's your turn, Player %d. Enter your move: ", player1_num);
        scanf("%d", &move);

        // Check if move is valid
        if (board[move - 1] == 'X' || board[move - 1] == 'O') {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Place your mark on the board
        board[move - 1] = 'X';

        // Check if the player has won
        if (board[0] == 'X' || board[1] == 'X' || board[2] == 'X' ||
            board[3] == 'X' || board[4] == 'X' || board[5] == 'X' ||
            board[6] == 'X' || board[7] == 'X' || board[8] == 'X') {
            game_over = 1;
            printf("Player %d has won!\n", player1_num);
        }

        // Check if the board is full
        if (board[0] == 'X' && board[1] == 'X' && board[2] == 'X' &&
            board[3] == 'X' && board[4] == 'X' && board[5] == 'X' &&
            board[6] == 'X' && board[7] == 'X' && board[8] == 'X') {
            game_over = 1;
            printf("It's a draw!\n");
        }

        // Switch to the next player
        player1_num = player2_num;
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to display the game board
void display_board(char board[]) {
    printf("\n");
    printf("| %c | %c | %c |\n", board[0], board[1], board[2]);
    printf("| %c | %c | %c |\n", board[3], board[4], board[5]);
    printf("| %c | %c | %c |\n", board[6], board[7], board[8]);
    printf("\n");
}

// Function to get the player's move
int get_player_move(char board[]) {
    int move = 0;
    while (1) {
        printf("Enter a number between 1 and 9 to make your move: ");
        scanf("%d", &move);
        if (move < 1 || move > 9 || board[move - 1] != ' ') {
            printf("Invalid move! Try again.\n");
        }
        else {
            break;
        }
    }
    return move;
}

// Function to get the computer's move
int get_computer_move(char board[]) {
    int move = 0;
    srand(time(NULL));
    while (1) {
        move = rand() % 9;
        if (board[move] == ' ') {
            break;
        }
    }
    return move;
}

// Function to check if a player has won
int check_win(char board[], char symbol) {
    // Check rows
    if (board[0] == symbol && board[1] == symbol && board[2] == symbol) {
        return 1;
    }
    if (board[3] == symbol && board[4] == symbol && board[5] == symbol) {
        return 1;
    }
    if (board[6] == symbol && board[7] == symbol && board[8] == symbol) {
        return 1;
    }
    // Check columns
    if (board[0] == symbol && board[3] == symbol && board[6] == symbol) {
        return 1;
    }
    if (board[1] == symbol && board[4] == symbol && board[7] == symbol) {
        return 1;
    }
    if (board[2] == symbol && board[5] == symbol && board[8] == symbol) {
        return 1;
    }
    // Check diagonals
    if (board[0] == symbol && board[4] == symbol && board[8] == symbol) {
        return 1;
    }
    if (board[2] == symbol && board[4] == symbol && board[6] == symbol) {
        return 1;
    }
    return 0;
}

int main() {
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int player_turn = 1;
    int game_over = 0;
    int move = 0;

    printf("Welcome to Retro Tic Tac Toe!\n\n");
    printf("Player 1 (X) - Player 2 (O)\n\n");

    while (!game_over) {
        display_board(board);
        if (player_turn) {
            printf("Player 1's turn (X)\n\n");
            move = get_player_move(board);
            board[move - 1] = 'X';
            if (check_win(board, 'X')) {
                display_board(board);
                printf("Player 1 wins!\n");
                game_over = 1;
            }
            player_turn = 0;
        }
        else {
            printf("Computer's turn (O)\n\n");
            move = get_computer_move(board);
            board[move] = 'O';
            if (check_win(board, 'O')) {
                display_board(board);
                printf("Computer wins!\n");
                game_over = 1;
            }
            player_turn = 1;
        }
        if (!game_over) {
            // Check for a tie
            int i, tie = 1;
            for (i = 0; i < 9; i++) {
                if (board[i] == ' ') {
                    tie = 0;
                }
            }
            if (tie) {
                display_board(board);
                printf("It's a tie!\n");
                game_over = 1;
            }
        }
    }

    return 0;
}
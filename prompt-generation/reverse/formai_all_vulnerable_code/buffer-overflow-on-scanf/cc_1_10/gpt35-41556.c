//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROWS 3
#define COLS 3

char board[ROWS][COLS] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char computer, player;

// Function to display the Tic Tac Toe board
void display_board() {
    int row, col;
    printf("\n");
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            printf(" %c ", board[row][col]);
            if (col != COLS - 1)
                printf("|");
        }
        printf("\n");
        if (row != ROWS - 1)
            printf("___|___|___\n");
        else
            printf("   |   |   \n");
    }
}

// Function to check if the game is over
bool game_over() {
    // Check rows
    for (int row = 0; row < ROWS; row++) {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2])
            return true;
    }

    // Check columns
    for (int col = 0; col < COLS; col++) {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col])
            return true;
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;

    // Check if any empty cell is left
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (board[row][col] != 'X' && board[row][col] != 'O')
                return false;
        }
    }

    // If all empty cells are filled
    return true;
}

// Function to get the move from the player
void get_player_move() {
    int row, col;
    printf("\nEnter the row and column for your move (e.g. 1 2 for first row, second column): ");
    scanf("%d %d", &row, &col);

    while (board[row - 1][col - 1] == 'X' || board[row - 1][col - 1] == 'O') {
        printf("\nInvalid move! Please try again.\n");
        printf("\nEnter the row and column for your move (e.g. 1 2 for first row, second column): ");
        scanf("%d %d", &row, &col);
    }

    board[row - 1][col - 1] = player;
    printf("\nPlayer %c has made the move %d %d\n", player, row, col);
}

// Function to get the move from the computer
void get_computer_move() {
    int row, col;
    srand(time(NULL));
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] == 'X' || board[row][col] == 'O');

    board[row][col] = computer;
    printf("\nComputer has made the move %d %d\n", row + 1, col + 1);
}

// Main function to play the game
int main() {
    printf("\nWelcome to Tic Tac Toe!\n");
    printf("\nEnter X or O to choose your symbol: ");
    scanf(" %c", &player);
    computer = player == 'X' ? 'O' : 'X';

    while (!game_over()) {
        display_board();
        get_player_move();
        if (game_over())
            break;
        get_computer_move();
    }
    display_board();
    printf("\nGame Over!\n");

    if (player == 'X' && game_over())
        printf(computer == 'O' ? "\nComputer wins!\n" : "\nCongratulations! You win!\n");

    if (player == 'O' && game_over())
        printf(computer == 'X' ? "\nComputer wins!\n" : "\nCongratulations! You win!\n");

    if (!game_over())
        printf("\nIt's a draw!\n");

    return 0;
}
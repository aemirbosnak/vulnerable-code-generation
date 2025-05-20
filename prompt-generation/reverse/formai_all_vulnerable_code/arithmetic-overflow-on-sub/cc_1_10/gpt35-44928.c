//FormAI DATASET v1.0 Category: Table Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

// Function to display the game board
void display_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j != BOARD_SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i != BOARD_SIZE - 1) {
            printf("---|---|---\n");
        }
    }
}

// Function to randomly choose the starting player
char choose_starting_player()
{
    int random_num = rand() % 2;
    if (random_num == 0) {
        return 'X';
    } else {
        return 'O';
    }
}

// Function to get the player's move input
void get_player_move(int *row, int *col)
{
    printf("Enter row number (1-3): ");
    scanf("%d", row);
    printf("Enter column number (1-3): ");
    scanf("%d", col);
    // Subtract 1 to make sure array index starts at 0
    *row -= 1;
    *col -= 1;
}

// Function to check if a move is valid
int is_valid_move(int row, int col, char board[BOARD_SIZE][BOARD_SIZE])
{
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        return 0;
    }
    if (board[row][col] != ' ') {
        return 0;
    }
    return 1;
}

// Function to check if a player has won
int has_player_won(char player, char board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    return 0;
}

// Function to check if the game is a tie
int is_game_tie(char board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

// Function to play the game
void play_game()
{
    char board[BOARD_SIZE][BOARD_SIZE] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    char current_player = choose_starting_player();
    int row, col;
    int game_over = 0;
    
    while (!game_over) {
        display_board(board);
        printf("Player %c's turn.\n", current_player);
        get_player_move(&row, &col);
        if (!is_valid_move(row, col, board)) {
            printf("Invalid move, please try again.\n");
            continue;
        }
        board[row][col] = current_player;
        if (has_player_won(current_player, board)) {
            display_board(board);
            printf("Player %c has won!\n", current_player);
            game_over = 1;
        } else if (is_game_tie(board)) {
            display_board(board);
            printf("Game is a tie.\n");
            game_over = 1;
        } else {
            // Switch to the other player's turn
            if (current_player == 'X') {
                current_player = 'O';
            } else {
                current_player = 'X';
            }
        }
    }
}

int main()
{
    srand(time(NULL));
    printf("Welcome to C Table Game!\n");
    play_game();
    return 0;
}
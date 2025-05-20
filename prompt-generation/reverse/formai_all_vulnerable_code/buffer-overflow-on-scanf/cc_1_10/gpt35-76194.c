//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define PLAYER_NONE ' '

// game board
char board[3][3];

// function declarations
bool is_game_over();
char get_winner();
void display_board();
bool make_move(char player, int row, int col);
void ai_move();

// main function
int main()
{
    // initialize game board
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            board[row][col] = PLAYER_NONE;
        }
    }

    printf("Welcome to Tic Tac Toe!\n");
    printf("You are player X, and the AI is player O.\n");
    printf("The game board is a 3x3 grid. To make a move, enter the row and column numbers (0-2).\n");

    // game loop
    while (!is_game_over()) {
        // player X's turn
        int x_row, x_col;
        do {
            printf("Player X, enter your move: ");
            scanf("%d%d", &x_row, &x_col);
        } while (!make_move(PLAYER_X, x_row, x_col));

        display_board();

        if (is_game_over()) {
            break;
        }

        // AI's turn
        printf("AI's turn...\n");
        ai_move();
        display_board();
    }

    // game is over, get the winner
    char winner = get_winner();

    if (winner == PLAYER_X) {
        printf("Player X wins!\n");
    } else if (winner == PLAYER_O) {
        printf("AI wins!\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}

// check if game is over
bool is_game_over()
{
    // check for a winner
    char winner = get_winner();
    if (winner != PLAYER_NONE) {
        return true;
    }

    // check for tie game
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row][col] == PLAYER_NONE) {
                return false;
            }
        }
    }

    return true;
}

// get the winner of the game
char get_winner()
{
    // check rows
    for (int row = 0; row < 3; row++) {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2] && board[row][0] != PLAYER_NONE) {
            return board[row][0];
        }
    }

    // check columns
    for (int col = 0; col < 3; col++) {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col] && board[0][col] != PLAYER_NONE) {
            return board[0][col];
        }
    }

    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != PLAYER_NONE) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != PLAYER_NONE) {
        return board[0][2];
    }

    return PLAYER_NONE;
}

// display the game board
void display_board()
{
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// make a move on the game board
bool make_move(char player, int row, int col)
{
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        printf("Error: invalid move, must be from 0-2.\n");
        return false;
    }
    if (board[row][col] != PLAYER_NONE) {
        printf("Error: invalid move, position already taken.\n");
        return false;
    }

    board[row][col] = player;
    return true;
}

// AI makes a move on the game board
void ai_move()
{
    // check for winning move
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row][col] == PLAYER_NONE) {
                board[row][col] = PLAYER_O;
                if (get_winner() == PLAYER_O) {
                    return;
                }
                board[row][col] = PLAYER_NONE;
            }
        }
    }

    // check for blocking move
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row][col] == PLAYER_NONE) {
                board[row][col] = PLAYER_X;
                if (get_winner() == PLAYER_X) {
                    board[row][col] = PLAYER_O;
                    return;
                }
                board[row][col] = PLAYER_NONE;
            }
        }
    }

    // make a random move
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (!make_move(PLAYER_O, row, col));
}
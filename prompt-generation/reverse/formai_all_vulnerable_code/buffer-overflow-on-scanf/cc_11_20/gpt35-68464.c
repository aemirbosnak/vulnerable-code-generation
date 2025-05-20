//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void draw_game_board(int board[3][3], int player_turn);
void make_move(int board[3][3], int player_turn);
int check_winner(int board[3][3]);

int main() {
    int board[3][3] = {0}; // initialize the game board
    int player_turn = 1;   // player 1 goes first

    // game loop
    while (1) {
        // clear the screen
        system("clear");

        // draw the game board
        draw_game_board(board, player_turn);

        // make a move
        make_move(board, player_turn);

        // check for a winner
        int winner = check_winner(board);
        if (winner != 0) {
            // clear the screen
            system("clear");

            // draw the game board
            draw_game_board(board, player_turn);

            // print the winner
            printf("Player %d wins!\n", winner);

            // reset the game board
            board[0][0] = board[0][1] = board[0][2] = 0;
            board[1][0] = board[1][1] = board[1][2] = 0;
            board[2][0] = board[2][1] = board[2][2] = 0;

            // reset the player turn
            player_turn = 1;

            // wait for the user to press a key
            getchar();

            // clear the screen
            system("clear");

            // draw the empty game board
            draw_game_board(board, player_turn);
        } else {
            // switch to the other player's turn
            player_turn = (player_turn == 1) ? 2 : 1;
        }
    }

    return 0;
}

// Draw the game board
void draw_game_board(int board[3][3], int player_turn) {
    printf("Tic Tac Toe\n\n");

    // Draw the top row
    printf(" %c | %c | %c \n", (board[0][0] == 0) ? ' ' : (board[0][0] == 1) ? 'X' : 'O',
                               (board[0][1] == 0) ? ' ' : (board[0][1] == 1) ? 'X' : 'O',
                               (board[0][2] == 0) ? ' ' : (board[0][2] == 1) ? 'X' : 'O');
    printf("---+---+---\n");

    // Draw the middle row
    printf(" %c | %c | %c \n", (board[1][0] == 0) ? ' ' : (board[1][0] == 1) ? 'X' : 'O',
                               (board[1][1] == 0) ? ' ' : (board[1][1] == 1) ? 'X' : 'O',
                               (board[1][2] == 0) ? ' ' : (board[1][2] == 1) ? 'X' : 'O');
    printf("---+---+---\n");

    // Draw the bottom row
    printf(" %c | %c | %c \n\n", (board[2][0] == 0) ? ' ' : (board[2][0] == 1) ? 'X' : 'O',
                                 (board[2][1] == 0) ? ' ' : (board[2][1] == 1) ? 'X' : 'O',
                                 (board[2][2] == 0) ? ' ' : (board[2][2] == 1) ? 'X' : 'O');

    printf("Player %d's turn (X)\n", player_turn);
}

// Make a move
void make_move(int board[3][3], int player_turn) {
    int row, col;

    // use srand and time to generate random numbers
    srand(time(NULL));

    // if it's the computer's turn (player 2)
    if (player_turn == 2) {
        // generate random row and col numbers until an empty cell is found
        do {
            row = rand() % 3;
            col = rand() % 3;
        } while (board[row][col] != 0);
    } else {
        // otherwise, get input from the user
        printf("Enter the row and column of your move (e.g. 1 2): ");
        scanf("%d %d", &row, &col);

        // check if the move is valid
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != 0) {
            printf("Invalid move, try again.\n");

            // wait for the user to press a key
            getchar();
        } else {
            // update the game board
            board[row-1][col-1] = 1;
        }
    }
}

// Check for a winner
int check_winner(int board[3][3]) {
    // check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    // check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] != 0 && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j];
        }
    }

    // check diagonals
    if (board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }

    if (board[0][2] != 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    // no winner yet
    return 0;
}
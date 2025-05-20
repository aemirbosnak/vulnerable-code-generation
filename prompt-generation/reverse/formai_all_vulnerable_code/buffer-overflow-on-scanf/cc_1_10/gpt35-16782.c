//FormAI DATASET v1.0 Category: Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// define the board dimensions
const int ROWS = 3;
const int COLS = 3;

// initialize the game board
char game_board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '},
};

// function to print the game board
void print_game_board() 
{
    printf("\n\n");
    printf("  %c | %c | %c \n", game_board[0][0], game_board[0][1], game_board[0][2]);
    printf(" ---|---|---\n");
    printf("  %c | %c | %c \n", game_board[1][0], game_board[1][1], game_board[1][2]);
    printf(" ---|---|---\n");
    printf("  %c | %c | %c \n\n", game_board[2][0], game_board[2][1], game_board[2][2]);
}

// function to check if a move is valid
int valid_move(int row, int col) 
{
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return 0;
    }
    if (game_board[row][col] != ' ') {
        return 0;
    }
    return 1;
}

// function to check if a player has won
int check_win(char player) 
{

    // check horizontal wins
    for (int i = 0; i < ROWS; i++) {
        if (game_board[i][0] == player && game_board[i][1] == player && game_board[i][2] == player) {
            return 1;
        }
    }

    // check vertical wins
    for (int j = 0; j < COLS; j++) {
        if (game_board[0][j] == player && game_board[1][j] == player && game_board[2][j] == player) {
            return 1;
        }
    }

    // check diagonal wins
    if ((game_board[0][0] == player && game_board[1][1] == player && game_board[2][2] == player) || 
        (game_board[0][2] == player && game_board[1][1] == player && game_board[2][0] == player)) {
            return 1;
    }

    // no win yet
    return 0;
}

// function to execute one turn of the game
void play_turn(char player) 
{

    // prompt for player move
    int row, col;
    printf("Player %c's Turn\n", player);
    printf("Enter row (0-2): ");
    scanf("%d", &row);
    printf("Enter column (0-2): ");
    scanf("%d", &col);

    // check for valid move
    if (!valid_move(row, col)) {
        printf("Invalid move, please try again.\n");
        play_turn(player);
        return;
    }

    // add player's move to game board
    game_board[row][col] = player;

    // print updated game board
    print_game_board();

    // check for win
    if (check_win(player)) {
        printf("Player %c wins!\n", player);
        exit(0);
    }

    // check for tie
    int num_spaces = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (game_board[i][j] == ' ') {
                num_spaces++;
            }
        }
    }
    if (num_spaces == 0) {
        printf("Tie game!\n");
        exit(0);
    }

    // switch to other player's turn
    if (player == 'X') {
        play_turn('O');
    } else {
        play_turn('X');
    }
}

int main() 
{
    // print welcome message and initial game board
    printf("Welcome to Tic Tac Toe!\n");
    print_game_board();

    // start game with X player's turn
    play_turn('X');

    return 0;
}
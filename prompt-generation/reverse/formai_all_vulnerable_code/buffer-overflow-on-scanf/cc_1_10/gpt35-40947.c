//FormAI DATASET v1.0 Category: Game ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

// function prototypes
void print_game_board(char game_board[3][3]);
int check_win(char game_board[3][3]);
void update_game_board(char game_board[3][3], int row, int col, char player);

int main() {
    // initialize game board
    char game_board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

    // initialize variables
    int row, col, turn = 0;
    char player = 'X';

    // display game board
    print_game_board(game_board);

    // gameplay loop
    while (1) {
        // prompt player for move
        printf("Player %c, enter row (1-3) and column (1-3) separated by a space:\n", player);
        scanf("%d %d", &row, &col);
        // validate user input
        if (row > 3 || row < 1 || col > 3 || col < 1) {
            printf("Invalid input. Please enter row and column as integers between 1 and 3.\n");
            continue;
        }
        if (game_board[row-1][col-1] == 'X' || game_board[row-1][col-1] == 'O') {
            printf("That position is already taken. Please choose another position.\n");
            continue;
        }
        // update game board and display
        update_game_board(game_board, row-1, col-1, player);
        print_game_board(game_board);
        // check for win
        if (check_win(game_board)) {
            printf("Player %c wins!\n", player);
            break;
        }
        // end game if all positions are filled
        turn++;
        if (turn == 9) {
            printf("It's a tie.\n");
            break;
        }
        // switch player
        if (player == 'X') {
            player = 'O';
        } else {
            player = 'X';
        }
    }

    return 0;
}

// function to print the game board
void print_game_board(char game_board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", game_board[i][0], game_board[i][1], game_board[i][2]);
        if (i != 2) {
            printf("\n---|---|---\n");
        }
    }
    printf("\n");
}

// function to check for a winning combination
int check_win(char game_board[3][3]) {
    // check rows
    for (int i = 0; i < 3; i++) {
        if (game_board[i][0] == game_board[i][1] && game_board[i][1] == game_board[i][2]) {
            return 1;
        }
    }
    // check columns
    for (int i = 0; i < 3; i++) {
        if (game_board[0][i] == game_board[1][i] && game_board[1][i] == game_board[2][i]) {
            return 1;
        }
    }
    // check diagonals
    if (game_board[0][0] == game_board[1][1] && game_board[1][1] == game_board[2][2]) {
        return 1;
    }
    if (game_board[0][2] == game_board[1][1] && game_board[1][1] == game_board[2][0]) {
        return 1;
    }
    // no winning combination found
    return 0;
}

// function to update the game board with player's move
void update_game_board(char game_board[3][3], int row, int col, char player) {
    game_board[row][col] = player;
}
//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to display the game board
void display_board(int board[3][3]) {
    printf("\n\n\tTic Tac Toe\n\n");

    printf("\tPlayer 1 (X)  -  Player 2 (O)\n\n");

    printf("\t     |     |     \n");
    printf("\t  %c  |  %c  |  %c  \n", board[0][0], board[0][1], board[0][2]);

    printf("\t_____|_____|_____\n");
    printf("\t     |     |     \n");

    printf("\t  %c  |  %c  |  %c  \n", board[1][0], board[1][1], board[1][2]);

    printf("\t_____|_____|_____\n");
    printf("\t     |     |     \n");

    printf("\t  %c  |  %c  |  %c  \n", board[2][0], board[2][1], board[2][2]);

    printf("\t     |     |     \n\n");
}

// function to check if the game is over
int check_game_end(int board[3][3]) {
    int i, j;

    // check if any of the rows have all same value
    for (i=0; i<3; i++) {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return 1;
    }

    // check if any of the columns have all same value
    for (i=0; i<3; i++) {
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return 1;
    }

    // check if the diagonal from top-left to bottom-right has all same value
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return 1;

    // check if the diagonal from top-right to bottom-left has all same value
    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return 1;

    // check if there is any empty cell left in the board
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            if (board[i][j] == ' ')
                return 0;
        }
    }

    // if we reach here that means there is no empty cell left and the game is tied
    return -1;
}

// function to play a move on the board
void play_move(int board[3][3], int player, int row, int col) {
    char player_token;

    // set the player token based on who is playing (X or O)
    if (player == 1)
        player_token = 'X';
    else
        player_token = 'O';

    // set the player token on the given location
    board[row][col] = player_token;
}

int main() {
    int board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int player = 1, game_end, row, col;

    // seed the random number generator
    srand(time(NULL));

    // loop until the game is over
    do {
        // display the game board
        display_board(board);

        // get the row and column from the player
        if (player == 1) {
            printf("Player 1 (X), enter row and column number to place X (e.g. 2 1): ");
            scanf("%d %d", &row, &col);
        } else {
            printf("Player 2 (O), enter row and column number to place O (e.g. 2 1): ");
            // generate random move for the computer player
            row = rand() % 3;
            col = rand() % 3;
            printf("%d %d\n", row, col);
        }

        // validate the input
        if (row < 0 || row >= 3 || col < 0 || col >= 3) {
            printf("Invalid input, please try again...\n");
            continue;
        } else if (board[row][col] != ' ') {
            printf("That cell is not empty, please try again...\n");
            continue;
        }

        // play the move
        play_move(board, player, row, col);

        // check if the game is over
        game_end = check_game_end(board);

        // switch to the next player
        player = (player == 1) ? 2 : 1;
    } while (game_end == 0);

    // display the final game board
    display_board(board);

    // print the result message
    if (game_end == 1)
        printf("Player %d wins!\n", player);
    else
        printf("Game tied!\n");

    return 0;
}
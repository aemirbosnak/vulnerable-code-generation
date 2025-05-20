//FormAI DATASET v1.0 Category: Table Game ; Style: active
// This program is a unique implementation of a Connect Four Table Game
// The program allows two players to take turns dropping pieces onto a four by four grid
// The first player to connect four pieces either vertically, horizontally, or diagonally is declared the winner
// Enjoy the game!

#include <stdio.h>

// define constants
#define BOARD_SIZE 4
#define EMPTY '.'
#define PLAYER_ONE 'X'
#define PLAYER_TWO 'O'

// function prototypes
void print_board(char board[][BOARD_SIZE]);
int make_move(char board[][BOARD_SIZE], char player, int column_choice);
int check_win(char board[][BOARD_SIZE], char player);

int main() {
    // initialize board with empty spaces
    char board[BOARD_SIZE][BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }

    // print starting board
    print_board(board);

    // variable to keep track of player turn
    int player_num = 1;

    // variable to keep track of column choice
    int column_choice;

    // loop until a player wins or the board is full
    while (1) {
        // get column choice from player
        printf("Player %d, please choose a column (1-%d): ", player_num, BOARD_SIZE);
        scanf("%d", &column_choice);

        // check if column_choice is valid
        if (column_choice < 1 || column_choice > BOARD_SIZE) {
            printf("Invalid column choice!\n");
            continue;
        }

        // drop player piece onto the board
        if (player_num == 1) {
            if (!make_move(board, PLAYER_ONE, column_choice - 1)) {
                printf("Column is full!\n");
                continue;
            }
        } else {
            if (!make_move(board, PLAYER_TWO, column_choice - 1)) {
                printf("Column is full!\n");
                continue;
            }
        }

        // print updated board
        print_board(board);

        // check for win
        if (check_win(board, PLAYER_ONE)) {
            printf("Player 1 wins!\n");
            break;
        } else if (check_win(board, PLAYER_TWO)) {
            printf("Player 2 wins!\n");
            break;
        }

        // check for tie game
        int is_full = 1;
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (board[0][i] == EMPTY) {
                is_full = 0;
                break;
            }
        }
        if (is_full) {
            printf("Tie game!\n");
            break;
        }

        // switch player turn
        player_num = (player_num == 1) ? 2 : 1;
    }

    // end program
    return 0;
}

// function to print game board
void print_board(char board[][BOARD_SIZE]) {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// function to drop player piece onto board
int make_move(char board[][BOARD_SIZE], char player, int column_choice) {
    int i;
    for (i = BOARD_SIZE - 1; i >= 0; i--) {
        if (board[i][column_choice] == EMPTY) {
            board[i][column_choice] = player;
            return 1;
        }
    }
    return 0;
}

// function to check for win
int check_win(char board[][BOARD_SIZE], char player) {
    // check for horizontal win
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j <= BOARD_SIZE - 4; j++) {
            if (board[i][j] == player &&
                board[i][j+1] == player &&
                board[i][j+2] == player &&
                board[i][j+3] == player) {
                    return 1;
            }
        }
    }

    // check for vertical win
    for (int i = 0; i <= BOARD_SIZE - 4; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == player &&
                board[i+1][j] == player &&
                board[i+2][j] == player &&
                board[i+3][j] == player) {
                    return 1;
            }
        }
    }

    // check for diagonal win (top left to bottom right)
    for (int i = 0; i <= BOARD_SIZE - 4; i++) {
        for (int j = 0; j <= BOARD_SIZE - 4; j++) {
            if (board[i][j] == player &&
                board[i+1][j+1] == player &&
                board[i+2][j+2] == player &&
                board[i+3][j+3] == player) {
                    return 1;
            }
        }
    }

    // check for diagonal win (bottom left to top right)
    for (int i = BOARD_SIZE-1; i >= 3; i--) {
        for (int j = 0; j <= BOARD_SIZE - 4; j++) {
            if (board[i][j] == player &&
                board[i-1][j+1] == player &&
                board[i-2][j+2] == player &&
                board[i-3][j+3] == player) {
                    return 1;
            }
        }
    }

    // no win found
    return 0;
}
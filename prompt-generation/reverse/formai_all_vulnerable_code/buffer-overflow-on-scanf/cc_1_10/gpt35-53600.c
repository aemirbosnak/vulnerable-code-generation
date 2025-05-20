//FormAI DATASET v1.0 Category: Table Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void print_board(int board[][COLS]);
int check_win(int board[][COLS], int player);
int get_input(int board[][COLS], int player);
void play_game(int board[][COLS], int player);

int main() {
    int board[ROWS][COLS];
    srand(time(NULL));
    int player = (rand() % 2) + 1;
    printf("Welcome to the Ken Thompson-style C Table Game!\n\n");

    // Initialize the game board
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }

    // Start the game
    play_game(board, player);

    return 0;
}

// Prints the current state of the board to the console
void print_board(int board[][COLS]) {
    printf("\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c | ", board[i][j] == 0 ? '.' : board[i][j] == 1 ? 'X' : 'O');
        }
        printf("\n");
        if(i < ROWS - 1) {
            printf("---------\n");
        }
    }
    printf("\n");
}

// Checks if there's a winner or a tie
int check_win(int board[][COLS], int player) {
    int winner = 0;
    // Check rows for a win
    for(int i = 0; i < ROWS; i++) {
        int sum = 0;
        for(int j = 0; j < COLS; j++) {
            sum += board[i][j];
        }
        if(sum == player * COLS) {
            winner = player;
        }
    }
    // Check columns for a win
    for(int i = 0; i < COLS; i++) {
        int sum = 0;
        for(int j = 0; j < ROWS; j++) {
            sum += board[j][i];
        }
        if(sum == player * ROWS) {
            winner = player;
        }
    }
    // Check diagonals for a win
    if(board[0][0] + board[1][1] + board[2][2] == player * ROWS ||
       board[0][2] + board[1][1] + board[2][0] == player * ROWS) {
        winner = player;
    }
    // Check for a tie
    int ties = 0;
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(board[i][j] != 0) {
                ties++;
            }
        }
    }
    if(ties == ROWS * COLS) {
        winner = -1;
    }
    return winner;
}

// Gets input from the player
int get_input(int board[][COLS], int player) {
    int row, col;
    printf("Player %d, enter your move (row, col): ", player);
    scanf("%d,%d", &row, &col);
    if(row < 1 || row > ROWS || col < 1 || col > COLS) {
        return -1;
    }
    if(board[row-1][col-1] != 0) {
        return -1;
    }
    board[row-1][col-1] = player;
    return 0;
}

// Plays the actual game
void play_game(int board[][COLS], int player) {
    while(1) {
        printf("Player %d's turn:\n", player);
        print_board(board);
        int input_result = get_input(board, player);
        if(input_result != 0) {
            printf("Invalid input, please try again.\n");
            continue;
        }
        int winner = check_win(board, player);
        if(winner != 0) {
            if(winner == -1) {
                printf("It's a tie!\n");
            } else {
                printf("Player %d wins!\n", winner);
            }
            break;
        }
        player = player == 1 ? 2 : 1;
    }
}
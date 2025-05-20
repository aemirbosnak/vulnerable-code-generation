//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE        3
#define HUMAN       'X'
#define COMPUTER    'O'
#define EMPTY       ' '

// our game board
char board[SIZE][SIZE];

// function prototypes
void draw_board();
void clear_board();
void human_turn();
void computer_turn();
bool is_win(char player);
bool is_tie();
bool is_valid_move(int row, int col);
int evaluate();

/* This function clears the board */
void clear_board() {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

/* This function draws the game board */
void draw_board() {
    int i, j;
    printf(" ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (i = 0; i < SIZE; i++) {
        printf("%d", i);
        for (j = 0; j < SIZE; j++) {
            printf(" %c", board[i][j]);
        }
        printf("\n");
    }
}

/* This function checks if the input row and column is a valid move */
bool is_valid_move(int row, int col) {
    if (row < 0 || col < 0 || row >= SIZE || col >= SIZE) {
        return false;
    }
    if (board[row][col] != EMPTY) {
        return false;
    }
    return true;
}

/* This function checks if the player has won */
bool is_win(char player) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        if ((board[i][0] == player) && (board[i][1] == player) && (board[i][2] == player)) {
            return true;
        }
        if ((board[0][i] == player) && (board[1][i] == player) && (board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player) && (board[1][1] == player) && (board[2][2] == player)) {
        return true;
    }
    if ((board[0][2] == player) && (board[1][1] == player) && (board[2][0] == player)) {
        return true;
    }
    return false;
}

/* This function checks if the game is tied */
bool is_tie() {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                return false;
            }
        }
    }
    return true;
}

/* This function evaluates the board and returns score */
int evaluate() {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2])) {
            if (board[i][0] == COMPUTER) {
                return 10;
            } else if (board[i][0] == HUMAN) {
                return -10;
            }
        }
        if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i])) {
            if (board[0][i] == COMPUTER) {
                return 10;
            } else if (board[0][i] == HUMAN) {
                return -10;
            }
        }
    }
    if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) {
        if (board[0][0] == COMPUTER) {
            return 10;
        } else if (board[0][0] == HUMAN) {
            return -10;
        }
    }
    if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0])) {
        if (board[0][2] == COMPUTER) {
            return 10;
        } else if (board[0][2] == HUMAN) {
            return -10;
        }
    }
    return 0;
}

/* This function performs the human's move */
void human_turn() {
    int row, col;
    printf("Enter your move row and column: ");
    scanf("%d%d", &row, &col);
    if (!is_valid_move(row, col)) {
        printf("Invalid move, please try again\n");
        human_turn();
    } else {
        board[row][col] = HUMAN;
    }
}

/* This function performs the computer's move */
void computer_turn() {
    int row, col;
    int best_score = -1000;
    int current_score;
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = COMPUTER;
                current_score = evaluate();
                board[i][j] = EMPTY;
                if (current_score > best_score) {
                    best_score = current_score;
                    row = i;
                    col = j;
                }
            }
        }
    }
    board[row][col] = COMPUTER;
}

/* Main function, starts the game */
int main() {
    clear_board();
    draw_board();
    while (true) {
        human_turn();
        if (is_win(HUMAN)) {
            draw_board();
            printf("You win!\n");
            break;
        }
        if (is_tie()) {
            draw_board();
            printf("It's a tie!\n");
            break;
        }
        computer_turn();
        if (is_win(COMPUTER)) {
            draw_board();
            printf("Computer wins!\n");
            break;
        }
        draw_board();
    }
    return 0;
}
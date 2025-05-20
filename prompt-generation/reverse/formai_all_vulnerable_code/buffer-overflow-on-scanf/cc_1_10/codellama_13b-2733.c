//Code Llama-13B DATASET v1.0 Category: Tic Tac Toe AI ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_BOARD_SIZE 3
#define MAX_MOVES 9
#define MAX_PLAYERS 2
#define MAX_TURNS 100

// Function prototypes
void print_board(char board[][MAX_BOARD_SIZE]);
int get_move(char board[][MAX_BOARD_SIZE], char symbol);
int check_win(char board[][MAX_BOARD_SIZE], char symbol);
void play_game(char board[][MAX_BOARD_SIZE]);

// Main function
int main() {
    char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int player_turn = 1;
    int move;
    int win;

    // Initialize the board
    for (int i = 0; i < MAX_BOARD_SIZE; i++) {
        for (int j = 0; j < MAX_BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    // Play the game
    while (1) {
        // Get the current player's move
        move = get_move(board, player_turn == 1 ? 'X' : 'O');

        // Check if the move is valid
        if (move == -1) {
            printf("Invalid move!\n");
            continue;
        }

        // Make the move
        board[move / MAX_BOARD_SIZE][move % MAX_BOARD_SIZE] = player_turn == 1 ? 'X' : 'O';

        // Print the board
        print_board(board);

        // Check if the game is over
        win = check_win(board, player_turn == 1 ? 'X' : 'O');
        if (win != 0) {
            printf("Player %d wins!\n", player_turn);
            break;
        }

        // Check if the game is a draw
        if (player_turn == MAX_TURNS) {
            printf("Draw!\n");
            break;
        }

        // Switch to the next player
        player_turn++;
    }

    return 0;
}

// Function definitions
void print_board(char board[][MAX_BOARD_SIZE]) {
    printf(" 1 | 2 | 3\n");
    printf("  ---------\n");
    printf(" 4 | 5 | 6\n");
    printf("  ---------\n");
    printf(" 7 | 8 | 9\n");
    printf("\n");
}

int get_move(char board[][MAX_BOARD_SIZE], char symbol) {
    int move;
    printf("Player %c, enter your move (1-9): ", symbol);
    scanf("%d", &move);

    if (move < 1 || move > 9) {
        return -1;
    }

    if (board[move / MAX_BOARD_SIZE][move % MAX_BOARD_SIZE] != ' ') {
        return -1;
    }

    return move;
}

int check_win(char board[][MAX_BOARD_SIZE], char symbol) {
    int win = 0;

    // Check rows
    for (int i = 0; i < MAX_BOARD_SIZE; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            win = 1;
            break;
        }
    }

    // Check columns
    if (!win) {
        for (int i = 0; i < MAX_BOARD_SIZE; i++) {
            if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) {
                win = 1;
                break;
            }
        }
    }

    // Check diagonals
    if (!win) {
        if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
            win = 1;
        }
        if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
            win = 1;
        }
    }

    return win;
}
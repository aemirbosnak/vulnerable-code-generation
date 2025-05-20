//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TABLE_ROWS 10
#define TABLE_COLS 10

// Structure to represent a game board
typedef struct {
    char board[TABLE_ROWS][TABLE_COLS];
    int score[TABLE_ROWS];
} game_board;

// Function to print the game board
void print_board(game_board *board) {
    int i, j;

    printf("--- GAME BOARD ---\n");
    for (i = 0; i < TABLE_ROWS; i++) {
        printf(" Row %d: ", i);
        for (j = 0; j < TABLE_COLS; j++) {
            printf("%c ", board->board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to get a random cell index
int get_random_cell_index(game_board *board) {
    int i, j;
    int index = -1;

    // Generate a random row and column
    for (i = 0; i < TABLE_ROWS; i++) {
        for (j = 0; j < TABLE_COLS; j++) {
            if (board->board[i][j] == ' ') {
                index = i * TABLE_COLS + j;
                break;
            }
        }
        if (index != -1) {
            break;
        }
    }
    return index;
}

// Function to place an 'X' or 'O' in a random cell
void place_mark(game_board *board, char mark) {
    int index = get_random_cell_index(board);

    if (index != -1) {
        board->board[index / TABLE_COLS][index % TABLE_COLS] = mark;
        board->score[index / TABLE_COLS]++;
    }
}

// Function to check if a player has won
int check_win(game_board *board) {
    int i, j;

    for (i = 0; i < TABLE_ROWS; i++) {
        if (board->board[i][0] == board->board[i][1] &&
                board->board[i][1] == board->board[i][2]) {
            return i;
        }
    }
    for (i = 0; i < TABLE_ROWS; i++) {
        if (board->board[0][i] == board->board[1][i] &&
                board->board[1][i] == board->board[2][i]) {
            return i;
        }
    }
    for (i = 0; i < TABLE_ROWS; i++) {
        if (board->board[i][0] == board->board[i][ TABLE_COLS - 1] &&
                board->board[i][ TABLE_COLS - 1] == board->board[i][ TABLE_COLS - 2]) {
            return i;
        }
    }
    return -1;
}

// Function to play a game
void play_game(game_board *board) {
    char mark;

    // Print the game board
    print_board(board);

    // Ask the player to choose a mark (X or O)
    printf("Enter a mark (X or O): ");
    scanf(" %c", &mark);

    // Place the mark in a random cell
    place_mark(board, mark);

    // Check if a player has won
    int winner = check_win(board);

    // Print the updated game board and the winner
    print_board(board);
    if (winner != -1) {
        printf("Game over! %c wins!\n", winner + 'A');
    } else {
        printf("Game continues...\n");
    }
}

int main() {
    game_board board;

    // Initialize the game board
    for (int i = 0; i < TABLE_ROWS; i++) {
        for (int j = 0; j < TABLE_COLS; j++) {
            board.board[i][j] = ' ';
        }
    }

    // Play the game
    play_game(&board);

    return 0;
}
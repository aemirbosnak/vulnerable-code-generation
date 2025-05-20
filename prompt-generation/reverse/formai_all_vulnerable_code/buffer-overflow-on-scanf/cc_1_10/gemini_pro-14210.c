//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

typedef struct {
    int row;
    int col;
} Position;

typedef struct {
    char symbol;
    Position position;
    int is_revealed;
} Card;

void print_board(Card board[BOARD_SIZE][BOARD_SIZE]) {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].is_revealed) {
                printf("%c ", board[i][j].symbol);
            } else {
                printf("? ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    // Create the game board
    Card board[BOARD_SIZE][BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].symbol = 'A' + rand() % 26;
            board[i][j].position.row = i;
            board[i][j].position.col = j;
            board[i][j].is_revealed = 0;
        }
    }

    // Print the initial board
    print_board(board);

    // Get the player's first guess
    Position first_guess;
    printf("Enter the row and column of your first guess (e.g. 1 2): ");
    scanf("%d %d", &first_guess.row, &first_guess.col);

    // Reveal the first guess
    board[first_guess.row - 1][first_guess.col - 1].is_revealed = 1;

    // Print the board with the first guess revealed
    print_board(board);

    // Get the player's second guess
    Position second_guess;
    printf("Enter the row and column of your second guess (e.g. 1 2): ");
    scanf("%d %d", &second_guess.row, &second_guess.col);

    // Reveal the second guess
    board[second_guess.row - 1][second_guess.col - 1].is_revealed = 1;

    // Print the board with the second guess revealed
    print_board(board);

    // Check if the player matched the two cards
    if (board[first_guess.row - 1][first_guess.col - 1].symbol == board[second_guess.row - 1][second_guess.col - 1].symbol) {
        printf("Elementary, my dear Watson! You matched the two cards.\n");
    } else {
        printf("The game is afoot! You did not match the two cards.\n");
    }

    return 0;
}
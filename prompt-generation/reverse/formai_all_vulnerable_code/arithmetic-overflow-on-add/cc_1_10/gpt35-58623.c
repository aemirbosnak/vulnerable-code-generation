//FormAI DATASET v1.0 Category: Memory Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4 // Change this to change the size of the board
#define NUM_PAIRS (BOARD_SIZE * BOARD_SIZE) / 2 // Number of pairs of cards needed

// Representation of a card
typedef struct card {
    int value; // Value of the card
    int matched; // Whether the card has been matched or not
} Card;

// Set all cards to be unmatched and reset the values
void init(Card board[][BOARD_SIZE]) {
    int val = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].matched = 0;
            board[i][j].value = val / 2 + 1;
            val++;
        }
    }
}

// Shuffle the values of the cards
void shuffle(Card board[][BOARD_SIZE]) {
    srand(time(NULL) + rand());

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int swap_i = rand() % BOARD_SIZE;
            int swap_j = rand() % BOARD_SIZE;

            int tmp = board[i][j].value;
            board[i][j].value = board[swap_i][swap_j].value;
            board[swap_i][swap_j].value = tmp;
        }
    }
}

// Print the current state of the board
void print_board(Card board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].matched) {
                printf("  ");
            } else {
                printf("%d ", board[i][j].value);
            }
        }
        printf("\n");
    }
}

// Prompt the user for a pair of coordinates to flip
void get_move(int *x1, int *y1, int *x2, int *y2) {
    printf("Enter x1: ");
    scanf("%d", x1);
    printf("Enter y1: ");
    scanf("%d", y1);
    printf("Enter x2: ");
    scanf("%d", x2);
    printf("Enter y2: ");
    scanf("%d", y2);
}

// Check if the game is over
int is_game_over(Card board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (!board[i][j].matched) {
                return 0;
            }
        }
    }
    return 1;
}

// Main game loop
int main() {
    Card board[BOARD_SIZE][BOARD_SIZE];

    init(board);
    shuffle(board);

    printf("Welcome to the Memory Game!\n");
    printf("Match pairs of cards to win!\n");
    printf("Enter the coordinates of the two cards you want to flip.\n");
    printf("Coordinates are 0-based, so the upper left corner is (0,0).\n");
    printf("The game board looks like this:\n");

    // Print the board for the first time
    print_board(board);

    int x1, y1, x2, y2;
    int num_moves = 0;
    while (!is_game_over(board)) {
        // Get a pair of moves from the user
        get_move(&x1, &y1, &x2, &y2);

        // Flip the cards over
        board[x1][y1].matched = 1;
        board[x2][y2].matched = 1;

        // Print the board again
        print_board(board);

        // Check if the cards match
        if (board[x1][y1].value != board[x2][y2].value) {
            printf("Sorry, those cards don't match.\n");
            board[x1][y1].matched = 0;
            board[x2][y2].matched = 0;
        } else {
            printf("Great job, you found a pair!\n");
        }

        num_moves++;
    }

    printf("Congratulations, you won in %d moves!\n", num_moves);
    return 0;
}
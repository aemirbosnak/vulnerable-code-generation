//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define NUM_PAIRS 8

// Card struct
typedef struct {
    int value;
    int revealed;
} Card;

// Global variables
Card board[BOARD_SIZE][BOARD_SIZE];
int pairs_found;

// Function prototypes
void initialize_board();
void print_board();
int get_input();
void flip_card(int row, int col);
int check_for_match(int row1, int col1, int row2, int col2);
int check_for_win();

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Initialize the board
    initialize_board();

    // Main game loop
    while (!check_for_win()) {
        // Print the board
        print_board();

        // Get the user's input
        int input = get_input();

        // Flip the selected card
        int row = input / BOARD_SIZE;
        int col = input % BOARD_SIZE;
        flip_card(row, col);

        // Check for a match
        if (check_for_match(row, col, -1, -1)) {
            pairs_found++;
        }
    }

    // Print the final board
    print_board();

    // Congratulate the player
    printf("Congratulations! You found all the pairs.\n");

    return 0;
}

// Initialize the board with random pairs of values
void initialize_board() {
    int values[NUM_PAIRS];
    for (int i = 0; i < NUM_PAIRS; i++) {
        values[i] = i + 1;
    }

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int index1 = rand() % NUM_PAIRS;
            int index2 = rand() % NUM_PAIRS;
            board[i][j].value = values[index1];
            board[i][j].revealed = 0;
            values[index1] = values[index2];
        }
    }
}

// Print the board to the console
void print_board() {
    printf("   ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%2d ", i);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%2d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].revealed) {
                printf("%2d ", board[i][j].value);
            } else {
                printf("## ");
            }
        }
        printf("\n");
    }
}

// Get the user's input
int get_input() {
    int input;
    printf("Enter the row and column of the card you want to flip (e.g. 12): ");
    scanf("%d", &input);
    return input;
}

// Flip the card at the given row and column
void flip_card(int row, int col) {
    board[row][col].revealed = 1;
}

// Check if the two cards match
int check_for_match(int row1, int col1, int row2, int col2) {
    if (row2 == -1 || col2 == -1) {
        return 0;
    } else if (board[row1][col1].value == board[row2][col2].value) {
        return 1;
    } else {
        return 0;
    }
}

// Check if all the pairs have been found
int check_for_win() {
    return pairs_found == NUM_PAIRS;
}
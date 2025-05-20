//FormAI DATASET v1.0 Category: Memory Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

int board[ROWS][COLS]; // Game board
int board_copy[ROWS][COLS]; // Copy of game board
int checked[ROWS][COLS]; // Tracks whether a card has been checked
int found_pairs = 0; // Number of found pairs
int attempts = 0; // Number of attempts made

void init_board();
void print_board();
void print_card(int, int);
void check_cards(int, int, int, int);
void reset_board();

int main() {
    srand(time(0)); // Seed random number generator
    init_board(); // Initialize game board
    print_board(); // Print initial game board

    // Main game loop
    while (found_pairs < ((ROWS * COLS) / 2)) {
        int row1, col1, row2, col2;

        // Get first card coordinates
        printf("Enter row and column for first card: ");
        scanf("%d %d", &row1, &col1);

        print_card(row1, col1);

        // Get second card coordinates
        printf("Enter row and column for second card: ");
        scanf("%d %d", &row2, &col2);

        print_card(row2, col2);

        // Check if cards are a match
        check_cards(row1, col1, row2, col2);
        print_board();
    }

    printf("Game over! You found all matching pairs in %d attempts.\n", attempts);

    return 0;
}

// Initializes game board with random numbers
void init_board() {
    // 0-7 used twice to provide pairs of matching cards
    int cards[ROWS * COLS / 2] = {0,1,2,3,4,5,6,7};
    int i, j, k;

    // Shuffle cards array
    for (i = 0; i < (ROWS * COLS / 2); i++) {
        k = rand() % (ROWS * COLS / 2);
        int temp = cards[i];
        cards[i] = cards[k];
        cards[k] = temp;
    }

    // Fill board with cards
    k = 0;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = cards[k];
            checked[i][j] = 0;
            k++;
        }
    }
}

// Prints game board to console
void print_board() {
    int i, j;

    printf("\n   0  1  2  3\n");
    printf("  ------------\n");

    for (i = 0; i < ROWS; i++) {
        printf("%d| ", i);
        for (j = 0; j < COLS; j++) {
            if (checked[i][j] == 0) {
                printf("*  ");
            } else {
                printf("%d  ", board[i][j]);
            }
        }
        printf("\n");
    }

    printf("\n");
}

// Prints the card at the specified coordinates
void print_card(int row, int col) {
    printf("Card at (%d, %d): %d\n", row, col, board[row][col]);
}

// Checks whether the cards at the specified coordinates match
void check_cards(int row1, int col1, int row2, int col2) {
    attempts++;

    // If cards already matched or out of bounds, do nothing
    if ((checked[row1][col1] == 1) || (checked[row2][col2] == 1)
        || (row1 < 0) || (row1 > (ROWS-1))
        || (row2 < 0) || (row2 > (ROWS-1))
        || (col1 < 0) || (col1 > (COLS-1))
        || (col2 < 0) || (col2 > (COLS-1))) {
        return;
    }

    // Copy board to allow for resetting of cards if they don't match
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board_copy[i][j] = board[i][j];
        }
    }

    // Check if cards match
    if (board[row1][col1] == board[row2][col2]) {
        checked[row1][col1] = 1;
        checked[row2][col2] = 1;
        found_pairs++;
    } else {
        reset_board();
    }
}

// Resets game board to its state prior to the last check
void reset_board() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = board_copy[i][j];
            checked[i][j] = 0;
        }
    }
}
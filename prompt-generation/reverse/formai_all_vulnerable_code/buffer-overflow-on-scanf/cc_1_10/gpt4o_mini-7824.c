//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define BOARD_SIZE 4
#define TOTAL_PAIRS (BOARD_SIZE * BOARD_SIZE / 2)

char board[BOARD_SIZE][BOARD_SIZE];
char visible[BOARD_SIZE][BOARD_SIZE];
int pair_values[TOTAL_PAIRS];

void initialize_board() {
    for (int i = 0; i < TOTAL_PAIRS; i++) {
        pair_values[i] = 'A' + i; // Assign letters A, B, C, ...
    }
    // Shuffle pair values
    for (int i = TOTAL_PAIRS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = pair_values[i];
        pair_values[i] = pair_values[j];
        pair_values[j] = temp;
    }

    // Fill the board with pairs
    int index = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (index < TOTAL_PAIRS) {
                board[i][j] = pair_values[index / 2]; // Place pairs
                index++;
            }
            visible[i][j] = '*'; // Initialize visible board
        }
    }
}

void print_board() {
    printf("Memory Game Board:\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", visible[i][j]);
        }
        printf("\n");
    }
}

bool check_match(int x1, int y1, int x2, int y2) {
    return board[x1][y1] == board[x2][y2];
}

bool is_game_over() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (visible[i][j] == '*') {
                return false;
            }
        }
    }
    return true;
}

void take_turn() {
    int x1, y1, x2, y2;

    // First guess
    printf("Enter coordinates for first card (row and column): ");
    scanf("%d %d", &x1, &y1);
    visible[x1][y1] = board[x1][y1];

    print_board();

    // Second guess
    printf("Enter coordinates for second card (row and column): ");
    scanf("%d %d", &x2, &y2);
    visible[x2][y2] = board[x2][y2];

    print_board();

    // Check for match
    if (check_match(x1, y1, x2, y2)) {
        printf("Match! You found a pair: %c\n", board[x1][y1]);
    } else {
        printf("Not a match. Try again!\n");
        // Hide cards again after a short delay
        sleep(1);
        visible[x1][y1] = '*';
        visible[x2][y2] = '*';
    }
}

int main() {
    srand(time(NULL)); // Initialize random seed

    initialize_board();

    while (!is_game_over()) {
        print_board();
        take_turn();
    }

    printf("Congratulations! You've matched all pairs!\n");
    return 0;
}
//FormAI DATASET v1.0 Category: Memory Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8
#define NUM_OF_MOVES 5

int board[BOARD_SIZE][BOARD_SIZE];

void initialize_board() {
    int i, j;
    // loop through the board and initialize each square with a random number
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = rand() % 10 + 1;
        }
    }
}

void print_board() {
    int i, j;
    // loop through the board and print each square
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int make_move(int row, int col) {
    // check if the selected square is already matched
    if (board[row][col] == 0) {
        printf("This square has already been matched!\n");
        return 0;
    }
    int i, j, num_of_matches = 0;
    // loop through NUM_OF_MOVES squares in each direction and check if the numbers match
    for (i = -NUM_OF_MOVES; i <= NUM_OF_MOVES; i++) {
        for (j = -NUM_OF_MOVES; j <= NUM_OF_MOVES; j++) {
            if (i == 0 && j == 0) continue; // the selected square itself should not be counted
            int current_row = row + i;
            int current_col = col + j;
            // check if the current position is within the board boundaries
            if (current_row >= 0 && current_row < BOARD_SIZE && current_col >= 0 && current_col < BOARD_SIZE) {
                // check if the numbers match
                if (board[row][col] == board[current_row][current_col]) {
                    num_of_matches++;
                    board[current_row][current_col] = 0; // mark the matched square as 0
                }
            }
        }
    }
    // mark the selected square as 0
    board[row][col] = 0;
    num_of_matches++; // add the selected square to the number of matches
    printf("You made %d match%s!\n", num_of_matches, num_of_matches == 1 ? "" : "es");
    return num_of_matches;
}


int main() {
    int row, col, remaining_squares = BOARD_SIZE * BOARD_SIZE;
    initialize_board();
    srand(time(NULL)); // seed the random number generator
    printf("Welcome to the Memory Game!\n");
    while (remaining_squares > 1) {
        printf("Remaining squares: %d\n", remaining_squares);
        print_board();
        printf("Please select a square to match (row col): ");
        scanf("%d %d", &row, &col);
        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
            printf("Invalid position!\n");
            continue;
        }
        int num_of_matches = make_move(row, col);
        if (num_of_matches == 0) {
            printf("Please try again.\n");
        } else {
            remaining_squares -= num_of_matches;
        }
    }
    printf("Congratulations, you have matched all the squares!\n");
    return 0;
}
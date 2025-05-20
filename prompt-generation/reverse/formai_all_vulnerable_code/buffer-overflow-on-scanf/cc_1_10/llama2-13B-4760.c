//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABLE_ROWS 10
#define TABLE_COLS 10
#define MAX_GUESSES 10

// Global variables
int game_state = 0; // 0 - not started, 1 - in progress, 2 - finished
int score = 0;
int guesses_left = MAX_GUESSES;
int table[TABLE_ROWS][TABLE_COLS] = {{0}};

// Function prototypes
void print_table(void);
void get_guess(int row, int col);
void check_guess(int row, int col);
void update_table(int row, int col);
void game_over(void);

int main(void)
{
    // Initialize the table
    for (int i = 0; i < TABLE_ROWS; i++) {
        for (int j = 0; j < TABLE_COLS; j++) {
            table[i][j] = (int)(rand() % 2) * 2 - 1;
        }
    }

    // Start the game
    game_state = 1;

    while (game_state == 1) {
        // Print the current table
        print_table();

        // Get a guess from the player
        int row, col;
        printf("Enter row (1-%d) and column (1-%d): ", TABLE_ROWS, TABLE_COLS);
        scanf("%d%d", &row, &col);
        get_guess(row, col);

        // Check if the guess is valid
        check_guess(row, col);

        // Update the table
        update_table(row, col);

        // Check if the game is over
        game_over();
    }

    // Print the final score
    printf("Final score: %d\n", score);

    return 0;
}

// Print the table
void print_table(void) {
    for (int i = 0; i < TABLE_ROWS; i++) {
        for (int j = 0; j < TABLE_COLS; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
}

// Get a guess from the player
void get_guess(int row, int col) {
    if (table[row][col] == 0) {
        printf("Oops! That's not a valid guess. Try again.\n");
        return;
    }
    guesses_left--;
}

// Check if the guess is valid
void check_guess(int row, int col) {
    int sum = 0;
    for (int i = 0; i < TABLE_ROWS; i++) {
        for (int j = 0; j < TABLE_COLS; j++) {
            if (table[i][j] == table[row][col]) {
                sum++;
            }
        }
    }
    if (sum == TABLE_ROWS * TABLE_COLS) {
        printf("Congratulations! You won! Your final score is %d\n", score);
        game_over();
    } else {
        printf("Better luck next time. You have %d guesses left.\n", guesses_left);
    }
}

// Update the table
void update_table(int row, int col) {
    table[row][col] *= -1;
}

// Game over function
void game_over(void) {
    game_state = 2;
}
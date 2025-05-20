//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: configurable
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 4
#define HEIGHT 4

// Game state
int board[WIDTH][HEIGHT];
int revealed[WIDTH][HEIGHT];
int matches;
int tries;

// Function to initialize the game
void init_game() {
    // Initialize the board with random numbers
    srand(time(NULL));
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            board[i][j] = rand() % 8;
        }
    }

    // Initialize the revealed array to all 0s
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            revealed[i][j] = 0;
        }
    }

    // Initialize the matches and tries counters to 0
    matches = 0;
    tries = 0;
}

// Function to print the game board
void print_board() {
    // Print the top border
    printf("+---+---+---+---+\n");

    // Print the board
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (revealed[i][j]) {
                printf("| %d ", board[i][j]);
            } else {
                printf("|   ");
            }
        }
        printf("|\n+---+---+---+---+\n");
    }
}

// Function to get the player's input
void get_input(int *x, int *y) {
    printf("Enter the coordinates of the first card (row, column): ");
    scanf("%d %d", x, y);
}

// Function to check if the two cards match
int check_match(int x1, int y1, int x2, int y2) {
    return board[x1][y1] == board[x2][y2];
}

// Function to play the game
void play_game() {
    int x1, y1, x2, y2;

    // Initialize the game
    init_game();

    // Print the initial board
    print_board();

    // Main game loop
    while (matches < WIDTH * HEIGHT / 2) {
        // Get the player's input
        get_input(&x1, &y1);

        // Reveal the first card
        revealed[x1][y1] = 1;

        // Print the board
        print_board();

        // Get the player's input
        get_input(&x2, &y2);

        // Reveal the second card
        revealed[x2][y2] = 1;

        // Print the board
        print_board();

        // Check if the two cards match
        if (check_match(x1, y1, x2, y2)) {
            printf("Match!\n");
            matches++;
        } else {
            printf("No match.\n");
            revealed[x1][y1] = 0;
            revealed[x2][y2] = 0;
        }

        // Increment the tries counter
        tries++;
    }

    // Print the final board
    print_board();

    // Print the results
    printf("You won in %d tries!\n", tries);
}

int main() {
    play_game();
    return 0;
}
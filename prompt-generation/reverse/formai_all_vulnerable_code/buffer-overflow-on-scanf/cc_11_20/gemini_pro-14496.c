//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The size of the board
#define SIZE 4

// The number of pairs of cards
#define PAIRS (SIZE * SIZE) / 2

// The maximum number of moves
#define MAX_MOVES 100

// The game board
char board[SIZE][SIZE];

// The array of card values
char values[PAIRS];

// The array of card states
int states[PAIRS];

// The current player
int player = 0;

// The number of moves
int moves = 0;

// The main game loop
void game_loop() {
    // Initialize the game board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '*';
        }
    }

    // Initialize the array of card values
    for (int i = 0; i < PAIRS; i++) {
        values[i] = 'A' + i;
    }

    // Initialize the array of card states
    for (int i = 0; i < PAIRS; i++) {
        states[i] = 0;
    }

    // Shuffle the array of card values
    srand(time(NULL));
    for (int i = 0; i < PAIRS; i++) {
        int j = rand() % PAIRS;
        char temp = values[i];
        values[i] = values[j];
        values[j] = temp;
    }

    // Game loop
    while (moves < MAX_MOVES) {
        // Print the game board
        printf("  ");
        for (int i = 0; i < SIZE; i++) {
            printf("%d ", i + 1);
        }
        printf("\n");
        for (int i = 0; i < SIZE; i++) {
            printf("%d ", i + 1);
            for (int j = 0; j < SIZE; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }

        // Get the player's input
        int x1, y1, x2, y2;
        printf("Player %d, enter the coordinates of two cards: ", player + 1);
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        // Check if the input is valid
        if (x1 < 1 || x1 > SIZE || y1 < 1 || y1 > SIZE || x2 < 1 || x2 > SIZE || y2 < 1 || y2 > SIZE) {
            printf("Invalid input. Please enter two valid coordinates.\n");
            continue;
        }

        // Check if the cards match
        if (values[(x1 - 1) * SIZE + (y1 - 1)] == values[(x2 - 1) * SIZE + (y2 - 1)]) {
            // The cards match. Reveal them.
            board[x1 - 1][y1 - 1] = values[(x1 - 1) * SIZE + (y1 - 1)];
            board[x2 - 1][y2 - 1] = values[(x2 - 1) * SIZE + (y2 - 1)];

            // Update the array of card states
            states[(x1 - 1) * SIZE + (y1 - 1)] = 1;
            states[(x2 - 1) * SIZE + (y2 - 1)] = 1;

            // Increment the number of moves
            moves++;

            // Check if the game is over
            int game_over = 1;
            for (int i = 0; i < PAIRS; i++) {
                if (states[i] == 0) {
                    game_over = 0;
                }
            }

            if (game_over) {
                printf("Game over! Player %d wins.\n", player + 1);
                return;
            }
        } else {
            // The cards do not match. Hide them.
            board[x1 - 1][y1 - 1] = '*';
            board[x2 - 1][y2 - 1] = '*';

            // Increment the number of moves
            moves++;

            // Switch the player
            player = (player + 1) % 2;
        }
    }

    // The game is over due to the maximum number of moves being reached.
    printf("Game over! No winner.\n");
}

// The main function
int main() {
    // Play the game
    game_loop();

    return 0;
}
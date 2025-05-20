//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define NUM_PAIRS 8

// Card struct
typedef struct card {
    int value;
    int is_revealed;
} card;

// Game state struct
typedef struct game_state {
    card board[BOARD_SIZE][BOARD_SIZE];
    int num_guesses;
    int num_matches;
    int game_over;
} game_state;

// Initialize the game board
void init_board(game_state *state) {
    // Generate a random order for the cards
    int values[NUM_PAIRS * 2];
    for (int i = 0; i < NUM_PAIRS * 2; i++) {
        values[i] = i / 2;
    }
    for (int i = 0; i < NUM_PAIRS * 2; i++) {
        int j = rand() % (NUM_PAIRS * 2);
        int temp = values[i];
        values[i] = values[j];
        values[j] = temp;
    }

    // Place the cards on the board
    int index = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            state->board[i][j].value = values[index++];
            state->board[i][j].is_revealed = 0;
        }
    }
}

// Print the game board
void print_board(game_state *state) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (state->board[i][j].is_revealed) {
                printf("%d ", state->board[i][j].value);
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }
}

// Get a guess from the player
void get_guess(game_state *state) {
    int row1, col1, row2, col2;
    printf("Enter the coordinates of two cards (e.g., 1 2 3 4): ");
    scanf("%d %d %d %d", &row1, &col1, &row2, &col2);

    // Check if the guesses are valid
    if (row1 < 1 || row1 > BOARD_SIZE || col1 < 1 || col1 > BOARD_SIZE ||
        row2 < 1 || row2 > BOARD_SIZE || col2 < 1 || col2 > BOARD_SIZE) {
        printf("Invalid guess. Please try again.\n");
        return;
    }

    // Reveal the cards
    state->board[row1 - 1][col1 - 1].is_revealed = 1;
    state->board[row2 - 1][col2 - 1].is_revealed = 1;

    // Increment the number of guesses
    state->num_guesses++;

    // Check if the cards match
    if (state->board[row1 - 1][col1 - 1].value == state->board[row2 - 1][col2 - 1].value) {
        printf("Match!\n");

        // Increment the number of matches
        state->num_matches++;

        // Check if the game is over
        if (state->num_matches == NUM_PAIRS) {
            state->game_over = 1;
        }
    } else {
        printf("No match.\n");
        state->board[row1 - 1][col1 - 1].is_revealed = 0;
        state->board[row2 - 1][col2 - 1].is_revealed = 0;
    }
}

// Play the game
void play_game(game_state *state) {
    // Initialize the game board
    init_board(state);

    // Print the game board
    print_board(state);

    // Get guesses from the player
    while (!state->game_over) {
        get_guess(state);
        print_board(state);
    }

    // Print the final score
    printf("Congratulations! You won in %d guesses.\n", state->num_guesses);
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Initialize the game state
    game_state state = {0};

    // Play the game
    play_game(&state);

    return 0;
}
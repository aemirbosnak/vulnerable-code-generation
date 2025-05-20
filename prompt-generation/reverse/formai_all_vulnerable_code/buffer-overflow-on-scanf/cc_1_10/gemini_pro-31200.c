//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define BOARD_SIZE 4
#define NUM_PAIRS (BOARD_SIZE * BOARD_SIZE / 2)
#define MAX_TRIES 100

// Card types
typedef enum {
    CARD_BLANK,
    CARD_ONE,
    CARD_TWO,
    CARD_THREE,
    CARD_FOUR,
    CARD_FIVE,
    CARD_SIX,
    CARD_SEVEN,
    CARD_EIGHT
} card_type;

// Game state
typedef struct {
    card_type board[BOARD_SIZE][BOARD_SIZE];
    int num_pairs_found;
    int num_tries;
} game_state;

// Function prototypes
void init_board(game_state *state);
void print_board(game_state *state);
int get_card_at(game_state *state, int row, int col);
void set_card_at(game_state *state, int row, int col, card_type type);
int is_valid_move(game_state *state, int row1, int col1, int row2, int col2);
int make_move(game_state *state, int row1, int col1, int row2, int col2);
int check_for_win(game_state *state);

// Main function
int main(void) {
    // Initialize the random number generator
    srand(time(NULL));

    // Create a new game state
    game_state state;

    // Initialize the board
    init_board(&state);

    // Print the welcome message
    printf("Welcome to the memory game!\n");

    // Get the player's name
    char name[256];
    printf("What is your name? ");
    scanf("%s", name);

    // Main game loop
    while (state.num_pairs_found < NUM_PAIRS && state.num_tries < MAX_TRIES) {
        // Print the board
        print_board(&state);

        // Get the player's move
        printf("%s, it is your turn. Enter the coordinates of two cards to flip (e.g. \"1 2 3 4\"): ", name);
        int row1, col1, row2, col2;
        scanf("%d %d %d %d", &row1, &col1, &row2, &col2);

        // Check if the move is valid
        if (!is_valid_move(&state, row1, col1, row2, col2)) {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Make the move
        make_move(&state, row1, col1, row2, col2);

        // Check for a win
        if (check_for_win(&state)) {
            printf("Congratulations, %s! You won the game in %d tries.\n", name, state.num_tries);
            break;
        }

        // Increment the number of tries
        state.num_tries++;
    }

    // Game over
    if (state.num_pairs_found == NUM_PAIRS) {
        printf("Congratulations, %s! You won the game!\n", name);
    } else {
        printf("Game over. You ran out of tries.\n");
    }

    return 0;
}

// Initializes the game board with random card types
void init_board(game_state *state) {
    // Create an array of all the card types
    card_type types[NUM_PAIRS * 2];
    for (int i = 0; i < NUM_PAIRS; i++) {
        types[i] = i + 1;
        types[i + NUM_PAIRS] = i + 1;
    }

    // Shuffle the array
    for (int i = 0; i < NUM_PAIRS * 2; i++) {
        int j = rand() % (NUM_PAIRS * 2);
        int temp = types[i];
        types[i] = types[j];
        types[j] = temp;
    }

    // Place the cards on the board
    int index = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            state->board[i][j] = types[index++];
        }
    }
}

// Prints the game board to the console
void print_board(game_state *state) {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (state->board[i][j]) {
                case CARD_BLANK:
                    printf("  ");
                    break;
                case CARD_ONE:
                    printf(" 1");
                    break;
                case CARD_TWO:
                    printf(" 2");
                    break;
                case CARD_THREE:
                    printf(" 3");
                    break;
                case CARD_FOUR:
                    printf(" 4");
                    break;
                case CARD_FIVE:
                    printf(" 5");
                    break;
                case CARD_SIX:
                    printf(" 6");
                    break;
                case CARD_SEVEN:
                    printf(" 7");
                    break;
                case CARD_EIGHT:
                    printf(" 8");
                    break;
            }
        }
        printf("\n");
    }
}

// Gets the card type at the specified row and column
int get_card_at(game_state *state, int row, int col) {
    return state->board[row][col];
}

// Sets the card type at the specified row and column
void set_card_at(game_state *state, int row, int col, card_type type) {
    state->board[row][col] = type;
}

// Checks if the specified move is valid
int is_valid_move(game_state *state, int row1, int col1, int row2, int col2) {
    // Check if the cards are the same
    if (get_card_at(state, row1, col1) != get_card_at(state, row2, col2)) {
        return 0;
    }

    // Check if the cards are already flipped
    if (get_card_at(state, row1, col1) == CARD_BLANK || get_card_at(state, row2, col2) == CARD_BLANK) {
        return 0;
    }

    // The move is valid
    return 1;
}

// Makes the specified move
int make_move(game_state *state, int row1, int col1, int row2, int col2) {
    // Flip the cards
    set_card_at(state, row1, col1, CARD_BLANK);
    set_card_at(state, row2, col2, CARD_BLANK);

    // Increment the number of pairs found
    state->num_pairs_found++;

    return 1;
}

// Checks if the game has been won
int check_for_win(game_state *state) {
    return state->num_pairs_found == NUM_PAIRS;
}
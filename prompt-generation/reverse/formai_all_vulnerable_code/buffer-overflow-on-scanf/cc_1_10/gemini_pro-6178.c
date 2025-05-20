//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define NUM_PAIRS 8

// Card struct
typedef struct {
    int value;
    int flipped;
} Card;

// Game state struct
typedef struct {
    Card board[BOARD_SIZE][BOARD_SIZE];
    int num_flipped;
    int num_matched;
} GameState;

// Function declarations
void init_board(GameState *game);
void print_board(GameState *game);
int get_user_input(GameState *game);
int check_match(GameState *game, int row1, int col1, int row2, int col2);
int check_win(GameState *game);

int main() {
    srand(time(NULL));

    // Initialize the game state
    GameState game;
    init_board(&game);

    // Main game loop
    while (!check_win(&game)) {
        // Print the board
        print_board(&game);

        // Get user input
        int row1, col1, row2, col2;
        get_user_input(&game);

        // Check if the cards match
        if (check_match(&game, row1, col1, row2, col2)) {
            // Cards match, increment the number of matched cards
            game.num_matched++;
        } else {
            // Cards don't match, flip them back over
            game.board[row1][col1].flipped = 0;
            game.board[row2][col2].flipped = 0;
        }
    }

    // Print the final board
    print_board(&game);

    // Congratulate the player
    printf("Congratulations! You win!\n");

    return 0;
}

// Initialize the game board
void init_board(GameState *game) {
    // Create an array of values for the cards
    int values[NUM_PAIRS * 2];
    for (int i = 0; i < NUM_PAIRS * 2; i++) {
        values[i] = i / 2;
    }

    // Shuffle the array of values
    for (int i = 0; i < NUM_PAIRS * 2; i++) {
        int r = rand() % (NUM_PAIRS * 2);
        int temp = values[i];
        values[i] = values[r];
        values[r] = temp;
    }

    // Assign the values to the cards
    int index = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            game->board[i][j].value = values[index++];
            game->board[i][j].flipped = 0;
        }
    }

    // Set the initial game state
    game->num_flipped = 0;
    game->num_matched = 0;
}

// Print the game board
void print_board(GameState *game) {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (game->board[i][j].flipped) {
                printf("%d ", game->board[i][j].value);
            } else {
                printf("# ");
            }
        }
        printf("\n");
    }
}

// Get user input
int get_user_input(GameState *game) {
    int row1, col1, row2, col2;

    // Get the first card
    printf("Enter the row and column of the first card: ");
    scanf("%d %d", &row1, &col1);

    // Get the second card
    printf("Enter the row and column of the second card: ");
    scanf("%d %d", &row2, &col2);

    // Check if the input is valid
    if (row1 < 0 || row1 >= BOARD_SIZE || col1 < 0 || col1 >= BOARD_SIZE || row2 < 0 || row2 >= BOARD_SIZE || col2 < 0 || col2 >= BOARD_SIZE) {
        printf("Invalid input\n");
        return -1;
    }

    // Check if the cards are already flipped
    if (game->board[row1][col1].flipped || game->board[row2][col2].flipped) {
        printf("Cards are already flipped\n");
        return -1;
    }

    // Flip the cards
    game->board[row1][col1].flipped = 1;
    game->board[row2][col2].flipped = 1;

    // Increment the number of flipped cards
    game->num_flipped += 2;

    return 0;
}

// Check if the cards match
int check_match(GameState *game, int row1, int col1, int row2, int col2) {
    return game->board[row1][col1].value == game->board[row2][col2].value;
}

// Check if the player has won
int check_win(GameState *game) {
    return game->num_matched == NUM_PAIRS;
}
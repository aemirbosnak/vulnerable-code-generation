//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define GRID_SIZE 4
#define NUM_PAIRS (GRID_SIZE * GRID_SIZE) / 2
#define MAX_TURNS 100

// Card states
enum card_state {
    HIDDEN,
    SHOWN,
    MATCHED
};

// Card struct
typedef struct card {
    int value;
    enum card_state state;
} card;

// Game struct
typedef struct game {
    card grid[GRID_SIZE][GRID_SIZE];
    int turns;
    int matched_pairs;
} game;

// Function prototypes
void init_game(game *g);
void print_grid(game *g);
int get_move(game *g);
int check_match(game *g, int x1, int y1, int x2, int y2);
int game_over(game *g);

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a new game
    game g;
    init_game(&g);

    // Play the game
    while (!game_over(&g)) {
        // Print the grid
        print_grid(&g);

        // Get the player's move
        int move = get_move(&g);

        // Check if the move is valid
        if (move < 0 || move > GRID_SIZE * GRID_SIZE) {
            printf("Invalid move!\n");
            continue;
        }

        // Convert the move to grid coordinates
        int x1 = move % GRID_SIZE;
        int y1 = move / GRID_SIZE;

        // Reveal the card
        g.grid[x1][y1].state = SHOWN;

        // Check if the player has matched two cards
        if (g.turns % 2 == 1) {
            // Get the player's second move
            move = get_move(&g);

            // Convert the move to grid coordinates
            int x2 = move % GRID_SIZE;
            int y2 = move / GRID_SIZE;

            // Check if the second move is valid
            if (move < 0 || move > GRID_SIZE * GRID_SIZE) {
                printf("Invalid move!\n");
                continue;
            }

            // Check if the two cards match
            int matched = check_match(&g, x1, y1, x2, y2);

            // If the cards match, mark them as matched
            if (matched) {
                g.grid[x1][y1].state = MATCHED;
                g.grid[x2][y2].state = MATCHED;
                g.matched_pairs++;
            } else {
                // If the cards don't match, hide them again
                g.grid[x1][y1].state = HIDDEN;
                g.grid[x2][y2].state = HIDDEN;
            }
        }

        // Increment the turn count
        g.turns++;
    }

    // Print the final grid
    print_grid(&g);

    // Print the game over message
    if (g.matched_pairs == NUM_PAIRS) {
        printf("Congratulations! You won the game in %d turns.\n", g.turns);
    } else {
        printf("Game over! You ran out of turns.\n");
    }

    return 0;
}

// Function to initialize the game
void init_game(game *g) {
    // Create an array of values for the cards
    int values[NUM_PAIRS * 2];
    for (int i = 0; i < NUM_PAIRS * 2; i++) {
        values[i] = (i / 2) + 1;
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
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            g->grid[i][j].value = values[index];
            g->grid[i][j].state = HIDDEN;
            index++;
        }
    }

    // Reset the game variables
    g->turns = 0;
    g->matched_pairs = 0;
}

// Function to print the game grid
void print_grid(game *g) {
    // Clear the console
    system("cls");

    // Print the top border
    printf("+---+---+---+---+\n");

    // Print the grid
    for (int i = 0; i < GRID_SIZE; i++) {
        printf("| ");
        for (int j = 0; j < GRID_SIZE; j++) {
            switch (g->grid[i][j].state) {
                case HIDDEN:
                    printf("   | ");
                    break;
                case SHOWN:
                    printf("%2d | ", g->grid[i][j].value);
                    break;
                case MATCHED:
                    printf(" ** | ");
                    break;
            }
        }
        printf("\n+---+---+---+---+\n");
    }

    // Print the bottom border
    printf("\n");
}

// Function to get the player's move
int get_move(game *g) {
    int move;
    printf("Enter your move (1-%d): ", GRID_SIZE * GRID_SIZE);
    scanf("%d", &move);
    return move - 1;
}

// Function to check if two cards match
int check_match(game *g, int x1, int y1, int x2, int y2) {
    return g->grid[x1][y1].value == g->grid[x2][y2].value;
}

// Function to check if the game is over
int game_over(game *g) {
    return g->turns >= MAX_TURNS || g->matched_pairs == NUM_PAIRS;
}
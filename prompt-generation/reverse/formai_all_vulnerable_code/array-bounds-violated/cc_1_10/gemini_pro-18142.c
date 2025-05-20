//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Card colors
#define RED   "\x1b[31m"
#define GREEN "\x1b[32m"
#define BLUE  "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN  "\x1b[36m"
#define YELLOW "\x1b[33m"

// Game settings
#define GRID_SIZE 4
#define NUM_CARDS (GRID_SIZE * GRID_SIZE)
#define MAX_TURNS 10

// Card struct
typedef struct {
    char color;
    bool matched;
} Card;

// Function prototypes
void print_grid(Card grid[GRID_SIZE][GRID_SIZE]);
void shuffle_grid(Card grid[GRID_SIZE][GRID_SIZE]);
bool get_player_input(int *row, int *col);
bool check_match(Card grid[GRID_SIZE][GRID_SIZE], int row1, int col1, int row2, int col2);
void reset_cards(Card grid[GRID_SIZE][GRID_SIZE], int row1, int col1, int row2, int col2);
bool check_for_win(Card grid[GRID_SIZE][GRID_SIZE]);
void print_colors();

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create and shuffle the grid
    Card grid[GRID_SIZE][GRID_SIZE];
    shuffle_grid(grid);

    // Print the colors
    print_colors();

    // Get player input
    int turns = 0;
    while (turns < MAX_TURNS && !check_for_win(grid)) {
        int row1, col1, row2, col2;

        // Get first card
        printf("Enter the coordinates of the first card (row, column): ");
        if (!get_player_input(&row1, &col1)) {
            printf("Invalid input. Please enter two numbers separated by a comma.\n");
            continue;
        }

        // Get second card
        printf("Enter the coordinates of the second card (row, column): ");
        if (!get_player_input(&row2, &col2)) {
            printf("Invalid input. Please enter two numbers separated by a comma.\n");
            continue;
        }

        // Check if the cards match
        if (check_match(grid, row1, col1, row2, col2)) {
            printf("Match!\n");
            grid[row1][col1].matched = true;
            grid[row2][col2].matched = true;
        } else {
            printf("No match.\n");
            reset_cards(grid, row1, col1, row2, col2);
        }

        // Print the grid
        print_grid(grid);

        turns++;
    }

    // Check if the player won
    if (check_for_win(grid)) {
        printf("Congratulations! You won in %d turns.\n", turns);
    } else {
        printf("Sorry, you lost. You ran out of turns.\n");
    }

    return 0;
}

void print_grid(Card grid[GRID_SIZE][GRID_SIZE]) {
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            if (grid[row][col].matched) {
                printf("%s  ", "  ");
            } else {
                switch (grid[row][col].color) {
                    case 'R':
                        printf("%s%s█%s", RED, grid[row][col].matched ? "█" : " ", RED);
                        break;
                    case 'G':
                        printf("%s%s█%s", GREEN, grid[row][col].matched ? "█" : " ", GREEN);
                        break;
                    case 'B':
                        printf("%s%s█%s", BLUE, grid[row][col].matched ? "█" : " ", BLUE);
                        break;
                    case 'M':
                        printf("%s%s█%s", MAGENTA, grid[row][col].matched ? "█" : " ", MAGENTA);
                        break;
                    case 'C':
                        printf("%s%s█%s", CYAN, grid[row][col].matched ? "█" : " ", CYAN);
                        break;
                    case 'Y':
                        printf("%s%s█%s", YELLOW, grid[row][col].matched ? "█" : " ", YELLOW);
                        break;
                }
            }
        }
        printf("\n");
    }
}

void shuffle_grid(Card grid[GRID_SIZE][GRID_SIZE]) {
    // Create an array of all the colors
    char colors[] = {'R', 'G', 'B', 'M', 'C', 'Y'};

    // Shuffle the colors
    for (int i = 0; i < NUM_CARDS; i++) {
        int j = rand() % NUM_CARDS;
        char temp = colors[i];
        colors[i] = colors[j];
        colors[j] = temp;
    }

    // Assign the colors to the grid
    int index = 0;
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            grid[row][col].color = colors[index++];
            grid[row][col].matched = false;
        }
    }
}

bool get_player_input(int *row, int *col) {
    char input[10];
    if (fgets(input, sizeof(input), stdin) == NULL) {
        return false;
    }

    int n = sscanf(input, "%d, %d", row, col);
    return n == 2;
}

bool check_match(Card grid[GRID_SIZE][GRID_SIZE], int row1, int col1, int row2, int col2) {
    return grid[row1][col1].color == grid[row2][col2].color;
}

void reset_cards(Card grid[GRID_SIZE][GRID_SIZE], int row1, int col1, int row2, int col2) {
    grid[row1][col1].matched = false;
    grid[row2][col2].matched = false;
}

bool check_for_win(Card grid[GRID_SIZE][GRID_SIZE]) {
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            if (!grid[row][col].matched) {
                return false;
            }
        }
    }
    return true;
}

void print_colors() {
    printf("Colors:\n");
    printf("%s Red   %s Green  %s Blue   %s Magenta\n", RED, GREEN, BLUE, MAGENTA);
    printf("%s Cyan  %s Yellow\n", CYAN, YELLOW);
}
//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define CARDS (ROWS * COLS) / 2

typedef struct {
    int value;
    int flipped;
} card_t;

void print_grid(card_t grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j].flipped) {
                printf("%2d ", grid[i][j].value);
            } else {
                printf("## ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    // Create the deck of cards
    int deck[CARDS];
    for (int i = 0; i < CARDS; i++) {
        deck[i] = i % (CARDS / 2) + 1;
    }

    // Shuffle the deck
    for (int i = 0; i < CARDS; i++) {
        int r = rand() % CARDS;
        int temp = deck[i];
        deck[i] = deck[r];
        deck[r] = temp;
    }

    // Create the grid
    card_t grid[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j].value = deck[i * COLS + j];
            grid[i][j].flipped = 0;
        }
    }

    // Play the game
    int matches = 0;
    int first_i = -1, first_j = -1;
    while (matches < CARDS / 2) {
        // Get the user's input
        int i, j;
        printf("Enter the row and column of the card you want to flip: ");
        scanf("%d %d", &i, &j);

        // Flip the card
        grid[i][j].flipped = 1;

        // Check if the card matches the first card flipped
        if (first_i == -1) {
            first_i = i;
            first_j = j;
        } else if (grid[i][j].value == grid[first_i][first_j].value) {
            printf("Yay! You found a match!\n");
            matches++;
            first_i = -1;
            first_j = -1;
        } else {
            printf("Aww, no match. Try again!\n");
            grid[i][j].flipped = 0;
            grid[first_i][first_j].flipped = 0;
            first_i = -1;
            first_j = -1;
        }

        // Print the grid
        print_grid(grid);
    }

    // Congratulate the player
    printf("Congratulations! You found all the matches!\n");

    return 0;
}
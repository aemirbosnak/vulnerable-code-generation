//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 4
#define NUM_PAIRS 8

typedef struct {
    int x;
    int y;
} coord;

int grid[GRID_SIZE][GRID_SIZE];
int flipped[GRID_SIZE][GRID_SIZE];
int pairs_found;
int moves;

void print_grid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%2d ", grid[i][j]);
        }
        printf("\n");
    }
}

void flip_card(coord c) {
    if (flipped[c.x][c.y] == 0) {
        flipped[c.x][c.y] = 1;
        moves++;
    }
}

int check_match(coord c1, coord c2) {
    return grid[c1.x][c1.y] == grid[c2.x][c2.y];
}

void reset_flipped() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            flipped[i][j] = 0;
        }
    }
}

int main() {
    srand(time(NULL));

    // Generate random grid
    int values[NUM_PAIRS * 2];
    for (int i = 0; i < NUM_PAIRS * 2; i++) {
        values[i] = i / 2 + 1;
    }
    for (int i = 0; i < NUM_PAIRS * 2; i++) {
        int j = rand() % (NUM_PAIRS * 2);
        int temp = values[i];
        values[i] = values[j];
        values[j] = temp;
    }
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = values[i * GRID_SIZE + j];
        }
    }

    // Game loop
    while (pairs_found < NUM_PAIRS) {
        print_grid();
        printf("Moves: %d\n", moves);

        // Get user input
        coord c1, c2;
        printf("Enter coordinates of first card (x, y): ");
        scanf("%d %d", &c1.x, &c1.y);
        printf("Enter coordinates of second card (x, y): ");
        scanf("%d %d", &c2.x, &c2.y);

        // Flip cards
        flip_card(c1);
        flip_card(c2);

        // Check for match
        if (check_match(c1, c2)) {
            pairs_found++;
            printf("Match found!\n");
        } else {
            printf("No match.\n");
            reset_flipped();
        }
    }

    // Game over
    printf("Congratulations! You found all the pairs in %d moves.\n", moves);

    return 0;
}
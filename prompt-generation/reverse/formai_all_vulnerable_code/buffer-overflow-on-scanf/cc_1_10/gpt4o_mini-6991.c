//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define GRID_SIZE 4 // Set the size of the grid (4x4)
#define TOTAL_CARDS (GRID_SIZE * GRID_SIZE)

void shuffle(int *cards) {
    for (int i = TOTAL_CARDS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

void initialize_cards(int *cards) {
    for (int i = 0; i < TOTAL_CARDS / 2; i++) {
        cards[i * 2] = i + 1;
        cards[i * 2 + 1] = i + 1;
    }
    shuffle(cards);
}

void display_grid(char grid[GRID_SIZE][GRID_SIZE], int revealed[GRID_SIZE][GRID_SIZE]) {
    printf("\nCurrent Grid:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (revealed[i][j]) {
                printf("%2d ", grid[i][j]);
            } else {
                printf(" * ");
            }
        }
        printf("\n");
    }
}

int check_match(int first_card, int second_card) {
    return first_card == second_card;
}

int main() {
    srand(time(NULL));
    int cards[TOTAL_CARDS];
    initialize_cards(cards);
    
    char grid[GRID_SIZE][GRID_SIZE];
    int revealed[GRID_SIZE][GRID_SIZE];
    memset(revealed, 0, sizeof(revealed));
    
    for (int i = 0; i < TOTAL_CARDS; i++) {
        grid[i / GRID_SIZE][i % GRID_SIZE] = cards[i];
    }

    int player_scores[2] = {0, 0};
    int attempts = 0;
    int current_player = 0;
    int total_pairs = TOTAL_CARDS / 2;

    while (player_scores[0] + player_scores[1] < total_pairs) {
        display_grid(grid, revealed);
        printf("Player %d's turn. Enter two positions (row col): ", current_player + 1);

        int first_row, first_col, second_row, second_col;
        scanf("%d %d %d %d", &first_row, &first_col, &second_row, &second_col);
        
        if (first_row < 0 || first_row >= GRID_SIZE || first_col < 0 || first_col >= GRID_SIZE ||
            second_row < 0 || second_row >= GRID_SIZE || second_col < 0 || second_col >= GRID_SIZE ||
            (first_row == second_row && first_col == second_col) ||
            revealed[first_row][first_col] || revealed[second_row][second_col]) {
            printf("Invalid input! Try again.\n");
            continue;
        }

        revealed[first_row][first_col] = 1;
        revealed[second_row][second_col] = 1;

        display_grid(grid, revealed);
        
        attempts++;
        if (check_match(grid[first_row][first_col], grid[second_row][second_col])) {
            printf("It's a match! Player %d scores a point.\n", current_player + 1);
            player_scores[current_player]++;
        } else {
            printf("No match. Next player's turn.\n");
            revealed[first_row][first_col] = 0;
            revealed[second_row][second_col] = 0;
            current_player = (current_player + 1) % 2; // Switch player
        }
    }

    printf("\nGame Over! Final Scores:\n");
    printf("Player 1: %d\n", player_scores[0]);
    printf("Player 2: %d\n", player_scores[1]);
    
    if (player_scores[0] > player_scores[1]) {
        printf("Player 1 wins!\n");
    } else if (player_scores[1] > player_scores[0]) {
        printf("Player 2 wins!\n");
    } else {
        printf("It's a tie!\n");
    }
    
    return 0;
}
//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a 4x4 grid of cards
    int grid[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    // Print the grid
    printf("---+\n");
    for (int i = 0; i < 4; i++) {
        printf("| ");
        for (int j = 0; j < 4; j++) {
            printf("%3d ", grid[i][j]);
        }
        printf("|\n");
        printf("---+\n");
    }

    // Play the game
    int turns = 0;
    int open_cards[16] = {0};
    int matched_pairs = 0;

    while (matched_pairs < 8 && turns < 100) {
        int card1, card2;
        printf("Click two cards:\n");
        scanf("%d %d", &card1, &card2);

        // Check if the cards are open
        if (open_cards[card1-1] && open_cards[card2-1]) {
            printf("Match!\n");
            open_cards[card1-1] = open_cards[card2-1] = 0;
            matched_pairs++;
        } else {
            printf("No match.\n");
        }

        // Flip over the other cards
        for (int i = 0; i < 16; i++) {
            if (!open_cards[i]) {
                open_cards[i] = 1 - open_cards[i];
            }
        }

        // Print the updated grid
        printf("---+\n");
        for (int i = 0; i < 4; i++) {
            printf("| ");
            for (int j = 0; j < 4; j++) {
                printf("%3d ", grid[i][j]);
            }
            printf("|\n");
            printf("---+\n");
        }

        // Increment the turn counter
        turns++;
    }

    // Print the final result
    if (matched_pairs == 8) {
        printf("Congratulations! You won!\n");
    } else {
        printf("You ran out of turns. Better luck next time!\n");
    }

    return 0;
}
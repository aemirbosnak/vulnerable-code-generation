//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int bingo[5][5];
    int i, j;

    // Initialize the bingo board with random numbers
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            bingo[i][j] = rand() % 15 + 1;
        }
    }

    // Print the bingo board
    printf("Bingo Board:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", bingo[i][j]);
        }
        printf("\n");
    }

    // Start the game
    int player_score = 0;
    while (player_score < 15) {
        int choice;
        printf("\nEnter your choice (1-15): ");
        scanf("%d", &choice);

        // Check if the chosen number is on the board
        int found = 0;
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                if (bingo[i][j] == choice) {
                    found = 1;
                    break;
                }
            }
            if (found) break;
        }

        // Update the player's score if the number is on the board
        if (found) {
            player_score++;
            printf("\n%d found! Your score is now %d.\n", choice, player_score);
        } else {
            printf("\n%d not found.\n", choice);
        }
    }

    // Print the final score
    printf("\nGame over! Your final score is %d.\n", player_score);

    return 0;
}
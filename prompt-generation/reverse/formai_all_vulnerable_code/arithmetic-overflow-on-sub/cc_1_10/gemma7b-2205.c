//Gemma-7B DATASET v1.0 Category: Table Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_Players 2

typedef struct Player {
    char name[20];
    int score;
    int lives;
} Player;

int main() {
    Player players[MAX_Players];
    int round = 1, currentPlayer = 0, gameWon = 0;
    char guess;

    // Initialize players
    for (int i = 0; i < MAX_Players; i++) {
        players[i].name[0] = '\0';
        players[i].score = 0;
        players[i].lives = 3;
    }

    // Game loop
    while (!gameWon) {
        // Get the current player's name
        printf("Enter your name: ");
        scanf("%s", players[currentPlayer].name);

        // Play the round
        for (int i = 0; i < 3; i++) {
            // Get the guess
            printf("Guess a number: ");
            scanf("%c", &guess);

            // Check if the guess is correct
            if (guess == players[currentPlayer].score) {
                // Increment the current player's score
                players[currentPlayer].score++;

                // Break out of the round loop
                break;
            } else if (guess < players[currentPlayer].score) {
                // Subtract a life from the current player
                players[currentPlayer].lives--;

                // Check if the current player has lost
                if (players[currentPlayer].lives == 0) {
                    // Game over
                    gameWon = 1;
                    printf("Game over! The winner is: %s", players[currentPlayer].name);
                } else {
                    // Tell the current player to guess higher
                    printf("Guess higher!\n");
                }
            } else {
                // Tell the current player to guess lower
                printf("Guess lower!\n");
            }
        }

        // Increment the round
        round++;

        // Move to the next player
        currentPlayer = (currentPlayer + 1) % MAX_Players;
    }

    return 0;
}
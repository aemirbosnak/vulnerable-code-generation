//Falcon-180B DATASET v1.0 Category: Table Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numPlayers;
    int playerScore[4];
    int diceValue;
    int currentPlayer = 1;
    int gameWon = 0;

    printf("Welcome to the C Table Game!\n");
    printf("How many players will be playing? ");
    scanf("%d", &numPlayers);

    // Roll dice to determine who goes first
    printf("Rolling dice to determine who goes first...\n");
    srand(time(NULL));
    diceValue = rand() % numPlayers + 1;

    for (int i = 1; i <= numPlayers; i++) {
        if (i == diceValue) {
            printf("Player %d goes first!\n", i);
            currentPlayer = i;
            break;
        }
    }

    while (!gameWon) {
        printf("\nPlayer %d's turn:\n", currentPlayer);
        printf("Roll the dice (1-6): ");
        scanf("%d", &diceValue);
        diceValue = rand() % 6 + 1; // Simulate dice roll

        if (diceValue == 1) {
            printf("You rolled a 1! Go back 3 spaces.\n");
            currentPlayer = (currentPlayer - 1 + numPlayers) % numPlayers;
        } else if (diceValue == 6) {
            printf("You rolled a 6! Move forward 3 spaces.\n");
            currentPlayer = (currentPlayer + 1) % numPlayers;
        } else {
            printf("You rolled a %d.\n", diceValue);
            currentPlayer = (currentPlayer + 1) % numPlayers;
        }

        if (currentPlayer == 1) {
            gameWon = 1;
            printf("\nPlayer %d wins the game!\n", currentPlayer);
        }
    }

    return 0;
}
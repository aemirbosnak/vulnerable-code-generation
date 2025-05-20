//FormAI DATASET v1.0 Category: Table Game ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numPlayers;
    int numCards;
    int deck[52];
    int playerScore[10];
    int playerHand[10][10];
    int dealerHand[10];
    int playerCount = 0;
    int dealerCount = 0;
    srand(time(NULL)); //Seed random number generator

    printf("Welcome to the C Table Game!\n\n");

    //Get number of players
    printf("How many players?: ");
    scanf("%d", &numPlayers);

    //Get number of cards
    printf("How many cards per player?: ");
    scanf("%d", &numCards);

    //Create deck
    for (int i = 0; i < 52; i++) {
        deck[i] = i + 1;
    }

    //Shuffle deck
    for (int i = 0; i < 52; i++) {
        int temp = deck[i];
        int r = rand() % 52;
        deck[i] = deck[r];
        deck[r] = temp;
    }

    //Deal cards
    for (int i = 0; i < numPlayers; i++) {
        printf("Player %d:\n", i+1);
        for (int j = 0; j < numCards; j++) {
            playerHand[i][j] = deck[playerCount];
            playerScore[i] += (playerHand[i][j] % 13) + 1; //Calculate player score
            playerCount++;
        }
        printf("Score: %d\n\n", playerScore[i]);
    }

    //Dealer's turn
    printf("Dealer's turn:\n");
    for (int i = 0; i < 2; i++) {
        dealerHand[i] = deck[playerCount];
        dealerCount += (dealerHand[i] % 13) + 1; //Calculate dealer score
        playerCount++;
    }
    printf("Score: %d\n\n", dealerCount);

    //Check for winner
    int winner = -1;
    int winningScore = 0;
    for (int i = 0; i < numPlayers; i++) {
        if ((playerScore[i] > winningScore) && (playerScore[i] <= 21)) {
            winner = i;
            winningScore = playerScore[i];
        }
    }
    if ((dealerCount > winningScore) && (dealerCount <= 21)) {
        winner = -2;
        winningScore = dealerCount;
    }
    if (winner == -1) {
        printf("No one wins!\n");
    } else if (winner == -2) {
        printf("Dealer wins with a score of %d!\n", winningScore);
    } else {
        printf("Player %d wins with a score of %d!\n", winner+1, winningScore);
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Table Game ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int players, cards, totalCards, maxHands, round, winner, maxScore, currentScore;
    printf("Welcome to the C Table Game!\n");
    printf("Enter the number of players (2-8): ");
    scanf("%d", &players);
    printf("Enter the number of cards per player (1-10): ");
    scanf("%d", &cards);
    totalCards = players * cards;
    int *deck = malloc(totalCards * sizeof(int)); // dynamically allocate memory for deck
    int *playerScores = calloc(players, sizeof(int)); // set playerScores to 0
    char *playerNames[8] = {"Alice", "Bob", "Charlie", "Dave", "Eve", "Frank", "Grace", "Heidi"};

    // initialize deck with numbers 1-10 for each suit (clubs, diamonds, hearts, spades)
    int cardIndex = 0;
    for (int i = 1; i <= 10; i++) {
        for (int j = 0; j < 4; j++) {
            deck[cardIndex] = i;
            cardIndex++;
        }
    }

    // shuffle deck using Fisher-Yates algorithm
    srand(time(NULL)); // seed random number generator with current time
    for (int i = totalCards - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }

    maxHands = totalCards / players; // number of hands in game
    round = 1;
    while (round <= maxHands) {
        printf("Round %d\n", round);
        for (int i = 0; i < players; i++) {
            printf("%s's turn\n", playerNames[i]);
            currentScore = 0;
            for (int j = 0; j < cards; j++) {
                int card = deck[i * cards + j];
                printf("Card %d: %d\n", j+1, card);
                currentScore += card;
            }
            playerScores[i] += currentScore;
            printf("%s's score: %d\n", playerNames[i], playerScores[i]);
        }
        round++;
    }

    // determine winner and max score
    winner = 0;
    maxScore = playerScores[0];
    for (int i = 1; i < players; i++) {
        if (playerScores[i] > maxScore) {
            winner = i;
            maxScore = playerScores[i];
        }
    }
    printf("%s wins with a score of %d!\n", playerNames[winner], maxScore);

    free(deck);
    free(playerScores);
    return 0;
}
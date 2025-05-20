//Gemma-7B DATASET v1.0 Category: Table Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAYER_COUNT 4

typedef struct Player {
    char name[20];
    int score;
    int hand[5];
} Player;

void dealCards(Player *players, int numPlayers);
void calculateScore(Player *players, int numPlayers);
void displayHand(Player *players, int numPlayers);

int main() {
    int numPlayers;
    printf("Enter the number of players (2-4): ");
    scanf("%d", &numPlayers);

    Player *players = malloc(numPlayers * sizeof(Player));

    for (int i = 0; i < numPlayers; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
        dealCards(players, numPlayers);
    }

    calculateScore(players, numPlayers);

    for (int i = 0; i < numPlayers; i++) {
        displayHand(players, numPlayers);
    }

    printf("The final score is: ");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }

    free(players);

    return 0;
}

void dealCards(Player *players, int numPlayers) {
    // Deal 5 cards to each player
    for (int i = 0; i < numPlayers; i++) {
        for (int j = 0; j < 5; j++) {
            players[i].hand[j] = rand() % 13 + 1;
        }
    }
}

void calculateScore(Player *players, int numPlayers) {
    // Calculate the score for each player
    for (int i = 0; i < numPlayers; i++) {
        int score = 0;
        for (int j = 0; j < 5; j++) {
            if (players[i].hand[j] == 1) {
                score += 10;
            } else if (players[i].hand[j] == 2) {
                score += 20;
            } else if (players[i].hand[j] == 3) {
                score += 30;
            }
        }
        players[i].score = score;
    }
}

void displayHand(Player *players, int numPlayers) {
    // Display the hand of each player
    for (int i = 0; i < numPlayers; i++) {
        printf("%s's hand: ", players[i].name);
        for (int j = 0; j < 5; j++) {
            printf("%d ", players[i].hand[j]);
        }
        printf("\n");
    }
}
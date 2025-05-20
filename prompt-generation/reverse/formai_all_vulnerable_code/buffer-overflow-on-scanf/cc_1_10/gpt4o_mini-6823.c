//GPT-4o-mini DATASET v1.0 Category: Poker Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUMBER_OF_PLAYERS 2
#define HAND_SIZE 5
#define DECK_SIZE 52

typedef struct {
    char *rank;
    char *suit;
} Card;

typedef struct {
    Card hand[HAND_SIZE];
    int score;
} Player;

Card deck[DECK_SIZE];

void initializeDeck() {
    const char *ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    const char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            deck[i * 4 + j].rank = ranks[i];
            deck[i * 4 + j].suit = suits[j];
        }
    }
}

void shuffleDeck() {
    for (int i = 0; i < DECK_SIZE; i++) {
        int r = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[r];
        deck[r] = temp;
    }
}

void dealCards(Player *player) {
    for (int i = 0; i < HAND_SIZE; i++) {
        player->hand[i] = deck[rand() % DECK_SIZE];
    }
}

void printHand(Player player) {
    printf("Player's hand:\n");
    for (int i = 0; i < HAND_SIZE; i++) {
        printf("%s of %s\n", player.hand[i].rank, player.hand[i].suit);
    }
}

int evaluateHand(Player player) {
    // A very simple scoring for paranoia (higher is worse)
    int score = 0;
    for (int i = 0; i < HAND_SIZE; i++) {
        if (strcmp(player.hand[i].rank, "A") == 0) {
            score += 14; // Aces are high, hence the paranoia increases
        } else if (strcmp(player.hand[i].rank, "K") == 0) {
            score += 13;
        } else if (strcmp(player.hand[i].rank, "Q") == 0) {
            score += 12;
        } else if (strcmp(player.hand[i].rank, "J") == 0) {
            score += 11;
        } else {
            score += atoi(player.hand[i].rank);
        }
    }
    return score;
}

void declareWinner(Player players[]) {
    printf("\nEvaluating hands...\n");
    int highestScore = 0;
    int winnerIndex = -1;

    for (int i = 0; i < NUMBER_OF_PLAYERS; i++) {
        players[i].score = evaluateHand(players[i]);
        printf("Player %d score: %d\n", i + 1, players[i].score);

        if (players[i].score > highestScore) {
            highestScore = players[i].score;
            winnerIndex = i;
        }
    }

    if (winnerIndex != -1) {
        printf("\nPlayer %d wins with a score of %d!\n", winnerIndex + 1, highestScore);
    } else {
        printf("\nIt's a tie!\n");
    }
}

int paranoidMode() {
    char choice[5];
    printf("Are you sure you want to play poker? Type 'yes' to continue or 'no' to panic: ");
    scanf("%s", choice);
    if (strcmp(choice, "yes") != 0) {
        printf("Panic mode activated! Exiting...\n");
        exit(0);
    }
    return 1;
}

int main() {
    srand(time(NULL));

    if (paranoidMode()) {
        initializeDeck();
        shuffleDeck();

        Player players[NUMBER_OF_PLAYERS];
        for (int i = 0; i < NUMBER_OF_PLAYERS; i++) {
            printf("\nDealing cards for Player %d...\n", i + 1);
            dealCards(&players[i]);
            printHand(players[i]);
        }

        declareWinner(players);

        printf("Done. Checking if someone is watching... \n");
        // This can be a suspicious check
        sleep(1);
        printf("All seems fine... but can we trust that?\n");
    }

    return 0;
}
//MISTRAL-7B DATASET v1.0 Category: Poker Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int value;
    char suit;
} Card;

typedef struct {
    Card cards[5];
    int score;
} PlayerHand;

void printHand(PlayerHand hand) {
    for (int i = 0; i < 5; ++i) {
        printf("%d%c ", hand.cards[i].value, hand.cards[i].suit);
    }
    printf("\nScore: %d\n", hand.score);
}

Card dealCard() {
    Card card;
    card.value = rand() % 13 + 1;
    card.suit = rand() % 4 + 'A';
    return card;
}

void initDeck(Card deck[52]) {
    for (int i = 0; i < 52; ++i) {
        deck[i].value = i % 13 + 1;
        deck[i].suit = (i / 13) % 4 + 'A';
    }
}

void shuffleDeck(Card deck[52], int size) {
    for (int i = 0; i < size; ++i) {
        int j = rand() % size;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

int main() {
    srand(time(NULL));

    Card deck[52];
    PlayerHand playerHand;
    Card communityCards[5];

    initDeck(deck);
    shuffleDeck(deck, 52);

    for (int i = 0; i < 5; ++i) {
        playerHand.cards[i] = dealCard();
    }

    for (int i = 0; i < 5; ++i) {
        communityCards[i] = dealCard();
    }

    printHand(playerHand);

    for (int i = 0; i < 5; ++i) {
        playerHand.score += playerHand.cards[i].value;
    }

    for (int i = 0; i < 5; ++i) {
        if (i < 4) {
            printf("%d%c ", communityCards[i].value, communityCards[i].suit);
        } else {
            playerHand.score += communityCards[i].value;
            printf("%d%c (Community Card)\n", communityCards[i].value, communityCards[i].suit);
        }
    }

    printf("Player's total score: %d\n", playerHand.score);

    return 0;
}
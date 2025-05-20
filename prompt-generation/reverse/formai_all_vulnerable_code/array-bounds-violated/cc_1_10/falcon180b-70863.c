//Falcon-180B DATASET v1.0 Category: Poker Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52

typedef struct {
    char suit;
    char rank;
} Card;

void shuffleDeck(Card deck[DECK_SIZE]) {
    int i, j;
    for (i = 0; i < DECK_SIZE; i++) {
        j = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

int compareCards(Card card1, Card card2) {
    if (card1.rank == 'A' || card1.rank == 'K' || card1.rank == 'Q' || card1.rank == 'J')
        return 1;
    else if (card2.rank == 'A' || card2.rank == 'K' || card2.rank == 'Q' || card2.rank == 'J')
        return -1;
    else if (card1.rank == card2.rank)
        return 0;
    else if (card1.rank > card2.rank)
        return 1;
    else
        return -1;
}

void displayHand(Card hand[5]) {
    int i;
    for (i = 0; i < 5; i++) {
        printf("%c%c ", hand[i].rank, hand[i].suit);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    Card deck[DECK_SIZE];
    char suit;
    int rank;

    printf("Welcome to the C Poker Game!\n");

    // Initialize the deck
    for (suit = 'C'; suit <= 'S'; suit++) {
        for (rank = 1; rank <= 13; rank++) {
            deck[rank * 4 + suit - 'C'] = (Card){suit, rank};
        }
    }

    // Shuffle the deck
    shuffleDeck(deck);

    // Deal 5 cards to the player
    Card hand[5];
    for (int i = 0; i < 5; i++) {
        hand[i] = deck[i];
    }

    // Display the player's hand
    printf("Your hand:\n");
    displayHand(hand);

    // Deal 5 cards to the dealer
    Card dealerHand[5];
    for (int i = 0; i < 5; i++) {
        dealerHand[i] = deck[i + 5];
    }

    // Display the dealer's hand
    printf("Dealer's hand:\n");
    displayHand(dealerHand);

    // Determine the winner
    int playerScore = 0;
    int dealerScore = 0;

    for (int i = 0; i < 5; i++) {
        playerScore += (hand[i].rank - '2') * (i + 1);
        dealerScore += (dealerHand[i].rank - '2') * (i + 1);
    }

    if (playerScore > 21 || dealerScore > 21) {
        printf("Bust! Dealer wins.\n");
    }
    else if (playerScore > dealerScore) {
        printf("You win!\n");
    }
    else if (dealerScore > playerScore) {
        printf("Dealer wins.\n");
    }
    else {
        printf("It's a tie!\n");
    }

    return 0;
}
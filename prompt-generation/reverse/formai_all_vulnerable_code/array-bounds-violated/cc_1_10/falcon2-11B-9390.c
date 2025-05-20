//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: optimized
#include <stdio.h>

// Define the card ranks and suits
#define RANK_2 2
#define RANK_3 3
#define RANK_4 4
#define RANK_5 5
#define RANK_6 6
#define RANK_7 7
#define RANK_8 8
#define RANK_9 9
#define RANK_10 10
#define RANK_JACK 11
#define RANK_QUEEN 12
#define RANK_KING 13
#define RANK_ACE 14

#define SUIT_DIAMOND 0
#define SUIT_HEART 1
#define SUIT_CLUB 2
#define SUIT_SPADE 3

// Define the player and dealer cards
int playerCard1[2];
int playerCard2[2];
int dealerCard1[2];
int dealerCard2[2];

// Function to shuffle the deck of cards
void shuffleDeck() {
    int suit, rank;
    int i, j;

    // Shuffle the deck
    for (i = 2; i < 14; i++) {
        for (j = 0; j < 4; j++) {
            suit = j;
            rank = i;
            playerCard1[j] = rank;
            playerCard2[j] = suit;
        }
    }
}

// Function to draw a card from the deck
void drawCard() {
    int suit, rank;

    // Draw a card from the deck
    suit = dealerCard1[0];
    rank = dealerCard1[1];

    // Print the drawn card
    printf("Dealer drew a %d of %d\n", rank, suit);
}

// Function to check the winner of the game
void checkWinner() {
    int playerScore = 0;
    int dealerScore = 0;

    // Loop through the player's cards
    for (int i = 0; i < 2; i++) {
        if (playerCard1[i] == RANK_ACE) {
            if (playerCard2[i] == SUIT_SPADE) {
                playerScore++;
            } else if (playerCard2[i] == SUIT_DIAMOND) {
                playerScore -= 10;
            }
        } else if (playerCard1[i] == RANK_JACK || playerCard1[i] == RANK_QUEEN || playerCard1[i] == RANK_KING) {
            playerScore += 10;
        } else if (playerCard1[i] == RANK_10) {
            playerScore += 10;
        } else {
            playerScore += playerCard1[i];
        }
    }

    // Loop through the dealer's cards
    for (int i = 0; i < 2; i++) {
        if (dealerCard1[i] == RANK_ACE) {
            if (dealerCard2[i] == SUIT_SPADE) {
                dealerScore++;
            } else if (dealerCard2[i] == SUIT_DIAMOND) {
                dealerScore -= 10;
            }
        } else if (dealerCard1[i] == RANK_JACK || dealerCard1[i] == RANK_QUEEN || dealerCard1[i] == RANK_KING) {
            dealerScore += 10;
        } else if (dealerCard1[i] == RANK_10) {
            dealerScore += 10;
        } else {
            dealerScore += dealerCard1[i];
        }
    }

    // Check the winner of the game
    if (playerScore > dealerScore) {
        printf("Player wins!\n");
    } else if (playerScore < dealerScore) {
        printf("Dealer wins!\n");
    } else {
        printf("It's a tie!\n");
    }
}

int main() {
    // Shuffle the deck of cards
    shuffleDeck();

    // Draw the dealer's cards
    drawCard();
    drawCard();

    // Check the winner of the game
    checkWinner();

    return 0;
}
//FormAI DATASET v1.0 Category: Poker Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int value;
    char suit;
} Card;

void shuffleDeck(Card deck[]) {
    int i, j;
    Card temp;

    for (i = 0; i < 52; i++) {
        j = rand() % 52;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealCards(Card deck[], Card playerHand[], Card computerHand[]) {
    int i;

    for (i = 0; i < 5; i++) {
        playerHand[i] = deck[i];
        computerHand[i] = deck[i + 5];
    }
}

void printHand(Card hand[]) {
    int i;

    for (i = 0; i < 5; i++) {
        printf("[%c %d] ", hand[i].suit, hand[i].value);
    }
    printf("\n");
}

int compareCards(const void *a, const void *b) {
    Card *cardA = (Card *)a;
    Card *cardB = (Card *)b;

    return (cardB->value - cardA->value);
}

void evaluateHand(Card hand[], char *handRank) {
    int i, numPairs = 0, numThreeOfAKind = 0, numFourOfAKind = 0;

    qsort(hand, 5, sizeof(Card), compareCards);

    for (i = 0; i < 4; i++) {
        if (hand[i].value == hand[i + 1].value) {
            if (++numPairs == 1) {
                *handRank = 'P';
            } else if (numPairs == 2) {
                *handRank = 'T';
                numThreeOfAKind = 1;
            } else if (numPairs == 3 || numPairs == 4) {
                numThreeOfAKind = 0;
                numFourOfAKind = 1;
            }
        }
    }

    if (numPairs == 0 && (hand[0].value - hand[4].value == 4)) {
        *handRank = 'S';
    } else if (numPairs == 1 && numThreeOfAKind == 1) {
        *handRank = 'F';
    } else if (numThreeOfAKind == 1 && numPairs < 2) {
        *handRank = 'T';
    } else if (numFourOfAKind == 1) {
        *handRank = 'Q';
    }
}

void playPoker() {
    int i, playerChips = 100, computerChips = 100, bet;
    char playAgain = 'Y', handRank = 'H';
    Card deck[52], playerHand[5], computerHand[5];

    srand(time(NULL));

    while (playAgain == 'Y' && playerChips > 0 && computerChips > 0) {
        printf("You have %d chips. Computer has %d chips.\n", playerChips, computerChips);
        printf("Ante is 10 chips. Place your bet: ");
        scanf("%d", &bet);

        playerChips -= bet;
        computerChips -= 10;

        for (i = 0; i < 52; i++) {
            deck[i].value = (i % 13) + 2;
            if (i < 13) {
                deck[i].suit = 'S';
            } else if (i < 26) {
                deck[i].suit = 'H';
            } else if (i < 39) {
                deck[i].suit = 'D';
            } else {
                deck[i].suit = 'C';
            }
        }

        shuffleDeck(deck);
        dealCards(deck, playerHand, computerHand);

        printf("Your hand is: ");
        printHand(playerHand);
        evaluateHand(playerHand, &handRank);
        printf("Your hand rank is %c.\n", handRank);

        printf("Computer's hand is: ");
        printHand(computerHand);
        evaluateHand(computerHand, &handRank);

        if (handRank == 'H') {
            printf("You win!\n");
            playerChips += (bet * 2);
        } else if (handRank == 'P') {
            printf("Pair! You win!\n");
            playerChips += (bet * 2);
        } else if (handRank == 'T') {
            printf("Three of a kind! You win!\n");
            playerChips += (bet * 2);
        } else if (handRank == 'S') {
            printf("Straight! You win!\n");
            playerChips += (bet * 2);
        } else if (handRank == 'F') {
            printf("Full house! You win!\n");
            playerChips += (bet * 2);
        } else if (handRank == 'Q') {
            printf("Four of a kind! You win!\n");
            playerChips += (bet * 2);
        } else {
            printf("Computer wins.\n");
            computerChips += (bet * 2);
        }

        printf("Play again? (Y/N) ");
        scanf(" %c", &playAgain);
    }

    printf("Thanks for playing!\n");
}

int main() {
    playPoker();
    return 0;
}
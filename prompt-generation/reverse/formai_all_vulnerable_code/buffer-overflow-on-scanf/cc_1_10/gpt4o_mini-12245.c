//GPT-4o-mini DATASET v1.0 Category: Poker Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 5

void shuffleDeck(char deck[][2], int size) {
    for (int i = 0; i < size; i++) {
        int r = rand() % size;
        char temp[2] = {deck[i][0], deck[i][1]};
        deck[i][0] = deck[r][0];
        deck[i][1] = deck[r][1];
        deck[r][0] = temp[0];
        deck[r][1] = temp[1];
    }
}

void dealCards(char deck[][2], char hand[][2], int numCards) {
    for (int i = 0; i < numCards; i++) {
        hand[i][0] = deck[i][0];
        hand[i][1] = deck[i][1];
    }
}

void printHand(char hand[][2]) {
    for (int i = 0; i < NUM_CARDS; i++) {
        printf("%c%c ", hand[i][0], hand[i][1]);
    }
    printf("\n");
}

void playFiveCardDraw() {
    char deck[52][2];
    char hand[NUM_CARDS][2];
    int cardIndex = 0;
    
    // Create the deck
    for (int suit = 0; suit < 4; suit++) {
        for (int value = 1; value <= 13; value++) {
            deck[cardIndex][0] = value + '0'; // Simplified value representation
            deck[cardIndex][1] = "HDSC"[suit]; // Hearts, Diamonds, Spades, Clubs
            cardIndex++;
        }
    }

    shuffleDeck(deck, 52);
    dealCards(deck, hand, NUM_CARDS);

    printf("Five Card Draw Hand:\n");
    printHand(hand);
}

void playTexasHoldEm() {
    char deck[52][2];
    char playerHand[2][2];
    char communityCards[5][2];
    int cardIndex = 0;

    // Create the deck
    for (int suit = 0; suit < 4; suit++) {
        for (int value = 1; value <= 13; value++) {
            deck[cardIndex][0] = value + '0';
            deck[cardIndex][1] = "HDSC"[suit];
            cardIndex++;
        }
    }

    shuffleDeck(deck, 52);
    dealCards(deck, playerHand, 2);
    dealCards(deck + 2, communityCards, 5); // deal 5 community cards

    printf("Texas Hold'em - Your Hand:\n");
    printHand(playerHand);
    printf("Community Cards:\n");
    printHand(communityCards);
}

void displayGameOptions() {
    printf("Welcome to the Shape-Shifting Poker Game!\n");
    printf("Select a game mode:\n");
    printf("1. Five Card Draw\n");
    printf("2. Texas Hold'em\n");
    printf("Enter your choice (1/2): ");
}

int main() {
    srand(time(NULL));
    int choice;

    displayGameOptions();
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            playFiveCardDraw();
            break;
        case 2:
            playTexasHoldEm();
            break;
        default:
            printf("Invalid choice. Exiting.\n");
            return -1;
    }

    printf("Thank you for playing!\n");
    return 0;
}
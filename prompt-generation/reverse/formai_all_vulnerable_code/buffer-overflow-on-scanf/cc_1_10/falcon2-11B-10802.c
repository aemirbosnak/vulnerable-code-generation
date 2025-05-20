//Falcon2-11B DATASET v1.0 Category: Poker Game ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This function sorts an array in descending order
void sortDescending(int *arr, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] < arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// This function compares two cards and returns -1 if first is lower, 1 if first is higher, 0 if equal
int compareCards(int card1, int card2) {
    if (card1 == card2) {
        return 0;
    }
    else if (card1 > card2) {
        return 1;
    }
    else {
        return -1;
    }
}

// This function plays the game of poker
void playPoker() {
    int n, card1, card2, result;

    // Get number of players
    printf("Enter the number of players: ");
    scanf("%d", &n);

    // Create a deck of cards
    int deck[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    int deckSize = sizeof(deck) / sizeof(deck[0]);

    // Shuffle the deck
    for (int i = 0; i < deckSize; i++) {
        int j = rand() % deckSize;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }

    // Deal cards to players
    for (int i = 0; i < n; i++) {
        card1 = deck[rand() % deckSize];
        card2 = deck[rand() % deckSize];
        printf("Player %d's card: %d\n", i+1, card1);
        printf("Player %d's card: %d\n", i+1, card2);
        result = compareCards(card1, card2);
        if (result == 1) {
            printf("Player %d wins!\n", i+1);
        }
        else if (result == 0) {
            printf("Draw!\n");
        }
        else {
            printf("Player %d loses!\n", i+1);
        }
    }
}

int main() {
    playPoker();
    return 0;
}
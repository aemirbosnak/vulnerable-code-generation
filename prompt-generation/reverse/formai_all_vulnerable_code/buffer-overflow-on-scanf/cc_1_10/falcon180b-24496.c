//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define TOTAL_CARDS 8

// Function to shuffle the deck of cards
void shuffleDeck(int deck[ROWS][COLS]) {
    int i, j, temp;
    srand(time(NULL));
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS - 1; j++) {
            temp = deck[i][j];
            deck[i][j] = deck[i][j + 1];
            deck[i][j + 1] = temp;
        }
    }
}

// Function to print the deck of cards
void printDeck(int deck[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", deck[i][j]);
        }
        printf("\n");
    }
}

// Function to check if two cards match
int checkMatch(int card1, int card2) {
    return (card1 == card2);
}

int main() {
    int deck[ROWS][COLS], i, j, matches = 0;

    // Initialize the deck of cards
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            deck[i][j] = rand() % TOTAL_CARDS + 1;
        }
    }

    // Shuffle the deck of cards
    shuffleDeck(deck);

    // Print the shuffled deck of cards
    printf("Shuffled Deck:\n");
    printDeck(deck);

    // Start the game
    int choice1, choice2, value1, value2, flag = 0;
    while (matches < TOTAL_CARDS) {
        flag = 0;
        printf("\nChoose two cards:\n");
        scanf("%d %d", &choice1, &choice2);
        value1 = deck[choice1 - 1][0];
        value2 = deck[choice2 - 1][0];
        if (checkMatch(value1, value2)) {
            printf("Congratulations! You found a match.\n");
            matches++;
        } else {
            printf("Sorry, try again.\n");
        }
        if (matches == TOTAL_CARDS) {
            printf("\nYou won the game in %d turns.\n", matches + 1);
        }
    }

    return 0;
}
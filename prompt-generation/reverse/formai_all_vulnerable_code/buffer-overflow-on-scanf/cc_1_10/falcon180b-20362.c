//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define TOTAL_CARDS 16

// Function to initialize the deck of cards
void initDeck(char deck[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            deck[i][j] = 'X';
        }
    }
}

// Function to shuffle the deck of cards
void shuffleDeck(char deck[ROWS][COLS]) {
    int i, j, temp;
    srand(time(NULL));
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS - 1; j++) {
            temp = rand() % (COLS - j) + j;
            char tempChar = deck[i][j];
            deck[i][j] = deck[i][temp];
            deck[i][temp] = tempChar;
        }
    }
}

// Function to print the deck of cards
void printDeck(char deck[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", deck[i][j]);
        }
        printf("\n");
    }
}

// Function to check if two cards match
int checkMatch(char card1, char card2) {
    if (card1 == card2) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if all cards have been matched
int checkWin(char deck[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (deck[i][j]!= 'X') {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    char deck[ROWS][COLS];
    int i, j, matches = 0;

    // Initialize the deck of cards
    initDeck(deck);

    // Shuffle the deck of cards
    shuffleDeck(deck);

    // Print the deck of cards
    printf("The deck has been shuffled:\n");
    printDeck(deck);

    // Start the game
    while (matches < TOTAL_CARDS / 2) {
        int choice1, choice2;
        printf("\nChoose two cards:\n");
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                printf("%d. %c\n", i * COLS + j + 1, deck[i][j]);
            }
        }
        scanf("%d %d", &choice1, &choice2);
        if (checkMatch(deck[choice1 - 1][0], deck[choice2 - 1][0])) {
            matches++;
            printf("\nMatch! Try again.\n");
        } else {
            printf("\nNo match. Try again.\n");
            deck[choice1 - 1][0] = 'X';
            deck[choice2 - 1][0] = 'X';
        }
    }

    // Check if all cards have been matched
    if (checkWin(deck)) {
        printf("\nCongratulations! You win!\n");
    } else {
        printf("\nSorry, you lose.\n");
    }

    return 0;
}
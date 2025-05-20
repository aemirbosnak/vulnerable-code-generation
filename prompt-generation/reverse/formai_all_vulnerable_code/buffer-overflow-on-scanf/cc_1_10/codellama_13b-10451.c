//Code Llama-13B DATASET v1.0 Category: Bingo Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 5
#define NUM_BALLS 15
#define WINNING_PATTERN 5

// Function to generate a random number between 1 and 75
int generateRandomNumber(void) {
    return (rand() % 75) + 1;
}

// Function to check if the player has won
int checkWin(int *playerCards, int numCards) {
    int i, j, count = 0;
    for (i = 0; i < numCards; i++) {
        for (j = 0; j < numCards; j++) {
            if (playerCards[i] == playerCards[j]) {
                count++;
            }
        }
    }
    return count >= WINNING_PATTERN;
}

// Main function
int main() {
    int i, j, k;
    int playerCards[NUM_CARDS];
    int bingoCard[NUM_BALLS];
    srand(time(NULL));

    // Generate the bingo card
    for (i = 0; i < NUM_BALLS; i++) {
        bingoCard[i] = generateRandomNumber();
    }

    // Print the bingo card
    printf("Bingo Card:\n");
    for (i = 0; i < NUM_BALLS; i++) {
        printf("%d ", bingoCard[i]);
        if ((i + 1) % 5 == 0) {
            printf("\n");
        }
    }

    // Ask the player to mark their cards
    printf("Mark your cards: ");
    for (i = 0; i < NUM_CARDS; i++) {
        scanf("%d", &playerCards[i]);
    }

    // Check if the player has won
    if (checkWin(playerCards, NUM_CARDS)) {
        printf("Congratulations, you have won!\n");
    } else {
        printf("Sorry, you did not win.\n");
    }

    return 0;
}
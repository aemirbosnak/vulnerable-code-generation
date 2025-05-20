//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 16
#define NUM_ATTEMPTS 10

struct card {
    int value;
    char *suit;
};

void shuffle_cards(struct card *deck) {
    int i, j;
    for (i = 0; i < NUM_CARDS; i++) {
        for (j = 0; j < NUM_CARDS - i - 1; j++) {
            if (rand() % 2 == 0) {
                struct card temp = deck[j];
                deck[j] = deck[j + 1];
                deck[j + 1] = temp;
            }
        }
    }
}

void print_cards(struct card *deck) {
    int i;
    for (i = 0; i < NUM_CARDS; i++) {
        printf("%d of %s\n", deck[i].value, deck[i].suit);
    }
}

int main() {
    struct card deck[NUM_CARDS];
    int i;

    // Initialize the deck of cards
    for (i = 0; i < NUM_CARDS; i++) {
        deck[i].value = i + 1;
        if (i % 2 == 0) {
            deck[i].suit = "Hearts";
        } else {
            deck[i].suit = "Spades";
        }
    }

    // Shuffle the deck
    shuffle_cards(deck);

    // Print the initial layout
    printf("The cards have been shuffled and laid out:\n");
    print_cards(deck);

    int num_matches = 0;
    int attempts_left = NUM_ATTEMPTS;

    // Start the game
    while (attempts_left > 0 && num_matches < NUM_CARDS) {
        int choice1, choice2;
        printf("You have %d attempts left.\n", attempts_left);
        printf("Enter the numbers of two cards to flip over: ");
        scanf("%d %d", &choice1, &choice2);

        // Check if the chosen cards match
        if (deck[choice1 - 1].value == deck[choice2 - 1].value) {
            printf("You found a match!\n");
            num_matches++;
        } else {
            printf("The cards do not match.\n");
            attempts_left--;
        }

        // Flip the cards back over
        deck[choice1 - 1].value = -1;
        deck[choice2 - 1].value = -1;
    }

    // Print the final layout and results
    printf("\nThe final layout of the cards:\n");
    print_cards(deck);

    if (num_matches == NUM_CARDS) {
        printf("\nCongratulations, you have matched all the cards!\n");
    } else {
        printf("\nSorry, you ran out of attempts and did not match all the cards.\n");
    }

    return 0;
}
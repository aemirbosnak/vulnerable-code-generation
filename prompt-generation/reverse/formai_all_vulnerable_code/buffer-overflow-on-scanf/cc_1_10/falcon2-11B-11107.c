//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: active
#include<stdio.h>
#include<stdlib.h>

#define NUM_CARDS 8

// Define the deck of cards
struct Card {
    int value;
    char suit;
};

struct Card deck[NUM_CARDS] = {
    {2, 'c'}, {3, 'd'}, {4, 'h'}, {5,'s'}, 
    {6, 'c'}, {7, 'd'}, {8, 'h'}, {9,'s'}
};

// Define a function to shuffle the deck
void shuffle(struct Card deck[NUM_CARDS]) {
    int i;
    for (i = NUM_CARDS-1; i > 0; i--) {
        int j = rand() % (i + 1);
        struct Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Define a function to print the deck
void print_deck(struct Card deck[NUM_CARDS]) {
    int i;
    for (i = 0; i < NUM_CARDS; i++) {
        printf("%d %c\n", deck[i].value, deck[i].suit);
    }
}

// Define a function to find a match
int find_match(struct Card deck[NUM_CARDS]) {
    int i, j;
    for (i = 0; i < NUM_CARDS; i++) {
        for (j = i+1; j < NUM_CARDS; j++) {
            if (deck[i].value == deck[j].value && deck[i].suit == deck[j].suit) {
                return 1;
            }
        }
    }
    return 0;
}

// Main function
int main() {
    int i, match = 0;

    // Shuffle the deck
    shuffle(deck);

    // Print the deck
    print_deck(deck);

    // Loop until a match is found
    while (!match) {
        // Prompt the user to guess a card
        printf("Guess a card: ");
        int guess = 0;
        scanf("%d", &guess);

        // Check if the guess is correct
        match = find_match(deck);
        if (match) {
            printf("You found a match! The card was %d %c.\n", guess, deck[guess].suit);
        } else {
            printf("Sorry, that's not a match. Try again!\n");
        }
    }

    printf("Congratulations, you won the game!\n");
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20 // number of cards
#define NUM_CARDS (SIZE * 2) // total number of cards (pairs)

void init_deck(char deck[NUM_CARDS]);
void print_deck(char deck[NUM_CARDS]);
void shuffle_deck(char deck[NUM_CARDS]);
int check_match(char card1, char card2);
void play_game(char deck[NUM_CARDS]);

int main() {
    char deck[NUM_CARDS];
    init_deck(deck);
    play_game(deck);
    return 0;
}

void init_deck(char deck[NUM_CARDS]) {
    int i;
    for (i = 0; i < NUM_CARDS; i++) {
        deck[i] = i + 'A';
    }
}

void print_deck(char deck[NUM_CARDS]) {
    int i;
    for (i = 0; i < NUM_CARDS; i++) {
        printf("%c ", deck[i]);
    }
    printf("\n");
}

void shuffle_deck(char deck[NUM_CARDS]) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < NUM_CARDS; i++) {
        j = rand() % NUM_CARDS;
        char temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

int check_match(char card1, char card2) {
    return (card1 == card2);
}

void play_game(char deck[NUM_CARDS]) {
    int num_turns = 0, matches = 0, i;
    printf("Let's play a memory game!\n");
    printf("There are %d cards in total.\n\n", NUM_CARDS);
    while (matches < SIZE) {
        num_turns++;
        int found_match = 0;
        printf("Turn %d:\n", num_turns);
        print_deck(deck);
        char card1, card2;
        scanf("%c %c", &card1, &card2);
        if (check_match(card1, card2)) {
            matches++;
            printf("Congratulations! You found a match!\n");
        } else {
            printf("Sorry, those cards don't match.\n");
        }
    }
    printf("You completed the game in %d turns.\n", num_turns);
}
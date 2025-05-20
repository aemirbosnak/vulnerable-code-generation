//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 16

typedef struct {
    int value;
    int flipped;
} card_t;

card_t cards[NUM_CARDS];
int num_matches = 0;
int num_guesses = 0;

void init_cards() {
    int i, j;
    
    for (i = 0; i < NUM_CARDS; i+=2) {
        cards[i].value = rand() % 8 + 1;
        cards[i+1].value = cards[i].value;
    }

    for (i = 0; i < NUM_CARDS; i++) {
        cards[i].flipped = 0;
    }
}

void shuffle_cards() {
    int i, j;
    card_t temp;
    
    for (i = 0; i < NUM_CARDS; i++) {
        j = rand() % NUM_CARDS;
        temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

void print_cards() {
    int i;
    
    printf(" ");
    for (i = 0; i < NUM_CARDS; i++) {
        printf(" %d ", i);
    }
    printf("\n");
    
    printf("+");
    for (i = 0; i < NUM_CARDS; i++) {
        printf("---+");
    }
    printf("\n");
    
    for (i = 0; i < NUM_CARDS; i++) {
        printf("|");
        if (cards[i].flipped) {
            printf(" %d |", cards[i].value);
        } else {
            printf("   |");
        }
    }
    printf("\n");
    
    printf("+");
    for (i = 0; i < NUM_CARDS; i++) {
        printf("---+");
    }
    printf("\n");
}

int get_guess() {
    int guess;
    
    printf("Enter your guess (0-%d): ", NUM_CARDS-1);
    scanf("%d", &guess);
    
    return guess;
}

int main() {
    int guess1, guess2;
    
    srand(time(NULL));
    init_cards();
    shuffle_cards();
    
    while (num_matches < NUM_CARDS/2) {
        print_cards();
        
        guess1 = get_guess();
        cards[guess1].flipped = 1;
        
        print_cards();
        
        guess2 = get_guess();
        cards[guess2].flipped = 1;
        
        num_guesses++;
        
        if (cards[guess1].value == cards[guess2].value) {
            printf("Match!\n");
            num_matches++;
        } else {
            printf("No match.\n");
            cards[guess1].flipped = 0;
            cards[guess2].flipped = 0;
        }
    }
    
    printf("Congratulations! You found all the matches in %d guesses.\n", num_guesses);
    
    return 0;
}
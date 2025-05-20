//FormAI DATASET v1.0 Category: Memory Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int value;
    char suit;
} card_t;

void shuffleDeck(card_t *deck, int size) {
    srand(time(0));
    for(int i = 0; i < size; i++) {
        int r = rand() % size;
        card_t temp = deck[i];
        deck[i] = deck[r];
        deck[r] = temp;
    }
}

void printDeck(card_t *deck, int size) {
    printf("Cards in the deck: \n");
    for(int i = 0; i < size; i++) {
        printf("%d%c ", deck[i].value, deck[i].suit);
    }
}

int main() {
    int size = 16;
    card_t deck[size];
    int values[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    char suits[4] = {'H', 'D', 'S', 'C'};
    
    int count = 0;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 4; j++) {
            deck[count].value = values[i];
            deck[count].suit = suits[j];
            count++;
        }
    }
    
    shuffleDeck(deck, size);
    printDeck(deck, size);
    
    int revealed[size];
    for(int i = 0; i < size; i++) {
        revealed[i] = 0;
    }
    
    int pairs = 0;
    while(pairs < 8) {
        int choice1, choice2;
        printf("\nChoose two cards to reveal (1-16): ");
        scanf("%d %d", &choice1, &choice2);
        choice1--;
        choice2--;
        if(choice1 < 0 || choice1 > 15 || choice2 < 0 || choice2 > 15) {
            printf("Invalid choices. Try again.\n");
            continue;
        }
        if(revealed[choice1] || revealed[choice2]) {
            printf("Already revealed. Try again.\n");
            continue;
        }
        printf("Revealing card %d: %d%c\n", choice1+1, deck[choice1].value, deck[choice1].suit);
        printf("Revealing card %d: %d%c\n", choice2+1, deck[choice2].value, deck[choice2].suit);
        if(deck[choice1].value == deck[choice2].value) {
            printf("It's a match!\n");
            pairs++;
            revealed[choice1] = 1;
            revealed[choice2] = 1;
        } else {
            printf("Sorry, try again.\n");
        }
    }
    
    printf("Congratulations, you found all the pairs!\n");
    
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEAP_SIZE 10
#define NUM_CARDS 5

typedef struct {
    int value;
    int isRevealed;
} Card;

void initDeck(Card deck[NUM_CARDS]) {
    int i;
    for (i = 0; i < NUM_CARDS; i++) {
        deck[i].value = i + 1;
        deck[i].isRevealed = 0;
    }
}

void shuffleDeck(Card deck[NUM_CARDS]) {
    int i, j, temp;
    srand(time(NULL));
    for (i = 0; i < NUM_CARDS; i++) {
        j = rand() % NUM_CARDS;
        temp = deck[i].value;
        deck[i].value = deck[j].value;
        deck[j].value = temp;
    }
}

void printDeck(Card deck[NUM_CARDS]) {
    int i;
    for (i = 0; i < NUM_CARDS; i++) {
        if (deck[i].isRevealed == 1) {
            printf("%d ", deck[i].value);
        } else {
            printf("? ");
        }
    }
    printf("\n");
}

int main() {
    Card deck[NUM_CARDS];
    int choice1, choice2, i;
    initDeck(deck);
    shuffleDeck(deck);
    printf("Welcome to the Post-Apocalyptic Memory Game!\n");
    printf("You have %d cards to match.\n", NUM_CARDS);
    while (1) {
        printDeck(deck);
        printf("Enter first card: ");
        scanf("%d", &choice1);
        if (choice1 < 1 || choice1 > NUM_CARDS) {
            printf("Invalid choice.\n");
            continue;
        }
        printf("Enter second card: ");
        scanf("%d", &choice2);
        if (choice2 < 1 || choice2 > NUM_CARDS) {
            printf("Invalid choice.\n");
            continue;
        }
        if (deck[choice1 - 1].isRevealed == 1 || deck[choice2 - 1].isRevealed == 1) {
            printf("Card already revealed.\n");
            continue;
        }
        if (deck[choice1 - 1].value == deck[choice2 - 1].value) {
            deck[choice1 - 1].isRevealed = 1;
            deck[choice2 - 1].isRevealed = 1;
            printf("Match!\n");
        } else {
            printf("No match.\n");
            deck[choice1 - 1].isRevealed = 1;
            deck[choice2 - 1].isRevealed = 1;
        }
    }
    return 0;
}
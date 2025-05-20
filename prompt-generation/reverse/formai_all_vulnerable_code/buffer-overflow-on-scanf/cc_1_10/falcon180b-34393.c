//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 100

typedef struct {
    int value;
    char name[10];
} Card;

Card cards[MAX_CARDS];

void initCards() {
    int i;
    for (i = 0; i < MAX_CARDS; i++) {
        cards[i].value = i + 1;
        sprintf(cards[i].name, "Card %d", i + 1);
    }
}

void shuffleCards() {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < MAX_CARDS; i++) {
        j = rand() % MAX_CARDS;
        Card temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

void printCard(Card card) {
    printf("%s (%d)\n", card.name, card.value);
}

int main() {
    int numPlayers, i;
    printf("Enter the number of players: ");
    scanf("%d", &numPlayers);

    initCards();
    shuffleCards();

    printf("Dealing cards...\n");
    int cardIndex = 0;
    for (i = 0; i < numPlayers; i++) {
        printf("Player %d's cards:\n", i + 1);
        while (cardIndex < MAX_CARDS) {
            printCard(cards[cardIndex]);
            cardIndex++;
        }
        cardIndex = 0;
    }

    return 0;
}
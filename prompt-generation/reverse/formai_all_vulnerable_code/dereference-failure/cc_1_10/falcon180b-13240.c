//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 100
#define MAX_PLAYERS 10

typedef struct {
    int id;
    char name[20];
} Player;

typedef struct {
    int value;
    int marked;
} Card;

void generateCard(Card* card) {
    card->value = rand() % 75 + 1;
    card->marked = 0;
}

void printCard(Card* card) {
    printf("%d ", card->value);
}

void generateCards(Card* deck) {
    for (int i = 0; i < MAX_CARDS; i++) {
        generateCard(&deck[i]);
    }
}

int compareCards(Card* a, Card* b) {
    return a->value - b->value;
}

void sortCards(Card* deck) {
    qsort(deck, MAX_CARDS, sizeof(Card), compareCards);
}

void shuffleCards(Card* deck) {
    srand(time(NULL));
    for (int i = 0; i < MAX_CARDS; i++) {
        int j = rand() % MAX_CARDS;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

int main() {
    srand(time(NULL));

    Player players[MAX_PLAYERS];
    for (int i = 0; i < MAX_PLAYERS; i++) {
        players[i].id = i + 1;
        sprintf(players[i].name, "Player %d", i + 1);
    }

    Card deck[MAX_CARDS];
    generateCards(deck);
    shuffleCards(deck);

    int currentCard = 0;
    while (currentCard < MAX_CARDS) {
        printf("\n");
        for (int i = 0; i < MAX_PLAYERS; i++) {
            printf("%s's cards:\n", players[i].name);
            for (int j = 0; j < 5; j++) {
                if (j < currentCard) {
                    printCard(&deck[currentCard]);
                    currentCard++;
                } else {
                    printf("XX ");
                }
            }
            printf("\n");
        }
        currentCard += 5;
    }

    return 0;
}
//Falcon2-11B DATASET v1.0 Category: Poker Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int value;
} Card;

typedef struct {
    Card hand[5];
    int numCards;
} Deck;

typedef struct {
    Deck* deck;
    Deck* deck2;
} Game;

void createDeck(Deck* deck) {
    for (int i = 0; i < 52; i++) {
        Card card;
        card.name[0] = 'A' + (i % 13);
        card.name[1] = 'A' + (i / 13);
        card.value = i;
        deck->hand[deck->numCards++] = card;
    }
}

void shuffleDeck(Deck* deck) {
    for (int i = 0; i < deck->numCards - 1; i++) {
        int r = rand() % (i + 1);
        Card temp = deck->hand[i];
        deck->hand[i] = deck->hand[r];
        deck->hand[r] = temp;
    }
}

void deal(Deck* deck, Game* game) {
    for (int i = 0; i < 2; i++) {
        int index = rand() % deck->numCards;
        game->deck->hand[game->deck->numCards++] = deck->hand[index];
    }
    game->deck->numCards = 0;
    shuffleDeck(game->deck2);
}

void printDeck(Deck* deck) {
    for (int i = 0; i < deck->numCards; i++) {
        printf("%s %d\n", deck->hand[i].name, deck->hand[i].value);
    }
}

void printHand(Game* game) {
    printf("Player 1 hand: ");
    for (int i = 0; i < game->deck->numCards; i++) {
        printf("%s %d\n", game->deck->hand[i].name, game->deck->hand[i].value);
    }
    printf("Player 2 hand: ");
    for (int i = 0; i < game->deck2->numCards; i++) {
        printf("%s %d\n", game->deck2->hand[i].name, game->deck2->hand[i].value);
    }
}

int main() {
    Deck deck;
    Deck deck2;
    Game game;
    createDeck(&deck);
    createDeck(&deck2);
    deal(&deck, &game);
    deal(&deck2, &game);
    printDeck(&deck);
    printDeck(&deck2);
    printHand(&game);
    return 0;
}
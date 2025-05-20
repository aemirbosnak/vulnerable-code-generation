//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 20
#define MAX_PLAYERS 4
#define MAX_TURNS 20

int cards[MAX_CARDS];
int players[MAX_PLAYERS];
int turns;
int deck_size;

void init_deck(void) {
    int i;
    for (i = 0; i < MAX_CARDS; i++) {
        cards[i] = i + 1;
    }
}

void shuffle_deck(void) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < MAX_CARDS; i++) {
        j = rand() % MAX_CARDS;
        int temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

int deal_card(void) {
    int card = cards[0];
    cards[0] = cards[deck_size - 1];
    deck_size--;
    return card;
}

int show_card(int card) {
    return card % 13 + 1;
}

void init_game(void) {
    int i;
    init_deck();
    shuffle_deck();
    deck_size = MAX_CARDS;
    for (i = 0; i < MAX_PLAYERS; i++) {
        players[i] = i + 1;
    }
    turns = 0;
}

void play_game(void) {
    int i, j;
    for (i = 0; i < MAX_TURNS; i++) {
        for (j = 0; j < MAX_PLAYERS; j++) {
            int card1 = deal_card();
            int card2 = deal_card();
            int player_card1 = show_card(card1);
            int player_card2 = show_card(card2);
            players[j] = (players[j] << 4) | player_card1;
            players[j] = (players[j] << 4) | player_card2;
        }
    }
}

void print_results(void) {
    int i;
    for (i = 0; i < MAX_PLAYERS; i++) {
        printf("Player %d has %d points.\n", i + 1, players[i]);
    }
}

int main(void) {
    int i;
    init_game();
    play_game();
    print_results();
    return 0;
}
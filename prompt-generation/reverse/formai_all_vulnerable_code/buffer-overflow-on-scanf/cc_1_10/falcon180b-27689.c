//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: recursive
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
    int id;
    char name[20];
    int score;
} Card;

void init_card(Card* card, int id, char* name) {
    card->id = id;
    strcpy(card->name, name);
    card->score = 0;
}

void print_card(Card* card) {
    printf("Card %d: %s\n", card->id, card->name);
}

int compare_cards(Card* a, Card* b) {
    return strcmp(a->name, b->name);
}

void swap_cards(Card* a, Card* b) {
    Card temp = *a;
    *a = *b;
    *b = temp;
}

void generate_cards(Card* cards, int num_cards) {
    srand(time(NULL));
    for (int i = 0; i < num_cards; i++) {
        int id = rand() % MAX_CARDS;
        char name[20];
        sprintf(name, "Card %d", id + 1);
        init_card(&cards[i], id, name);
    }
    qsort(cards, num_cards, sizeof(Card), compare_cards);
}

void play_bingo(Player* players, Card* cards, int num_players, int num_cards) {
    for (int i = 0; i < num_players; i++) {
        printf("Player %d: ", i + 1);
        for (int j = 0; j < num_cards; j++) {
            print_card(&cards[j]);
        }
        printf("\n");
    }
}

int main() {
    Player players[MAX_PLAYERS];
    Card cards[MAX_CARDS];

    int num_players, num_cards;
    printf("Enter number of players: ");
    scanf("%d", &num_players);
    printf("Enter number of cards: ");
    scanf("%d", &num_cards);

    for (int i = 0; i < num_players; i++) {
        printf("Enter name of player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].id = i;
    }

    generate_cards(cards, num_cards);

    play_bingo(players, cards, num_players, num_cards);

    return 0;
}
//FormAI DATASET v1.0 Category: Poker Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13
#define NUM_PLAYERS 4
#define NUM_CARDS 5

struct player {
    char name[20];
    int hand[NUM_CARDS];
};

int deck[NUM_SUITS][NUM_RANKS];
char *suit_names[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
char *rank_names[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

int deal_card();
void shuffle_deck();
void print_card(int suit, int rank);
void print_hand(struct player p);
int calculate_score(struct player p);

int main() {
    srand(time(NULL));

    struct player players[NUM_PLAYERS];
    int scores[NUM_PLAYERS];
    int winner, high_score;

    // initialize blank names and scores
    for (int i = 0; i < NUM_PLAYERS; i++) {
        strcpy(players[i].name, "");
        scores[i] = 0;
    }

    // get player names
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Enter name for player %d: ", i+1);
        scanf("%s", players[i].name);
    }

    // shuffle deck
    shuffle_deck();

    // deal cards
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("%s's hand:\n", players[i].name);
        for (int j = 0; j < NUM_CARDS; j++) {
            players[i].hand[j] = deal_card();
            print_card(players[i].hand[j] / NUM_RANKS, players[i].hand[j] % NUM_RANKS);
        }
        printf("\n");
    }

    // calculate scores and find winner
    high_score = -1;
    for (int i = 0; i < NUM_PLAYERS; i++) {
        scores[i] = calculate_score(players[i]);
        printf("%s's score: %d\n", players[i].name, scores[i]);
        if (scores[i] > high_score) {
            high_score = scores[i];
            winner = i;
        }
    }

    // print winner
    printf("\n%s wins with a score of %d!\n", players[winner].name, high_score);

    return 0;
}

int deal_card() {
    int card;
    do {
        card = rand() % (NUM_SUITS * NUM_RANKS);
    } while (deck[card / NUM_RANKS][card % NUM_RANKS] == 1);
    deck[card / NUM_RANKS][card % NUM_RANKS] = 1;
    return card;
}

void shuffle_deck() {
    for (int i = 0; i < NUM_SUITS; i++) {
        for (int j = 0; j < NUM_RANKS; j++) {
            deck[i][j] = 0;
        }
    }
}

void print_card(int suit, int rank) {
    printf("%s of %s  ", rank_names[rank], suit_names[suit]);
}

void print_hand(struct player p) {
    for (int i = 0; i < NUM_CARDS; i++) {
        print_card(p.hand[i] / NUM_RANKS, p.hand[i] % NUM_RANKS);
    }
    printf("\n");
}

int calculate_score(struct player p) {
    int score = 0;
    for (int i = 0; i < NUM_CARDS; i++) {
        score += p.hand[i] % NUM_RANKS + 1;
    }
    return score;
}
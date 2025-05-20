//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_CARDS 52

typedef struct {
    char name[20];
    int score;
    int hand[MAX_CARDS];
    int hand_size;
} player_t;

typedef struct {
    int deck[MAX_CARDS];
    int deck_size;
} deck_t;

void shuffle_deck(deck_t *deck) {
    int i, j, temp;

    for (i = 0; i < deck->deck_size; i++) {
        j = rand() % deck->deck_size;
        temp = deck->deck[i];
        deck->deck[i] = deck->deck[j];
        deck->deck[j] = temp;
    }
}

void deal_cards(deck_t *deck, player_t *players, int num_players) {
    int i, j, k;

    for (i = 0; i < num_players; i++) {
        for (j = 0; j < MAX_CARDS; j++) {
            players[i].hand[j] = -1;
        }
        players[i].hand_size = 0;
    }

    for (i = 0; i < MAX_CARDS; i++) {
        for (j = 0; j < num_players; j++) {
            players[j].hand[players[j].hand_size++] = deck->deck[i++];
        }
    }
}

void print_hand(player_t *player) {
    int i;

    printf("%s's hand:\n", player->name);
    for (i = 0; i < player->hand_size; i++) {
        printf("%d ", player->hand[i]);
    }
    printf("\n");
}

int get_score(player_t *player) {
    int i, score;

    score = 0;
    for (i = 0; i < player->hand_size; i++) {
        if (player->hand[i] > 10) {
            score += 10;
        } else {
            score += player->hand[i];
        }
    }

    return score;
}

int compare_scores(player_t *player1, player_t *player2) {
    int score1, score2;

    score1 = get_score(player1);
    score2 = get_score(player2);

    if (score1 > score2) {
        return 1;
    } else if (score1 == score2) {
        return 0;
    } else {
        return -1;
    }
}

int main() {
    deck_t deck;
    player_t players[MAX_PLAYERS];
    int num_players, i;

    srand(time(NULL));

    printf("Enter the number of players (1-4): ");
    scanf("%d", &num_players);

    if (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 0;
    }

    for (i = 0; i < MAX_CARDS; i++) {
        deck.deck[i] = i % 13 + 1;
    }
    deck.deck_size = MAX_CARDS;

    shuffle_deck(&deck);

    for (i = 0; i < num_players; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);
    }

    deal_cards(&deck, players, num_players);

    for (i = 0; i < num_players; i++) {
        print_hand(&players[i]);
    }

    for (i = 0; i < num_players; i++) {
        players[i].score = get_score(&players[i]);
    }

    int winner = -1;
    int max_score = -1;

    for (i = 0; i < num_players; i++) {
        if (players[i].score > max_score) {
            max_score = players[i].score;
            winner = i;
        }
    }

    printf("The winner is %s with a score of %d.\n", players[winner].name, players[winner].score);

    return 0;
}
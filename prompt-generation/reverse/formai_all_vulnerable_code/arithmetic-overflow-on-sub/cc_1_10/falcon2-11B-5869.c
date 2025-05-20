//Falcon2-11B DATASET v1.0 Category: Poker Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num_players;
    int deck[52];
} Deck;

typedef struct {
    int player_num;
    int hand[5];
} Hand;

typedef struct {
    int player_num;
    int chips;
} Player;

void shuffle_deck(Deck* deck) {
    int i, j;
    for (i = deck->num_players - 1; i > 0; i--) {
        j = rand() % (i + 1);
        int temp = deck->deck[i];
        deck->deck[i] = deck->deck[j];
        deck->deck[j] = temp;
    }
}

void deal_cards(Deck* deck, Hand* hands, Player* players, int num_players) {
    int i;
    for (i = 0; i < num_players; i++) {
        hands[i].hand[0] = deck->deck[0];
        hands[i].hand[1] = deck->deck[1];
        hands[i].hand[2] = deck->deck[2];
        hands[i].hand[3] = deck->deck[3];
        hands[i].hand[4] = deck->deck[4];
        players[i].chips = 1000;
    }
}

void show_hands(Hand* hands, int num_players) {
    int i;
    for (i = 0; i < num_players; i++) {
        printf("Player %d: ", i + 1);
        for (int j = 0; j < 5; j++) {
            printf("%d ", hands[i].hand[j]);
        }
        printf("\n");
    }
}

void play_poker(Deck* deck, Hand* hands, Player* players, int num_players) {
    int i;
    for (i = 0; i < num_players; i++) {
        if (players[i].chips > 0) {
            int bet = players[i].chips;
            players[i].chips -= bet;
            printf("Player %d bets %d chips.\n", i + 1, bet);
        }
    }
}

int main() {
    Deck deck;
    Deck deck2;
    Hand hands[5];
    Player players[5];
    int num_players = 5;

    shuffle_deck(&deck);
    shuffle_deck(&deck2);

    deal_cards(&deck, hands, players, num_players);
    deal_cards(&deck2, hands, players, num_players);

    show_hands(hands, num_players);

    play_poker(&deck, hands, players, num_players);
    play_poker(&deck2, hands, players, num_players);

    return 0;
}
//Falcon2-11B DATASET v1.0 Category: Poker Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>

#define MAX_CARDS 52
#define MAX_HAND 5

#define SUIT_CLUBS 1
#define SUIT_DIAMONDS 2
#define SUIT_HEARTS 3
#define SUIT_SPADES 4

typedef struct card {
    int suit;
    int rank;
} card;

typedef struct deck {
    int cards[MAX_CARDS];
} deck;

typedef struct hand {
    int cards[MAX_HAND];
} hand;

typedef struct game {
    deck deck;
    hand player_hand;
    hand computer_hand;
} game;

void deal_cards(game *game) {
    int i, j, suit, rank;

    for (i = 0; i < MAX_HAND; i++) {
        suit = rand() % 4;
        rank = rand() % 13 + 1;
        game->player_hand.cards[i] = suit * 13 + rank;
        game->computer_hand.cards[i] = suit * 13 + rank;
    }
}

void display_hand(hand hand) {
    int i;
    printf("Your hand:\n");
    for (i = 0; i < MAX_HAND; i++) {
        printf("%c %d\n", (hand.cards[i] / 13) + 'A', hand.cards[i] % 13);
    }
}

void display_deck(deck deck) {
    int i;
    printf("Deck:\n");
    for (i = 0; i < MAX_CARDS; i++) {
        printf("%c %d\n", (deck.cards[i] / 13) + 'A', deck.cards[i] % 13);
    }
}

int main(int argc, char *argv[]) {
    game game;
    hand player_hand;
    hand computer_hand;

    if (argc!= 2) {
        printf("Usage: %s <number of hands>\n", argv[0]);
        return 1;
    }

    srand(time(NULL));

    deal_cards(&game);
    display_deck(game.deck);
    display_hand(game.player_hand);

    int num_hands = atoi(argv[1]);

    for (int i = 0; i < num_hands; i++) {
        printf("Hand %d:\n", i + 1);
        display_deck(game.deck);
        display_hand(game.player_hand);
        display_hand(game.computer_hand);

        int keep = 0;
        while (keep < 3) {
            printf("Keep cards? (1-5): ");
            int card = scanf("%d", &keep);
            if (card!= 1 && card!= 2 && card!= 3 && card!= 4 && card!= 5) {
                printf("Invalid input.\n");
                continue;
            }
            keep = card;
        }

        for (int j = 0; j < keep; j++) {
            int card = scanf("%d", &game.player_hand.cards[j]);
            if (card!= 1 && card!= 2 && card!= 3 && card!= 4 && card!= 5) {
                printf("Invalid input.\n");
                break;
            }
        }

        for (int j = 0; j < keep; j++) {
            int card = scanf("%d", &game.computer_hand.cards[j]);
            if (card!= 1 && card!= 2 && card!= 3 && card!= 4 && card!= 5) {
                printf("Invalid input.\n");
                break;
            }
        }

        for (int j = 0; j < keep; j++) {
            game.player_hand.cards[j] = game.player_hand.cards[j + keep];
            game.computer_hand.cards[j] = game.computer_hand.cards[j + keep];
        }

        deal_cards(&game);
        display_deck(game.deck);
        display_hand(game.player_hand);
        display_hand(game.computer_hand);
    }

    return 0;
}
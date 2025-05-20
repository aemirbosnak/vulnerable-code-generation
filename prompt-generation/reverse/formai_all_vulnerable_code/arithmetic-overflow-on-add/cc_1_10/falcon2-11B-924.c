//Falcon2-11B DATASET v1.0 Category: Poker Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <assert.h>

typedef struct Card {
    char suit;
    int rank;
} Card;

typedef struct Player {
    int id;
    int chips;
    Card hand[5];
} Player;

typedef struct Deck {
    Card cards[52];
    int current_index;
} Deck;

typedef struct Hand {
    Card cards[5];
    int points;
} Hand;

void shuffle_deck(Deck *deck) {
    for (int i = deck->current_index - 1; i >= 0; i--) {
        int j = rand() % (i + 1);
        Card temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
    deck->current_index = 0;
}

void print_deck(Deck *deck) {
    printf("Deck: ");
    for (int i = 0; i < 52; i++) {
        printf("%c%d ", deck->cards[i].suit, deck->cards[i].rank);
    }
    printf("\n");
}

void print_hand(Hand *hand) {
    printf("Hand: ");
    for (int i = 0; i < 5; i++) {
        printf("%c%d ", hand->cards[i].suit, hand->cards[i].rank);
    }
    printf("\n");
}

int compare_ranks(Card a, Card b) {
    if (a.rank > b.rank) return 1;
    if (a.rank < b.rank) return -1;
    return 0;
}

void print_ranks(Card cards[5]) {
    printf("Ranks: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", cards[i].rank);
    }
    printf("\n");
}

int get_hand_value(Card cards[5]) {
    int value = 0;
    int aces = 0;
    for (int i = 0; i < 5; i++) {
        value += cards[i].rank;
        if (cards[i].rank == 1) aces++;
    }
    for (int i = 4; i >= 0; i--) {
        if (aces > 0 && cards[i].rank == 1) {
            value += 10;
            aces--;
        }
    }
    return value;
}

int main() {
    srand(time(NULL));

    Deck deck;
    shuffle_deck(&deck);
    print_deck(&deck);

    Player players[2];
    for (int i = 0; i < 2; i++) {
        players[i].id = i + 1;
        players[i].chips = 100;
        for (int j = 0; j < 5; j++) {
            players[i].hand[j].rank = (int) 'A' + rand() % 13;
            players[i].hand[j].suit = (char) 'S' + rand() % 4;
        }
    }

    int current_player;
    for (int i = 0; i < 52; i++) {
        if (deck.current_index < 52) {
            Card card = deck.cards[deck.current_index];
            deck.current_index++;
            printf("Deck: ");
            print_ranks(&card);
            printf("\n");
        }
        printf("Player %d's turn\n", players[current_player].id);
        print_hand(&players[current_player].hand);

        int points = get_hand_value(&players[current_player].hand);
        printf("Points: %d\n", points);

        if (points > 21) {
            printf("Player %d busts, loses %d chips\n", players[current_player].id, players[current_player].chips);
            players[current_player].chips -= players[current_player].chips;
            current_player = (current_player + 1) % 2;
            continue;
        }

        for (int j = 0; j < 5; j++) {
            printf("Player %d's card: %c%d\n", players[current_player].id, players[current_player].hand[j].suit, players[current_player].hand[j].rank);
        }

        int choice = -1;
        while (choice < 0 || choice > 4) {
            printf("Hit or Stand? (0 = Hit, 1 = Stand)\n");
            scanf("%d", &choice);
            if (choice < 0 || choice > 4) {
                printf("Invalid choice, please enter 0 or 1\n");
            }
        }

        if (choice == 0) {
            Card card = deck.cards[deck.current_index];
            deck.current_index++;
            printf("Deck: ");
            print_ranks(&card);
            printf("\n");
            players[current_player].hand[players[current_player].hand[5].rank] = card;
            current_player = (current_player + 1) % 2;
        } else {
            current_player = (current_player + 1) % 2;
        }
    }

    printf("Game Over\n");

    return 0;
}
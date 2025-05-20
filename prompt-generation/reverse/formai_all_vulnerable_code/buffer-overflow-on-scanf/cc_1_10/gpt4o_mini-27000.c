//GPT-4o-mini DATASET v1.0 Category: Poker Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 4
#define CARDS_IN_HAND 5
#define DECK_SIZE 52

const char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
const char *ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

typedef struct {
    int rank;
    int suit;
} Card;

typedef struct {
    Card hand[CARDS_IN_HAND];
    int player_id;
} Player;

Card deck[DECK_SIZE];
int player_count;

void initialize_deck() {
    int index = 0;
    for (int suit = 0; suit < 4; suit++) {
        for (int rank = 0; rank < 13; rank++) {
            deck[index].rank = rank;
            deck[index].suit = suit;
            index++;
        }
    }
}

void shuffle_deck() {
    srand(time(NULL));
    for (int i = DECK_SIZE - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void deal_cards(Player players[]) {
    for (int i = 0; i < player_count; i++) {
        for (int j = 0; j < CARDS_IN_HAND; j++) {
            players[i].hand[j] = deck[i * CARDS_IN_HAND + j];
            players[i].player_id = i + 1;
        }
    }
}

void display_hand(Player player) {
    printf("Player %d's Hand:\n", player.player_id);
    for (int i = 0; i < CARDS_IN_HAND; i++) {
        printf("%s of %s\n", ranks[player.hand[i].rank], suits[player.hand[i].suit]);
    }
    printf("\n");
}

void play_game() {
    printf("Enter number of players (2 to %d): ", MAX_PLAYERS);
    scanf("%d", &player_count);
    if (player_count < 2 || player_count > MAX_PLAYERS) {
        printf("Invalid number of players!\n");
        return;
    }

    Player players[MAX_PLAYERS];
    initialize_deck();
    shuffle_deck();
    deal_cards(players);

    for (int i = 0; i < player_count; i++) {
        display_hand(players[i]);
    }
}

int main() {
    play_game();
    return 0;
}
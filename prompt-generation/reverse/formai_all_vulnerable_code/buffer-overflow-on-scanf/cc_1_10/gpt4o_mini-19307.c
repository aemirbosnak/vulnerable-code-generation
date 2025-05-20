//GPT-4o-mini DATASET v1.0 Category: Poker Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 4
#define CARDS_IN_HAND 5
#define DECK_SIZE 52

typedef struct {
    char suit[9];
    char value[3];
} Card;

typedef struct {
    char name[30];
    Card hand[CARDS_IN_HAND];
    int score;
} Player;

Card deck[DECK_SIZE];
int top_card_index = 0;

void initialize_deck() {
    const char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    const char *values[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    int index = 0;
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            strcpy(deck[index].suit, suits[i]);
            strcpy(deck[index].value, values[j]);
            index++;
        }
    }
}

void shuffle_deck() {
    srand(time(NULL));
    for (int i = 0; i < DECK_SIZE; i++) {
        int r = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[r];
        deck[r] = temp;
    }
    top_card_index = 0;
}

Card draw_card() {
    return deck[top_card_index++];
}

void initialize_players(Player players[], int num_players) {
    for (int i = 0; i < num_players; i++) {
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
        for (int j = 0; j < CARDS_IN_HAND; j++) {
            players[i].hand[j] = draw_card();
        }
    }
}

void display_player_hand(Player player) {
    printf("Player %s's Hand:\n", player.name);
    for (int i = 0; i < CARDS_IN_HAND; i++) {
        printf("%s %s\n", player.hand[i].value, player.hand[i].suit);
    }
}

void calculate_scores(Player players[], int num_players) {
    for (int i = 0; i < num_players; i++) {
        // Simplistic score calculation: just counting number of Aces
        players[i].score = 0;
        for (int j = 0; j < CARDS_IN_HAND; j++) {
            if (strcmp(players[i].hand[j].value, "A") == 0) {
                players[i].score++;
            }
        }
    }
}

void determine_winner(Player players[], int num_players) {
    int max_score = -1;
    Player *winner = NULL;

    for (int i = 0; i < num_players; i++) {
        if (players[i].score > max_score) {
            max_score = players[i].score;
            winner = &players[i];
        }
    }

    if (winner != NULL) {
        printf("The winner is %s with a score of %d!\n", winner->name, winner->score);
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int num_players = 0;

    printf("Welcome to the Visionary Poker Game!\n");
    printf("How many players (max %d)? ", MAX_PLAYERS);
    scanf("%d", &num_players);

    if (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }

    initialize_deck();
    shuffle_deck();
    initialize_players(players, num_players);

    for (int i = 0; i < num_players; i++) {
        display_player_hand(players[i]);
    }

    calculate_scores(players, num_players);
    determine_winner(players, num_players);

    return 0;
}
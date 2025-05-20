//Falcon2-11B DATASET v1.0 Category: Poker Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 4
#define NUM_CARDS 52

// Global variables
char players[MAX_PLAYERS][20];
int player_points[MAX_PLAYERS];
int cards[MAX_PLAYERS][2];
int current_player;
int total_points;

// Function to shuffle the cards
void shuffle_cards(int cards[MAX_PLAYERS][2]) {
    int i, j, temp;
    for (i = 0; i < MAX_PLAYERS * 2; i++) {
        j = (int) (RAND_MAX * i) % (MAX_PLAYERS * 2);
        temp = cards[i][0];
        cards[i][0] = cards[j][0];
        cards[j][0] = temp;
        temp = cards[i][1];
        cards[i][1] = cards[j][1];
        cards[j][1] = temp;
    }
}

// Function to deal cards
void deal_cards(int cards[MAX_PLAYERS][2], int cards_to_deal) {
    int i;
    for (i = 0; i < MAX_PLAYERS; i++) {
        for (int j = 0; j < cards_to_deal; j++) {
            int r = rand() % NUM_CARDS;
            if (cards[i][j] == 0 && r!= cards[i][j]) {
                cards[i][j] = r;
                break;
            }
        }
    }
}

// Function to print cards
void print_cards(int cards[MAX_PLAYERS][2]) {
    int i;
    for (i = 0; i < MAX_PLAYERS; i++) {
        printf("Player %d: ", i + 1);
        printf("%d %d\n", cards[i][0], cards[i][1]);
    }
}

// Function to calculate points for a hand
void calculate_points(int cards[MAX_PLAYERS][2]) {
    int i;
    int j;
    int straight = 0;
    int flush = 0;
    int full_house = 0;
    int four_of_a_kind = 0;
    int three_of_a_kind = 0;
    int two_pair = 0;
    int one_pair = 0;
    int highest_card = 0;

    for (i = 0; i < MAX_PLAYERS; i++) {
        for (j = 0; j < 2; j++) {
            if (cards[i][j] == 1) {
                straight += 1;
            }
            if (cards[i][j] == 14) {
                flush += 1;
            }
            if (cards[i][j] == 7) {
                full_house += 1;
            }
            if (cards[i][j] == 6) {
                four_of_a_kind += 1;
            }
            if (cards[i][j] == 5) {
                three_of_a_kind += 1;
            }
            if (cards[i][j] == 4) {
                two_pair += 1;
            }
            if (cards[i][j] == 3) {
                one_pair += 1;
            }
            if (cards[i][j] > highest_card) {
                highest_card = cards[i][j];
            }
        }
    }

    if (straight == 5) {
        total_points += 50;
    }
    if (flush == 1) {
        total_points += 15;
    }
    if (full_house == 1) {
        total_points += 20;
    }
    if (four_of_a_kind == 1) {
        total_points += 25;
    }
    if (three_of_a_kind == 1) {
        total_points += 10;
    }
    if (two_pair == 1) {
        total_points += 5;
    }
    if (one_pair == 1) {
        total_points += 1;
    }
    if (highest_card == 14) {
        total_points += 1;
    }

    for (i = 0; i < MAX_PLAYERS; i++) {
        player_points[i] += total_points;
    }
}

// Main function
int main() {
    char option;
    while (1) {
        printf("Please select an option:\n");
        printf("1. Deal cards\n");
        printf("2. Calculate points\n");
        printf("3. Exit\n");
        scanf(" %c", &option);

        if (option == '1') {
            shuffle_cards(cards);
            deal_cards(cards, 2);
            printf("Dealing cards...\n");
            print_cards(cards);
            printf("\n");
        } else if (option == '2') {
            calculate_points(cards);
            printf("Player 1: %d\n", player_points[0]);
            printf("Player 2: %d\n", player_points[1]);
            printf("Player 3: %d\n", player_points[2]);
            printf("Player 4: %d\n", player_points[3]);
            printf("\n");
        } else if (option == '3') {
            break;
        } else {
            printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}
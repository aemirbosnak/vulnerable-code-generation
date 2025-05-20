//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_CARDS 100
#define MAX_NUMBERS 75

int main() {
    srand(time(NULL));
    int num_players;
    printf("Enter the number of players: ");
    scanf("%d", &num_players);

    if (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }

    int players[MAX_PLAYERS];
    int num_cards;
    printf("Enter the number of cards per player: ");
    scanf("%d", &num_cards);

    if (num_cards < 1 || num_cards > MAX_CARDS) {
        printf("Invalid number of cards.\n");
        return 1;
    }

    int cards[MAX_PLAYERS][MAX_CARDS];
    for (int i = 0; i < num_players; i++) {
        for (int j = 0; j < num_cards; j++) {
            cards[i][j] = rand() % MAX_NUMBERS + 1;
        }
    }

    int num_called;
    printf("Enter the number of numbers to call: ");
    scanf("%d", &num_called);

    if (num_called < 1 || num_called > MAX_NUMBERS) {
        printf("Invalid number of numbers to call.\n");
        return 1;
    }

    int called_numbers[MAX_NUMBERS];
    for (int i = 0; i < num_called; i++) {
        called_numbers[i] = rand() % MAX_NUMBERS + 1;
    }

    int winners[MAX_PLAYERS];
    int num_winners = 0;
    for (int i = 0; i < num_players; i++) {
        int num_matched = 0;
        for (int j = 0; j < num_called; j++) {
            for (int k = 0; k < num_cards; k++) {
                if (called_numbers[j] == cards[i][k]) {
                    num_matched++;
                    break;
                }
            }
        }
        if (num_matched == num_called) {
            winners[num_winners++] = i;
        }
    }

    printf("The winners are: ");
    for (int i = 0; i < num_winners; i++) {
        printf("%d ", winners[i]);
    }
    printf("\n");

    return 0;
}
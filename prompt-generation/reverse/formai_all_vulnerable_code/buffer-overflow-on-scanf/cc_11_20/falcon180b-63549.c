//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_CARDS 100
#define MAX_BINGO_CARDS 5
#define BINGO_NUMBER 75
#define MAX_NUMBERS 15

struct player {
    char name[50];
    int score;
};

struct card {
    int numbers[MAX_NUMBERS];
};

int main() {
    int num_players, i;
    char input[50];
    struct player players[MAX_PLAYERS];
    struct card bingo_cards[MAX_CARDS];
    struct card winning_card;
    int num_bingo_cards, j;
    int num_numbers;
    int num_played_cards;
    int player_index;

    srand(time(NULL));
    num_players = rand() % MAX_PLAYERS + 1;
    num_bingo_cards = rand() % MAX_BINGO_CARDS + 1;
    num_numbers = rand() % MAX_NUMBERS + 1;

    printf("Welcome to the C Bingo Simulator!\n");
    printf("Number of players: %d\n", num_players);
    printf("Number of bingo cards: %d\n", num_bingo_cards);
    printf("Number of numbers per card: %d\n", num_numbers);

    for (i = 0; i < num_players; i++) {
        printf("Enter name of player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    for (i = 0; i < num_bingo_cards; i++) {
        num_played_cards = 0;
        while (num_played_cards < num_players) {
            player_index = rand() % num_players;
            if (player_index!= i) {
                strcpy(bingo_cards[i].numbers[num_played_cards], players[player_index].name);
                num_played_cards++;
            }
        }
    }

    for (i = 0; i < num_bingo_cards; i++) {
        for (j = 0; j < num_numbers; j++) {
            printf("%s ", bingo_cards[i].numbers[j]);
        }
        printf("\n");
    }

    for (i = 0; i < num_bingo_cards; i++) {
        for (j = 0; j < num_numbers; j++) {
            if (j == 0 || j == 4 || j == 8 || j == 12) {
                winning_card.numbers[j] = rand() % BINGO_NUMBER + 1;
            } else {
                winning_card.numbers[j] = rand() % BINGO_NUMBER + 1;
            }
        }
        printf("Bingo card %d:\n", i + 1);
        for (j = 0; j < num_numbers; j++) {
            if (j == 0 || j == 4 || j == 8 || j == 12) {
                printf("%d ", winning_card.numbers[j]);
            } else {
                printf("%d ", winning_card.numbers[j]);
            }
        }
        printf("\n");
    }

    return 0;
}
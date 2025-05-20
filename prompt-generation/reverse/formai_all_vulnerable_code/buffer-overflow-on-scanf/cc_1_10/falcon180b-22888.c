//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_CARDS 100
#define MAX_NUMBERS 75

typedef struct {
    int id;
    char name[20];
    int score;
} Player;

typedef struct {
    int num;
    int called;
} Number;

void generate_cards(Number cards[MAX_NUMBERS], int num_cards) {
    srand(time(NULL));
    for (int i = 0; i < num_cards; i++) {
        cards[i].num = rand() % 75 + 1;
        cards[i].called = 0;
    }
}

void print_card(Number card) {
    printf("%d ", card.num);
}

void print_cards(Number cards[MAX_NUMBERS], int num_cards) {
    for (int i = 0; i < num_cards; i++) {
        print_card(cards[i]);
        if (i % 5 == 4) {
            printf("\n");
        }
    }
}

void play_bingo(Player players[MAX_PLAYERS], Number cards[MAX_NUMBERS], int num_cards) {
    int num, player_id;
    char input[20];

    for (int i = 0; i < num_cards; i++) {
        num = cards[i].num;
        printf("Calling number %d...\n", num);
        for (int j = 0; j < MAX_PLAYERS; j++) {
            if (players[j].id == num) {
                players[j].score++;
                printf("Player %d got a bingo!\n", j + 1);
            }
        }
    }

    printf("\nGame over!\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (players[i].score > 0) {
            printf("Player %d wins!\n", i + 1);
        }
    }
}

int main() {
    Player players[MAX_PLAYERS];
    Number cards[MAX_NUMBERS];

    int num_players, num_cards;
    printf("Enter number of players (1-10): ");
    scanf("%d", &num_players);

    printf("Enter number of cards per player (1-100): ");
    scanf("%d", &num_cards);

    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf(" %s", players[i].name);
        players[i].id = i + 1;
        players[i].score = 0;
    }

    generate_cards(cards, num_cards);
    print_cards(cards, num_cards);

    play_bingo(players, cards, num_cards);

    return 0;
}
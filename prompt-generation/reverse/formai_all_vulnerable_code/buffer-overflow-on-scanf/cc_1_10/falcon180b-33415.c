//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 100
#define MAX_PLAYERS 10

struct card {
    int number;
    int marked;
};

struct player {
    char name[20];
    int score;
    struct card cards[MAX_CARDS];
};

void generate_cards(struct card cards[], int num_cards) {
    int i;
    for (i = 0; i < num_cards; i++) {
        cards[i].number = rand() % 100;
        cards[i].marked = 0;
    }
}

void print_card(struct card card) {
    if (card.marked) {
        printf("X");
    } else {
        printf("%d", card.number);
    }
}

void print_cards(struct card cards[], int num_cards) {
    int i;
    for (i = 0; i < num_cards; i++) {
        print_card(cards[i]);
        printf(" ");
    }
    printf("\n");
}

int check_win(struct card cards[], int num_cards) {
    int i, j;
    for (i = 0; i < num_cards; i++) {
        if (cards[i].marked) {
            continue;
        }
        for (j = i + 1; j < num_cards; j++) {
            if (cards[j].number == cards[i].number) {
                cards[j].marked = 1;
            }
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));

    int num_players, num_cards;
    printf("Enter number of players: ");
    scanf("%d", &num_players);

    struct player players[MAX_PLAYERS];
    int i;
    for (i = 0; i < num_players; i++) {
        printf("Enter name of player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    printf("Enter number of cards per player: ");
    scanf("%d", &num_cards);

    struct card cards[MAX_CARDS];
    generate_cards(cards, num_cards);

    int winner = -1;
    while (winner == -1) {
        for (i = 0; i < num_players; i++) {
            printf("Player %s's turn:\n", players[i].name);
            print_cards(cards, num_cards);
            printf("Enter a number: ");
            scanf("%d", &cards[i * num_cards].number);
            cards[i * num_cards].marked = 1;
        }
        winner = check_win(cards, num_cards);
    }

    printf("Congratulations, %s, you won!\n", players[winner].name);

    return 0;
}
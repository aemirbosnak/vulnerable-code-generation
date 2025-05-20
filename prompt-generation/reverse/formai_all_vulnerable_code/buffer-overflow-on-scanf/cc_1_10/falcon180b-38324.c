//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 100
#define MAX_PLAYERS 10

typedef struct {
    char name[20];
    int card[MAX_CARDS];
} Player;

void generate_card(int card[MAX_CARDS]) {
    int i;
    for (i = 0; i < MAX_CARDS; i++) {
        card[i] = rand() % 100;
    }
}

int compare_cards(const void *a, const void *b) {
    int *card_a = (int *) a;
    int *card_b = (int *) b;
    int i;

    for (i = 0; i < MAX_CARDS; i++) {
        if (card_a[i] > card_b[i]) {
            return 1;
        } else if (card_a[i] < card_b[i]) {
            return -1;
        }
    }

    return 0;
}

void print_card(int card[MAX_CARDS]) {
    int i;
    for (i = 0; i < MAX_CARDS; i++) {
        printf("%d ", card[i]);
    }
    printf("\n");
}

int main() {
    int i, j, num_players;
    char input[20];
    Player players[MAX_PLAYERS];
    int cards[MAX_CARDS];

    srand(time(NULL));

    printf("Enter number of players: ");
    scanf("%d", &num_players);

    for (i = 0; i < num_players; i++) {
        printf("Enter player %d's name: ", i+1);
        scanf("%s", players[i].name);
        generate_card(players[i].card);
    }

    qsort(players, num_players, sizeof(Player), compare_cards);

    for (i = 0; i < num_players; i++) {
        printf("Player %d's card: ", i+1);
        print_card(players[i].card);
    }

    return 0;
}
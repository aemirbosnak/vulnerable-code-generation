//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 100
#define MAX_PLAYERS 10

typedef struct {
    int id;
    char name[20];
    int cards[MAX_CARDS];
} Player;

void init_card(int card[5]) {
    int i;
    for (i = 0; i < 5; i++) {
        card[i] = rand() % 15 + 1;
    }
}

int compare_cards(int card1[5], int card2[5]) {
    int i;
    for (i = 0; i < 5; i++) {
        if (card1[i] > card2[i]) {
            return 1;
        } else if (card1[i] < card2[i]) {
            return -1;
        }
    }
    return 0;
}

void print_card(int card[5]) {
    int i;
    for (i = 0; i < 5; i++) {
        printf("%d ", card[i]);
    }
    printf("\n");
}

void bingo(int cards[MAX_CARDS], int num_players, int num_winners) {
    int i, j;
    int winners[num_winners];
    int winner_count = 0;

    srand(time(NULL));
    for (i = 0; i < num_players; i++) {
        init_card(cards[i]);
    }

    while (winner_count < num_winners) {
        for (i = 0; i < num_players; i++) {
            if (compare_cards(cards[i], cards[(i+1)%num_players]) == 1) {
                winners[winner_count] = i;
                winner_count++;
                break;
            }
        }
    }

    printf("Bingo winners:\n");
    for (i = 0; i < num_winners; i++) {
        printf("Player %d\n", winners[i]+1);
    }
}

int main() {
    int num_players, num_winners;

    printf("Enter number of players: ");
    scanf("%d", &num_players);

    Player players[MAX_PLAYERS];
    int i;
    for (i = 0; i < num_players; i++) {
        printf("Enter name of player %d: ", i+1);
        scanf("%s", players[i].name);
        players[i].id = i;
    }

    printf("Enter number of winners: ");
    scanf("%d", &num_winners);

    int cards[MAX_CARDS];
    for (i = 0; i < num_players; i++) {
        init_card(cards[i]);
    }

    bingo(cards, num_players, num_winners);

    return 0;
}
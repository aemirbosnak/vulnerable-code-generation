//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 100
#define MAX_PLAYERS 10

typedef struct {
    char name[50];
    int card[MAX_CARDS];
} Player;

void shuffle(int *deck, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void print_card(int card) {
    switch (card) {
        case 0:
            printf("B");
            break;
        case 1:
            printf("I");
            break;
        case 2:
            printf("N");
            break;
        case 3:
            printf("G");
            break;
        case 4:
            printf("O");
            break;
        default:
            printf("?");
            break;
    }
}

void print_row(int row[], int n) {
    for (int i = 0; i < n; i++) {
        print_card(row[i]);
        printf(" ");
    }
    printf("\n");
}

void print_card_list(int list[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d: ", i + 1);
        print_row(list[i], 5);
    }
}

int main() {
    int n, m;
    printf("Enter number of players (1-10): ");
    scanf("%d", &n);
    printf("Enter number of cards per player (1-100): ");
    scanf("%d", &m);

    if (n < 1 || n > MAX_PLAYERS || m < 1 || m > MAX_CARDS) {
        printf("Invalid input.\n");
        return 1;
    }

    int deck[MAX_CARDS];
    for (int i = 0; i < MAX_CARDS; i++) {
        deck[i] = i;
    }

    shuffle(deck, MAX_CARDS);

    Player players[MAX_PLAYERS];
    for (int i = 0; i < n; i++) {
        printf("Enter player %d name: ", i + 1);
        scanf("%s", players[i].name);
        for (int j = 0; j < m; j++) {
            players[i].card[j] = deck[j];
            deck[j] = -1;
        }
    }

    printf("Deck:\n");
    print_card_list(deck, MAX_CARDS);

    printf("\nPlayers:\n");
    for (int i = 0; i < n; i++) {
        printf("Player %s:\n", players[i].name);
        print_card_list(players[i].card, m);
    }

    return 0;
}
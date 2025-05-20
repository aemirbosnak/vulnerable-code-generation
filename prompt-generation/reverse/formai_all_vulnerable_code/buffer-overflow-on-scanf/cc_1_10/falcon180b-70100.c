//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 100
#define MAX_PLAYERS 10

typedef struct {
    char name[20];
    int card[MAX_CARDS];
} Player;

void shuffle(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void print_card(int card[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", card[i]);
    }
    printf("\n");
}

int main() {
    int num_players, num_cards;
    printf("Enter the number of players: ");
    scanf("%d", &num_players);
    printf("Enter the number of cards per player: ");
    scanf("%d", &num_cards);

    Player players[MAX_PLAYERS];
    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d's name: ", i+1);
        scanf("%s", players[i].name);
        for (int j = 0; j < num_cards; j++) {
            players[i].card[j] = rand() % 75 + 1;
        }
    }

    printf("Game starting...\n");
    int called_num;
    while (1) {
        called_num = rand() % 75 + 1;
        printf("Called number: %d\n", called_num);
        for (int i = 0; i < num_players; i++) {
            int matches = 0;
            for (int j = 0; j < num_cards; j++) {
                if (players[i].card[j] == called_num) {
                    matches++;
                }
            }
            if (matches == num_cards) {
                printf("%s wins!\n", players[i].name);
                return 0;
            }
        }
    }

    return 0;
}
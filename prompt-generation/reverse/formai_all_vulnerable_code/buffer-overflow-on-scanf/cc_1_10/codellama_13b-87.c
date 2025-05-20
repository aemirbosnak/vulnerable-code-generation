//Code Llama-13B DATASET v1.0 Category: Sorting ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    int score;
} Player;

void print_players(Player players[], int num_players) {
    for (int i = 0; i < num_players; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

void swap(Player *p1, Player *p2) {
    Player temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void bubble_sort(Player players[], int num_players) {
    for (int i = 0; i < num_players - 1; i++) {
        for (int j = 0; j < num_players - i - 1; j++) {
            if (players[j].score > players[j + 1].score) {
                swap(&players[j], &players[j + 1]);
            }
        }
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int num_players;

    printf("Enter number of players: ");
    scanf("%d", &num_players);

    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
        printf("Enter player %d's score: ", i + 1);
        scanf("%d", &players[i].score);
    }

    bubble_sort(players, num_players);

    printf("Sorted players:\n");
    print_players(players, num_players);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 5
#define MAX_POINTS 10

typedef struct {
    char name[20];
    int points;
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

int compare(const void *a, const void *b) {
    Player *player1 = (Player *)a;
    Player *player2 = (Player *)b;
    return player2->points - player1->points;
}

void print_players(Player players[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s: %d points\n", players[i].name, players[i].points);
    }
}

int main() {
    int num_players = 2;
    Player players[MAX_PLAYERS];

    for (int i = 0; i < num_players; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].points = 0;
    }

    for (int round = 1; round <= MAX_ROUNDS; round++) {
        int total_points = 0;
        shuffle(players, num_players);
        printf("Round %d:\n", round);
        for (int i = 0; i < num_players; i++) {
            printf("%s rolls the dice and gets ", players[i].name);
            int dice_roll = rand() % 6 + 1;
            printf("%d\n", dice_roll);
            players[i].points += dice_roll;
            total_points += dice_roll;
        }
        printf("Total points for this round: %d\n\n", total_points);
    }

    qsort(players, num_players, sizeof(Player), compare);
    printf("Final scores:\n");
    print_players(players, num_players);

    return 0;
}
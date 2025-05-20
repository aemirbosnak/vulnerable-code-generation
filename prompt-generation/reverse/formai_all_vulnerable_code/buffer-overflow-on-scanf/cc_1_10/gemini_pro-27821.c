//GEMINI-pro DATASET v1.0 Category: Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE 120
#define MAX_NUM_PLAYERS 4

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    int score;
} Player;

Player players[MAX_NUM_PLAYERS];

int main() {
    int num_players;

    printf("How many players are there (1-4)? ");
    scanf("%d", &num_players);

    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);

        printf("Enter player %d's age: ", i + 1);
        scanf("%d", &players[i].age);

        players[i].score = 0;
    }

    // Play the game
    int round = 1;
    while (round <= 10) {
        printf("Round %d\n", round);

        for (int i = 0; i < num_players; i++) {
            int roll1 = rand() % 6 + 1;
            int roll2 = rand() % 6 + 1;

            printf("%s rolled %d and %d\n", players[i].name, roll1, roll2);

            players[i].score += roll1 + roll2;
        }

        round++;
    }

    // Print the final scores
    printf("Final scores:\n");

    for (int i = 0; i < num_players; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }

    return 0;
}
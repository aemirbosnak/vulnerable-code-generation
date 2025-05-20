//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_EXERCISES 3

struct player {
    int id;
    char name[50];
    int level;
    int experience;
    int progress[MAX_EXERCISES];
};

typedef struct player Player;

void init_players(Player players[], int num_players) {
    int i, j;
    for (i = 0; i < num_players; i++) {
        players[i].id = i + 1;
        printf("Enter name for player %d: ", players[i].id);
        scanf("%s", players[i].name);
        players[i].level = 1;
        players[i].experience = 0;
        for (j = 0; j < MAX_EXERCISES; j++)
            players[i].progress[j] = 0;
    }
}

void print_progress(Player players[], int num_players) {
    int i, j;
    for (i = 0; i < num_players; i++) {
        printf("%s ", players[i].name);
        for (j = 0; j < MAX_EXERCISES; j++)
            printf("%d/%d ", players[i].progress[j], players[i].level * 10);
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    Player players[MAX_PLAYERS];
    int num_players;
    printf("Enter number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    init_players(players, num_players);
    printf("\nPlayers created:\n");
    print_progress(players, num_players);

    printf("\nStarting exercise tracking...\n");

    int i, j;
    while (1) {
        int exercise_num = rand() % MAX_EXERCISES;
        int experience = rand() % 5 + 1;
        printf("\nExercise %d selected\n", exercise_num + 1);
        for (i = 0; i < num_players; i++) {
            printf("%s, how many reps did you do? ", players[i].name);
            int reps;
            scanf("%d", &reps);
            players[i].progress[exercise_num] += reps;
            while (players[i].progress[exercise_num] >= players[i].level * 10) {
                players[i].experience++;
                players[i].progress[exercise_num] -= players[i].level * 10;
                printf("%s leveled up to level %d!\n", players[i].name, players[i].level + 1);
                players[i].level++;
            }
            players[i].experience += experience;
        }
        printf("\nCurrent progress:\n");
        print_progress(players, num_players);
    }

    return 0;
}
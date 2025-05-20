//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4

typedef struct Player {
  char name[20];
  int heart_rate;
  int steps_taken;
  int calories_burned;
} Player;

void calculate_stats(Player *player) {
  player->calories_burned = (player->heart_rate * player->steps_taken) / 20;
}

int main() {
  Player players[MAX_PLAYERS];
  int i, j, num_players;

  printf("Enter the number of players: ");
  scanf("%d", &num_players);

  for (i = 0; i < num_players; i++) {
    printf("Enter the name of player %d: ", i + 1);
    scanf("%s", players[i].name);

    printf("Enter the heart rate of player %d: ", i + 1);
    scanf("%d", &players[i].heart_rate);

    printf("Enter the number of steps taken by player %d: ", i + 1);
    scanf("%d", &players[i].steps_taken);
  }

  for (i = 0; i < num_players; i++) {
    calculate_stats(&players[i]);
  }

  printf("The stats for each player are:\n");

  for (i = 0; i < num_players; i++) {
    printf("Player: %s\n", players[i].name);
    printf("Heart Rate: %d\n", players[i].heart_rate);
    printf("Steps Taken: %d\n", players[i].steps_taken);
    printf("Calories Burned: %d\n", players[i].calories_burned);
    printf("\n");
  }

  return 0;
}
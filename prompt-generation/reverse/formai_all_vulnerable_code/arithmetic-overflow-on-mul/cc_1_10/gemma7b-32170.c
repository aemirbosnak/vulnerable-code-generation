//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4

typedef struct Player {
  char name[20];
  int heartRate;
  int stepsTaken;
  int caloriesBurned;
} Player;

int main() {
  int numPlayers;
  Player players[MAX_PLAYERS];

  // Initialize players
  for (int i = 0; i < MAX_PLAYERS; i++) {
    players[i].name[0] = '\0';
    players[i].heartRate = 0;
    players[i].stepsTaken = 0;
    players[i].caloriesBurned = 0;
  }

  // Get number of players
  printf("Enter the number of players: ");
  scanf("%d", &numPlayers);

  // Join the game
  for (int i = 0; i < numPlayers; i++) {
    printf("Enter the name of player %d: ", i + 1);
    scanf("%s", players[i].name);

    printf("Enter your heart rate: ");
    scanf("%d", &players[i].heartRate);

    printf("Enter the number of steps you took: ");
    scanf("%d", &players[i].stepsTaken);

    // Calculate calories burned
    players[i].caloriesBurned = (players[i].heartRate * players[i].stepsTaken) / 200;
  }

  // Display results
  printf("Here are the results:\n");
  for (int i = 0; i < numPlayers; i++) {
    printf("%s burned %d calories and took %d steps.\n", players[i].name, players[i].caloriesBurned, players[i].stepsTaken);
  }

  return 0;
}
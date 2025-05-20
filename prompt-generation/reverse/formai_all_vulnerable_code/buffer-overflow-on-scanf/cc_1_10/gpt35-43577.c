//FormAI DATASET v1.0 Category: Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10

typedef struct {
  char name[20];
  int score;
} player_t;

int main() {
  player_t players[MAX_PLAYERS];
  int num_players;

  // Get number of players
  printf("How many players? (1 - %d): ", MAX_PLAYERS);
  scanf("%d", &num_players);

  // Validate number of players
  if (num_players < 1 || num_players > MAX_PLAYERS) {
    printf("Invalid number of players.\n");
    return 1;
  }

  // Get player names
  for (int i = 0; i < num_players; i++) {
    printf("Enter name for player %d: ", i+1);
    scanf("%s", &players[i].name);
  }

  // Game loop
  int round = 1;
  while (1) {
    printf("Round %d\n", round);

    // Get scores for each player
    for (int i = 0; i < num_players; i++) {
      printf("%s's turn: ", players[i].name);
      int score;
      scanf("%d", &score);
      players[i].score += score;
    }

    // Check if any player won
    for (int i = 0; i < num_players; i++) {
      if (players[i].score >= 100) {
        printf("%s wins!\n", players[i].name);
        return 0;
      }
    }

    round++;
  }

  return 0;
}
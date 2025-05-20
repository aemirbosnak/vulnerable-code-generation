//Gemma-7B DATASET v1.0 Category: Table Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAYER_COUNT 2

typedef struct Player {
  char name[20];
  int score;
} Player;

void playGame() {
  Player players[MAX_PLAYER_COUNT];
  int i, j, round, totalScore = 0;

  // Initialize players
  for (i = 0; i < MAX_PLAYER_COUNT; i++) {
    players[i].name[0] = '\0';
    players[i].score = 0;
  }

  // Get player names
  printf("Enter player names (separated by commas): ");
  scanf("%s", players[0].name);
  if (MAX_PLAYER_COUNT == 2) {
    scanf("%s", players[1].name);
  }

  // Play rounds
  for (round = 1; round <= 3; round++) {
    // Get player rolls
    for (i = 0; i < MAX_PLAYER_COUNT; i++) {
      players[i].score += rand() % 6 + 1;
    }

    // Calculate round total score
    totalScore = 0;
    for (i = 0; i < MAX_PLAYER_COUNT; i++) {
      totalScore += players[i].score;
    }

    // Announce round score
    printf("Round %d: Total score is %d\n", round, totalScore);
  }

  // Calculate winner
  for (i = 0; i < MAX_PLAYER_COUNT; i++) {
    if (players[i].score > totalScore / 2) {
      printf("%s won the game!\n", players[i].name);
    }
  }
}

int main() {
  playGame();
  return 0;
}
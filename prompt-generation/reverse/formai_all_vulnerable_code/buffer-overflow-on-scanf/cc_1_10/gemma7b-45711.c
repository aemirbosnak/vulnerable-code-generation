//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4

typedef struct Player {
  char name[20];
  int score;
  int position;
} Player;

Player players[MAX_PLAYERS];

void initializePlayers() {
  for (int i = 0; i < MAX_PLAYERS; i++) {
    players[i].name[0] = '\0';
    players[i].score = 0;
    players[i].position = -1;
  }
}

void displayPlayers() {
  for (int i = 0; i < MAX_PLAYERS; i++) {
    if (players[i].name[0] != '\0') {
      printf("  %s: Score - %d, Position - %d\n", players[i].name, players[i].score, players[i].position);
    }
  }
}

int main() {
  initializePlayers();

  // Game loop
  while (1) {
    // Get player input
    char input[100];
    printf("Enter command: ");
    scanf("%s", input);

    // Process player input
    if (strcmp(input, "add") == 0) {
      // Add a player
      char name[20];
      printf("Enter player name: ");
      scanf("%s", name);

      // Add the player to the game
      for (int i = 0; i < MAX_PLAYERS; i++) {
        if (players[i].name[0] == '\0') {
          strcpy(players[i].name, name);
          players[i].position = 0;
          break;
        }
      }

      printf("Player added.\n");
    } else if (strcmp(input, "move") == 0) {
      // Move a player
      char playerName[20];
      int direction;
      printf("Enter player name: ");
      scanf("%s", playerName);

      printf("Enter direction (left/right): ");
      scanf("%d", &direction);

      // Move the player
      for (int i = 0; i < MAX_PLAYERS; i++) {
        if (strcmp(players[i].name, playerName) == 0) {
          switch (direction) {
            case 0:
              players[i].position--;
              break;
            case 1:
              players[i].position++;
              break;
          }
        }
      }

      printf("Player moved.\n");
    } else if (strcmp(input, "score") == 0) {
      // Get the score of a player
      char playerName[20];
      printf("Enter player name: ");
      scanf("%s", playerName);

      // Get the player's score
      for (int i = 0; i < MAX_PLAYERS; i++) {
        if (strcmp(players[i].name, playerName) == 0) {
          printf("Player score: %d\n", players[i].score);
        }
      }
    } else if (strcmp(input, "quit") == 0) {
      // Quit the game
      printf("Goodbye!\n");
      break;
    } else {
      // Invalid input
      printf("Invalid command.\n");
    }

    displayPlayers();
  }

  return 0;
}
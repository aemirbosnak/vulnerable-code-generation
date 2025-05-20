//Gemma-7B DATASET v1.0 Category: RAM usage monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAYER_NUM 4

struct Player {
  char name[20];
  int ram_usage;
  int score;
};

void show_usage(struct Player *players) {
  for (int i = 0; i < MAX_PLAYER_NUM; i++) {
    printf("%s: RAM usage %d, Score: %d\n", players[i].name, players[i].ram_usage, players[i].score);
  }
}

int main() {
  struct Player players[MAX_PLAYER_NUM];

  for (int i = 0; i < MAX_PLAYER_NUM; i++) {
    players[i].name[0] = '\0';
    players[i].ram_usage = 0;
    players[i].score = 0;
  }

  // Gameplay loop
  while (1) {
    // Get player input
    char command[20];
    printf("Enter command: ");
    scanf("%s", command);

    // Analyze command
    if (strcmp(command, "add") == 0) {
      // Get player name and RAM usage
      char name[20];
      int ram_usage;
      printf("Enter player name: ");
      scanf("%s", name);
      printf("Enter RAM usage: ");
      scanf("%d", &ram_usage);

      // Add player to game
      for (int i = 0; i < MAX_PLAYER_NUM; i++) {
        if (players[i].name[0] == '\0') {
          strcpy(players[i].name, name);
          players[i].ram_usage = ram_usage;
          break;
        }
      }
    } else if (strcmp(command, "show") == 0) {
      // Show player usage
      show_usage(players);
    } else if (strcmp(command, "quit") == 0) {
      // Quit game
      break;
    } else {
      // Invalid command
      printf("Invalid command.\n");
    }
  }

  // End game
  show_usage(players);
  printf("Game over.\n");

  return 0;
}
//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Players 4
#define MAX_Turns 3

typedef struct Player {
  char name[20];
  int score;
  int turn;
} Player;

void initializePlayers(Player *players) {
  for (int i = 0; i < MAX_Players; i++) {
    players[i].name[0] = '\0';
    players[i].score = 0;
    players[i].turn = 0;
  }
}

void displayPlayers(Player *players) {
  for (int i = 0; i < MAX_Players; i++) {
    printf("%s: %d, Turn: %d\n", players[i].name, players[i].score, players[i].turn);
  }
}

int main() {
  Player players[MAX_Players];
  initializePlayers(players);

  // Game loop
  for (int turn = 0; turn < MAX_Turns; turn++) {
    // Each player takes their turn
    for (int i = 0; i < MAX_Players; i++) {
      if (players[i].turn == turn) {
        // Get player's input
        char input[20];
        printf("%s, enter your move: ", players[i].name);
        scanf("%s", input);

        // Validate move
        if (input[0] >= 'a' && input[0] <= 'h' && input[1] >= '1' && input[1] <= '6') {
          // Calculate move
          int move = input[0] - 'a' + 11 * (input[1] - '1') - 1;

          // Update player's turn and score
          players[i].turn++;
          players[i].score++;

          // Display updated players
          displayPlayers(players);
        } else {
          printf("Invalid move.\n");
        }
      }
    }
  }

  // Final scores
  printf("Final scores:\n");
  displayPlayers(players);

  return 0;
}
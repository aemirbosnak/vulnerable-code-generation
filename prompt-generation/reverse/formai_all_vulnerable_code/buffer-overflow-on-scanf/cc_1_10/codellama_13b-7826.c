//Code Llama-13B DATASET v1.0 Category: Table Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define MAX_VAL 100
#define MAX_NUM_PLAYERS 4
#define MAX_PLAYER_NAME_LEN 30

typedef struct {
  char name[MAX_PLAYER_NAME_LEN];
  int score;
} Player;

void print_table(Player players[MAX_NUM_PLAYERS]) {
  printf("  1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10\n");
  printf("  ----------|---------|---------|---------|---------|---------|---------|---------|---------|---------\n");
  for (int i = 0; i < MAX_NUM_PLAYERS; i++) {
    printf("%s |", players[i].name);
    for (int j = 0; j < MAX_ROWS; j++) {
      printf(" %d |", players[i].score);
    }
    printf("\n");
  }
}

int main() {
  Player players[MAX_NUM_PLAYERS];
  for (int i = 0; i < MAX_NUM_PLAYERS; i++) {
    players[i].score = 0;
    printf("Enter player %d name: ", i + 1);
    scanf("%s", players[i].name);
  }

  srand(time(NULL));

  for (int i = 0; i < MAX_ROWS; i++) {
    for (int j = 0; j < MAX_COLS; j++) {
      int num = rand() % MAX_VAL + 1;
      for (int k = 0; k < MAX_NUM_PLAYERS; k++) {
        if (num == players[k].score) {
          players[k].score += num;
        }
      }
    }
    print_table(players);
  }

  for (int i = 0; i < MAX_NUM_PLAYERS; i++) {
    printf("%s has a total score of %d.\n", players[i].name, players[i].score);
  }

  return 0;
}
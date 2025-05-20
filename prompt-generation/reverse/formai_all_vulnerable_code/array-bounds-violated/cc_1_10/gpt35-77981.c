//FormAI DATASET v1.0 Category: Educational ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int num_players, max_rounds, i, j;
  printf("Welcome to the ultimate jousting tournament!\n");
  printf("How many players will be competing? ");
  scanf("%d", &num_players);
  printf("How many rounds will there be in the tournament? ");
  scanf("%d", &max_rounds);

  // Initialize players with random names and strength values
  char player_names[num_players][20];
  int player_strengths[num_players];
  for (i = 0; i < num_players; i++) {
    printf("Enter name for player %d: ", i+1);
    scanf("%s", player_names[i]);
    player_strengths[i] = rand() % 21 + 80;
    printf("%s has a strength of %d.\n", player_names[i], player_strengths[i]);
  }

  // Start tournament rounds
  for (i = 1; i <= max_rounds; i++) {
    printf('\n');
    printf("Round %d: ", i);

    // Pair up random players for jousting
    int player1 = rand() % num_players;
    int player2 = rand() % num_players;
    while (player1 == player2) {
      player2 = rand() % num_players;
    }
    printf("%s will joust against %s.\n", player_names[player1], player_names[player2]);

    // Determine winner based on player strengths
    int p1_result = rand() % player_strengths[player1];
    int p2_result = rand() % player_strengths[player2];
    if (p1_result > p2_result) {
      printf("%s won this round!\n", player_names[player1]);
    } else if (p2_result > p1_result) {
      printf("%s won this round!\n", player_names[player2]);
    } else {
      printf("It's a tie!\n");
    }
  }

  // Determine overall tournament winner
  int max_strength = 0;
  int winner_index = -1;
  for (i = 0; i < num_players; i++) {
    if (player_strengths[i] > max_strength) {
      max_strength = player_strengths[i];
      winner_index = i;
    }
  }
  printf("\n\nCongratulations, %s is the winner of the jousting tournament!\n", player_names[winner_index]);
  return 0;
}
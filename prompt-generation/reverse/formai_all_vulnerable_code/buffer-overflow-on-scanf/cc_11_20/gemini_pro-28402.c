//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct {
  char name[256];
  int score;
} player;

int main() {
  // Initialize the game
  player players[4];
  int num_players = 0;
  int current_player = 0;
  char input[256];
  int target_temp;
  int guess;
  int correct_guesses = 0;
  int round = 1;

  // Get the number of players
  printf("How many players? (1-4) ");
  scanf("%d", &num_players);

  // Get the names of the players
  for (int i = 0; i < num_players; i++) {
    printf("Enter the name of player %d: ", i + 1);
    scanf("%s", players[i].name);
  }

  // Set the target temperature
  target_temp = rand() % 100 + 1;
  printf("\nThe target temperature is: %d\n\n", target_temp);

  // Start the game loop
  while (correct_guesses < num_players) {
    // Get the current player's guess
    printf("%s, enter your guess: ", players[current_player].name);
    scanf("%d", &guess);

    // Check if the guess is correct
    if (guess == target_temp) {
      printf("Correct!\n");
      players[current_player].score++;
      correct_guesses++;
    } else if (guess < target_temp) {
      printf("Your guess is too low.\n");
    } else {
      printf("Your guess is too high.\n");
    }

    // Move to the next player
    current_player++;
    if (current_player == num_players) {
      current_player = 0;
    }
  }

  // Print the scores of the players
  printf("\nScores:\n");
  for (int i = 0; i < num_players; i++) {
    printf("%s: %d\n", players[i].name, players[i].score);
  }

  // Find the winner
  int winning_score = 0;
  for (int i = 0; i < num_players; i++) {
    if (players[i].score > winning_score) {
      winning_score = players[i].score;
    }
  }

  // Print the winner
  printf("\nThe winner is: ");
  for (int i = 0; i < num_players; i++) {
    if (players[i].score == winning_score) {
      printf("%s\n", players[i].name);
    }
  }

  return 0;
}
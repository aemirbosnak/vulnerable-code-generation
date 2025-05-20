//GEMINI-pro DATASET v1.0 Category: Game ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_TURNS 10

int main() {
  int player_score = 0;
  int computer_score = 0;
  int turn;
  int player_choice;
  int computer_choice;

  // Seed the random number generator
  srand(time(NULL));

  // Play the game
  for (turn = 0; turn < NUM_TURNS; turn++) {
    // Get the player's choice
    printf("Enter your choice (1 for rock, 2 for paper, 3 for scissors): ");
    scanf("%d", &player_choice);

    // Get the computer's choice
    computer_choice = rand() % 3 + 1;

    // Determine the winner of the turn
    if (player_choice == computer_choice) {
      printf("Tie\n");
    } else if (player_choice == 1 && computer_choice == 3) {
      printf("You win!\n");
      player_score++;
    } else if (player_choice == 2 && computer_choice == 1) {
      printf("You win!\n");
      player_score++;
    } else if (player_choice == 3 && computer_choice == 2) {
      printf("You win!\n");
      player_score++;
    } else {
      printf("You lose!\n");
      computer_score++;
    }
  }

  // Print the final scores
  printf("Your score: %d\n", player_score);
  printf("Computer score: %d\n", computer_score);

  // Determine the overall winner
  if (player_score > computer_score) {
    printf("You win the game!\n");
  } else if (player_score == computer_score) {
    printf("Tie game!\n");
  } else {
    printf("You lose the game!\n");
  }

  return 0;
}
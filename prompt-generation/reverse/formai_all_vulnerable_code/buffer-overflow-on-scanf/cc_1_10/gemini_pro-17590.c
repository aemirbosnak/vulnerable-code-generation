//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_range(int min, int max) {
  return rand() % (max - min + 1) + min;
}

// Function to play a round of the game
int play_round(int player_score, int computer_score) {
  // Get player's move
  printf("Player's turn: ");
  int player_move;
  scanf("%d", &player_move);

  // Get computer's move
  int computer_move = rand_range(1, 6);

  // Calculate the winner of the round
  int winner;
  if (player_move > computer_move) {
    winner = 1; // Player wins
  } else if (player_move < computer_move) {
    winner = 2; // Computer wins
  } else {
    winner = 0; // Tie
  }

  // Update the scores
  if (winner == 1) {
    player_score++;
  } else if (winner == 2) {
    computer_score++;
  }

  // Print the results of the round
  printf("Player: %d, Computer: %d\n", player_score, computer_score);

  // Return the winner of the round
  return winner;
}

// Function to play the game
void play_game() {
  // Initialize the scores
  int player_score = 0;
  int computer_score = 0;

  // Play the rounds
  for (int i = 0; i < 10; i++) {
    int winner = play_round(player_score, computer_score);

    // Check if there is a winner
    if (winner == 1 || winner == 2) {
      // Print the winner
      if (winner == 1) {
        printf("Player wins!\n");
      } else {
        printf("Computer wins!\n");
      }
      return;
    }
  }

  // If there is no winner, declare a tie
  printf("Tie game!\n");
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Play the game
  play_game();

  return 0;
}
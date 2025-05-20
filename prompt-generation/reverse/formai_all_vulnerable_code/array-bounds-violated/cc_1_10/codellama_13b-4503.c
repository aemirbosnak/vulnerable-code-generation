//Code Llama-13B DATASET v1.0 Category: Table Game ; Style: rigorous
// A rigorous C Table Game example program
#include <stdio.h>

// Define the number of players and the number of rounds
#define PLAYERS 4
#define ROUNDS 3

// Define the table and the player's scores
int table[ROUNDS][PLAYERS];
int scores[PLAYERS];

// Define the possible actions
#define ACTION_HIT 1
#define ACTION_STAND 2

// Define the possible outcomes
#define OUTCOME_WIN 3
#define OUTCOME_LOSE 4
#define OUTCOME_DRAW 5

// Define the winning condition
#define WINNING_CONDITION 21

// Define the function to play a round
void playRound(int round, int player) {
  // Get the player's action
  int action;
  scanf("%d", &action);

  // Check if the player hit or stand
  if (action == ACTION_HIT) {
    // Get the player's score
    int score;
    scanf("%d", &score);

    // Add the score to the table
    table[round][player] += score;

    // Check if the player won
    if (table[round][player] > WINNING_CONDITION) {
      scores[player]++;
    }
  } else if (action == ACTION_STAND) {
    // Get the player's score
    int score;
    scanf("%d", &score);

    // Add the score to the table
    table[round][player] += score;

    // Check if the player won
    if (table[round][player] > WINNING_CONDITION) {
      scores[player]++;
    }
  }
}

// Define the function to play the game
void playGame(int rounds) {
  // Initialize the table and scores
  for (int i = 0; i < PLAYERS; i++) {
    for (int j = 0; j < ROUNDS; j++) {
      table[i][j] = 0;
    }
    scores[i] = 0;
  }

  // Play the game
  for (int i = 0; i < rounds; i++) {
    for (int j = 0; j < PLAYERS; j++) {
      playRound(i, j);
    }
  }
}

// Define the main function
int main() {
  // Play the game
  playGame(ROUNDS);

  // Print the scores
  for (int i = 0; i < PLAYERS; i++) {
    printf("Player %d: %d\n", i, scores[i]);
  }

  return 0;
}
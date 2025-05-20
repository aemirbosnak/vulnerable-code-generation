//FormAI DATASET v1.0 Category: Table Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // initialize random seed
  srand(time(NULL));
  // define variables
  int turn = 1;
  int player1_score = 0;
  int player2_score = 0;
  int player1_turn_score = 0;
  int player2_turn_score = 0;
  int dice_roll = 0;
  char input;
  
  printf("Welcome to the C Table Game!\n");
  
  while (player1_score < 100 && player2_score < 100) {
    printf("Turn %d\n", turn);
    printf("Player 1 score: %d\n", player1_score);
    printf("Player 2 score: %d\n", player2_score);
    
    // player 1's turn
    printf("Player 1, enter 'r' to roll the dice or 'h' to hold: ");
    scanf(" %c", &input);
    
    if (input == 'r') {
      dice_roll = rand() % 6 + 1;
      printf("Player 1 rolled a %d\n", dice_roll);
      if (dice_roll == 1) {
        player1_turn_score = 0;
        printf("Player 1 rolled a 1 and lost their turn\n");
      } else {
        player1_turn_score += dice_roll;
        printf("Player 1's turn score: %d\n", player1_turn_score);
      }
    } else if (input == 'h') {
      player1_score += player1_turn_score;
      player1_turn_score = 0;
      printf("Player 1 chose to hold with a score of %d\n", player1_score);
    }
    
    // player 2's turn
    printf("Player 2, enter 'r' to roll the dice or 'h' to hold: ");
    scanf(" %c", &input);
    
    if (input == 'r') {
      dice_roll = rand() % 6 + 1;
      printf("Player 2 rolled a %d\n", dice_roll);
      if (dice_roll == 1) {
        player2_turn_score = 0;
        printf("Player 2 rolled a 1 and lost their turn\n");
      } else {
        player2_turn_score += dice_roll;
        printf("Player 2's turn score: %d\n", player2_turn_score);
      }
    } else if (input == 'h') {
      player2_score += player2_turn_score;
      player2_turn_score = 0;
      printf("Player 2 chose to hold with a score of %d\n", player2_score);
    }
    
    turn++;
  }
  
  // determine winner
  if (player1_score >= 100) {
    printf("Player 1 wins!\n");
  } else if (player2_score >= 100) {
    printf("Player 2 wins!\n");
  }
  
  return 0;
}
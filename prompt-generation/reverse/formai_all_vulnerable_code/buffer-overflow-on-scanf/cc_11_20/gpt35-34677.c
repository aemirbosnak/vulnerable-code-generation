//FormAI DATASET v1.0 Category: Table Game ; Style: Ada Lovelace
/*
 * Ada Lovelace inspired C Table Game
 * Created by [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); //seed the random number generator with current time
  int player1_score = 0, player2_score = 0; //initialize scores to 0 for both players
  int turn_score = 0; //initialize turn score to 0
  
  printf("Welcome to the Ada Lovelace inspired C Table Game!\n");
  printf("The objective of the game is to score exactly 21 points.\n");
  printf("If you go over 21 points, you automatically lose.\n");
  printf("The player with the highest score that does not exceed 21 points wins.\n");
  printf("Player 1 will go first.\n\n");
  
  while (player1_score <= 21 && player2_score <= 21) { //loop until one player exceeds 21 points
    int dice_roll = rand() % 6 + 1; //generate a random number between 1 and 6
    printf("Player 1 rolled a %d.\n", dice_roll);
    
    if (dice_roll == 1) { //if player rolls a 1, turn score is lost and turn ends
      printf("Sorry, you rolled a 1. Your turn is over.\n");
      turn_score = 0;
    } else {
      turn_score += dice_roll; //add roll to turn score
      printf("Your current turn score is %d.\n", turn_score);
      printf("Do you want to roll again? (y/n) ");
      char answer;
      scanf(" %c", &answer); //get player's answer
      
      while (answer == 'y') { //loop as long as player answers 'y'
        dice_roll = rand() % 6 + 1; //roll dice again
        printf("You rolled a %d.\n", dice_roll);
        
        if (dice_roll == 1) { //if player rolls a 1, turn score is lost and turn ends
          printf("Sorry, you rolled a 1. Your turn is over.\n");
          turn_score = 0;
          break; //exit loop
        } else {
          turn_score += dice_roll; //add roll to turn score
          printf("Your current turn score is %d.\n", turn_score);
          printf("Do you want to roll again? (y/n) ");
          scanf(" %c", &answer); //get player's answer
        }
      }
    }
    
    player1_score += turn_score; //add turn score to player's total score
    printf("Player 1's total score is %d.\n\n", player1_score);
    
    if (player1_score > 21) { //check if player 1 exceeded 21 points
      printf("Player 1 exceeded 21 points. Player 2 wins!\n");
      return 0; //end program
    }
    
    turn_score = 0; //reset turn score for player 2's turn
    
    dice_roll = rand() % 6 + 1; //generate a random number between 1 and 6
    printf("Player 2 rolled a %d.\n", dice_roll);
    
    if (dice_roll == 1) { //if player rolls a 1, turn score is lost and turn ends
      printf("Sorry, you rolled a 1. Your turn is over.\n");
      turn_score = 0;
    } else {
      turn_score += dice_roll; //add roll to turn score
      printf("Your current turn score is %d.\n", turn_score);
      
      //determine whether to roll again based on probability
      int probability = rand() % 2;
      if (probability == 0) {
        printf("Player 2 decides to hold.\n");
      } else {
        printf("Player 2 decides to roll again.\n");
        dice_roll = rand() % 6 + 1; //roll dice again
        printf("You rolled a %d.\n", dice_roll);
        
        if (dice_roll == 1) { //if player rolls a 1, turn score is lost and turn ends
          printf("Sorry, you rolled a 1. Your turn is over.\n");
          turn_score = 0;
        } else {
          turn_score += dice_roll; //add roll to turn score
          printf("Your current turn score is %d.\n", turn_score);
        }
      }
    }
    
    player2_score += turn_score; //add turn score to player's total score
    printf("Player 2's total score is %d.\n\n", player2_score);
    
    if (player2_score > 21) { //check if player 2 exceeded 21 points
      printf("Player 2 exceeded 21 points. Player 1 wins!\n");
      return 0; //end program
    }
    
    turn_score = 0; //reset turn score for player 1's turn
  }
  
  if (player1_score == player2_score) { //check for a tie
    printf("It's a tie!\n");
  } else if (player1_score > player2_score) {
    printf("Player 1 wins!\n");
  } else {
    printf("Player 2 wins!\n");
  }
  
  return 0;
}
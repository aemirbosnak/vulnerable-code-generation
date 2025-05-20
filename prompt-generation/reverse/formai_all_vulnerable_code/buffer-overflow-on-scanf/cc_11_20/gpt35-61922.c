//FormAI DATASET v1.0 Category: Table Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // seed for random number generation
  
  int player1_score = 0, player2_score = 0;
  int dice_roll, turn_score = 0;
  int current_player = 1;
  char play_again = 'y';
  
  printf("Welcome to the C Table Game!\n");
  printf("Each player takes turns rolling a dice.\n");
  printf("The score is the sum of the dice on each turn.\n");
  printf("The first player to reach 50 points wins!\n\n");
  
  while (play_again == 'y') { // loop until players quit
    while (player1_score < 50 && player2_score < 50) { // loop until a player wins
      printf("Player %d, it's your turn!\n", current_player);
      
      dice_roll = rand() % 6 + 1; // roll the dice
      printf("You rolled a %d.\n", dice_roll);
      
      if (dice_roll == 1) { // player rolled a 1
        printf("Sorry, you lose your turn and your score is reset to 0.\n");
        turn_score = 0;
      } else { // player didn't roll a 1
        turn_score += dice_roll; // add current roll to turn score
        printf("Your current turn score is %d and your total score is %d.\n", turn_score, (current_player == 1) ? player1_score : player2_score);
        
        printf("Do you want to roll again? (y/n) ");
        char response;
        scanf(" %c", &response);
        
        if (response == 'n') { // player ends turn
          if (current_player == 1) {
            player1_score += turn_score;
          } else {
            player2_score += turn_score;
          }
          printf("Your turn has ended. Your total score is %d.\n", (current_player == 1) ? player1_score : player2_score);
          turn_score = 0; // reset turn score for next player
          current_player = (current_player == 1) ? 2 : 1; // switch to other player's turn
        }
      }
    }
    
    if (player1_score >= 50) {
      printf("Player 1 wins with a score of %d!\n", player1_score);
    } else {
      printf("Player 2 wins with a score of %d!\n", player2_score);
    }
    
    printf("Do you want to play again? (y/n) ");
    scanf(" %c", &play_again);
    player1_score = 0;
    player2_score = 0;
    current_player = 1;
    turn_score = 0;
  }
  
  printf("Thanks for playing the C Table Game!\n");
  
  return 0;
}
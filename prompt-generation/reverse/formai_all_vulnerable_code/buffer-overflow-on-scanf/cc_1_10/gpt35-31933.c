//FormAI DATASET v1.0 Category: Table Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to roll the dice
int rollDice() {
  return rand() % 6 + 1;
}

int main() {
  //Seed the random number generator
  srand(time(NULL));

  //Declare variables
  int player1Score = 0, player2Score = 0, roundScore = 0, currentPlayer = 1, winner = 0, roundNum = 1;

  //Loop until a winner is found
  while (!winner) {
    printf("Round %d\n", roundNum);

    //Switch between players
    if (currentPlayer == 1) {
      printf("Player 1, it's your turn!\n");

      //Roll the dice
      int diceRoll = rollDice();

      //If a 1 is rolled, end the round and set the round score to 0
      if (diceRoll == 1) {
        printf("You rolled a 1. Your turn is over.\n");
        roundScore = 0;
        currentPlayer = 2;
      }
      //Otherwise, add the dice roll to the round score
      else {
        printf("You rolled a %d.\n", diceRoll);
        roundScore += diceRoll;
        printf("Your current round score is %d.\n", roundScore);
        printf("Your total score is %d.\n", player1Score + roundScore);

        //Ask the player if they want to keep rolling
        char input;
        printf("Do you want to roll again? (Y/N) ");
        scanf(" %c", &input);

        //If they do not want to roll again, end the round and add the round score to their total score
        if (input == 'N' || input == 'n') {
          player1Score += roundScore;
          printf("Your turn is over. Your total score is %d.\n", player1Score);
          currentPlayer = 2;
          roundScore = 0;
        }
      }
    }
    else {
      printf("Player 2, it's your turn!\n");

      //Roll the dice
      int diceRoll = rollDice();

      //If a 1 is rolled, end the round and set the round score to 0
      if (diceRoll == 1) {
        printf("You rolled a 1. Your turn is over.\n");
        roundScore = 0;
        currentPlayer = 1;
      }
      //Otherwise, add the dice roll to the round score
      else {
        printf("You rolled a %d.\n", diceRoll);
        roundScore += diceRoll;
        printf("Your current round score is %d.\n", roundScore);
        printf("Your total score is %d.\n", player2Score + roundScore);

        //Ask the player if they want to keep rolling
        char input;
        printf("Do you want to roll again? (Y/N) ");
        scanf(" %c", &input);

        //If they do not want to roll again, end the round and add the round score to their total score
        if (input == 'N' || input == 'n') {
          player2Score += roundScore;
          printf("Your turn is over. Your total score is %d.\n", player2Score);
          currentPlayer = 1;
          roundScore = 0;
        }
      }
    }

    //Check if a player has won
    if (player1Score >= 100) {
      winner = 1;
      printf("Player 1 wins!\n");
    }
    else if (player2Score >= 100) {
      winner = 1;
      printf("Player 2 wins!\n");
    }

    roundNum++;
  }

  return 0;
}
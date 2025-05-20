//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to roll a dice
int roll_dice(void) {
  //Generating a random number between 1 and 6
  return rand() % 6 + 1;
}

//Function to simulate rolling two dice
int roll_two_dice(void) {
  //Rolling the first dice
  int dice1 = roll_dice();

  //Rolling the second dice
  int dice2 = roll_dice();

  //Returning the sum of the two dice
  return dice1 + dice2;
}

//Function to play a game of craps
void play_craps(void) {
  //Getting the player's bet
  int bet;
  printf("Enter your bet: ");
  scanf("%d", &bet);

  //Rolling the dice
  int roll = roll_two_dice();

  //Checking the outcome of the roll
  if (roll == 7 || roll == 11) {
    //The player wins
    printf("You win! You won %d dollars.\n", bet);
  } else if (roll == 2 || roll == 3 || roll == 12) {
    //The player loses
    printf("You lose! You lost %d dollars.\n", bet);
  } else {
    //The point is established
    int point = roll;

    //Loop until the player rolls the point or a 7
    while (1) {
      roll = roll_two_dice();

      if (roll == point) {
        //The player wins
        printf("You win! You won %d dollars.\n", bet);
        break;
      } else if (roll == 7) {
        //The player loses
        printf("You lose! You lost %d dollars.\n", bet);
        break;
      }
    }
  }
}

//Main function
int main(void) {
  //Setting the random seed
  srand(time(NULL));

  //Playing the game of craps
  play_craps();

  return 0;
}
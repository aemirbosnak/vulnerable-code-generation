//FormAI DATASET v1.0 Category: Table Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Main function
int main()
{
  // Define the variables
  int player_score = 0, computer_score = 0, round_count = 1;
  char choice;

  // Output the welcome message
  printf("Welcome to the C Table Game!\n");

  // Play the game until someone scores 100 or more points
  while (player_score < 100 && computer_score < 100)
  {
    printf("\nRound %d:\n", round_count);

    // Generate a random number between 1 and 6 for both the player and computer
    srand(time(NULL));
    int player_roll = rand() % 6 + 1;
    int computer_roll = rand() % 6 + 1;

    // Output the rolls
    printf("You rolled a %d.\n", player_roll);
    printf("The computer rolled a %d.\n", computer_roll);

    // Determine the winner of the round
    if (player_roll > computer_roll)
    {
      printf("You won this round!\n");
      player_score += player_roll;
    }
    else if (player_roll < computer_roll)
    {
      printf("The computer won this round.\n");
      computer_score += computer_roll;
    }
    else
    {
      printf("This round was a tie.\n");
    }

    // Output the current score
    printf("Your score is %d.\n", player_score);
    printf("The computer's score is %d.\n", computer_score);

    // Ask the player if they want to quit or keep playing
    printf("Do you want to keep playing? (y/n)\n");
    scanf(" %c", &choice);

    // Increment the round count
    round_count++;
  }

  // Output the final score and winner
  printf("\nFinal score:\n");
  printf("Your score is %d.\n", player_score);
  printf("The computer's score is %d.\n", computer_score);

  if (player_score > computer_score)
  {
    printf("Congratulations! You won the game!\n");
  }
  else
  {
    printf("Sorry, the computer won the game. Better luck next time!\n");
  }

  return 0;
}
//FormAI DATASET v1.0 Category: Table Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int player_score = 0;
  int computer_score = 0;
  int round_num = 1;
  int player_choice;

  srand(time(NULL)); // Seed the random number generator with the current time

  printf("Welcome to the C Table Game!\n\n");

  while (round_num <= 10) // Play 10 rounds
  {
    printf("Round %d:\n", round_num);

    // Get player's choice
    printf("Choose your option:\n1 - Rock\n2 - Paper\n3 - Scissors\n");
    scanf("%d", &player_choice);

    // Generate computer's choice randomly
    int computer_choice = rand() % 3 + 1;

    // Compare choices and determine winner
    if (player_choice == computer_choice)
    {
      printf("Tie!\n");
    }
    else if ((player_choice == 1 && computer_choice == 3) || (player_choice == 2 && computer_choice == 1) || (player_choice == 3 && computer_choice == 2))
    {
      printf("You win this round!\n");
      player_score++;
    }
    else
    {
      printf("Computer wins this round!\n");
      computer_score++;
    }

    // Display current score
    printf("Score: Player - %d, Computer - %d\n\n", player_score, computer_score);

    round_num++;
  }

  // Determine overall winner
  printf("Game over!\n");
  if (player_score > computer_score)
  {
    printf("You win!\n");
  }
  else if (computer_score > player_score)
  {
    printf("Computer wins!\n");
  }
  else
  {
    printf("It's a tie!\n");
  }

  return 0;
}
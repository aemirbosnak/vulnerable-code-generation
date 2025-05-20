//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: romantic
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LENGTH 20 //Maximum length of player name
#define MAX_POINTS 10 //Number of points to win the game

int main()
{
  // Initialization
  srand(time(NULL));
  int player1_points = 0, player2_points = 0, round_points = 0, dice_roll, round_number = 1, player_turn = 1;
  char player1[MAX_LENGTH], player2[MAX_LENGTH];

  // Getting player names
  printf("Welcome to the Love Dice game!\n");
  printf("Player 1: Please enter your name (max %d characters): ", MAX_LENGTH);
  scanf("%s", player1);
  printf("Player 2: Please enter your name (max %d characters): ", MAX_LENGTH);
  scanf("%s", player2);

  // Game loop
  while (player1_points < MAX_POINTS && player2_points < MAX_POINTS)
  {
    printf("\n-------- Round %d --------\n", round_number);

    // Dice roll and display
    dice_roll = rand() % 6 + 1;
    printf("Player %d, it's your turn! You rolled a %d.\n", player_turn, dice_roll);

    // Check for a heart
    if (dice_roll == 6)
    {
      printf("Wow! You rolled a heart! You earn 2 points and get to go again.\n");
      round_points += 2;
      player_turn = player_turn;
    }
    else
    {
      round_points += dice_roll;
      printf("Your current round score is %d.\n", round_points);
      printf("Press enter to roll again.\n");
      getchar();

      // Second dice roll and display
      dice_roll = rand() % 6 + 1;
      printf("You rolled a %d.\n", dice_roll);

      // Check for a heart
      if (dice_roll == 6)
      {
        printf("Wow! You rolled a heart! You earn 2 points and get to go again.\n");
        round_points += 2;
        player_turn = player_turn;
      }
      else
      {
        round_points += dice_roll;
        printf("Your final round score is %d.\n", round_points);

        // Add points to player score
        if (player_turn == 1)
        {
          player1_points += round_points;
          printf("Player %d, your total score is now %d.\n", player_turn, player1_points);
          player_turn = 2;
          round_points = 0;
        }
        else
        {
          player2_points += round_points;
          printf("Player %d, your total score is now %d.\n", player_turn, player2_points);
          player_turn = 1;
          round_points = 0;
        }
      }
    }

    round_number++;
  }

  // End of game
  if (player1_points >= MAX_POINTS)
  {
    printf("\nCongratulations %s! You have won the game of love!\n", player1);
  }
  else
  {
    printf("\nCongratulations %s! You have won the game of love!\n", player2);
  }

  return 0;
}
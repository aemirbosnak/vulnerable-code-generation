//FormAI DATASET v1.0 Category: Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int user_choice, computer_choice;
  int user_score = 0, computer_score = 0;
  int round = 1;

  printf("Welcome to Rock, Paper, Scissors!\n");

  while (round <= 5) {
    printf("\nRound %d\n", round);

    printf("Select your choice:\n");
    printf("1) Rock\n");
    printf("2) Paper\n");
    printf("3) Scissors\n");
    scanf("%d", &user_choice);

    // Generate random number for computer choice
    srand(time(NULL));
    computer_choice = rand() % 3 + 1;

    // Compare choices and determine the winner
    if (user_choice == 1) {
      if (computer_choice == 1) {
        printf("It's a tie! You both chose rock.\n");
      } else if (computer_choice == 2) {
        printf("Sorry, paper beats rock. You lose.\n");
        computer_score++;
      } else {
        printf("Congrats, rock beats scissors. You win!\n");
        user_score++;
      }
    } else if (user_choice == 2) {
      if (computer_choice == 1) {
        printf("Congrats, paper beats rock. You win!\n");
        user_score++;
      } else if (computer_choice == 2) {
        printf("It's a tie! You both chose paper.\n");
      } else {
        printf("Sorry, scissors beats paper. You lose.\n");
        computer_score++;
      }
    } else if (user_choice == 3) {
      if (computer_choice == 1) {
        printf("Sorry, rock beats scissors. You lose.\n");
        computer_score++;
      } else if (computer_choice == 2) {
        printf("Congrats, scissors beats paper. You win!\n");
        user_score++;
      } else {
        printf("It's a tie! You both chose scissors.\n");
      }
    } else {
      printf("Invalid choice. Please choose 1, 2, or 3.\n");
      continue;
    }

    round++;
  }

  printf("\nFinal score:\n");
  printf("You: %d\n", user_score);
  printf("Computer: %d\n", computer_score);

  if (user_score > computer_score) {
    printf("You win the game!\n");
  } else if (computer_score > user_score) {
    printf("Sorry, you lose the game.\n");
  } else {
    printf("It's a tie game.\n");
  }

  return 0;
}
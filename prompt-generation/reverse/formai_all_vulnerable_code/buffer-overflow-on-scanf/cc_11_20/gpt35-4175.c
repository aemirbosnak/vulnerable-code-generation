//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
  // Initialize variables
  int playerScore = 0;
  int computerScore = 0;
  char playerChoice[10];
  char computerChoice[10];
  char options[3][10] = {"rock", "paper", "scissors"};

  // Welcome message
  printf("Welcome to Rock, Paper, Scissors!\n");

  while(1) {
    // Prompt player for their choice
    printf("Enter your choice (rock, paper, or scissors): ");
    scanf("%s", playerChoice);

    // Generate random choice for computer
    srand(time(0));
    int computerIndex = rand() % 3;
    strcpy(computerChoice, options[computerIndex]);

    // Determine winner and update scores accordingly
    if (strcmp(playerChoice, "rock") == 0) {
      if (strcmp(computerChoice, "paper") == 0) {
        printf("Computer wins! Paper beats rock.\n");
        computerScore++;
      } else if (strcmp(computerChoice, "scissors") == 0) {
        printf("Player wins! Rock beats scissors.\n");
        playerScore++;
      } else {
        printf("Tie game!\n");
      }
    } else if (strcmp(playerChoice, "paper") == 0) {
      if (strcmp(computerChoice, "scissors") == 0) {
        printf("Computer wins! Scissors beats paper.\n");
        computerScore++;
      } else if (strcmp(computerChoice, "rock") == 0) {
        printf("Player wins! Paper beats rock.\n");
        playerScore++;
      } else {
        printf("Tie game!\n");
      }
    } else if (strcmp(playerChoice, "scissors") == 0) {
      if (strcmp(computerChoice, "rock") == 0) {
        printf("Computer wins! Rock beats scissors.\n");
        computerScore++;
      } else if (strcmp(computerChoice, "paper") == 0) {
        printf("Player wins! Scissors beats paper.\n");
        playerScore++;
      } else {
        printf("Tie game!\n");
      }
    } else {
      printf("Invalid choice. Please try again.\n");
    }

    // Show current scores
    printf("Player: %d     Computer: %d\n", playerScore, computerScore);

    // Determine if game is over
    if (playerScore == 10) {
      printf("Player wins! With a score of %d to %d.\n", playerScore, computerScore);
      break;
    } else if (computerScore == 10) {
      printf("Computer wins! With a score of %d to %d.\n", computerScore, playerScore);
      break;
    }
  }

  return 0;
}
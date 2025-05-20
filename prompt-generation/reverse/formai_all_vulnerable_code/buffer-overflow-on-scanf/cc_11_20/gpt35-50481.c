//FormAI DATASET v1.0 Category: Table Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int user_choice;
  int computer_choice;
  int user_score = 0;
  int computer_score = 0;
  int round = 1;
  char play_again;

  // Display game instructions to user
  printf("Welcome to the C Table Game!\n");
  printf("The objective of the game is to guess a number between 1 and 5.\n");
  printf("You will go first, and if you guess correctly, you will get a point.\n");
  printf("Then the computer will take a turn, and if it guesses correctly, it will get a point.\n");
  printf("The game will continue for 5 rounds.\n");

  // Seed the random number generator
  srand(time(NULL));

  // Game loop
  do {
    printf("\nRound %d:\n", round);

    // User's turn
    printf("Your turn! Guess a number between 1 and 5: ");
    scanf("%d", &user_choice);

    // Ensure user's input is a valid choice
    while (user_choice < 1 || user_choice > 5) {
      printf("Invalid choice. Guess a number between 1 and 5: ");
      scanf("%d", &user_choice);
    }
    
    // Computer's turn
    computer_choice = rand() % 5 + 1;
    printf("Computer's turn! It guessed %d.\n", computer_choice);

    // Check for a draw
    if (user_choice == computer_choice) {
      printf("It's a draw.\n");
    }
    // Check for user win
    else if ((user_choice == 1 && computer_choice == 5) || (user_choice == 2 && computer_choice == 1) || (user_choice == 3 && computer_choice == 2) || (user_choice == 4 && computer_choice == 3) || (user_choice == 5 && computer_choice == 4)) {
      printf("You win this round!\n");
      user_score++;
    }
    // Computer wins otherwise
    else {
      printf("The computer wins this round.\n");
      computer_score++;
    }

    // Display current score
    printf("Current score: You %d - %d Computer\n", user_score, computer_score);

    // Increment round counter
    round++;

    // Ask user if they want to play again
    printf("\nDo you want to play again? (y/n) ");
    scanf(" %c", &play_again);
  } while (play_again == 'y' || play_again == 'Y');

  // Display final score
  printf("\nFinal score: You %d - %d Computer\n", user_score, computer_score);

  // Determine winner
  if (user_score > computer_score) {
    printf("Congratulations! You win!\n");
  }
  else if (user_score < computer_score) {
    printf("Sorry, the computer wins.\n");
  }
  else {
    printf("It's a draw.\n");
  }

  return 0;
}
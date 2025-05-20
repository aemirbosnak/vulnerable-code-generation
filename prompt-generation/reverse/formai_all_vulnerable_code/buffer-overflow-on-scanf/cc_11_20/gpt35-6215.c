//FormAI DATASET v1.0 Category: Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int playerScore = 0, computerScore = 0, roundScore;
  char hitOrStand, playAgain;
  srand(time(NULL));

  printf("Welcome to the Funny Blackjack Game!\n");

  do {
    printf("\nNew Game Starting...\n");
    roundScore = 0;

    // Player's turn
    while (1) {
      printf("Your current score is: %d\n", playerScore);
      printf("Do you want to hit (h) or stand (s)? ");
      scanf(" %c", &hitOrStand);

      if (hitOrStand == 'h') {
        int card = rand() % 10 + 1;
        printf("You drew a %d.\n", card);
        roundScore += card;

        if (roundScore > 21) {
          printf("You busted! Your score is %d.\n", roundScore);
          computerScore++;
          break;
        }
      } else if (hitOrStand == 's') {
        playerScore += roundScore;
        printf("Your score is now %d.\n", playerScore);
        break;
      } else {
        printf("Invalid input! Try again\n");
      }
    }

    // Computer's turn
    if (playerScore <= 21) {
      roundScore = 0;
      printf("\nComputer's turn...\n");

      while (roundScore < 17) {
        int card = rand() % 10 + 1;
        printf("Computer drew a %d.\n", card);
        roundScore += card;
      }

      if (roundScore > 21) {
        printf("Computer busted! Your score is %d.\n", playerScore);
        playerScore++;
      } else if (roundScore > playerScore) {
        printf("Computer wins! Your score is %d.\n", playerScore);
        computerScore++;
      } else if (roundScore < playerScore) {
        printf("You win! Your score is %d.\n", playerScore);
        playerScore++;
      } else {
        printf("It's a tie! Your score is %d.\n", playerScore);
      }
    }

    // Ask if the player wants to play again
    printf("Do you want to play again (y/n)? ");
    scanf(" %c", &playAgain);
  } while (playAgain == 'y');

  printf("Thanks for playing Funny Blackjack!\n");
  printf("Final Scores:\n");
  printf("Player: %d\n", playerScore);
  printf("Computer: %d\n", computerScore);

  return 0;
}
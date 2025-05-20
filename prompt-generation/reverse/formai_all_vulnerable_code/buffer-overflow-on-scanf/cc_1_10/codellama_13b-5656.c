//Code Llama-13B DATASET v1.0 Category: Game ; Style: unmistakable
/*
 * C Game Programming Example
 *
 * This program implements a simple game of "Guess the Number"
 *
 * Author: [Your Name]
 * Date:   [Current Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 100
int getRandomNumber() {
  return rand() % 100 + 1;
}

// Function to check if the user's guess is correct
int isGuessCorrect(int guess, int answer) {
  if (guess == answer) {
    return 1;
  } else {
    return 0;
  }
}

// Function to play a single round of the game
void playRound(int answer) {
  int guess;
  printf("Enter a number between 1 and 100: ");
  scanf("%d", &guess);
  if (isGuessCorrect(guess, answer)) {
    printf("You guessed it! The answer was %d\n", answer);
  } else {
    printf("Sorry, that's not the correct answer. The answer was %d\n", answer);
  }
}

// Function to play the game until the user quits
void playGame() {
  int answer = getRandomNumber();
  while (1) {
    playRound(answer);
    printf("Do you want to play again? (y/n) ");
    char answer;
    scanf(" %c", &answer);
    if (answer == 'n') {
      break;
    }
  }
}

int main() {
  srand(time(NULL));
  playGame();
  return 0;
}
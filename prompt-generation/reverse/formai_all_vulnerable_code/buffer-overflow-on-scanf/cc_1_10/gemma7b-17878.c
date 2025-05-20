//Gemma-7B DATASET v1.0 Category: Educational ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 10

int main() {
  int n, i, score1 = 0, score2 = 0;
  char name1[20], name2[20];

  printf("Enter your name: ");
  scanf("%s", name1);

  printf("Enter your friend's name: ");
  scanf("%s", name2);

  printf("Let's play a game of Guess the Number! You and your friend will take turns guessing a number between 1 and %d.\n", MAX_NUM);

  // Generate a random number between 1 and MAX_NUM
  srand(time(NULL));
  n = rand() % MAX_NUM + 1;

  // Player 1's turn
  printf("%s, guess a number: ", name1);
  scanf("%d", &i);

  // Check if the guess is correct
  if (i == n) {
    score1++;
    printf("Congratulations, %s! You guessed the number correctly!\n", name1);
  } else {
    printf("Sorry, %s. Your guess is incorrect. The number was %d.\n", name1, n);
  }

  // Player 2's turn
  printf("%s, guess a number: ", name2);
  scanf("%d", &i);

  // Check if the guess is correct
  if (i == n) {
    score2++;
    printf("Congratulations, %s! You guessed the number correctly!\n", name2);
  } else {
    printf("Sorry, %s. Your guess is incorrect. The number was %d.\n", name2, n);
  }

  // Display the final scores
  printf("The final score is: %d - %d\n", score1, score2);

  return 0;
}
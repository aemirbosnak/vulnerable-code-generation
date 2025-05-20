//FormAI DATASET v1.0 Category: Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int score = 0; // initialize player's score to 0
  int i, j;
  srand(time(NULL)); // seed the random number generator with the current time
  
  printf("========================\n");
  printf("Welcome to the Fruit Game!\n");
  printf("========================\n");

  while(1) { // keep the game running until player quits
    printf("\n"); // add a line break for readability

    // randomly select a fruit from the list
    char *fruits[] = {"apple", "banana", "orange", "grape", "watermelon"};
    int random_index = rand() % 5;
    char *selected_fruit = fruits[random_index];

    // print the selected fruit and prompt player to guess the index
    printf("The selected fruit is: %s\n", selected_fruit);
    printf("Guess the index of the fruit (0-4): ");
    scanf("%d", &i);

    // validate player's input
    if (i < 0 || i > 4) {
      printf("Invalid index, try again.\n");
      continue; // go to the start of the loop
    }

    // randomly generate a bonus point
    int bonus = rand() % 2;

    // randomly generate a distraction
    int distraction = rand() % 2;

    if (i == random_index) {
      printf("Congratulations, you guessed correctly!\n");
      score += 1 + bonus; // add 1 or 2 to the score
      if (bonus == 1) {
        printf("Bonus point added!\n");
      }
    } else {
      printf("Oops, wrong guess!\n");
      score -= 1; // deduct 1 point from the score
      if (distraction == 1) {
        printf("Oh no, a monkey stole your next guess!\n");
        continue;
      }
    }
    printf("Current score: %d\n", score);

    // prompt player to continue or quit
    char choice;
    printf("Do you want to continue playing (Y/N)? ");
    scanf(" %c", &choice);
    if (choice == 'N' || choice == 'n') {
      printf("Thank you for playing! Final score: %d\n", score);
      break; // exit the loop and end the game
    }
  }
  return 0;
}
//Gemma-7B DATASET v1.0 Category: Dice Roller ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main() {
  int roll_again = 1, number_rolled = 0, side_of_the_die = 0, total_score = 0;
  char character_rolled = 'a';

  printf("Welcome to the grandest game of chance, my dear friend!\n");
  printf("Let's roll that die!\n");

  while (roll_again) {
    side_of_the_die = rand() % 6 + 1;
    number_rolled++;

    switch (side_of_the_die) {
      case 1:
        character_rolled = 'a';
        break;
      case 2:
        character_rolled = 'b';
        break;
      case 3:
        character_rolled = 'c';
        break;
      case 4:
        character_rolled = 'd';
        break;
      case 5:
        character_rolled = 'e';
        break;
      case 6:
        character_rolled = 'f';
        break;
    }

    printf("You rolled a %d, which is a %c.\n", side_of_the_die, character_rolled);

    if (side_of_the_die == 6) {
      total_score += side_of_the_die;
      printf("Congratulations! You've rolled a six and won a point!\n");
    }

    printf("Do you want to roll again? (y/n): ");
    scanf("%c", &roll_again);

    if (roll_again == 'n') {
      printf("Thank you for playing! Your total score is: %d\n", total_score);
    }
  }

  return 0;
}
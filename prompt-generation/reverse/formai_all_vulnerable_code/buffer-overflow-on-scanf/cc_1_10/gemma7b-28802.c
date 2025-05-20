//Gemma-7B DATASET v1.0 Category: Dice Roller ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 6

int main() {
  // Declare variables
  int num_rolled = 0;
  int face_rolled = 0;
  int roll_again = 1;

  // Loop until the user wants to quit
  while (roll_again) {
    // Roll the dice
    face_rolled = rand() % MAX_NUM + 1;

    // Increment the number of rolls
    num_rolled++;

    // Print the face of the die
    switch (face_rolled) {
      case 1:
        printf("You rolled a 1.\n");
        break;
      case 2:
        printf("You rolled a 2.\n");
        break;
      case 3:
        printf("You rolled a 3.\n");
        break;
      case 4:
        printf("You rolled a 4.\n");
        break;
      case 5:
        printf("You rolled a 5.\n");
        break;
      case 6:
        printf("You rolled a 6.\n");
        break;
    }

    // Ask the user if they want to roll again
    printf("Do you want to roll again? (y/n): ");
    char answer;
    scanf("%c", &answer);

    // Check if the user wants to roll again
    if (answer == 'y') {
      roll_again = 1;
    } else {
      roll_again = 0;
    }
  }

  // Print the number of rolls
  printf("You rolled a total of %d times.\n", num_rolled);

  return 0;
}
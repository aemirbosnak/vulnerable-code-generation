//Gemma-7B DATASET v1.0 Category: Dice Roller ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
  int roll_num = 0;
  int sum = 0;
  int face_num = 0;
  char symbol = '\0';

  printf("Let's play a game of C Dice Roller!\n");

  // Loop to roll the dice as long as the user wants
  while (1) {
    // Get the number of rolls from the user
    printf("How many times do you want to roll the dice? (Enter a number): ");
    scanf("%d", &roll_num);

    // If the user wants to quit, break out of the loop
    if (roll_num == 0) {
      break;
    }

    // Roll the dice
    face_num = rand() % 6 + 1;

    // Update the sum of the rolls
    sum += face_num;

    // Get the symbol for the face of the die
    switch (face_num) {
      case 1:
        symbol = 'A';
        break;
      case 2:
        symbol = 'B';
        break;
      case 3:
        symbol = 'C';
        break;
      case 4:
        symbol = 'D';
        break;
      case 5:
        symbol = 'E';
        break;
      case 6:
        symbol = 'F';
        break;
    }

    // Print the results of the roll
    printf("You rolled a %d, which is a %c.\n", face_num, symbol);

    // Print the total sum of the rolls
    printf("The total sum of your rolls is %d.\n", sum);

    // Clear the screen
    system("clear");
  }

  // Thank the user for playing
  printf("Thank you for playing C Dice Roller!\n");

  return 0;
}
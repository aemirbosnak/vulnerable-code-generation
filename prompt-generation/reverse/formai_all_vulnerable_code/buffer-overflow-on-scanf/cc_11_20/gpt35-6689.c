//FormAI DATASET v1.0 Category: Dice Roller ; Style: configurable
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
  int sides = 6; // Default to a standard six-sided die
  int numOfDice = 1; // Default to rolling one die
  int modifier = 0; // Default to no modifier
  int rollTotal = 0; // Initialize total of all rolls to zero
  char modifierSign = '+'; // Default modifier is positive
  char input; // User input
  srand(time(0)); // Seed random number generator
  
  printf("Welcome to the Dice Roller!\n");
  printf("===========================\n");
  printf("You can configure your dice roll by adding options\n");
  printf("to the basic command of 'roll'. For example, you\n");
  printf("could type 'roll 3d8' to roll three eight-sided dice.\n");
  printf("Here are the options you can add:\n");
  printf("  - (Number)d(Number): rolls a specified number\n");
  printf("      of dice with a specified number of sides.\n");
  printf("  - +(Number) or -(Number): adds or subtracts a\n");
  printf("      modifier from the total roll.\n");

  while(1) { // Loop until user quits
    printf("\nEnter a command (type 'q' to quit): ");
    scanf(" %c", &input);

    if(input == 'q') { // Quit program
      printf("Thanks for rolling with us!\n");
      break;
    }
    else if(input == 'h') { // Display help information
      printf("Here are the options you can add:\n");
      printf("  - (Number)d(Number): rolls a specified number\n");
      printf("      of dice with a specified number of sides.\n");
      printf("  - +(Number) or -(Number): adds or subtracts a\n");
      printf("      modifier from the total roll.\n");

      continue;
    }
    else if(input != 'r') { // Input is not valid
      printf("Invalid command! Type 'h' for help.\n");
      continue;
    }

    // Process roll command
    scanf("%d", &numOfDice); // Read in number of dice to roll

    if(getchar() != 'd') { // Missing 'd' separator
      printf("Invalid roll command! Type 'h' for help.\n");
      continue;
    }

    scanf("%d", &sides); // Read in number of sides on dice

    // Roll the dice based on user input
    for(int i=0; i<numOfDice; i++) {
      rollTotal += rand() % sides + 1; // Add result to total roll
    }

    // Check for optional modifier
    if(getchar() == '+' || getchar() == '-') {
      modifierSign = getchar(); // Get modifier sign
      scanf("%d", &modifier); // Get modifier value

      if(modifierSign == '-') { // Subtraction modifier
        rollTotal -= modifier;
      }
      else { // Addition modifier
        rollTotal += modifier;
      }
    }

    // Display result to user
    printf("You rolled %d", rollTotal);

    if(numOfDice > 1) { // Indicate multiple dice were rolled
      printf(" (%dd%d)", numOfDice, sides);
    }

    if(modifier != 0) { // Indicate modifier applied
      printf(" %c %d", modifierSign, modifier);
    }

    printf("\n");

    // Reset for next roll
    numOfDice = 1;
    sides = 6;
    modifier = 0;
    rollTotal = 0;
    modifierSign = '+';
  }

  return 0;
}
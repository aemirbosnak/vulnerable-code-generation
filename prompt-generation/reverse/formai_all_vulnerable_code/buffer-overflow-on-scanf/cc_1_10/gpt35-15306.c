//FormAI DATASET v1.0 Category: Dice Roller ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int roll[7] = {0, 0, 0, 0, 0, 0, 0}; // Initialize array to keep track of dice rolls
  srand(time(NULL)); // Seed random number generator with current time
  
  printf("Welcome to the Dice Roller!\n\n");
  
  char choice = 'Y'; // Initialize variable for user choice
  
  while(choice == 'Y')
  {
    int numRolls, diceSides;
    
    printf("How many rolls would you like? ");
    scanf("%d", &numRolls);
    
    printf("How many sides does the dice have? ");
    scanf("%d", &diceSides);
    
    printf("\nRolling %d %d-sided dice...\n\n", numRolls, diceSides);
    
    int i;
    for(i = 0; i < numRolls; i++) // Loop through number of rolls requested
    {
      int rollValue = rand() % diceSides + 1; // Generate random number between 1 and number of sides on dice
      roll[rollValue]++;
      
      printf("Roll %d: %d\n", i+1, rollValue);
    }
    
    printf("\nResults: \n");
    for(i = 1; i <= diceSides; i++) // Loop through possible values of dice rolls
    {
      printf("%d: %d\n", i, roll[i]); // Print number of times each value was rolled
    }
    
    printf("\nWould you like to roll again? (Y/N) ");
    scanf(" %c", &choice); // Get user choice for continuing or exiting
    
    if(choice != 'Y' && choice != 'N')
    {
      printf("Invalid choice. Exiting program.\n");
      return 0;
    }
    
    printf("\n");
  }
  
  printf("Thank you for using the Dice Roller. Goodbye!\n");
  
  return 0;
}
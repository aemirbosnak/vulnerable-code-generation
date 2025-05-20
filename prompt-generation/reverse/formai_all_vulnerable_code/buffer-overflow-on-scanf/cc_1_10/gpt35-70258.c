//FormAI DATASET v1.0 Category: Dice Roller ; Style: creative
/*
  This program emulates a dice roller for various types of dice. 
  It prompts the user with a menu and then rolls the chosen dice.
  The user can choose to roll as many times as they like or they can exit the program.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int choice, sides, rolls;
  char confirm;
  srand(time(NULL)); // Seed random number generator

  do
  {
    printf("Welcome to the Dice Roller program!\n");
    printf("Choose an option from the menu below:\n");
    printf("1. Roll a standard six-sided die\n");
    printf("2. Roll a custom die\n");
    printf("3. Exit program\n");
    scanf("%d", &choice);
  
    switch(choice)
    {
      case 1:
        printf("How many times would you like to roll the dice?\n");
        scanf("%d", &rolls);
        for(int i=0; i<rolls; i++)
        {
          printf("Roll %d: %d\n",i+1, rand()%6+1);
        }
        break;
        
      case 2:
        printf("How many sides does your custom die have?\n");
        scanf("%d", &sides);
        printf("How many times would you like to roll the dice?\n");
        scanf("%d", &rolls);
        for(int i=0; i<rolls; i++)
        {
          printf("Roll %d: %d\n",i+1, rand()%sides+1);
        }
        break;
        
      case 3:
        printf("Are you sure you want to exit the program? (y/n)\n");
        scanf("%s", &confirm);
        if(confirm == 'y' || confirm == 'Y')
        {
          printf("Exiting program...\n");
          exit(0);
        }
        break;
        
      default:
        printf("Invalid choice. Try again.\n");
        break;
    }
  }while(choice!=3);
  
  return 0;
}
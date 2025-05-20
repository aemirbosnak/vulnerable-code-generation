//FormAI DATASET v1.0 Category: Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char password[20] = "password123";
  char input[20];
  int tries = 0;

  printf("Please enter the password:\n");

  while(1)
  {
    scanf("%s", input);

    if(strcmp(input, password) == 0)
    {
      printf("Access granted! Welcome!\n");
      break;
    }
    else
    {
      tries++;
      printf("Incorrect password.");

      if(tries == 1)
      {
        printf(" You have one more try.\n");
      }
      else if(tries == 2)
      {
        printf(" This is your last chance.\n");
      }
      else if(tries >= 3)
      {
        printf(" You have been locked out. Please contact your administrator for assistance.\n");
        exit(0);
      }
    }
  }
  
  printf("You are now logged in.\n");

  int choice;

  printf("Please select an option from the menu:\n");
  printf("1. Play game\n");
  printf("2. View leaderboard\n");
  printf("3. Exit\n");

  scanf("%d", &choice);

  switch(choice)
  {
    case 1:
      printf("Let's play the game!\n");
      break;
    case 2:
      printf("Here are the top scores:\n");
      printf("1. Player 1: 1000 points\n");
      printf("2. Player 2: 900 points\n");
      printf("3. Player 3: 800 points\n");
      break;
    case 3:
      printf("Goodbye!\n");
      break;
    default:
      printf("Invalid choice. Please try again.\n");
      break;
  }

  return 0;
}
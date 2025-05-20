//FormAI DATASET v1.0 Category: Smart home light control ; Style: protected
#include <stdio.h>

#define PASSWORD "1234"

void turnOnLights(int lights[])

{
  printf("Turning on the lights...\n");

  for(int i = 0; i < 4; i++)
  {
    lights[i] = 1;
  }
}

void turnOffLights(int lights[])
{
  printf("Turning off the lights...\n");

  for(int i = 0; i < 4; i++)
  {
    lights[i] = 0;
  }
}

int main()
{
  int lights[4] = {0, 0, 0, 0};

  int passwordAttempts = 0;

  while(passwordAttempts != 3)
  {
    char inputPassword[5];
    printf("Enter the password (4 digits only): ");
    scanf("%s", inputPassword);

    if(strcmp(inputPassword, PASSWORD) == 0)
    {
      // Correct password
      printf("Access granted!\n");
      break;
    }
    else
    {
      // Wrong password
      printf("Wrong password. Try again.\n");
      passwordAttempts++;

      if(passwordAttempts == 3)
      {
        printf("Too many password attempts. Closing program...\n");
        return 0;
      }
    }
  }

  int userChoice = 0;
  while(userChoice != 3)
  {
    printf("What do you want to do?\n");
    printf("1. Turn on the lights.\n");
    printf("2. Turn off the lights.\n");
    printf("3. Exit.\n");

    scanf("%d", &userChoice);

    switch(userChoice)
    {
      case 1:
        turnOnLights(lights);
        printf("Lights are now on.\n");
        break;
      case 2:
        turnOffLights(lights);
        printf("Lights are now off.\n");
        break;
      case 3:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice. Try again.\n");
        break;
    }
  }

  return 0;
}
//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int steps = 0;
  int heart_rate = 0;
  char mood = 'a';

  printf("Welcome to the C Fitness Tracker!\n");

  while (1)
  {
    printf("Enter the number of steps you took: ");
    scanf("%d", &steps);

    printf("Enter your heart rate: ");
    scanf("%d", &heart_rate);

    printf("Enter your mood (happy, sad, neutral): ");
    scanf(" %c", &mood);

    int total_calories = steps * 20 + heart_rate * 10;

    printf("Total calories burned: %d\n", total_calories);

    printf("Your mood is: %c\n", mood);

    if (mood == 'h')
    {
      printf("Enjoy your day, and keep up the good work!\n");
    }
    else if (mood == 's')
    {
      printf("It's okay to feel sad, but don't dwell on it.\n");
    }
    else
    {
      printf("Neutral as a neutron.\n");
    }

    printf("Would you like to continue? (Y/N): ");
    char answer;

    scanf(" %c", &answer);

    if (answer == 'N')
    {
      break;
    }
  }

  return 0;
}
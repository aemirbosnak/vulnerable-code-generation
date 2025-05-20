//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  // Introduction
  printf("Welcome to the Automated Fortune Teller! I am here to predict your future.\n\n");

  // Ask for user's name
  char name[20];
  printf("What's your name?\n");
  scanf("%s", name);
  printf("Hi %s! Let's begin...\n\n", name);

  // Ask for user's age
  int age;
  printf("How old are you?\n");
  scanf("%d", &age);

  if (age < 18)
    printf("Oh no! You are too young to know your future. Come back in a few years.\n\n");
  else
  {
    // Generate a random number between 1-10
    srand(time(NULL));
    int num = rand() % 10 + 1;

    // Determine the fortune based on the random number
    switch (num)
    {
      case 1:
        printf("Your future holds a great success, %s!\n", name);
        break;
      case 2:
        printf("You'll soon meet the love of your life, %s!\n", name);
        break;
      case 3:
        printf("You'll have a surprising adventure, %s!\n", name);
        break;
      case 4:
        printf("You should be cautious about decisions you make, %s\n", name);
        break;
      case 5:
        printf("Your financial fortune is looking up, %s!\n", name);
        break;
      case 6:
        printf("You'll have an unexpected reunion with an old friend, %s!\n", name);
        break;
      case 7:
        printf("You'll be given a rare opportunity, %s!\n", name);
        break;
      case 8:
        printf("Your future looks bright, %s!\n", name);
        break;
      case 9:
        printf("You'll have an eventful year ahead, %s!\n", name);
        break;
      case 10:
        printf("You'll discover a hidden talent within you, %s!\n", name);
        break;
      default:
        printf("Hmmm, something went wrong and I cannot predict your fortune at this time, %s!\n", name);
    }
  }

  // Farewell
  printf("\nThank you for using the Automated Fortune Teller! I hope you enjoyed it. Goodbye, %s!\n", name);

  return 0;
}
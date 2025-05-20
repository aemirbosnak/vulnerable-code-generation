//GEMINI-pro DATASET v1.0 Category: Automated Fortune Teller ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Get the user's name
  char name[20];
  printf("What is your name?\n");
  scanf("%s", name);

  // Generate a random fortune
  int fortune = rand() % 9;

  // Print the fortune
  switch (fortune) {
    case 0:
      printf("Today is your lucky day, %s!\n", name);
      break;
    case 1:
      printf("You will have a great day, %s!\n", name);
      break;
    case 2:
      printf("You will have a good day, %s!\n", name);
      break;
    case 3:
      printf("You will have an okay day, %s!\n", name);
      break;
    case 4:
      printf("You will have a bad day, %s!\n", name);
      break;
    case 5:
      printf("You will have a terrible day, %s!\n", name);
      break;
    case 6:
      printf("You will have a lucky week, %s!\n", name);
      break;
    case 7:
      printf("You will have a great week, %s!\n", name);
      break;
    case 8:
      printf("You will have a good week, %s!\n", name);
      break;
    default:
      printf("I'm not sure what the future holds for you, %s!\n", name);
  }

  return 0;
}
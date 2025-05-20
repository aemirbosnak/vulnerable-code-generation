//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Initialize variables
  char name[20];
  int age;
  int luckyNum;
  int favoriteNum;
  char answer;

  // Seed random number generator
  srand(time(NULL));

  // Ask for user's name
  printf("Welcome to the Automated Fortune Teller! What is your name?\n");
  scanf("%s", name);

  // Ask for user's age
  printf("Nice to meet you, %s! How old are you?\n", name);
  scanf("%d", &age);

  // Ask for user's lucky number
  printf("What is your lucky number?\n");
  scanf("%d", &luckyNum);

  // Ask for user's favorite number
  printf("What is your favorite number?\n");
  scanf("%d", &favoriteNum);

  // Generate random fortune
  int rnd = rand() % 3;
  switch (rnd) {
    case 0:
      printf("Your lucky number is %d.\n", luckyNum);
      break;
    case 1:
      printf("%d will be your lucky number.\n", favoriteNum);
      break;
    case 2:
      printf("Your fortune is looking bright!\n");
      break;
  }

  // Ask if user wants to play again
  printf("Do you want to try again? (y/n)\n");
  scanf(" %c", &answer);

  // Keep asking until the user says no
  while (answer == 'y') {
    // Ask for user's lucky number
    printf("What is your lucky number?\n");
    scanf("%d", &luckyNum);

    // Ask for user's favorite number
    printf("What is your favorite number?\n");
    scanf("%d", &favoriteNum);

    // Generate random fortune
    rnd = rand() % 3;
    switch (rnd) {
      case 0:
        printf("Your lucky number is %d.\n", luckyNum);
        break;
      case 1:
        printf("%d will be your lucky number.\n", favoriteNum);
        break;
      case 2:
        printf("Your fortune is looking bright!\n");
        break;
    }

    // Ask if user wants to play again
    printf("Do you want to try again? (y/n)\n");
    scanf(" %c", &answer);
  }

  // Say goodbye
  printf("Goodbye, %s! Thanks for playing.\n", name);

  // Exit program
  return 0;
}
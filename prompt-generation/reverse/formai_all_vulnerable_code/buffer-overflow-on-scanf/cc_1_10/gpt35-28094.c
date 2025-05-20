//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Welcome message
  printf("Welcome to the Automated Fortune Teller! \n");

  // Declare variables
  char name[50];
  int age;
  int luckyNumber;
  int birthMonth;

  // Get user information
  printf("What is your name? ");
  scanf("%s", name);

  printf("How old are you? ");
  scanf("%d", &age);

  printf("What is your lucky number? ");
  scanf("%d", &luckyNumber);

  printf("In which month were you born (as a number)? ");
  scanf("%d", &birthMonth);

  // Generate random fortune
  srand(time(NULL));
  int fortuneNumber = rand() % 5;

  // Output the fortune
  printf("\n%s, your fortune for today is: \n", name);

  switch(fortuneNumber) {
    case 0:
      printf("You will find success in the near future. \n");
      break;
    case 1:
      printf("Be prepared for a challenging obstacle in the coming days. \n");
      break;
    case 2:
      printf("Your lucky number %d will bring you good fortune today. \n", luckyNumber);
      break;
    case 3:
      printf("You will meet someone new and interesting today. \n");
      break;
    case 4:
      printf("Your birthday month, %d, is a lucky month for you. \n", birthMonth);
      break;
    default:
      break;
  }

  return 0;
}
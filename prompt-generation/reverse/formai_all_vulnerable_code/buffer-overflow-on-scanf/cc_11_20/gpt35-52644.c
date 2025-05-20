//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: curious
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
  int input = 0;

  printf("Hello and welcome to the automated fortune teller!\n");
  printf("Please enter a number between 1 and 10: ");
  scanf("%d", &input);

  if (input < 1 || input > 10) {
    printf("Oops! That number is out of range. Please try again with a number between 1 and 10.\n");
    return 0;
  }

  // Generate a random number between 1 and 10
  srand(time(NULL)); // seeding the rand() function with the current time
  int answer = rand() % 10 + 1;

  if (input == answer) {
    printf("Congratulations! You have picked the right number.\n");
  } else {
    printf("Unfortunately, that was not the right number. The correct number was %d.\n", answer);
  }

  printf("Would you like to know your fortune? (y/n): ");
  char choice = '\0';
  scanf(" %c", &choice);

  if (choice == 'y') {
    int fortune = rand() % 6 + 1;
    switch (fortune) {
      case 1:
        printf("Your future is looking very bright! Keep following your dreams.\n");
        break;
      case 2:
        printf("You will face some challenges in the near future, but they will ultimately make you stronger.\n");
        break;
      case 3:
        printf("Your love life will become much more fulfilling in the coming months.\n");
        break;
      case 4:
        printf("Your financial situation will improve dramatically in the next year.\n");
        break;
      case 5:
        printf("Be cautious of new people who enter your life; not everyone may have good intentions.\n");
        break;
      case 6:
        printf("Your hard work will pay off in a big way. Keep grinding!\n");
        break;
      default:
        printf("Oops, something went wrong. Please try again later.\n");
        break;
    }
  } else if (choice == 'n') {
    printf("No problem, maybe next time!\n");
  } else {
    printf("Sorry, I didn't understand your choice. Please try again.\n");
  }

  printf("Thanks for playing the automated fortune teller. See you next time!\n");
  return 0;
}
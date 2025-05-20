//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num1, num2, choice;
  char playAgain;

  srand(time(NULL)); // seed the random number generator with the current time

  do {
    printf("Welcome to the Math Game!\n");
    printf("Please choose a difficulty level:\n");
    printf("1. Easy\n");
    printf("2. Medium\n");
    printf("3. Hard\n");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        num1 = rand() % 10 + 1; // generate a random number between 1 and 10
        num2 = rand() % 10 + 1;
        printf("What is %d + %d?\n", num1, num2);
        if(scanf("%d", &num1)!= 1 || num1!= (num1 + num2)) {
          printf("Sorry, that's incorrect.\n");
        } else {
          printf("Correct!\n");
        }
        break;

      case 2:
        num1 = rand() % 50 + 1; // generate a random number between 1 and 50
        num2 = rand() % 50 + 1;
        printf("What is %d * %d?\n", num1, num2);
        if(scanf("%d", &num1)!= 1 || num1!= (num1 * num2)) {
          printf("Sorry, that's incorrect.\n");
        } else {
          printf("Correct!\n");
        }
        break;

      case 3:
        num1 = rand() % 100 + 1; // generate a random number between 1 and 100
        num2 = rand() % 100 + 1;
        printf("What is %d / %d?\n", num1, num2);
        if(scanf("%d", &num1)!= 1 || num1!= (num1 / num2)) {
          printf("Sorry, that's incorrect.\n");
        } else {
          printf("Correct!\n");
        }
        break;

      default:
        printf("Invalid choice. Please try again.\n");
    }

    printf("Do you want to play again? (y/n)\n");
    scanf(" %c", &playAgain);
  } while(playAgain == 'y' || playAgain == 'Y');

  printf("Thanks for playing!\n");
  return 0;
}
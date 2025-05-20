//Falcon-180B DATASET v1.0 Category: Educational ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int num1, num2, operator;
  char playAgain;

  do {
    printf("Welcome to the Math Game!\n");
    printf("Please choose a difficulty level:\n");
    printf("1. Easy\n");
    printf("2. Medium\n");
    printf("3. Hard\n");
    scanf("%d", &num1);

    switch(num1) {
      case 1:
        printf("You have chosen Easy mode.\n");
        break;
      case 2:
        printf("You have chosen Medium mode.\n");
        break;
      case 3:
        printf("You have chosen Hard mode.\n");
        break;
      default:
        printf("Invalid choice. Exiting...\n");
        return 0;
    }

    int min = 1, max = 10;
    if(num1 == 2) {
      min = 1;
      max = 100;
    } else if(num1 == 3) {
      min = 1;
      max = 1000;
    }

    printf("Generating random numbers...\n");
    int num1_rand = rand() % max + min;
    int num2_rand = rand() % max + min;

    printf("Your task is to find the sum of %d and %d.\n", num1_rand, num2_rand);
    scanf("%d", &num2);

    switch(num2) {
      case -1:
        printf("Sorry, you have chosen to quit.\n");
        break;
      default:
        if(num2 == num1_rand + num2_rand) {
          printf("Correct! Great job!\n");
        } else {
          printf("Incorrect. The correct answer is %d.\n", num1_rand + num2_rand);
        }
        break;
    }

    printf("Do you want to play again? (y/n): ");
    scanf(" %c", &playAgain);

  } while(playAgain == 'y' || playAgain == 'Y');

  return 0;
}
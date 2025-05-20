//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  
  //Welcome Message
  printf("Welcome to the Automated Fortune Teller\n\n");

  //Seed the Random Number Generator
  srand(time(NULL));

  //Declare and Initialize Variables
  int fortuneNumber = 0;
  char playAgain = 'y';

  //The Fortune Telling Loop
  while (playAgain == 'y') {

    //Generate a Random Number between 1 and 5
    fortuneNumber = (rand() % 5) + 1;

    //Display the Appropriate Fortune
    switch (fortuneNumber) {
      case 1:
        printf("\nYour future looks bright!");
        break;
      case 2:
        printf("\nYour future is uncertain, but full of possibilities.");
        break;
      case 3:
        printf("\nYou are about to embark on a great adventure!");
        break;
      case 4:
        printf("\nMoney is in your future.");
        break;
      case 5:
        printf("\nA new opportunity will present itself to you soon.");
        break;
      default:
        break;
    }

    //Ask if the User Wants to Play Again
    printf("\n\nDo you want to know your fortune again? (y/n): ");
    scanf(" %c", &playAgain);

    //Clear the Input Buffer
    fflush(stdin);
  }

  //Goodbye Message
  printf("\nThank you for visiting the Automated Fortune Teller.");

  return 0;
}
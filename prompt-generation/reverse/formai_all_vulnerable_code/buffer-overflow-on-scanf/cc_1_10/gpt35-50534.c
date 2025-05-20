//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number
int generateRandomNumber() {
  srand(time(NULL));
  int randNum = rand() % 10 + 1; // Generate random number between 1 and 10
  return randNum;
}

// Function to print fortune based on random number
void printFortune(int randNum) {
  switch (randNum) {
    case 1:
      printf("You will have a great opportunity presented to you today.\n");
      break;
    case 2:
      printf("It may be hard to believe, but money is coming your way.\n");
      break;
    case 3:
      printf("You will find love in unexpected places.\n");
      break;
    case 4:
      printf("Your hard work is about to pay off in a big way.\n");
      break;
    case 5:
      printf("A special someone is thinking of you right now.\n");
      break;
    case 6:
      printf("Your creativity will bring you great success.\n");
      break;
    case 7:
      printf("Your dreams are about to become a reality.\n");
      break;
    case 8:
      printf("You will be offered a once-in-a-lifetime opportunity.\n");
      break;
    case 9:
      printf("A lucky streak is about to come your way.\n");
      break;
    case 10:
      printf("You will overcome your biggest fear and come out stronger.\n");
      break;
    default:
      printf("Error: Something went wrong. Please try again later.\n");
  }
}

// Main function
int main() {
  int userChoice;
  printf("Welcome to the Automated Fortune Teller!\n");
  do {
    printf("\nPlease choose which type of fortune you would like to receive:\n");
    printf("1. Love\n");
    printf("2. Money\n");
    printf("3. Success\n");
    printf("4. Anything\n");
    printf("5. Exit\n");
    printf("Your choice: ");
    scanf("%d", &userChoice);
    switch (userChoice) {
      case 1:
        printf("\nYour love fortune is: ");
        printFortune(generateRandomNumber());
        break;
      case 2:
        printf("\nYour money fortune is: ");
        printFortune(generateRandomNumber());
        break;
      case 3:
        printf("\nYour success fortune is: ");
        printFortune(generateRandomNumber());
        break;
      case 4:
        printf("\nYour fortune is: ");
        printFortune(generateRandomNumber());
        break;
      case 5:
        printf("\nThank you for using the Automated Fortune Teller. Goodbye!\n");
        break;
      default:
        printf("\nInvalid choice. Please try again.\n");
    }
  } while (userChoice != 5);
  return 0;
}
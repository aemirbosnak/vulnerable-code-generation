//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Introductory message
  printf("Good evening, my dear Watson. As you know, I have been keeping a close eye on the stock market lately. Let me show you my latest creation - a C program to track stock prices!\n\n");

  // Stock options menu
  printf("Let me pull up the current options for you:\n");
  printf("1. Apple Inc. (AAPL)\n");
  printf("2. Microsoft Corporation (MSFT)\n");
  printf("3. Amazon.com, Inc. (AMZN)\n");
  printf("4. Tesla, Inc. (TSLA)\n");
  printf("5. General Electric Company (GE)\n");
  printf("Enter the number corresponding to the stock you would like to track: ");

  // Get user input
  int option;
  scanf("%d", &option);

  // Switch statement for stock option chosen by user
  switch(option) {
    case 1:
      printf("\nYou have chosen to track Apple Inc. (AAPL). Here are the stock prices for the last 5 days:\n");
      break;
    case 2:
      printf("\nYou have chosen to track Microsoft Corporation (MSFT). Here are the stock prices for the last 5 days:\n");
      break;
    case 3:
      printf("\nYou have chosen to track Amazon.com, Inc. (AMZN). Here are the stock prices for the last 5 days:\n");
      break;
    case 4:
      printf("\nYou have chosen to track Tesla, Inc. (TSLA). Here are the stock prices for the last 5 days:\n");
      break;
    case 5:
      printf("\nYou have chosen to track General Electric Company (GE). Here are the stock prices for the last 5 days:\n");
      break;
    default:
      printf("\nInvalid selection. Please run the program again and choose a valid option.\n");
      return 0;
  }

  // Generate and display stock prices for the last 5 days
  srand(time(NULL));
  for(int i = 0; i < 5; i++) {
    int price = rand() % 51 + 50; // generate price between 50 and 100 inclusive
    printf("Day %d: $%d\n", i+1, price);
  }

  // Exit message
  printf("\nThank you for using my stock market tracker program. I hope you found it useful, Watson!\n");

  return 0;
}
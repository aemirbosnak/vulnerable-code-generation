//FormAI DATASET v1.0 Category: Stock market tracker ; Style: immersive
#include<stdio.h>
#include<stdlib.h>

int main() {
  // Welcome message
  printf("Welcome to the C stock market tracker!\n\n");

  // User input
  printf("Please enter the number of stocks you would like to track: ");
  int numStocks;
  scanf("%d", &numStocks);

  // Allocate memory for the array of stock prices
  float* stockPrices = (float*) malloc(numStocks * sizeof(float));

  // Input loop for stock prices
  for(int i = 1; i <= numStocks; i++) {
    printf("Enter the price of stock %d: ", i);
    scanf("%f", &stockPrices[i-1]);
  }

  // Menu loop for different options
  int choice;
  do {
    printf("\nWhat would you like to do?\n");
    printf("1. Display all stock prices\n");
    printf("2. Display highest stock price\n");
    printf("3. Calculate average stock price\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        // Display all stock prices
        printf("\nStock Prices:\n");
        for(int i = 0; i < numStocks; i++) {
          printf("%.2f\n", stockPrices[i]);
        }
        break;

      case 2:
        // Display highest stock price
        printf("\nHighest stock price: ");
        float maxPrice = stockPrices[0];
        for(int i = 1; i < numStocks; i++) {
          if(stockPrices[i] > maxPrice) {
            maxPrice = stockPrices[i];
          }
        }
        printf("%.2f\n", maxPrice);
        break;

      case 3:
        // Calculate average stock price
        printf("\nAverage stock price: ");
        float sum = 0;
        for(int i = 0; i < numStocks; i++) {
          sum += stockPrices[i];
        }
        printf("%.2f\n", sum/numStocks);
        break;

      case 4:
        // Exit program
        printf("\nThank you for using the C stock market tracker!\n");
        break;

      default:
        printf("\nInvalid choice.\n");
    }
  } while(choice != 4);

  // Free memory allocated for the array of stock prices
  free(stockPrices);

  return 0;
}
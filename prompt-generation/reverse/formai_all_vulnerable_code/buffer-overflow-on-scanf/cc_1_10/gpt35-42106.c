//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Sherlock Holmes
//I say, Watson, we must investigate the latest movements in the stock market. 
//This program will be our guide, tracking the prices of various companies.

#include <stdio.h>
#include <stdlib.h>

int main() {
  
  //Let us first establish an array to hold the current stock prices for a few chosen companies.
  double stockPrices[5] = {50.27, 101.56, 30.64, 72.98, 88.45};

  int choice;
  
  //We must now ask the user for their desired course of action.
  printf("Greetings, my dear Watson. Please enter a number to choose your desired action:\n");
  printf("1. View current stock prices\n");
  printf("2. Update a stock price\n");
  printf("3. Exit the program\n");
  scanf("%d", &choice);
  
  //We shall then provide a switch-case structure to handle their decision.
  switch (choice) {
    case 1:
      printf("The current stock prices are as follows:\n");
      printf("Company A: %.2lf\n", stockPrices[0]);
      printf("Company B: %.2lf\n", stockPrices[1]);
      printf("Company C: %.2lf\n", stockPrices[2]);
      printf("Company D: %.2lf\n", stockPrices[3]);
      printf("Company E: %.2lf\n", stockPrices[4]);
      break;
      
    case 2:
      printf("Which company's stock price would you like to update? Please enter a number:\n");
      printf("1. Company A\n");
      printf("2. Company B\n");
      printf("3. Company C\n");
      printf("4. Company D\n");
      printf("5. Company E\n");
      scanf("%d", &choice);
      
      if (choice < 1 || choice > 5) {
        printf("I'm sorry, that is not a valid choice. Please try again.\n");
        break;
      }
      
      double updatedPrice;
      printf("Please enter the new stock price for the selected company:\n");
      scanf("%lf", &updatedPrice);
      stockPrices[choice - 1] = updatedPrice;
      
      printf("The new stock prices are as follows:\n");
      printf("Company A: %.2lf\n", stockPrices[0]);
      printf("Company B: %.2lf\n", stockPrices[1]);
      printf("Company C: %.2lf\n", stockPrices[2]);
      printf("Company D: %.2lf\n", stockPrices[3]);
      printf("Company E: %.2lf\n", stockPrices[4]);
      break;
    
    case 3:
      printf("Farewell, my dear Watson. Until next time.\n");
      break;
      
    default:
      printf("I'm sorry, that is not a valid choice. Please try again.\n");
  }

  return 0;
}
//FormAI DATASET v1.0 Category: Stock market tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 10 // Maximum number of stocks that can be tracked
#define STOCK_NAME_LENGTH 20 // Maximum length of stock name
#define MAX_PRICE 1000 // Maximum stock price

typedef struct {
  char name[STOCK_NAME_LENGTH];
  int price;
} Stock;

Stock stocks[MAX_STOCKS];
int numStocks = 0;

// Function to add a new stock to the tracker
void addStock() {
  if (numStocks == MAX_STOCKS) {
    printf("Maximum number of stocks reached.\n");
    return;
  }
  
  Stock newStock;
  printf("Enter name of stock: ");
  scanf("%s", newStock.name);
  printf("Enter current price of stock: ");
  scanf("%d", &newStock.price);
  stocks[numStocks++] = newStock;
  
  printf("%s added to tracker.\n", newStock.name);
}

// Function to remove a stock from the tracker
void removeStock() {
  if (numStocks == 0) {
    printf("No stocks to remove.\n");
    return;
  }
  
  printf("Enter name of stock to remove: ");
  char removeName[STOCK_NAME_LENGTH];
  scanf("%s", removeName);
  
  int removeIndex = -1;
  for (int i = 0; i < numStocks; i++) {
    if (strcmp(stocks[i].name, removeName) == 0) {
      removeIndex = i;
      break;
    }
  }
  
  if (removeIndex == -1) {
    printf("%s not found in tracker.\n", removeName);
    return;
  }
  
  for (int i = removeIndex; i < numStocks - 1; i++) {
    stocks[i] = stocks[i+1];
  }
  
  numStocks--;
  printf("%s removed from tracker.\n", removeName);
}

// Function to update the prices of all stocks in the tracker with random values
void updatePrices() {
  srand(time(NULL)); // Seed the random number generator with the current time
  
  for (int i = 0; i < numStocks; i++) {
    int priceChange = rand() % 21 - 10; // Generate a random number between -10 and 10
    stocks[i].price += priceChange;
    
    // Ensure the stock price remains within the bounds 0 and MAX_PRICE
    if (stocks[i].price < 0) {
      stocks[i].price = 0;
    } else if (stocks[i].price > MAX_PRICE) {
      stocks[i].price = MAX_PRICE;
    }
  }
  
  printf("Stock prices updated.\n");
}

// Function to print the current prices of all stocks in the tracker
void printPrices() {
  if (numStocks == 0) {
    printf("No stocks to show.\n");
    return;
  }
  
  printf("Current stock prices:\n");
  for (int i = 0; i < numStocks; i++) {
    printf("%s: $%d\n", stocks[i].name, stocks[i].price);
  }
}

int main() {
  while (1) {
    printf("\n");
    printf("1. Add stock\n");
    printf("2. Remove stock\n");
    printf("3. Update prices\n");
    printf("4. Print prices\n");
    printf("5. Quit\n");
    
    int choice;
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
      case 1:
        addStock();
        break;
      case 2:
        removeStock();
        break;
      case 3:
        updatePrices();
        break;
      case 4:
        printPrices();
        break;
      case 5:
        printf("Goodbye!\n");
        return 0;
      default:
        printf("Invalid choice.\n");
    }
  }
}
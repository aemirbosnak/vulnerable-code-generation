//FormAI DATASET v1.0 Category: Stock market tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_STOCKS 100

struct Stock {
  char name[20];
  float price;
};

int numStocks = 0;
struct Stock stocks[MAX_STOCKS];

void addStock() {
  char name[20];
  float price;
  
  printf("Enter stock name: ");
  scanf("%s", name);
  printf("Enter stock price: ");
  scanf("%f", &price);
  
  struct Stock newStock = {name, price};
  stocks[numStocks++] = newStock;
}

void removeStock() {
  int index;
  printf("Enter index of stock to remove (0-%d): ", numStocks-1);
  scanf("%d", &index);
  
  if (index < 0 || index >= numStocks) {
    printf("Invalid index!\n");
    return;
  }
  
  for (int i = index; i < numStocks-1; i++) {
    stocks[i] = stocks[i+1];
  }
  
  numStocks--;
}

void printStocks() {
  printf("Stocks:\n");
  for (int i = 0; i < numStocks; i++) {
    printf("%d: %s - $%.2f\n", i, stocks[i].name, stocks[i].price);
  }
}

void printMenu() {
  printf("\nMenu:\n");
  printf("1. Add a stock\n");
  printf("2. Remove a stock\n");
  printf("3. View all stocks\n");
  printf("4. Exit\n");
}

int main() {
  int choice;
  
  do {
    printMenu();
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
      case 1:
        addStock();
        break;
      case 2:
        removeStock();
        break;
      case 3:
        printStocks();
        break;
      case 4:
        printf("Goodbye!\n");
        break;
      default:
        printf("Invalid choice!\n");
        break;
    }
  } while (choice != 4);
  
  return 0;
}
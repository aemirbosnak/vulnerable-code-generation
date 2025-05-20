//FormAI DATASET v1.0 Category: Stock market tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STOCKS 10
#define MAX_NAME_LEN 50

typedef struct {
  char name[MAX_NAME_LEN];
  float price;
  float change;
} Stock;

Stock portfolio[MAX_STOCKS];
int numStocks = 0;

void addStock() {
  if (numStocks == MAX_STOCKS) {
    printf("Portfolio is already full.\n");
    return;
  }

  Stock newStock;
  printf("Enter stock name: ");
  scanf("%s", newStock.name);
  printf("Enter current stock price: ");
  scanf("%f", &newStock.price);
  printf("Enter percentage change (+/-): ");
  scanf("%f", &newStock.change);
  portfolio[numStocks++] = newStock;
}

void removeStock() {
  if (numStocks == 0) {
    printf("Portfolio is empty.\n");
    return;
  }

  char name[MAX_NAME_LEN];
  printf("Enter name of stock to remove: ");
  scanf("%s", name);

  int i, index = -1;
  for (i = 0; i < numStocks; i++) {
    if (strcmp(name, portfolio[i].name) == 0) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    printf("Stock not found.\n");
    return;
  }

  for (i = index; i < numStocks - 1; i++) {
    portfolio[i] = portfolio[i+1];
  }
  numStocks--;
  printf("%s has been removed from the portfolio.\n", name);
}

void updateStock() {
  if (numStocks == 0) {
    printf("Portfolio is empty.\n");
    return;
  }

  char name[MAX_NAME_LEN];
  printf("Enter name of stock to update: ");
  scanf("%s", name);

  int i, index = -1;
  for (i = 0; i < numStocks; i++) {
    if (strcmp(name, portfolio[i].name) == 0) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    printf("Stock not found.\n");
    return;
  }

  printf("Enter new price: ");
  scanf("%f", &portfolio[index].price);
  printf("Enter new percentage change (+/-): ");
  scanf("%f", &portfolio[index].change);
  printf("%s has been update.\n", name);
}

void displayPortfolio() {
  if (numStocks == 0) {
    printf("Portfolio is empty.\n");
    return;
  }

  printf("\nPortfolio:\n");
  printf("Name\tPrice\tChange\n");
  int i;
  for (i = 0; i < numStocks; i++) {
    printf("%s\t%.2f\t%.2f%%\n", portfolio[i].name, portfolio[i].price, portfolio[i].change);
  }
}

int main() {
  printf("Welcome to your stock market tracker!\n");

  while (1) {
    printf("\nWhat would you like to do?\n");
    printf("1. Add stock\n");
    printf("2. Remove stock\n");
    printf("3. Update stock\n");
    printf("4. Display portfolio\n");
    printf("5. Exit\n");

    int choice;
    printf("Enter choice (1-5): ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addStock();
        break;
      case 2:
        removeStock();
        break;
      case 3:
        updateStock();
        break;
      case 4:
        displayPortfolio();
        break;
      case 5:
        printf("Goodbye!\n");
        exit(0);
      default:
        printf("Invalid choice.\n");
    }
  }
  return 0;
}
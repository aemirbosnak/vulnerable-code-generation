//FormAI DATASET v1.0 Category: Stock market tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10 // Maximum number of stocks that can be tracked

struct stock {
  char name[20];
  float price;
};

void print_menu() {
  printf("1. Add stock\n");
  printf("2. Delete stock\n");
  printf("3. Update stock price\n");
  printf("4. Show all stocks\n");
  printf("5. Exit\n");
}

int main() {
  struct stock stocks[MAX_STOCKS];
  int num_stocks = 0;
  int choice;

  while (1) {
    print_menu();
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        if (num_stocks == MAX_STOCKS) {
          printf("Maximum number of stocks reached\n");
        } else {
          struct stock new_stock;
          printf("Enter stock name: ");
          scanf("%s", new_stock.name);
          printf("Enter stock price: ");
          scanf("%f", &new_stock.price);
          stocks[num_stocks++] = new_stock;
          printf("Stock added successfully\n");
        }
        break;
      case 2:
        if (num_stocks == 0) {
          printf("There are no stocks to delete\n");
        } else {
          char name[20];
          printf("Enter stock name to delete: ");
          scanf("%s", name);
          int found = 0;
          for (int i = 0; i < num_stocks; i++) {
            if (strcmp(stocks[i].name, name) == 0) {
              found = 1;
              for (int j = i; j < num_stocks - 1; j++) {
                stocks[j] = stocks[j + 1];
              }
              num_stocks--;
              printf("Stock deleted successfully\n");
              break;
            }
          }
          if (!found) {
            printf("Stock not found\n");
          }
        }
        break;
      case 3:
        if (num_stocks == 0) {
          printf("There are no stocks to update\n");
        } else {
          char name[20];
          printf("Enter stock name to update: ");
          scanf("%s", name);
          int found = 0;
          for (int i = 0; i < num_stocks; i++) {
            if (strcmp(stocks[i].name, name) == 0) {
              found = 1;
              printf("Enter new stock price: ");
              scanf("%f", &stocks[i].price);
              printf("Stock updated successfully\n");
              break;
            }
          }
          if (!found) {
            printf("Stock not found\n");
          }
        }
        break;
      case 4:
        if (num_stocks == 0) {
          printf("There are no stocks to show\n");
        } else {
          printf("Name\tPrice\n");
          for (int i = 0; i < num_stocks; i++) {
            printf("%s\t%.2f\n", stocks[i].name, stocks[i].price);
          }
        }
        break;
      case 5:
        printf("Exiting...\n");
        exit(0);
      default:
        printf("Invalid choice\n");
        break;
    }
  }
  return 0;
}
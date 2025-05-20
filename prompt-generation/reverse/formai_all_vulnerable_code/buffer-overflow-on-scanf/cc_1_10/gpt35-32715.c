//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10

typedef struct Item {
  char name[20];
  int price;
  int quantity;
} Item;

void printMenu(Item items[]) {
  printf("Welcome to the Cafe Billing System\n");
  printf("-------------------------------\n");
  printf("Item Name     | Price (in coins)\n");
  printf("-------------------------------\n");
  for (int i = 0; i < MAX_ITEMS; i++) {
    printf("%-14s| %d\n", items[i].name, items[i].price);
  }
  printf("-------------------------------\n");
}

void printBill(Item items[], int quantities[]) {
  int total = 0;
  printf("Your Bill:\n");
  printf("-----------\n");
  for (int i = 0; i < MAX_ITEMS; i++) {
    if (quantities[i] > 0) {
      printf("%-17s x%d = %d\n", items[i].name, quantities[i], items[i].price*quantities[i]);
      total += items[i].price*quantities[i];
    }
  }
  printf("-----------\n");
  printf("Total: %d coins\n", total);
}

int main() {

  Item items[MAX_ITEMS] = {
    {"Coffee", 10, 0},
    {"Tea", 8, 0},
    {"Burger", 15, 0},
    {"Fries", 7, 0},
    {"Cake", 12, 0},
    {"Muffin", 6, 0},
    {"Soda", 5, 0},
    {"Water", 3, 0},
    {"Donut", 5, 0},
    {"Bagel", 7, 0},
  };
  
  int quantities[MAX_ITEMS] = {0};

  char order[20];
  int quantity;
  int isDone = 0;

  printf("Welcome to our cafe! What is your name?\n");
  char name[20];
  scanf("%s", name);
  printf("Hello, %s! Here is our menu:\n", name);

  while (!isDone) {
    printMenu(items);

    printf("What would you like to order? (type 'done' when finished)\n");
    scanf("%s", order);

    if (!strcmp(order, "done")) {
      isDone = 1;
      printf("Thank you for your order! Here is your bill:\n");
      printBill(items, quantities);
    }
    else {
      printf("How many would you like?\n");
      scanf("%d", &quantity);
      
      for (int i = 0; i < MAX_ITEMS; i++) {
        if (!strcmp(order, items[i].name)) {
          quantities[i] += quantity;
          break;
        }
      }
    }
  }

  return 0;
}
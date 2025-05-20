//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cafeItem {
  char name[30];
  int price;
  int quantity;
};

struct cafeOrder {
  struct cafeItem items[10];
  int numItems;
  int totalAmount;
};

void printMenu() {
  printf("Cafe Menu:\n");
  printf("--------------------\n");
  printf("Name\t\tPrice\n");
  printf("--------------------\n");
  printf("Espresso\t$2.00\n");
  printf("Americano\t$2.50\n");
  printf("Latte\t\t$3.00\n");
  printf("Cappuccino\t$3.50\n");
  printf("Mocha\t\t$4.00\n");
  printf("--------------------\n");
}

int main() {
  struct cafeOrder order;
  order.numItems = 0;
  order.totalAmount = 0;

  int choice;
  do {
    printMenu();

    printf("Enter your choice (1-5, 0 to exit): ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      strcpy(order.items[order.numItems].name, "Espresso");
      order.items[order.numItems].price = 200;
      order.items[order.numItems].quantity = 1;
      order.numItems++;
      order.totalAmount += 200;
      break;
    case 2:
      strcpy(order.items[order.numItems].name, "Americano");
      order.items[order.numItems].price = 250;
      order.items[order.numItems].quantity = 1;
      order.numItems++;
      order.totalAmount += 250;
      break;
    case 3:
      strcpy(order.items[order.numItems].name, "Latte");
      order.items[order.numItems].price = 300;
      order.items[order.numItems].quantity = 1;
      order.numItems++;
      order.totalAmount += 300;
      break;
    case 4:
      strcpy(order.items[order.numItems].name, "Cappuccino");
      order.items[order.numItems].price = 350;
      order.items[order.numItems].quantity = 1;
      order.numItems++;
      order.totalAmount += 350;
      break;
    case 5:
      strcpy(order.items[order.numItems].name, "Mocha");
      order.items[order.numItems].price = 400;
      order.items[order.numItems].quantity = 1;
      order.numItems++;
      order.totalAmount += 400;
      break;
    }
  } while (choice != 0);

  printf("Your order:\n");
  printf("--------------------\n");
  printf("Name\t\tQuantity\tPrice\n");
  printf("--------------------\n");
  for (int i = 0; i < order.numItems; i++) {
    printf("%s\t\t%d\t\t$%.2f\n", order.items[i].name, order.items[i].quantity,
           order.items[i].price / 100.0);
  }
  printf("--------------------\n");
  printf("Total Amount: $%.2f\n", order.totalAmount / 100.0);

  return 0;
}
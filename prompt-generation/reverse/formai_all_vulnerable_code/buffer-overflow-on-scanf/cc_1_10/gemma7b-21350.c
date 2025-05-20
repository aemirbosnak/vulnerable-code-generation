//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
  char name[20];
  int quantity;
  double price;
} Item;

Item items[MAX_ITEMS];

void addItem(char name[], int quantity, double price) {
  for (int i = 0; i < MAX_ITEMS; i++) {
    if (items[i].name[0] == '\0') {
      items[i].name[0] = name[0];
      items[i].quantity = quantity;
      items[i].price = price;
      return;
    }
  }

  printf("Error: Item limit reached.\n");
}

void displayItems() {
  for (int i = 0; i < MAX_ITEMS; i++) {
    if (items[i].name[0] != '\0') {
      printf("%s: %d, $%.2lf\n", items[i].name, items[i].quantity, items[i].price);
    }
  }
}

double calculateTotal(int quantity, double price) {
  return quantity * price;
}

void generateBill() {
  int totalQuantity = 0;
  double totalCost = 0.0;

  printf("Items:\n");
  displayItems();

  printf("\nTotal quantity: %d\n", totalQuantity);
  printf("Total cost: $%.2lf\n", totalCost);

  printf("\nPayment:\n");
  double payment = 0.0;
  printf("Enter payment: $");
  scanf("%lf", &payment);

  double change = payment - totalCost;

  printf("\nChange: $%.2lf\n", change);
  printf("Thank you for your visit!\n");
}

int main() {
  addItem("Coffee", 5, 2.50);
  addItem("Tea", 3, 1.75);
  addItem("Juice", 2, 1.25);

  generateBill();

  return 0;
}
//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
  printf("Welcome to Caffeinated Dreams!\n");
  printf("-------------------\n");
  printf("1. Espresso\n");
  printf("2. Latte\n");
  printf("3. Cappuccino\n");
  printf("4. Mocha\n");
  printf("5. Frappuccino\n");
  printf("-------------------\n");
  printf("Please select a drink:");
}

void calculateBill() {
  int choice;
  float price = 0;

  displayMenu();
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      price = 3.50;
      break;
    case 2:
      price = 4.00;
      break;
    case 3:
      price = 4.50;
      break;
    case 4:
      price = 5.00;
      break;
    case 5:
      price = 5.50;
      break;
    default:
      printf("Invalid selection.\n");
  }

  printf("Your total bill is: $%.2f\n", price);
}

int main() {
  calculateBill();

  return 0;
}
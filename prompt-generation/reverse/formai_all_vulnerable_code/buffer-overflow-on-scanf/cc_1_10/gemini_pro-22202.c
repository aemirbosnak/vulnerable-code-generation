//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Define the menu items
#define ITEM_COFFEE 1
#define ITEM_TEA 2
#define ITEM_CAKE 3
#define ITEM_SANDWICH 4
#define ITEM_EXIT 5

// Define the menu prices
#define PRICE_COFFEE 2.50
#define PRICE_TEA 1.50
#define PRICE_CAKE 3.00
#define PRICE_SANDWICH 4.00

// Function to display the menu
void displayMenu() {
  printf("\nWelcome to the Cafe Billing System!\n");
  printf("---------------------------------\n");
  printf("1. Coffee - $%.2f\n", PRICE_COFFEE);
  printf("2. Tea - $%.2f\n", PRICE_TEA);
  printf("3. Cake - $%.2f\n", PRICE_CAKE);
  printf("4. Sandwich - $%.2f\n", PRICE_SANDWICH);
  printf("5. Exit\n");
  printf("---------------------------------\n");
}

// Function to get the user's choice
int getChoice() {
  int choice;
  printf("Enter your choice: ");
  scanf("%d", &choice);
  return choice;
}

// Function to calculate the total bill
double calculateBill(int items[], int quantities[]) {
  double total = 0.0;
  for (int i = 0; i < 5; i++) {
    total += items[i] * quantities[i];
  }
  return total;
}

// Function to print the bill
void printBill(int items[], int quantities[], double total) {
  printf("\nYour Bill:\n");
  printf("---------------------------------\n");
  for (int i = 0; i < 5; i++) {
    if (items[i] > 0) {
      printf("%d %s - $%.2f x %d = $%.2f\n", items[i], items[i] == ITEM_COFFEE ? "Coffee" : items[i] == ITEM_TEA ? "Tea" : items[i] == ITEM_CAKE ? "Cake" : "Sandwich", items[i] == ITEM_COFFEE ? PRICE_COFFEE : items[i] == ITEM_TEA ? PRICE_TEA : items[i] == ITEM_CAKE ? PRICE_CAKE : PRICE_SANDWICH, quantities[i], items[i] * quantities[i]);
    }
  }
  printf("---------------------------------\n");
  printf("Total: $%.2f\n", total);
}

// Main function
int main() {
  int items[5] = {0, 0, 0, 0, 0}; // Array to store the selected items
  int quantities[5] = {0, 0, 0, 0, 0}; // Array to store the quantities of each item
  double total = 0.0; // Variable to store the total bill

  int choice;
  do {
    displayMenu();
    choice = getChoice();
    switch (choice) {
      case ITEM_COFFEE:
        printf("How many coffees would you like? ");
        scanf("%d", &quantities[ITEM_COFFEE - 1]);
        items[ITEM_COFFEE - 1] = ITEM_COFFEE;
        break;
      case ITEM_TEA:
        printf("How many teas would you like? ");
        scanf("%d", &quantities[ITEM_TEA - 1]);
        items[ITEM_TEA - 1] = ITEM_TEA;
        break;
      case ITEM_CAKE:
        printf("How many cakes would you like? ");
        scanf("%d", &quantities[ITEM_CAKE - 1]);
        items[ITEM_CAKE - 1] = ITEM_CAKE;
        break;
      case ITEM_SANDWICH:
        printf("How many sandwiches would you like? ");
        scanf("%d", &quantities[ITEM_SANDWICH - 1]);
        items[ITEM_SANDWICH - 1] = ITEM_SANDWICH;
        break;
      case ITEM_EXIT:
        break;
      default:
        printf("Invalid choice. Please enter a number between 1 and 5.\n");
    }
  } while (choice != ITEM_EXIT);

  total = calculateBill(items, quantities);
  printBill(items, quantities, total);

  return 0;
}
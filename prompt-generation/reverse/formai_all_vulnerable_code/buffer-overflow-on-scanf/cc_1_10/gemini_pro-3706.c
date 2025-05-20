//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: energetic
// Cafe Billing System: A Whirlwind of Coffee and Cashflow

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Menu items and prices
char menu[][20] = {"Espresso", "Americano", "Latte", "Cappuccino", "Mocha"};
int prices[] = {2, 3, 4, 5, 6};
int quantities[5];

// Function to display the menu
void displayMenu() {
  printf("\n** Welcome to JavaBeans Cafe! **\n\n");
  printf("Our tantalizing menu:\n");
  for (int i = 0; i < 5; i++) {
    printf("%d. %s - $%d\n", i + 1, menu[i], prices[i]);
  }
  printf("\n");
}

// Function to take order and calculate total
void takeOrder() {
  int choice, quantity;
  float total = 0.0;
  char confirm;

  printf("Brew up your order! Enter item numbers and quantities:\n");
  for (int i = 0; i < 5; i++) {
    printf("%s: ", menu[i]);
    scanf("%d", &quantity);
    quantities[i] = quantity;
    total += prices[i] * quantity;
  }

  printf("\nYour java jolt total: $%.2f\n", total);
  printf("Confirm your caffeine fix? (Y/N): ");
  scanf(" %c", &confirm);

  if (confirm == 'Y' || confirm == 'y') {
    printf("\nYour order is on its way, lightning-fast!\n");
  } else {
    printf("\nNo worries, brew again next time!\n");
  }
}

// Main event, where the coffee magic happens
int main() {
  char choice;

  // Welcome note
  printf("** Welcome to JavaBeans Cafe, where every sip is a jolt of joy! **\n\n");

  // Menu and order flow
  do {
    displayMenu();
    takeOrder();

    // Ask for continuation
    printf("\nNeed more caffeine? (Y/N): ");
    scanf(" %c", &choice);
  } while (choice == 'Y' || choice == 'y');

  // Farewell message
  printf("\nThanks for sipping with us! May your caffeine adventures be epic.\n\n");

  return 0;
}
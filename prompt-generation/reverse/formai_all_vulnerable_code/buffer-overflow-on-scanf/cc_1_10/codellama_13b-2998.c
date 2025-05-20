//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: secure
/*
 * MEDICAL STORE MANAGEMENT SYSTEM
 *
 * This program allows the user to manage the inventory and transactions
 * of a medical store.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the struct for the inventory
typedef struct {
  char name[50];
  int quantity;
  float price;
} inventory;

// Define the struct for the transactions
typedef struct {
  char date[10];
  char item[50];
  int quantity;
  float price;
} transaction;

// Function to add an inventory item
void add_inventory(inventory *items, int *num_items) {
  // Get the name of the item
  printf("Enter the name of the item: ");
  fgets(items[*num_items].name, 50, stdin);
  // Get the quantity of the item
  printf("Enter the quantity of the item: ");
  scanf("%d", &items[*num_items].quantity);
  // Get the price of the item
  printf("Enter the price of the item: ");
  scanf("%f", &items[*num_items].price);
  // Increment the number of items
  (*num_items)++;
}

// Function to add a transaction
void add_transaction(transaction *transactions, int *num_transactions, inventory *items, int num_items) {
  // Get the date of the transaction
  printf("Enter the date of the transaction (YYYY-MM-DD): ");
  fgets(transactions[*num_transactions].date, 10, stdin);
  // Get the name of the item
  printf("Enter the name of the item: ");
  fgets(transactions[*num_transactions].item, 50, stdin);
  // Get the quantity of the item
  printf("Enter the quantity of the item: ");
  scanf("%d", &transactions[*num_transactions].quantity);
  // Get the price of the item
  printf("Enter the price of the item: ");
  scanf("%f", &transactions[*num_transactions].price);
  // Increment the number of transactions
  (*num_transactions)++;
}

// Function to display the inventory
void display_inventory(inventory *items, int num_items) {
  // Loop through all the items
  for (int i = 0; i < num_items; i++) {
    // Print the name, quantity, and price of the item
    printf("%s: %d x $%.2f\n", items[i].name, items[i].quantity, items[i].price);
  }
}

// Function to display the transactions
void display_transactions(transaction *transactions, int num_transactions, inventory *items, int num_items) {
  // Loop through all the transactions
  for (int i = 0; i < num_transactions; i++) {
    // Print the date, name, quantity, and price of the item
    printf("%s: %s: %d x $%.2f\n", transactions[i].date, transactions[i].item, transactions[i].quantity, transactions[i].price);
  }
}

int main() {
  // Initialize the inventory and transaction arrays
  inventory items[100];
  int num_items = 0;
  transaction transactions[100];
  int num_transactions = 0;

  // Loop until the user quits
  while (1) {
    // Display the menu
    printf("Welcome to the Medical Store Management System\n");
    printf("1. Add inventory\n");
    printf("2. Add transaction\n");
    printf("3. Display inventory\n");
    printf("4. Display transactions\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");

    // Get the user's choice
    int choice;
    scanf("%d", &choice);

    // Perform the selected action
    switch (choice) {
      case 1:
        add_inventory(&items, &num_items);
        break;
      case 2:
        add_transaction(&transactions, &num_transactions, &items, num_items);
        break;
      case 3:
        display_inventory(items, num_items);
        break;
      case 4:
        display_transactions(transactions, num_transactions, items, num_items);
        break;
      case 5:
        return 0;
      default:
        printf("Invalid choice\n");
        break;
    }
  }

  return 0;
}
//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

struct coffee_item { 
  char name[50];
  float price;
  int quantity;
};

int main() {
  // Create menu items
  struct coffee_item americano = {"Americano", 2.50, 0}; 
  struct coffee_item latte = {"Latte", 3.75, 0}; 
  struct coffee_item cappuccino = {"Cappuccino", 3.00, 0};
  
  // Define program variables
  int selection, quantity_input, payment, total_price = 0, items_ordered = 0;
  char exit_input;

  // Display menu
  printf("Welcome to the Linus Torvalds Cafe!\n");
  printf("%-15s%-15s%s\n", "Item", "Price", "Quantity");
  printf("%-15s$%-14.2f%d\n", americano.name, americano.price, americano.quantity);
  printf("%-15s$%-14.2f%d\n", latte.name, latte.price, latte.quantity);
  printf("%-15s$%-14.2f%d\n", cappuccino.name, cappuccino.price, cappuccino.quantity);

  // User selection loop
  do {
    printf("\nEnter the number of the item you would like to order (0 to exit): ");
    scanf("%d", &selection);
    
    // Validate selection
    if (selection < 0 || selection > 3) {
      printf("\nInvalid selection. Please select a valid item.\n");
      continue;
    }
    
    // Exit program if selection is 0
    if (selection == 0) {
      printf("\nThank you for ordering at Linus Torvalds Cafe!\n");
      return 0;
    }
    
    // Get quantity input and validate
    printf("Enter the quantity you would like to order: ");
    scanf("%d", &quantity_input);
    if (quantity_input < 1) {
      printf("\nInvalid quantity. Please enter a valid quantity.\n");
      continue;
    }
    
    // Add item to total and update quantity
    switch(selection) {
      case 1:
        total_price += (americano.price * quantity_input);
        americano.quantity += quantity_input;
        break;
      case 2:
        total_price += (latte.price * quantity_input);
        latte.quantity += quantity_input;
        break;
      case 3:
        total_price += (cappuccino.price * quantity_input);
        cappuccino.quantity += quantity_input;
        break;
    }
    
    // Update number of items ordered
    items_ordered += quantity_input;
    
    // Confirm order
    printf("\nYou have ordered %d %s. Your total is now $%.2f.\n", quantity_input, selection == 1 ? "Americano" : selection == 2 ? "Latte" : "Cappuccino", total_price);

    // Ask user if they want to order something else
    printf("Would you like to order anything else? (Y/N): ");
    scanf(" %c", &exit_input);
    if (exit_input == 'N' || exit_input == 'n') {
      // Process payment
      printf("\nYou have ordered %d item(s) and your total is $%.2f.\n", items_ordered, total_price);
      printf("Please enter your payment amount: $");
      scanf("%d", &payment);
      
      // Validate payment
      if (payment < total_price) {
        printf("\nInsufficient payment. Please enter the correct amount.\n");
        continue;
      }
      
      // Calculate and print change
      printf("Your change is $%.2f. Thank you for ordering at Linus Torvalds Cafe!\n", payment - total_price);
      return 0;
    }
    
  } while(1); // Infinite loop to keep program running

  return 0; // End program
}
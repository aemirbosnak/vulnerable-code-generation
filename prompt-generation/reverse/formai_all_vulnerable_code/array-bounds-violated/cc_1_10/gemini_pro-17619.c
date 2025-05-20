//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// Define the menu items and their prices
struct MenuItem {
  char name[50];
  float price;
};

struct MenuItem menuItems[] = {
  {"Coffee", 2.50},
  {"Tea", 2.00},
  {"Soda", 1.50},
  {"Water", 1.00},
  {"Cake", 3.00},
  {"Pie", 3.50}
};

// Define the customer order
struct CustomerOrder {
  char name[50];
  int numItems;
  struct MenuItem items[10];
};

// Define the cafe billing system
struct CafeBillingSystem {
  int numCustomers;
  struct CustomerOrder customers[100];
};

// Function to print the menu
void printMenu() {
  printf("Menu:\n");
  for (int i = 0; i < 6; i++) {
    printf("%d. %s - $%.2f\n", i + 1, menuItems[i].name, menuItems[i].price);
  }
}

// Function to take the customer order
struct CustomerOrder takeOrder() {
  struct CustomerOrder order;
  
  printf("Enter your name: ");
  scanf("%s", order.name);
  
  printf("How many items would you like to order? ");
  scanf("%d", &order.numItems);
  
  for (int i = 0; i < order.numItems; i++) {
    int itemNum;
    printf("Enter the number of the item you would like to order: ");
    scanf("%d", &itemNum);
    
    order.items[i] = menuItems[itemNum - 1];
  }
  
  return order;
}

// Function to calculate the total bill
float calculateTotalBill(struct CustomerOrder order) {
  float total = 0.0;
  for (int i = 0; i < order.numItems; i++) {
    total += order.items[i].price;
  }
  return total;
}

// Function to print the receipt
void printReceipt(struct CustomerOrder order, float total) {
  printf("Receipt:\n");
  printf("Customer: %s\n", order.name);
  for (int i = 0; i < order.numItems; i++) {
    printf("%s - $%.2f\n", order.items[i].name, order.items[i].price);
  }
  printf("Total: $%.2f\n", total);
}

// Main function
int main() {
  // Create a new cafe billing system
  struct CafeBillingSystem billingSystem;
  billingSystem.numCustomers = 0;
  
  // Print the menu
  printMenu();
  
  // Take the customer order
  struct CustomerOrder order = takeOrder();
  
  // Calculate the total bill
  float total = calculateTotalBill(order);
  
  // Print the receipt
  printReceipt(order, total);
  
  return 0;
}
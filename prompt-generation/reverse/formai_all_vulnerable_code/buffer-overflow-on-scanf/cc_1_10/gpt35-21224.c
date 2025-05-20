//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct that holds data for each menu item
typedef struct {
  char name[30];
  double price;
} MenuItem;

// Define the struct that holds data for each order
typedef struct {
  char item[30];
  double price;
  int quantity;
} Order;

// Define the menu items and their prices
MenuItem menu[] = {
  {"Coffee", 2.50},
  {"Bagel", 3.00},
  {"Pastry", 2.75},
  {"Sandwich", 4.50},
  {"Smoothie", 4.00}
};
int menuLength = sizeof(menu) / sizeof(menu[0]);

// Define global variables to keep track of the current order
Order orders[50];
int orderIndex = 0;

// Function to get the index of a menu item by name
int getMenuIndex(char itemName[30]) {
  int i;
  for (i = 0; i < menuLength; i++) {
    if (strcmp(menu[i].name, itemName) == 0) {
      return i;
    }
  }
  return -1;
}

// Function to add an item to the current order
void addToOrder(char itemName[30], int quantity) {
  int index = getMenuIndex(itemName);
  if (index != -1) {
    Order order;
    strcpy(order.item, itemName);
    order.price = menu[index].price;
    order.quantity = quantity;
    orders[orderIndex++] = order;
    printf("%d %s added to order.\n", quantity, itemName);
  } else {
    printf("%s not found on menu.\n", itemName);
  }
}

// Function to calculate the subtotal of the order
double calculateSubtotal() {
  double subtotal = 0;
  int i;
  for (i = 0; i < orderIndex; i++) {
    subtotal += orders[i].price * orders[i].quantity;
  }
  return subtotal;
}

// Function to print out the current order
void printOrder() {
  printf("Order:\n");
  int i;
  for (i = 0; i < orderIndex; i++) {
    printf("%dx %s ($%.2f each)\n", orders[i].quantity, orders[i].item, orders[i].price);
  }
}

// Function to generate the bill and print it out
void generateBill(double subtotal) {
  double tax = subtotal * 0.1;
  double total = subtotal + tax;
  printf("Subtotal: $%.2f\n", subtotal);
  printf("Tax:      $%.2f\n", tax);
  printf("Total:    $%.2f\n", total);
}

int main() {
  printf("***Welcome to the Future Cafe Billing System!***\n\n");

  // Loop to take menu orders until user quits
  char input[30];
  int quantity;
  while (1) {
    printf("Enter menu item name (or 'quit' to exit): ");
    scanf("%s", input);
    if (strcmp(input, "quit") == 0) {
      break;
    }
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    addToOrder(input, quantity);
  }

  // Print out the order and ask for confirmation
  printOrder();
  char confirm[5];
  printf("Is this order correct? (y/n): ");
  scanf("%s", confirm);
  if (strcmp(confirm, "y") != 0) {
    printf("Order cancelled.\n");
    return 0;
  }

  // Generate the bill and exit
  double subtotal = calculateSubtotal();
  generateBill(subtotal);
  printf("***Thank you for using the Future Cafe Billing System!***\n");
  return 0;
}
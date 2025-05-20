//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold the menu items
struct MenuItem {
  char name[20];
  float price;
};

// Structure to hold the orders
struct Order {
  char name[20];
  float price;
  int quantity;
  float total;
};

// Function to calculate the total price of each order
float calculateTotal(struct Order *order) {
  return order->price * order->quantity;
}

// Function to display the main menu
int displayMenu(struct MenuItem menu[], int menuSize) {
  printf("================ MENU ================\n");
  for (int i = 0; i < menuSize; i++) {
    printf("%d. %s - Rs. %.2f\n", i+1, menu[i].name, menu[i].price);
  }
  printf("%d. Exit\n", menuSize+1);
  printf("Select an option: ");
  int choice;
  scanf("%d", &choice);
  return choice;
}

// Function to add an order to the bill
void addOrder(struct MenuItem menu[], int choice, struct Order *order) {
  strcpy(order->name, menu[choice-1].name);
  order->price = menu[choice-1].price;
  printf("Enter quantity: ");
  scanf("%d", &order->quantity);
  order->total = calculateTotal(order);
  printf("%d x %s added to the bill for Rs. %.2f\n", order->quantity, order->name, order->total);
}

// Function to display the bill
void displayBill(struct Order orders[], int orderCount) {
  printf("=========== BILL ===========\n");
  printf("%-20s%-10s%-10s%-10s\n", "Item", "Price", "Qty", "Total");
  float grandTotal = 0;
  for (int i = 0; i < orderCount; i++) {
    printf("%-20s%-10.2f%-10d%-10.2f\n", orders[i].name, orders[i].price, orders[i].quantity, orders[i].total);
    grandTotal += orders[i].total;
  }
  printf("Grand Total: Rs. %.2f\n", grandTotal);
}

int main() {
  struct MenuItem menu[] = {{"Coffee", 50}, {"Tea", 20}, {"Sandwich", 80}, {"Cake", 100}};
  int menuSize = sizeof(menu) / sizeof(menu[0]);
  struct Order orders[10];
  int orderCount = 0;
  int choice;
  
  printf("Welcome to Brave Cafe Billing System!\n");
  
  do {
    choice = displayMenu(menu, menuSize);
    if (choice >= 1 && choice <= menuSize) {
      struct Order order;
      addOrder(menu, choice, &order);
      orders[orderCount++] = order;
    }
  } while (choice != menuSize+1);
  
  displayBill(orders, orderCount);
  
  return 0;
}
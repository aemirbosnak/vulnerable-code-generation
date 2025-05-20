//Code Llama-13B DATASET v1.0 Category: Warehouse Management System ; Style: detailed
/*
 * Warehouse Management System in C
 *
 * This program is an example of a simple warehouse management system that allows
 * users to track inventory, manage orders, and generate reports.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures to represent the data
typedef struct {
  char name[50];
  int quantity;
  double price;
} Item;

typedef struct {
  int id;
  char name[50];
  int quantity;
  double price;
  char status;
} Order;

// Function prototypes
void menu();
void addItem(Item *item);
void removeItem(Item *item);
void updateItem(Item *item);
void addOrder(Order *order);
void updateOrder(Order *order);
void processOrder(Order *order);
void generateReport();

// Global variables
Item items[100];
int numItems = 0;
Order orders[100];
int numOrders = 0;

int main() {
  // Welcome message
  printf("Welcome to the Warehouse Management System!\n");
  printf("Please enter your choice: ");

  // Loop until the user exits the program
  while (1) {
    menu();
    int choice;
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        addItem(&items[numItems]);
        numItems++;
        break;
      case 2:
        removeItem(&items[numItems]);
        numItems--;
        break;
      case 3:
        updateItem(&items[numItems]);
        break;
      case 4:
        addOrder(&orders[numOrders]);
        numOrders++;
        break;
      case 5:
        updateOrder(&orders[numOrders]);
        break;
      case 6:
        processOrder(&orders[numOrders]);
        numOrders--;
        break;
      case 7:
        generateReport();
        break;
      case 8:
        printf("Exiting program...\n");
        exit(0);
        break;
      default:
        printf("Invalid choice!\n");
        break;
    }
  }

  return 0;
}

void menu() {
  printf("1. Add item\n");
  printf("2. Remove item\n");
  printf("3. Update item\n");
  printf("4. Add order\n");
  printf("5. Update order\n");
  printf("6. Process order\n");
  printf("7. Generate report\n");
  printf("8. Exit program\n");
}

void addItem(Item *item) {
  printf("Enter item name: ");
  scanf("%s", item->name);
  printf("Enter item quantity: ");
  scanf("%d", &item->quantity);
  printf("Enter item price: ");
  scanf("%lf", &item->price);
  printf("Item added successfully!\n");
}

void removeItem(Item *item) {
  printf("Enter item name: ");
  scanf("%s", item->name);
  printf("Enter item quantity: ");
  scanf("%d", &item->quantity);
  printf("Item removed successfully!\n");
}

void updateItem(Item *item) {
  printf("Enter item name: ");
  scanf("%s", item->name);
  printf("Enter item quantity: ");
  scanf("%d", &item->quantity);
  printf("Enter item price: ");
  scanf("%lf", &item->price);
  printf("Item updated successfully!\n");
}

void addOrder(Order *order) {
  printf("Enter order ID: ");
  scanf("%d", &order->id);
  printf("Enter order name: ");
  scanf("%s", order->name);
  printf("Enter order quantity: ");
  scanf("%d", &order->quantity);
  printf("Enter order price: ");
  scanf("%lf", &order->price);
  printf("Order added successfully!\n");
}

void updateOrder(Order *order) {
  printf("Enter order ID: ");
  scanf("%d", &order->id);
  printf("Enter order name: ");
  scanf("%s", order->name);
  printf("Enter order quantity: ");
  scanf("%d", &order->quantity);
  printf("Enter order price: ");
  scanf("%lf", &order->price);
  printf("Order updated successfully!\n");
}

void processOrder(Order *order) {
  printf("Enter order ID: ");
  scanf("%d", &order->id);
  printf("Order processed successfully!\n");
}

void generateReport() {
  printf("Generating report...\n");
  printf("Item name, quantity, price\n");
  for (int i = 0; i < numItems; i++) {
    printf("%s, %d, %.2lf\n", items[i].name, items[i].quantity, items[i].price);
  }
  printf("Order ID, order name, quantity, price, status\n");
  for (int i = 0; i < numOrders; i++) {
    printf("%d, %s, %d, %.2lf, %c\n", orders[i].id, orders[i].name, orders[i].quantity, orders[i].price, orders[i].status);
  }
  printf("Report generated successfully!\n");
}
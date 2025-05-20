//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: surprised
/*
* Medical Store Management System
*
* This program is designed to manage medical stores and provide a user-friendly interface for managing inventory, orders, and customers.
*
* Author: [Your Name]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structs for the different data types used in the system

typedef struct {
  char name[50];
  char address[100];
  char phone[20];
} Customer;

typedef struct {
  char name[50];
  int quantity;
  float price;
} InventoryItem;

typedef struct {
  char order_id[20];
  Customer customer;
  InventoryItem item;
  int quantity;
  float total_cost;
} Order;

// Define the functions for managing the system

void print_menu() {
  printf("1. Manage Inventory\n");
  printf("2. Manage Orders\n");
  printf("3. Manage Customers\n");
  printf("4. Exit\n");
}

void manage_inventory() {
  printf("Manage Inventory\n");
  printf("1. Add item\n");
  printf("2. Remove item\n");
  printf("3. Update quantity\n");
  printf("4. Back\n");
}

void manage_orders() {
  printf("Manage Orders\n");
  printf("1. Add order\n");
  printf("2. Remove order\n");
  printf("3. Update order\n");
  printf("4. Back\n");
}

void manage_customers() {
  printf("Manage Customers\n");
  printf("1. Add customer\n");
  printf("2. Remove customer\n");
  printf("3. Update customer\n");
  printf("4. Back\n");
}

int main() {
  int choice;
  printf("Welcome to Medical Store Management System\n");
  while (1) {
    print_menu();
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        manage_inventory();
        break;
      case 2:
        manage_orders();
        break;
      case 3:
        manage_customers();
        break;
      case 4:
        printf("Exiting...\n");
        return 0;
    }
  }
  return 0;
}
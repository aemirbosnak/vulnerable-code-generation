//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[50];
  int quantity;
  float price;
} Item;

typedef struct {
  char customerName[50];
  Item items[10];
  int numItems;
  float total;
} Bill;

void printMenu();
void takeOrder(Bill *bill);
void calculateTotal(Bill *bill);
void printBill(Bill *bill);

int main() {
  Bill bill;

  strcpy(bill.customerName, "");
  bill.numItems = 0;
  bill.total = 0.0;

  int choice;
  do {
    printMenu();
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        takeOrder(&bill);
        break;
      case 2:
        calculateTotal(&bill);
        break;
      case 3:
        printBill(&bill);
        break;
      case 4:
        exit(0);
      default:
        printf("Invalid choice. Please enter a valid choice.\n");
    }
  } while (choice != 4);

  return 0;
}

void printMenu() {
  printf("1. Take Order\n");
  printf("2. Calculate Total\n");
  printf("3. Print Bill\n");
  printf("4. Exit\n");
  printf("Enter your choice: ");
}

void takeOrder(Bill *bill) {
  printf("Enter customer name: ");
  scanf("%s", bill->customerName);

  printf("Enter the number of items: ");
  scanf("%d", &bill->numItems);

  for (int i = 0; i < bill->numItems; i++) {
    printf("Enter item name: ");
    scanf("%s", bill->items[i].name);

    printf("Enter quantity: ");
    scanf("%d", &bill->items[i].quantity);

    printf("Enter price: ");
    scanf("%f", &bill->items[i].price);
  }
}

void calculateTotal(Bill *bill) {
  bill->total = 0.0;

  for (int i = 0; i < bill->numItems; i++) {
    bill->total += bill->items[i].quantity * bill->items[i].price;
  }
}

void printBill(Bill *bill) {
  printf("Customer Name: %s\n", bill->customerName);
  printf("---------------------------\n");
  printf("Item Name\tQuantity\tPrice\n");
  printf("---------------------------\n");

  for (int i = 0; i < bill->numItems; i++) {
    printf("%s\t%d\t%.2f\n", bill->items[i].name, bill->items[i].quantity, bill->items[i].price);
  }

  printf("---------------------------\n");
  printf("Total: %.2f\n", bill->total);
}
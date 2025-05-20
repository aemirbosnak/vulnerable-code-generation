//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
  char name[20];
  float price;
  int quantity;
} Item;

Item items[MAX_ITEMS];

void addItem(char name[], float price, int quantity) {
  for (int i = 0; i < MAX_ITEMS; i++) {
    if (items[i].name[0] == '\0') {
      strcpy(items[i].name, name);
      items[i].price = price;
      items[i].quantity = quantity;
      return;
    }
  }
  printf("Error: Item list full.\n");
}

void displayItems() {
  for (int i = 0; i < MAX_ITEMS; i++) {
    if (items[i].name[0] != '\0') {
      printf("%s - %.2f - %d\n", items[i].name, items[i].price, items[i].quantity);
    }
  }
}

float calculateTotal() {
  float total = 0.0f;
  for (int i = 0; i < MAX_ITEMS; i++) {
    if (items[i].name[0] != '\0') {
      total += items[i].price * items[i].quantity;
    }
  }
  return total;
}

void generateBill() {
  printf("-----------------------------------------------------------------------\n");
  printf("                                 C Cafe Billing System\n");
  printf("-----------------------------------------------------------------------\n");
  printf("Items:\n");
  displayItems();
  printf("\nTotal: %.2f\n", calculateTotal());
  printf("\nPayment: ");
  float payment = 0.0f;
  scanf("%f", &payment);
  printf("\nChange: %.2f\n", payment - calculateTotal());
  printf("Thank you for your visit!\n");
}

int main() {
  addItem("Coffee", 5.0f, 2);
  addItem("Tea", 3.0f, 1);
  addItem("Juice", 4.0f, 3);

  generateBill();

  return 0;
}
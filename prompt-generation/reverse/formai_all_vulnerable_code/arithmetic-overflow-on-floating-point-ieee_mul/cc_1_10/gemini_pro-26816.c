//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
  char name[20];
  int quantity;
  float price;
};

struct bill {
  char customer_name[20];
  char customer_phone[10];
  char customer_email[30];
  struct item items[10];
  int num_items;
  float total_amount;
};

void add_item(struct bill *b, struct item i) {
  b->items[b->num_items] = i;
  b->num_items++;
  b->total_amount += i.quantity * i.price;
}

void print_bill(struct bill b) {
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  printf("====================================================================================================\n");
  printf("                          Cafe Billing System                                                 \n");
  printf("====================================================================================================\n\n");
  printf("Customer Name: %s                                  Customer Phone: %s\n", b.customer_name, b.customer_phone);
  printf("Customer Email: %s\n\n", b.customer_email);
  printf("----------------------------------------------------------------------------------------------------\n");
  printf("Item Name                        Quantity                        Price                        Amount\n");
  for (int i = 0; i < b.num_items; i++) {
    printf("%-25s                        %-10d                        %-10.2f                        %-10.2f\n", b.items[i].name, b.items[i].quantity, b.items[i].price, b.items[i].quantity * b.items[i].price);
  }
  printf("----------------------------------------------------------------------------------------------------\n");
  printf("Total Amount: %.2f\n", b.total_amount);
  printf("====================================================================================================\n");
  printf("                                 Thank You for Visiting Us!                                        \n");
  printf("====================================================================================================\n");
}

int main() {
  struct bill b;
  strcpy(b.customer_name, "John Doe");
  strcpy(b.customer_phone, "1234567890");
  strcpy(b.customer_email, "johndoe@example.com");
  struct item i1 = {"Coffee", 1, 2.50};
  add_item(&b, i1);
  struct item i2 = {"Tea", 2, 1.50};
  add_item(&b, i2);
  struct item i3 = {"Cake", 1, 3.00};
  add_item(&b, i3);
  print_bill(b);
  return 0;
}
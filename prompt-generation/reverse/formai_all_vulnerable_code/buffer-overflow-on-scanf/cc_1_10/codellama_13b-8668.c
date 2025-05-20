//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: mathematical
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  struct Customer {
    char name[100];
    int age;
    float balance;
  };

  struct Order {
    int item_count;
    char item_name[100];
    float item_price;
    int item_quantity;
  };

  struct Bill {
    float total_amount;
    float discount_amount;
    float tax_amount;
    float grand_total;
  };

  void add_customer(struct Customer *customers, int *customer_count) {
    printf("Enter the customer's name: ");
    scanf("%s", customers[*customer_count].name);
    printf("Enter the customer's age: ");
    scanf("%d", &customers[*customer_count].age);
    printf("Enter the customer's initial balance: ");
    scanf("%f", &customers[*customer_count].balance);
    (*customer_count)++;
  }

  void add_order(struct Order *orders, int *order_count) {
    printf("Enter the item name: ");
    scanf("%s", orders[*order_count].item_name);
    printf("Enter the item price: ");
    scanf("%f", &orders[*order_count].item_price);
    printf("Enter the item quantity: ");
    scanf("%d", &orders[*order_count].item_quantity);
    orders[*order_count].item_count++;
    (*order_count)++;
  }

  void calculate_bill(struct Customer *customers, int customer_count, struct Order *orders, int order_count, struct Bill *bill) {
    for (int i = 0; i < order_count; i++) {
      bill->total_amount += orders[i].item_price * orders[i].item_quantity;
    }
    bill->discount_amount = bill->total_amount * 0.1;
    bill->tax_amount = bill->total_amount * 0.15;
    bill->grand_total = bill->total_amount + bill->tax_amount - bill->discount_amount;
  }

  void print_bill(struct Customer *customers, int customer_count, struct Order *orders, int order_count, struct Bill *bill) {
    printf("Customer Details:\n");
    for (int i = 0; i < customer_count; i++) {
      printf("Name: %s\nAge: %d\nBalance: %f\n", customers[i].name, customers[i].age, customers[i].balance);
    }
    printf("Order Details:\n");
    for (int i = 0; i < order_count; i++) {
      printf("Item: %s\nPrice: %f\nQuantity: %d\n", orders[i].item_name, orders[i].item_price, orders[i].item_quantity);
    }
    printf("Bill Details:\n");
    printf("Total Amount: %f\nDiscount Amount: %f\nTax Amount: %f\nGrand Total: %f\n", bill->total_amount, bill->discount_amount, bill->tax_amount, bill->grand_total);
  }

  int main() {
    struct Customer customers[100];
    struct Order orders[100];
    struct Bill bill;
    int customer_count = 0;
    int order_count = 0;

    add_customer(customers, &customer_count);
    add_order(orders, &order_count);
    calculate_bill(customers, customer_count, orders, order_count, &bill);
    print_bill(customers, customer_count, orders, order_count, &bill);

    return 0;
  }
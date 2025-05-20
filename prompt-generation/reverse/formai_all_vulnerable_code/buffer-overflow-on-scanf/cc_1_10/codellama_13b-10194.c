//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: unmistakable
// Medical Store Management System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct medicine {
  char name[50];
  int price;
  int quantity;
};

struct customer {
  char name[50];
  int age;
  char gender;
};

struct order {
  char medicine_name[50];
  int quantity;
  int total_price;
  struct customer customer;
};

void add_medicine(struct medicine medicine[], int *total_medicines) {
  printf("Enter the name of the medicine: ");
  scanf("%s", medicine[*total_medicines].name);
  printf("Enter the price of the medicine: ");
  scanf("%d", &medicine[*total_medicines].price);
  printf("Enter the quantity of the medicine: ");
  scanf("%d", &medicine[*total_medicines].quantity);
  *total_medicines += 1;
}

void display_medicines(struct medicine medicine[], int total_medicines) {
  for (int i = 0; i < total_medicines; i++) {
    printf("%s\t%d\t%d\n", medicine[i].name, medicine[i].price, medicine[i].quantity);
  }
}

void add_customer(struct customer customer[]) {
  printf("Enter the name of the customer: ");
  scanf("%s", customer->name);
  printf("Enter the age of the customer: ");
  scanf("%d", &customer->age);
  printf("Enter the gender of the customer: ");
  scanf(" %c", &customer->gender);
}

void add_order(struct order order[], struct medicine medicine[], int total_medicines) {
  printf("Enter the name of the medicine: ");
  scanf("%s", order->medicine_name);
  for (int i = 0; i < total_medicines; i++) {
    if (strcmp(order->medicine_name, medicine[i].name) == 0) {
      order->quantity = medicine[i].quantity;
      order->total_price = order->quantity * medicine[i].price;
      break;
    }
  }
  add_customer(&order->customer);
}

void display_orders(struct order order[], int total_orders) {
  for (int i = 0; i < total_orders; i++) {
    printf("%s\t%d\t%d\t%s\t%d\t%c\n", order[i].medicine_name, order[i].quantity, order[i].total_price, order[i].customer.name, order[i].customer.age, order[i].customer.gender);
  }
}

int main() {
  struct medicine medicine[100];
  struct customer customer[100];
  struct order order[100];
  int total_medicines = 0, total_customers = 0, total_orders = 0;

  char choice;
  do {
    printf("Welcome to the Medical Store Management System\n");
    printf("1. Add medicine\n");
    printf("2. Display medicines\n");
    printf("3. Add customer\n");
    printf("4. Add order\n");
    printf("5. Display orders\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);

    switch (choice) {
      case '1':
        add_medicine(medicine, &total_medicines);
        break;
      case '2':
        display_medicines(medicine, total_medicines);
        break;
      case '3':
        add_customer(customer);
        total_customers += 1;
        break;
      case '4':
        add_order(order, medicine, total_medicines);
        total_orders += 1;
        break;
      case '5':
        display_orders(order, total_orders);
        break;
      default:
        printf("Invalid choice\n");
    }
  } while (choice != '0');

  return 0;
}
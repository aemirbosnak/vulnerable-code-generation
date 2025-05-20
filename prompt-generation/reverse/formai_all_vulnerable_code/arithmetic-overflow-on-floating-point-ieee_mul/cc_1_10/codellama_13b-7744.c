//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: complex
// C Program to implement a complex Cafe Billing System

#include <stdio.h>
#include <string.h>

// Structure to store customer details
struct customer {
  char name[50];
  int age;
  char address[100];
  char contact[10];
  float balance;
};

// Structure to store menu items
struct menu_item {
  char name[50];
  float price;
  int quantity;
};

// Function to add a new customer
void add_customer(struct customer *cust) {
  printf("Enter the name of the customer: ");
  scanf("%s", cust->name);
  printf("Enter the age of the customer: ");
  scanf("%d", &cust->age);
  printf("Enter the address of the customer: ");
  scanf("%s", cust->address);
  printf("Enter the contact number of the customer: ");
  scanf("%s", cust->contact);
  cust->balance = 0.0;
}

// Function to add a new menu item
void add_menu_item(struct menu_item *item) {
  printf("Enter the name of the menu item: ");
  scanf("%s", item->name);
  printf("Enter the price of the menu item: ");
  scanf("%f", &item->price);
  printf("Enter the quantity of the menu item: ");
  scanf("%d", &item->quantity);
}

// Function to calculate the total cost of the order
float calculate_total_cost(struct menu_item *item) {
  return item->price * item->quantity;
}

// Function to display the bill
void display_bill(struct customer *cust, struct menu_item *item) {
  printf("Bill for %s\n", cust->name);
  printf("-------------------------\n");
  printf("Item\t\tPrice\tQuantity\tTotal\n");
  printf("%s\t\t%f\t%d\t\t%f\n", item->name, item->price, item->quantity, calculate_total_cost(item));
  printf("-------------------------\n");
  printf("Total Cost: %f\n", calculate_total_cost(item));
}

// Function to add a payment
void add_payment(struct customer *cust, float amount) {
  cust->balance += amount;
}

int main() {
  // Create a customer
  struct customer cust;
  add_customer(&cust);

  // Create a menu item
  struct menu_item item;
  add_menu_item(&item);

  // Display the bill
  display_bill(&cust, &item);

  // Add a payment
  float payment;
  printf("Enter the payment amount: ");
  scanf("%f", &payment);
  add_payment(&cust, payment);

  // Display the updated balance
  printf("Balance: %f\n", cust.balance);

  return 0;
}
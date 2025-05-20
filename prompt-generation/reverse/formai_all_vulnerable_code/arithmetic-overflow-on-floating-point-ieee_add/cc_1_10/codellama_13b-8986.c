//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: all-encompassing
// Cafe Billing System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define struct for customer
typedef struct {
  char name[50];
  char address[100];
  char phone[20];
  int order_num;
  float total_price;
} Customer;

// Define struct for order
typedef struct {
  int item_num;
  char item_name[50];
  int quantity;
  float price;
} Order;

// Define struct for billing
typedef struct {
  int bill_num;
  char customer_name[50];
  char customer_address[100];
  char customer_phone[20];
  int order_num;
  float total_price;
  float tax;
  float discount;
  float grand_total;
} Bill;

// Function to calculate tax
float calculate_tax(float total_price, float tax_rate) {
  return total_price * tax_rate;
}

// Function to calculate discount
float calculate_discount(float total_price, float discount_rate) {
  return total_price * discount_rate;
}

// Function to calculate grand total
float calculate_grand_total(float total_price, float tax, float discount) {
  return total_price + tax - discount;
}

// Function to print billing
void print_billing(Bill b) {
  printf("Billing Information:\n");
  printf("Bill Number: %d\n", b.bill_num);
  printf("Customer Name: %s\n", b.customer_name);
  printf("Customer Address: %s\n", b.customer_address);
  printf("Customer Phone: %s\n", b.customer_phone);
  printf("Order Number: %d\n", b.order_num);
  printf("Total Price: %.2f\n", b.total_price);
  printf("Tax: %.2f\n", b.tax);
  printf("Discount: %.2f\n", b.discount);
  printf("Grand Total: %.2f\n", b.grand_total);
}

// Main function
int main() {
  Customer c;
  Order o;
  Bill b;

  // Initialize customer and order information
  printf("Enter customer information:\n");
  printf("Name: ");
  scanf("%s", c.name);
  printf("Address: ");
  scanf("%s", c.address);
  printf("Phone: ");
  scanf("%s", c.phone);
  printf("Order Number: ");
  scanf("%d", &o.item_num);
  printf("Item Name: ");
  scanf("%s", o.item_name);
  printf("Quantity: ");
  scanf("%d", &o.quantity);
  printf("Price: ");
  scanf("%f", &o.price);

  // Calculate total price and tax
  b.total_price = o.quantity * o.price;
  b.tax = calculate_tax(b.total_price, 0.07);

  // Calculate discount and grand total
  b.discount = calculate_discount(b.total_price, 0.10);
  b.grand_total = calculate_grand_total(b.total_price, b.tax, b.discount);

  // Print billing information
  print_billing(b);

  return 0;
}
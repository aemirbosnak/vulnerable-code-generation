//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: artistic
/*
 * C Cafe Billing System
 *
 * This program is an example of a simple cash register system for a cafe.
 * It allows the user to input the names of the items they would like to purchase and
 * their prices, and then calculates the total cost of the items and outputs
 * the total cost, as well as a receipt with the items purchased.
 */

#include <stdio.h>
#include <string.h>

// Define the maximum number of items that can be purchased at once
#define MAX_ITEMS 5

// Define the structure to hold information about an item
typedef struct {
  char name[50];
  float price;
} item;

// Define the structure to hold information about the receipt
typedef struct {
  char items[MAX_ITEMS][50];
  float prices[MAX_ITEMS];
  int num_items;
  float total_cost;
} receipt;

// Function to add an item to the receipt
void add_item(receipt *r, char *name, float price) {
  // Check if the receipt is full
  if (r->num_items == MAX_ITEMS) {
    printf("Receipt is full, cannot add more items.\n");
    return;
  }

  // Add the item to the receipt
  strcpy(r->items[r->num_items], name);
  r->prices[r->num_items] = price;
  r->num_items++;
  r->total_cost += price;
}

// Function to print the receipt
void print_receipt(receipt *r) {
  // Print the receipt header
  printf("--- Receipt ---\n");

  // Print the items purchased
  for (int i = 0; i < r->num_items; i++) {
    printf("%s: $%.2f\n", r->items[i], r->prices[i]);
  }

  // Print the total cost
  printf("Total: $%.2f\n", r->total_cost);
}

int main() {
  // Declare a receipt variable
  receipt r;

  // Initialize the receipt
  r.num_items = 0;
  r.total_cost = 0;

  // Prompt the user for the items they would like to purchase
  printf("Welcome to the Cafe!\n");
  printf("What would you like to order?\n");
  char item_name[50];
  float item_price;
  int item_count = 0;
  while (item_count < MAX_ITEMS) {
    printf("Item %d: ", item_count + 1);
    scanf("%s", item_name);
    printf("Price: ");
    scanf("%f", &item_price);
    add_item(&r, item_name, item_price);
    item_count++;
  }

  // Print the receipt
  print_receipt(&r);

  return 0;
}
//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a product
typedef struct Product {
  char name[20];
  int price;
  int quantity;
} Product;

// Create an array of products
Product products[] = {
  {"Coffee", 50, 10},
  {"Tea", 40, 8},
  {"Juice", 30, 6},
  {"Smoothie", 60, 4}
};

// Define the function to calculate the total cost of an order
int calculateTotalCost(int numItems, Product products[]) {
  int totalCost = 0;
  for (int i = 0; i < numItems; i++) {
    totalCost += products[i].price * products[i].quantity;
  }
  return totalCost;
}

// Define the function to print the bill
void printBill(int totalCost, int numItems, Product products[]) {
  printf("-------------------------------------------------------------------\n");
  printf("C Cafe Billing System\n");
  printf("-------------------------------------------------------------------\n");
  printf("Total Items: %d\n", numItems);
  printf("Total Cost: $%d\n", totalCost);
  printf("Products:\n");
  for (int i = 0; i < numItems; i++) {
    printf("%s - $%d (Qty: %d)\n", products[i].name, products[i].price, products[i].quantity);
  }
  printf("-------------------------------------------------------------------\n");
  printf("Thank you for your order at C Cafe!\n");
  printf("-------------------------------------------------------------------\n");
}

int main() {
  int numItems = 0;
  int totalCost = 0;
  Product products[] = {products};

  // Get the number of items ordered
  printf("Enter the number of items you ordered: ");
  scanf("%d", &numItems);

  // Calculate the total cost of the order
  totalCost = calculateTotalCost(numItems, products);

  // Print the bill
  printBill(totalCost, numItems, products);

  return 0;
}
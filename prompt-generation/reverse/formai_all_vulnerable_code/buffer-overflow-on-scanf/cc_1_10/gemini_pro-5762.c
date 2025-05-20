//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: unmistakable
#include <stdio.h>

// Structure to store the details of each item ordered
typedef struct {
  char name[50];
  float price;
  int quantity;
} Item;

// Function to take the order from the user
void takeOrder(Item items[], int *numItems) {
  printf("Enter the number of items you want to order: ");
  scanf("%d", numItems);

  for (int i = 0; i < *numItems; i++) {
    printf("Enter the name of item %d: ", i + 1);
    scanf(" %[^\n]", items[i].name);

    printf("Enter the price of item %d: ", i + 1);
    scanf(" %f", &items[i].price);

    printf("Enter the quantity of item %d: ", i + 1);
    scanf(" %d", &items[i].quantity);
  }
}

// Function to calculate the total bill
float calculateBill(Item items[], int numItems) {
  float total = 0;

  for (int i = 0; i < numItems; i++) {
    total += items[i].price * items[i].quantity;
  }

  return total;
}

// Function to print the receipt
void printReceipt(Item items[], int numItems, float total) {
  printf("\n\n==================================================\n");
  printf("Cafe Billing System\n");
  printf("==================================================\n");

  printf("\nItems Ordered:\n");
  for (int i = 0; i < numItems; i++) {
    printf("%-30s %5.2f %3d %7.2f\n", items[i].name, items[i].price, items[i].quantity,
           items[i].price * items[i].quantity);
  }

  printf("\nTotal Bill: %.2f\n", total);
  printf("==================================================\n");
}

// Main function
int main() {
  // Array to store the items ordered
  Item items[100];

  // Variable to store the number of items ordered
  int numItems;

  // Take the order from the user
  takeOrder(items, &numItems);

  // Calculate the total bill
  float total = calculateBill(items, numItems);

  // Print the receipt
  printReceipt(items, numItems, total);

  return 0;
}
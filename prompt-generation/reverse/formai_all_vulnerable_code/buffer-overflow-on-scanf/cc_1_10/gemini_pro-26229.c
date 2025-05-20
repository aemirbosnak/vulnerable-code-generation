//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A happy little struct to hold our medicine data
typedef struct Medicine {
  char name[50];
  float price;
  int quantity;
} Medicine;

// Our cheerful little medicine store
Medicine store[] = {
  { "Paracetamol", 5.0, 100 },
  { "Ibuprofen", 6.0, 75 },
  { "Aspirin", 4.0, 120 },
  { "Amoxicillin", 10.0, 50 },
  { "Ciprofloxacin", 15.0, 30 },
};

// The number of medicines in our store
int num_medicines = sizeof(store) / sizeof(Medicine);

// Our merry little main function
int main() {
  // Greet the user with a smile
  printf("Welcome to the Happiest Medical Store in Town!\n");

  // Print a list of our medicines
  printf("Here's a list of our cheerful medicines:\n");
  for (int i = 0; i < num_medicines; i++) {
    printf("%s - %.2f - %d\n", store[i].name, store[i].price, store[i].quantity);
  }

  // Ask the user what they want to buy
  char medicine_name[50];
  printf("Which medicine would you like to purchase, my friend?\n");
  scanf("%s", medicine_name);

  // Find the medicine in our store
  int medicine_index = -1;
  for (int i = 0; i < num_medicines; i++) {
    if (strcmp(medicine_name, store[i].name) == 0) {
      medicine_index = i;
      break;
    }
  }

  // Check if the medicine exists
  if (medicine_index == -1) {
    printf("Sorry, we don't have that medicine in stock.\n");
    return 0;
  }

  // Ask the user how much they want to buy
  int quantity;
  printf("How many units of %s would you like to buy?\n", store[medicine_index].name);
  scanf("%d", &quantity);

  // Check if we have enough in stock
  if (quantity > store[medicine_index].quantity) {
    printf("Sorry, we don't have that much in stock.\n");
    return 0;
  }

  // Calculate the total price
  float total_price = store[medicine_index].price * quantity;

  // Print the receipt
  printf("Your total bill is %.2f. Thank you for shopping with us!\n", total_price);

  // Update the stock
  store[medicine_index].quantity -= quantity;

  printf("Come again soon!");

  return 0;
}
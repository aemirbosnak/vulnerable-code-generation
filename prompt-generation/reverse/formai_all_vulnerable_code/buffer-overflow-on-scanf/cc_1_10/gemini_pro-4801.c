//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char name[50];
  int quantity;
  float price;
} Item;

void print_menu() {
  printf("========= Cafe Menu =========\n");
  printf("1. Coffee - $2.50\n");
  printf("2. Tea - $1.50\n");
  printf("3. Cake - $3.00\n");
  printf("4. Sandwich - $4.00\n");
  printf("5. Salad - $5.00\n");
  printf("6. Exit\n");
}

int get_choice() {
  int choice;
  printf("Enter your choice: ");
  scanf("%d", &choice);
  return choice;
}

void add_item(Item *items, int *num_items, Item item) {
  items[*num_items] = item;
  (*num_items)++;
}

float calculate_total(Item *items, int num_items) {
  float total = 0;
  for (int i = 0; i < num_items; i++) {
    total += items[i].quantity * items[i].price;
  }
  return total;
}

void print_receipt(Item *items, int num_items, float total) {
  printf("\n========= Cafe Receipt =========\n");
  for (int i = 0; i < num_items; i++) {
    printf("%s x%d - $%.2f\n", items[i].name, items[i].quantity, items[i].price * items[i].quantity);
  }
  printf("Total: $%.2f\n", total);
}

int main() {
  // Initialize variables
  Item items[100];
  int num_items = 0;
  float total = 0;

  // Print the menu
  print_menu();

  // Get the user's choice
  int choice = get_choice();

  // Process the user's choice
  while (choice != 6) {
    switch (choice) {
      case 1:
        add_item(items, &num_items, (Item){"Coffee", 1, 2.50});
        break;
      case 2:
        add_item(items, &num_items, (Item){"Tea", 1, 1.50});
        break;
      case 3:
        add_item(items, &num_items, (Item){"Cake", 1, 3.00});
        break;
      case 4:
        add_item(items, &num_items, (Item){"Sandwich", 1, 4.00});
        break;
      case 5:
        add_item(items, &num_items, (Item){"Salad", 1, 5.00});
        break;
      default:
        printf("Invalid choice. Please enter a number between 1 and 6.\n");
        break;
    }

    // Print the menu again
    print_menu();

    // Get the user's choice
    choice = get_choice();
  }

  // Calculate the total
  total = calculate_total(items, num_items);

  // Print the receipt
  print_receipt(items, num_items, total);

  return 0;
}
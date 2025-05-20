//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: enthusiastic
// Cafe Billing System
// By: [Your Name]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 20

struct Item {
  char name[MAX_NAME_LENGTH];
  double price;
};

struct Order {
  struct Item items[MAX_ITEMS];
  int num_items;
  double total;
};

void print_menu() {
  printf("--- Menu ---\n");
  printf("1. Coffee - $2.00\n");
  printf("2. Tea - $1.50\n");
  printf("3. Chocolate Mug - $3.00\n");
  printf("4. Cinnamon Roll - $4.00\n");
  printf("5. S'mores - $5.00\n");
  printf("6. Bread Pudding - $6.00\n");
  printf("--- End of Menu ---\n");
}

void print_order(struct Order *order) {
  printf("--- Order ---\n");
  printf("Items:\n");
  for (int i = 0; i < order->num_items; i++) {
    printf("  %s - $%.2f\n", order->items[i].name, order->items[i].price);
  }
  printf("Total: $%.2f\n", order->total);
  printf("--- End of Order ---\n");
}

int main() {
  struct Order order = {0};
  int choice;
  char name[MAX_NAME_LENGTH];

  print_menu();
  printf("Enter your name: ");
  scanf("%s", name);

  while (1) {
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        strcpy(order.items[order.num_items].name, "Coffee");
        order.items[order.num_items].price = 2.00;
        break;
      case 2:
        strcpy(order.items[order.num_items].name, "Tea");
        order.items[order.num_items].price = 1.50;
        break;
      case 3:
        strcpy(order.items[order.num_items].name, "Chocolate Mug");
        order.items[order.num_items].price = 3.00;
        break;
      case 4:
        strcpy(order.items[order.num_items].name, "Cinnamon Roll");
        order.items[order.num_items].price = 4.00;
        break;
      case 5:
        strcpy(order.items[order.num_items].name, "S'mores");
        order.items[order.num_items].price = 5.00;
        break;
      case 6:
        strcpy(order.items[order.num_items].name, "Bread Pudding");
        order.items[order.num_items].price = 6.00;
        break;
      case 0:
        goto end;
      default:
        printf("Invalid choice. Please try again.\n");
        continue;
    }

    order.num_items++;
    order.total += order.items[order.num_items - 1].price;
    print_order(&order);
  }

end:
  printf("Thank you for choosing our cafe, %s! Your order total is $%.2f.\n", name, order.total);
  return 0;
}
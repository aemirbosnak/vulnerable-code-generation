//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>

// Declare structures
struct menu_item {
  char name[50];
  double price;
};

struct order_item {
  char name[50];
  double price;
  int quantity;
};

// Declare functions
void display_menu(struct menu_item menu[], int menu_size);
void take_order(struct order_item order[], int *order_size, struct menu_item menu[], int menu_size);
void display_order(struct order_item order[], int order_size);
double calculate_total(struct order_item order[], int order_size);

int main() {
  // Initialize menu
  struct menu_item menu[5] = {
    {"Coffee", 3.99},
    {"Tea", 2.99},
    {"Muffin", 2.99},
    {"Sandwich", 5.99},
    {"Cake", 4.99}
  };

  // Initialize order
  struct order_item order[20];
  int order_size = 0;

  // Display menu and take order
  printf("Welcome to the Cafe!\n");
  display_menu(menu, 5);
  take_order(order, &order_size, menu, 5);

  // Display order and total
  printf("\nOrder Summary:\n");
  display_order(order, order_size);
  printf("\nTotal: $%.2lf\n", calculate_total(order, order_size));

  return 0;
}

// Function to display the menu
void display_menu(struct menu_item menu[], int menu_size) {
  printf("\nMenu:\n");
  for (int i = 0; i < menu_size; i++) {
    printf("%d. %s - $%.2lf\n", i+1, menu[i].name, menu[i].price);
  }
}

// Function to take the order
void take_order(struct order_item order[], int *order_size, struct menu_item menu[], int menu_size) {
  int choice, quantity;
  char response;

  do {
    printf("\nEnter your choice (1-%d): ", menu_size);
    scanf("%d", &choice);
    printf("Enter quantity: ");
    scanf("%d", &quantity);

    // Add item to order
    strcpy(order[*order_size].name, menu[choice-1].name);
    order[*order_size].price = menu[choice-1].price;
    order[*order_size].quantity = quantity;
    (*order_size)++;

    printf("Add another item (y/n)? ");
    scanf(" %c", &response);
  } while (response == 'y' || response == 'Y');
}

// Function to display the order
void display_order(struct order_item order[], int order_size) {
  for (int i = 0; i < order_size; i++) {
    printf("%d. %s (x%d) - $%.2lf\n", i+1, order[i].name, order[i].quantity, order[i].price * order[i].quantity);
  }
}

// Function to calculate the total
double calculate_total(struct order_item order[], int order_size) {
  double total = 0.0;
  for (int i = 0; i < order_size; i++) {
    total += order[i].price * order[i].quantity;
  }
  return total;
}
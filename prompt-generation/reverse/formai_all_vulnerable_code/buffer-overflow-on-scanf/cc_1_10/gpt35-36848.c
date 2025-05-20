//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: modular
#include <stdio.h>

// Struct to represent an item in the menu
struct MenuItem {
  int id;
  char name[50];
  float price;
};

// Function to display the menu
void displayMenu(struct MenuItem menu[], int menuSize) {
  printf("\nMenu:\n");
  printf("ID\tName\t\tPrice\n");
  for(int i = 0; i < menuSize; i++) {
    printf("%d\t%s\t%.2f\n", menu[i].id, menu[i].name, menu[i].price);
  }
}

// Function to search for an item in the menu given the ID
struct MenuItem* searchMenuItem(struct MenuItem menu[], int menuSize, int id) {
  for(int i = 0; i < menuSize; i++) {
    if(menu[i].id == id) {
      return &menu[i];
    }
  }
  return NULL;
}

// Function to calculate total price of the order
float calculateTotal(struct MenuItem order[], int orderSize) {
  float total = 0;
  for(int i = 0; i < orderSize; i++) {
    total += order[i].price;
  }
  return total;
}

// Function to display the bill for an order
void displayBill(struct MenuItem order[], int orderSize) {
  printf("\nBill:\n");
  printf("Name\tPrice\n");
  for(int i = 0; i < orderSize; i++) {
    printf("%s\t%.2f\n", order[i].name, order[i].price);
  }
  printf("Total: %.2f\n", calculateTotal(order, orderSize));
}

int main() {
  // Define menu items
  struct MenuItem menu[] = {
    {1, "Coffee", 2.5},
    {2, "Tea", 1.5},
    {3, "Croissant", 1.75},
    {4, "Sandwich", 4.0}
  };
  int menuSize = 4;
  
  // Prompt user for order
  int orderSize = 0;
  printf("Enter number of items in order: ");
  scanf("%d", &orderSize);
  
  // Initialize order array with size of order
  struct MenuItem order[orderSize];
  
  // Prompt user for each item in the order
  for(int i = 0; i < orderSize; i++) {
    int id;
    printf("Enter ID for item %d: ", i+1);
    scanf("%d", &id);
    
    // Search for item in menu
    struct MenuItem* menuItem = searchMenuItem(menu, menuSize, id);
    
    // If item exists, add to order
    if(menuItem != NULL) {
      order[i] = *menuItem;
    } else { // If item does not exist, display error and decrement i
      printf("Item not found in menu.\n");
      i--;
    }
  }
  
  // Display bill
  displayBill(order, orderSize);
  
  return 0;
}
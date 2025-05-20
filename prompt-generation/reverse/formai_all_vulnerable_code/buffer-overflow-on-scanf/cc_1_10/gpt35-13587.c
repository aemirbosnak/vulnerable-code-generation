//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: synchronous
#include <stdio.h>
#include <string.h>

struct MenuItem {
  char name[50];
  float price;
};

void printMenu(struct MenuItem menu[], int n) {
  printf("MENU:\n");
  for (int i = 0; i < n; i++) {
    printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
  }
  printf("\n");
}

int main() {
  struct MenuItem menu[5] = {
    {"Coffee", 2.99},
    {"Muffin", 1.99},
    {"Sandwich", 4.99},
    {"Tea", 1.99},
    {"Scone", 2.99}
  };

  int selection;
  int quantity;
  float total = 0;

  printf("Welcome to the C Cafe Billing System!\n");
  printf("------------------------------------\n");

  do {
    printMenu(menu, 5);

    // Get user input
    printf("Enter selection (1-5) or enter 0 to exit: ");
    scanf("%d", &selection);

    // Validate selection
    if (selection < 0 || selection > 5) {
      printf("Invalid selection, please try again.\n\n");
      continue;
    }

    if (selection == 0) {
      printf("\n Thank you for visiting C Cafe Billing System! Your total is $%.2f\n", total);
      break;
    }

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    if (quantity <= 0) {
      printf("Invalid quantity, please try again.\n\n");
      continue;
    }

    // Add to total
    total += (menu[selection-1].price * quantity);

    printf("\nAdded %d %s to your order. \n\n", quantity, menu[selection-1].name);

  } while (1);

  return 0;
}
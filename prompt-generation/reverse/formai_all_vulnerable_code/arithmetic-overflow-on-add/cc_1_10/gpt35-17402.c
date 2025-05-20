//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: imaginative
#include <stdio.h>

int main() {
  int menu[5] = {50, 70, 30, 20, 40};
  char names[5][20] = {"Espresso", "Cappuccino", "Latte", "Mocha", "Iced coffee"};
  int quantity[5] = {0, 0, 0, 0, 0};
  int amount[5] = {0, 0, 0, 0, 0};
  int i, total = 0;

  printf("Welcome to Café Grande! Here is our menu:\n");
  for (i = 0; i < 5; i++) {
    printf("%d. %s - $%d\n", i+1, names[i], menu[i]);
  }

  while (1) {
    int choice;
    printf("Enter your choice (0 to exit): ");
    scanf("%d", &choice);

    if (choice == 0) {
      break;
    }

    if (choice < 1 || choice > 5) {
      printf("Invalid choice. Try again.\n");
      continue;
    }

    int qty;
    printf("How many cups would you like? ");
    scanf("%d", &qty);

    quantity[choice-1] += qty;
    amount[choice-1] += qty * menu[choice-1];
  }

  printf("\nHere is your bill:\n");
  printf("ITEM\t\tQUANTITY\tAMOUNT\n");

  for (i = 0; i < 5; i++) {
    if (quantity[i] > 0) {
      printf("%s\t\t%d\t\t$%d\n", names[i], quantity[i], amount[i]);
      total += amount[i];
    }
  }

  printf("\nTOTAL BILL: $%d\n", total);

  printf("Thank you for visiting Café Grande! Have a nice day :)\n");
  return 0;
}
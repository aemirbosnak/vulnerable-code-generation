//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

void display_menu() {
  printf("-------------------------\n");
  printf("  C Cafe Menu\n");
  printf("-------------------------\n");
  printf("1. Coffee\n");
  printf("2. Tea\n");
  printf("3. Juice\n");
  printf("4. Smoothie\n");
  printf("5. Pastry\n");
  printf("-------------------------\n");
}

int main() {
  int choice, quantity, total_price = 0;
  char name[20];

  display_menu();

  printf("Enter your name: ");
  scanf("%s", name);

  printf("Enter your choice: ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("Enter the quantity: ");
      scanf("%d", &quantity);
      total_price += quantity * 50;
      break;
    case 2:
      printf("Enter the quantity: ");
      scanf("%d", &quantity);
      total_price += quantity * 40;
      break;
    case 3:
      printf("Enter the quantity: ");
      scanf("%d", &quantity);
      total_price += quantity * 30;
      break;
    case 4:
      printf("Enter the quantity: ");
      scanf("%d", &quantity);
      total_price += quantity * 20;
      break;
    case 5:
      printf("Enter the quantity: ");
      scanf("%d", &quantity);
      total_price += quantity * 10;
      break;
    default:
      printf("Invalid choice.\n");
  }

  printf("Thank you, %s. Your total price is: $%d\n", name, total_price);

  return 0;
}
//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

void display_menu() {
  printf("----------------------------------------\n");
  printf("Welcome to Coffee Bean Cafe!\n");
  printf("----------------------------------------\n");
  printf("Please select an item:\n");
  printf("1. Coffee\n");
  printf("2. Tea\n");
  printf("3. Juice\n");
  printf("4. Sandwich\n");
  printf("5. Dessert\n");
  printf("----------------------------------------\n");
}

int main() {
  int choice;
  float total_amount = 0.0f;
  char name[20];

  display_menu();
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      total_amount += 5.0f;
      printf("You selected Coffee!\n");
      break;
    case 2:
      total_amount += 4.0f;
      printf("You selected Tea!\n");
      break;
    case 3:
      total_amount += 3.0f;
      printf("You selected Juice!\n");
      break;
    case 4:
      total_amount += 6.0f;
      printf("You selected Sandwich!\n");
      break;
    case 5:
      total_amount += 2.0f;
      printf("You selected Dessert!\n");
      break;
    default:
      printf("Invalid choice.\n");
  }

  printf("Enter your name:");
  scanf("%s", name);

  printf("Thank you, %s, for visiting Coffee Bean Cafe!\n", name);
  printf("Your total amount is: $%.2f\n", total_amount);

  return 0;
}
//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: minimalist
#include <stdio.h>
#include <string.h>

void display_menu()
{
  printf("\nWelcome to the Coffee Cafe!\n");
  printf("-----------------------\n");
  printf("1. Coffee\n");
  printf("2. Tea\n");
  printf("3. Juice\n");
  printf("4. Cold Brew\n");
  printf("5. Smoothies\n");
  printf("-----------------------\n");
  printf("Please select an item: ");
}

int main()
{
  char item;
  int quantity;
  float total_cost = 0.0f;
  display_menu();
  scanf("%c", &item);

  switch (item)
  {
    case '1':
      total_cost += 2.50f;
      break;
    case '2':
      total_cost += 2.00f;
      break;
    case '3':
      total_cost += 1.50f;
      break;
    case '4':
      total_cost += 3.00f;
      break;
    case '5':
      total_cost += 3.50f;
      break;
    default:
      printf("Invalid item selection.\n");
  }

  printf("Enter the quantity: ");
  scanf("%d", &quantity);
  total_cost *= quantity;

  printf("Total cost: $%.2f\n", total_cost);

  return 0;
}
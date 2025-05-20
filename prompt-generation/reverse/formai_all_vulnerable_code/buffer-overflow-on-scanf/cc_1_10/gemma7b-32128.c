//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_menu() {
  printf("--------------------------------------------------------------------\n");
  printf("Welcome to the Future Cafe!\n");
  printf("--------------------------------------------------------------------\n");
  printf("Please select an item:\n");
  printf("1. Quantum Coffee\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t$10.00\n");
  printf("2. Molecular Tea\t\t\t\t\t\t\t\t\t\t\t\t\t\t$8.00\n");
  printf("3. Nano Smoothies\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t$9.00\n");
  printf("4. Galactic Juice\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t$7.00\n");
  printf("--------------------------------------------------------------------\n");
}

int main() {
  int item_no;
  float total_amount = 0.0f;
  char customer_name[20];

  printf("Please enter your name: ");
  scanf("%s", customer_name);

  display_menu();

  printf("Enter the item number: ");
  scanf("%d", &item_no);

  switch (item_no) {
    case 1:
      total_amount += 10.00f;
      break;
    case 2:
      total_amount += 8.00f;
      break;
    case 3:
      total_amount += 9.00f;
      break;
    case 4:
      total_amount += 7.00f;
      break;
    default:
      printf("Invalid item number.\n");
  }

  printf("Total amount: $%.2f\n", total_amount);

  printf("Thank you, %s, for your visit to the Future Cafe!\n", customer_name);

  return 0;
}
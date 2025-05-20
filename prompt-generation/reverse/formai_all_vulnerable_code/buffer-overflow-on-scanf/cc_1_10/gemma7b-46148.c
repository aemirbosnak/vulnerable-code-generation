//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: funny
#include <stdio.h>
#include <stdlib.h>

void greet_customer(char name[]) {
  printf("Welcome, %s! Prepare for a caffeine assault!\n", name);
}

void take_order(int beverage_id, char customer_name[]) {
  switch (beverage_id) {
    case 1:
      printf("You've ordered a black coffee, %s. Weak as a baby's cry.\n", customer_name);
      break;
    case 2:
      printf("You've ordered a cappuccino, %s. May your day be as creamy as your drink.\n", customer_name);
      break;
    case 3:
      printf("You've ordered a latte, %s. It's probably not your cup of tea, but we're all pretending.\n", customer_name);
      break;
  }
}

int calculate_bill(int beverage_id) {
  switch (beverage_id) {
    case 1:
      return 2;
    case 2:
      return 3;
    case 3:
      return 4;
  }
}

void print_receipt(char customer_name[], int total_cost) {
  printf("----------------------------------------\n");
  printf("Customer Name: %s\n", customer_name);
  printf("Total Cost: $%d\n", total_cost);
  printf("Please pay the barista, and may your day be as caffeinated as a squirrel on Red Bull.\n");
  printf("----------------------------------------\n");
}

int main() {
  char customer_name[20];
  int beverage_id;

  printf("What is your name, my dear customer? ");
  scanf("%s", customer_name);

  printf("Please select your beverage:\n");
  printf("1. Black Coffee\n");
  printf("2. Cappuccino\n");
  printf("3. Latte\n");
  scanf("%d", &beverage_id);

  take_order(beverage_id, customer_name);

  int total_cost = calculate_bill(beverage_id);

  print_receipt(customer_name, total_cost);

  return 0;
}
//FormAI DATASET v1.0 Category: Educational ; Style: real-life
#include <stdio.h>

int main() {
  // Welcome message and input
  printf("Welcome to the Sales Calculator!\n");
  printf("Please enter the number of items sold: ");
  int num_items;
  scanf("%d", &num_items);

  // Input validation
  if (num_items < 1) {
    printf("Error: Invalid input. You must sell at least one item.\n");
    return 1;
  }

  // Calculate total cost of items sold
  double total_cost = 0;
  for (int i = 1; i <= num_items; i++) {
    printf("Please enter the cost of item %d: ", i);
    double item_cost;
    scanf("%lf", &item_cost);

    // Input validation
    if (item_cost < 0) {
      printf("Error: Invalid input. Item cost cannot be negative.\n");
      return 1;
    }

    total_cost += item_cost;
  }

  // Calculate commission rate based on total cost of items
  double commission_rate;
  if (total_cost < 100) {
    commission_rate = 0.05;
  } else if (total_cost < 500) {
    commission_rate = 0.1;
  } else {
    commission_rate = 0.15;
  }

  // Calculate commission and earnings
  double commission = total_cost * commission_rate;
  double earnings = total_cost + commission;

  // Output results
  printf("Total cost of items sold: $%.2f\n", total_cost);
  printf("Commission rate: %.2f%%\n", commission_rate * 100);
  printf("Commission earned: $%.2f\n", commission);
  printf("Total earnings: $%.2f\n", earnings);

  return 0;
}
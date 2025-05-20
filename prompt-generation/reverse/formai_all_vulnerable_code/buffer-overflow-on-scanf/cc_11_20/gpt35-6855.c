//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main() {
  int num_items, max_weight;
  printf("Welcome to the Happy Knapsack Problem Solver!\n");
  printf("How many items are there in the knapsack? ");
  scanf("%d", &num_items);
  printf("What is the maximum weight the knapsack can hold? ");
  scanf("%d", &max_weight);
  
  int item_weights[num_items];
  int item_values[num_items];
  for (int i = 0; i < num_items; i++) {
    printf("Enter the weight for item %d: ", i+1);
    scanf("%d", &item_weights[i]);
    printf("Enter the value for item %d: ", i+1);
    scanf("%d", &item_values[i]);
  }
  
  printf("\nCalculating optimal solution...\n");
  
  int total_weight = 0;
  int total_value = 0;
  int chosen_items[num_items];
  for (int i = 0; i < num_items; i++) {
    chosen_items[i] = 0;
  }
  
  while (total_weight < max_weight) {
    int best_item = -1;
    double best_value_per_weight = 0.0;
    for (int i = 0; i < num_items; i++) {
      if (!chosen_items[i]) {
        double value_per_weight = item_values[i] / (double)item_weights[i];
        if (value_per_weight > best_value_per_weight) {
          best_item = i;
          best_value_per_weight = value_per_weight;
        }
      }
    }
    
    if (best_item == -1) {
      break;
    }
    
    int weight_added = item_weights[best_item];
    if (total_weight + weight_added > max_weight) {
      weight_added = max_weight - total_weight;
    }
    
    chosen_items[best_item] = 1;
    total_weight += weight_added;
    total_value += weight_added * (item_values[best_item] / (double)item_weights[best_item]);
  }
  
  printf("\nThe optimal solution is to include the following items:\n");
  for (int i = 0; i < num_items; i++) {
    if (chosen_items[i]) {
      printf("- Item %d (weight %d, value %d)\n", i+1, item_weights[i], item_values[i]);
    }
  }
  printf("Total weight: %d\n", total_weight);
  printf("Total value: %d\n", total_value);
  
  printf("\nHooray! Knapsack problem solved! Have a great day :)\n");
  
  return 0;
}
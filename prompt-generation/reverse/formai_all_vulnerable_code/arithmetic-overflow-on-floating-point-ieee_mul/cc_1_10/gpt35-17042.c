//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

int main() {
  int total_items, capacity, i;
  float total_profit = 0;

  // Taking user input for total items and capacity of knapsack
  printf("Enter total number of items: ");
  scanf("%d", &total_items);
  printf("Enter the maximum capacity of knapsack: ");
  scanf("%d", &capacity);

  // Dynamic memory allocation for items' weight and profit
  int *weight = (int *)malloc(total_items * sizeof(int));
  float *profit = (float *)malloc(total_items * sizeof(float));

  // Taking user input for items' weight and profit
  for (i = 0; i < total_items; i++) {
    printf("\nEnter weight for item %d: ", i + 1);
    scanf("%d", &weight[i]);
    printf("Enter profit for item %d: ", i + 1);
    scanf("%f", &profit[i]);
  }

  // Calculating profit-to-weight ratios and sorting items in decreasing order of ratios
  float *ratio = (float *)malloc(total_items * sizeof(float));
  for (i = 0; i < total_items; i++) {
    ratio[i] = profit[i] / weight[i];
  }
  int j;
  for (i = 0; i < total_items - 1; i++) {
    for (j = i + 1; j < total_items; j++) {
      if (ratio[i] < ratio[j]) {
        float temp = ratio[j];
        ratio[j] = ratio[i];
        ratio[i] = temp;

        int temp2 = weight[j];
        weight[j] = weight[i];
        weight[i] = temp2;

        float temp3 = profit[j];
        profit[j] = profit[i];
        profit[i] = temp3;
      }
    }
  }

  // Filling the knapsack with items
  int filled_capacity = 0, k = 0;
  while (filled_capacity < capacity) {
    if (weight[k] <= capacity - filled_capacity) {
      total_profit += profit[k];
      filled_capacity += weight[k];
      k++;
    } else {
      total_profit += ratio[k] * (capacity - filled_capacity);
      filled_capacity = capacity;
    }
  }

  // Printing the maximum profit
  printf("\nMaximum profit is: %.2f", total_profit);

  // Freeing dynamically allocated memory
  free(weight);
  free(profit);
  free(ratio);

  return 0;
}
//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: high level of detail
#include <stdio.h>

int main() {
  int n, i, j;
  printf("Enter the number of items: ");
  scanf("%d", &n);

  int weights[n], values[n], capacity;
  printf("Enter the capacity of the knapsack: ");
  scanf("%d", &capacity);

  float ratios[n];
  for (i = 0; i < n; i++) {
    printf("Enter the weight and value for item %d: ", i+1);
    scanf("%d %d", &weights[i], &values[i]);
    ratios[i] = (float)values[i] / weights[i];
  }

  //Sorting the items based on their value to weight ratios
  for (i = 0; i < n-1; i++) {
    for (j = i+1; j < n; j++) {
      if (ratios[i] < ratios[j]) {
        float temp = ratios[i];
        ratios[i] = ratios[j];
        ratios[j] = temp;

        int temp2 = weights[i];
        weights[i] = weights[j];
        weights[j] = temp2;

        temp2 = values[i];
        values[i] = values[j];
        values[j] = temp2;
      }
    }
  }

  int currentWeight = 0;
  float finalValue = 0.0;

  for (i = 0; i < n; i++) {
    if (currentWeight + weights[i] <= capacity) {
      currentWeight += weights[i];
      finalValue += values[i];
    }
    else {
      int remainingCapacity = capacity - currentWeight;
      finalValue += ratios[i] * remainingCapacity;
      break;
    }
  }

  printf("The maximum value that can be put into the knapsack is: %.2f\n", finalValue);

  return 0;
}
//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Dennis Ritchie
#include <stdio.h>

int main() {
  int n, max_weight;
  printf("Enter the number of items:");
  scanf("%d", &n);
  printf("Enter the maximum weight:");
  scanf("%d", &max_weight);
  
  int i, j;
  int weight[n], value[n];
  float wv_ratio[n];
  
  printf("Enter the weight and value of each item:\n");
  for (i = 0; i < n; i++) {
    scanf("%d %d", &weight[i], &value[i]);
    wv_ratio[i] = (float)value[i] / (float)weight[i];
  }
  
  float temp_ratio;
  int temp_weight, temp_value;
  
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (wv_ratio[j] < wv_ratio[j + 1]) {
        temp_ratio = wv_ratio[j + 1];
        wv_ratio[j + 1] = wv_ratio[j];
        wv_ratio[j] = temp_ratio;
        
        temp_weight = weight[j + 1];
        weight[j + 1] = weight[j];
        weight[j] = temp_weight;
        
        temp_value = value[j + 1];
        value[j + 1] = value[j];
        value[j] = temp_value;
      }
    }
  }
  
  int current_weight = 0, current_value = 0;
  float ratio_sum = 0;
  
  printf("Items to be included in the knapsack:\n");
  for (i = 0; i <n; i++) {
    if (current_weight == max_weight) {
      break;
    } else if (current_weight + weight[i] <= max_weight) {
      current_weight += weight[i];
      current_value += value[i];
      printf("Item %d with weight %d and value %d\n", i + 1, weight[i], value[i]);
    } else {
      int remaining_weight = max_weight - current_weight;
      ratio_sum = (float)remaining_weight / (float)weight[i];
      current_weight += remaining_weight;
      current_value += value[i] * ratio_sum;
      printf("Item %d partially included with weight %d and value %.2f\n", i + 1, remaining_weight, value[i] * ratio_sum);
    }
  }
  
  printf("Total value of items included: %d", current_value);
  
  return 0;
}
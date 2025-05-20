//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Alan Touring
#include <stdio.h>

int main() {
  int n, capacity;
  
  printf("Enter the number of items: ");
  scanf("%d", &n);
  
  int weights[n], profits[n];
  float ratios[n], max_profit = 0;
  
  printf("Enter the capacity of the knapsack: ");
  scanf("%d", &capacity);
  
  for(int i=0; i<n; i++) {
    printf("Enter the weight of item %d: ", i+1);
    scanf("%d", &weights[i]);
    
    printf("Enter the profit of item %d: ", i+1);
    scanf("%d", &profits[i]);
    
    ratios[i] = (float)profits[i] / (float)weights[i];
  }
  
  // Sorting the ratios array in descending order
  for(int i=0; i<n-1; i++) {
    for(int j=0; j<n-i-1; j++) {
      if(ratios[j] < ratios[j+1]) {
        float temp = ratios[j];
        ratios[j] = ratios[j+1];
        ratios[j+1] = temp;
        
        int temp_weight = weights[j];
        weights[j] = weights[j+1];
        weights[j+1] = temp_weight;
        
        int temp_profit = profits[j];
        profits[j] = profits[j+1];
        profits[j+1] = temp_profit;
      }
    }
  }
  
  int i = 0;
  while(capacity > 0 && i < n) {
    if(weights[i] <= capacity) {
      max_profit += profits[i];
      capacity -= weights[i];
    }
    else {
      max_profit += (float)capacity * ratios[i];
      capacity = 0;
    }
    i++;
  }
  
  printf("The maximum profit is: %.2f\n", max_profit);
  
  return 0;
}
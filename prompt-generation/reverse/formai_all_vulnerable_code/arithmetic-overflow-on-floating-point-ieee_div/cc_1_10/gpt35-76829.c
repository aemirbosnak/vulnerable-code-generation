//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: realistic
#include <stdio.h>

int main() {
  int num_jobs, i, j, profit, weight, capacity, temp, total_profit = 0;
  float profit_per_kg;
  
  printf("Enter the number of jobs: ");
  scanf("%d", &num_jobs);
  
  int profits[num_jobs], weights[num_jobs];
  float ppk[num_jobs];
  
  printf("Enter the profits and weights for each job: \n");
  for (i = 0; i < num_jobs; i++) {
    printf("Job %d: ", i+1);
    scanf("%d", &profit);
    scanf("%d", &weight);
    profits[i] = profit;
    weights[i] = weight;
    ppk[i] = (float)profits[i]/weights[i];
  }
  
  // sort jobs in decreasing order of profit per kilogram
  for (i = 0; i < num_jobs-1; i++) {
    for (j = i+1; j < num_jobs; j++) {
      if (ppk[i] < ppk[j]) {
        // swap ppk
        temp = ppk[i];
        ppk[i] = ppk[j];
        ppk[j] = temp;
        
        // swap profits
        temp = profits[i];
        profits[i] = profits[j];
        profits[j] = temp;
        
        // swap weights
        temp = weights[i];
        weights[i] = weights[j];
        weights[j] = temp;
      }
    }
  }
  
  printf("Enter the capacity of the knapsack: ");
  scanf("%d", &capacity);
  
  // fill knapsack with jobs in decreasing order of ppk
  for (i = 0; i < num_jobs; i++) {
    if (capacity >= weights[i]) {
      total_profit += profits[i];
      capacity -= weights[i];
    }
    else {
      // take a fraction of the job to fill the knapsack
      profit_per_kg = (float)profits[i]/weights[i];
      total_profit += (int)(profit_per_kg*capacity);
      break;
    }
  }
  
  printf("Total profit = %d", total_profit);
  
  return 0;
}
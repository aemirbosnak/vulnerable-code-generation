//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Dennis Ritchie
#include <stdio.h>

int main() {
  int n, i;
  float max_wt, curr_wt = 0, profit = 0;
  
  printf("Enter the number of objects: ");
  scanf("%d", &n);
  
  float wt[n], val[n];
  
  printf("Enter the weight and value of each object:\n");

  for(i=0; i<n; i++) {
    printf("Object %d: ", i+1);
    scanf("%f %f", &wt[i], &val[i]);
  }
  
  printf("Enter the maximum weight capacity of the knapsack: ");
  scanf("%f", &max_wt);
  
  float ratio[n], temp;
  
  // Calculating ratio of value to weight for all objects
  for(i=0; i<n; i++) {
    ratio[i] = val[i]/wt[i];
  }
  
  // Sorting objects in descending order of ratio
  for(i=0; i<n-1; i++) {
    for(int j=i+1; j<n; j++) {
      if(ratio[i] < ratio[j]) {
        temp = ratio[j];
        ratio[j] = ratio[i];
        ratio[i] = temp;
        temp = val[j];
        val[j] = val[i];
        val[i] = temp;
        temp = wt[j];
        wt[j] = wt[i];
        wt[i] = temp;
      }
    }
  }
  
  // Adding objects to knapsack till maximum weight capacity is reached
  for(i=0; i<n; i++) {
    if(curr_wt + wt[i] <= max_wt) {
      curr_wt += wt[i];
      profit += val[i];
    }
    else {
      profit += (max_wt - curr_wt) * ratio[i];
      break;
    }
  }
  
  printf("Maximum profit that can be obtained is: %.2f", profit);
  
  return 0;
}
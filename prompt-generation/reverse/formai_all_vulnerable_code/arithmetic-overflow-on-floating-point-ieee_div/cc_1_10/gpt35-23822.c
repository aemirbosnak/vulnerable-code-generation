//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: intelligent
#include <stdio.h>

int main()
{
  int n, i, j, capacity;
  float weight[20], profit[20], ratio[20], temp, total_profit = 0;
  
  printf("Enter the number of items: ");
  scanf("%d", &n);
  
  printf("Enter the capacity of the knapsack: ");
  scanf("%d", &capacity);
  
  printf("Enter the weight and profit of %d items\n", n);
  for(i=0;i<n;i++)
  {
    scanf("%f%f", &weight[i], &profit[i]);
    ratio[i] = profit[i]/weight[i];
  }
  
  for(i=0;i<n;i++)
  {
    for(j=i+1;j<n;j++)
    {
      if(ratio[i] < ratio[j])
      {
        temp = ratio[j];
        ratio[j] = ratio[i];
        ratio[i] = temp;
        
        temp = weight[j];
        weight[j] = weight[i];
        weight[i] = temp;
        
        temp = profit[j];
        profit[j] = profit[i];
        profit[i] = temp;
      }
    }
  }
  
  for(i=0;i<n;i++)
  {
    if(capacity >= weight[i])
    {
      printf("Selected item with weight = %.2f and profit = %.2f\n", weight[i], profit[i]);
      capacity = capacity - weight[i];
      total_profit = total_profit + profit[i];
    }
    else
    {
      float fraction = capacity/weight[i];
      printf("Selected item with weight = %.2f and profit = %.2f as fraction %.2f\n", weight[i], profit[i], fraction);
      total_profit = total_profit + (fraction * profit[i]);
      capacity = capacity - (fraction * weight[i]);
    }
  }
  
  printf("Total profit = %.2f\n", total_profit);
  return 0;
}
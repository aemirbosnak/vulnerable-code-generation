//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: automated
#include<stdio.h>
#include<stdlib.h>

#define MAX 100 

int item[MAX], weight[MAX];
float p[MAX], profit = 0;
int n, capacity;

void knapsack(){

  int i, j, u;
  u = capacity;

  for(i=0;i<n;i++)
    p[i] = (float) item[i] / weight[i];

  for(i=0;i<n;i++){
    if(weight[i]>u)
      break;
    else{
      profit += item[i];
      u -= weight[i];
    }
  }

  if(i<n)
    profit += p[i] * u;
}

int main(){

  int i;

  printf("\nEnter the no. of items: ");
  scanf("%d", &n);

  printf("\nEnter the weights of the %d items: \n", n);
  for(i=0;i<n;i++)
    scanf("%d", &weight[i]);

  printf("\nEnter the corresponding values of the %d items: \n", n);
  for(i=0;i<n;i++)
    scanf("%d", &item[i]);

  printf("\nEnter the capacity of the knapsack: ");
  scanf("%d", &capacity);

  knapsack();

  printf("\nThe maximum profit is: %.2f\n", profit);

  return 0;
}
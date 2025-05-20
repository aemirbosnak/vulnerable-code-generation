//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// function to sort array in descending order
void sortArray(int arr[], int n) {
   int i, j, temp;
   for(i=0; i<n-1; i++) {
      for(j=0; j<n-i-1; j++) {
         if(arr[j] < arr[j+1]) {
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
         }
      }
   }
}

int main() {
   int n, i, j, capacity;
   float profit=0;

   // taking number of items
   printf("Enter number of items: ");
   scanf("%d", &n);

   // taking capacity of knapsack
   printf("Enter capacity of knapsack: ");
   scanf("%d", &capacity);

   int weight[n], cost[n], ratio[n];

   // taking weights and costs of all the items
   for(i=0; i<n; i++) {
      printf("\nEnter weight and cost of item %d: ", i+1);
      scanf("%d %d", &weight[i], &cost[i]);
   }

   // calculating the cost-to-weight ratio
   for(i=0; i<n; i++) {
      ratio[i] = cost[i]/weight[i];
   }

   // sorting the items according to their cost-to-weight ratio
   sortArray(ratio, n);

   // greedy approach
   for(i=0; i<n; i++) {
      if(weight[i] <= capacity) {
         profit += cost[i];
         capacity -= weight[i];
      } else {
         profit += (float)capacity*ratio[i];
         break;
      }
   }

   printf("\nMaximum profit = %0.2f", profit);

   return 0;
}
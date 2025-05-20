//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: scalable
#include <stdio.h>

void knapsack(int n, float capacity, float weight[], float profit[]) {
   float x[20], tp = 0;
   int i, j, u;
   u = capacity;

   for (i = 0; i < n; i++)
      x[i] = 0.0;

   for (i = 0; i < n; i++) {
      if (weight[i] > u)
         break;
      else {
         x[i] = 1.0;
         tp += profit[i];
         u -= weight[i];
      }
   }

   if (i < n)
      x[i] = u / weight[i];

   tp += (x[i] * profit[i]);

   printf("\nThe maximum profit is %.2f", tp);
}

int main() {
   float weight[20], profit[20], capacity;
   int num, i, j;
   float ratio[20], temp;

   printf("\nEnter the number of objects: ");
   scanf("%d", &num);

   printf("\nEnter the weights and profits of each object:\n");
   for (i = 0; i < num; i++) {
      printf("Weight[%d]: ", i);
      scanf("%f", &weight[i]);
      printf("Profit[%d]: ", i);
      scanf("%f", &profit[i]);
   }

   printf("\nEnter the capacity of knapsack: ");
   scanf("%f", &capacity);

   for (i = 0; i < num; i++) {
      ratio[i] = profit[i] / weight[i];
   }

   for (i = 0; i < num; i++) {
      for (j = i + 1; j < num; j++) {
         if (ratio[i] < ratio[j]) {
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

   knapsack(num, capacity, weight, profit);
   return 0;
}
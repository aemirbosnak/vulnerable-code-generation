//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: puzzling
#include <stdio.h>

int main() {
   int n, w;
   float valperwt[100], value[100], weight[100], temp;
   float totalweight = 0, totalvalue = 0; 
   int i, j;

   printf("Enter the number of items: ");
   scanf("%d", &n);

   printf("Enter the maximum capacity of the knapsack: ");
   scanf("%d", &w);

   printf("Enter the values and weights of the %d items\n\n", n);

   for (i = 0; i < n; i++) {
      printf("Item %d:\n", i + 1);

      printf("Weight: ");
      scanf("%f", &weight[i]);

      printf("Value: ");
      scanf("%f", &value[i]);

      valperwt[i] = value[i] / weight[i];
   }

   for (i = 0 ; i < n; i++) {
      for (j = i + 1;  j < n; j++) {
         if (valperwt[i] < valperwt[j]) {
            temp = valperwt[j];
            valperwt[j] = valperwt[i];
            valperwt[i] = temp;

            temp = weight[j];
            weight[j] = weight[i];
            weight[i] = temp;

            temp = value[j];
            value[j] = value[i];
            value[i] = temp;
         }
      }
   }

   for (i = 0; i < n; i++) {
      if (totalweight + weight[i] <= w) {
         totalweight += weight[i];
         totalvalue += value[i];
      } else {
         float remainingvalue = value[i] * ((w - totalweight) / weight[i]);
         totalweight = w;
         totalvalue += remainingvalue;

         break;
      }
   }

   printf("\nThe maximum possible value of the knapsack is %.2f\n", totalvalue);

   return 0;
}
//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: dynamic
#include <stdio.h>

#define MAX_ELEMENTS 100

void greedy_algorithm(int n, int weights[], int values[], int capacity) {
   int i, j, max_value, max_index, total_weight;
   float fraction;
   int taken[MAX_ELEMENTS] = {0};

   while(capacity > 0) {
      max_value = -1;
      for(i = 0; i < n; i++) {
         if(taken[i] == 0 && values[i]/weights[i] > max_value) {
            max_value = values[i]/weights[i];
            max_index = i;
         }
      }

      if(weights[max_index] > capacity) {
         fraction = (float)capacity/weights[max_index];
         taken[max_index] = fraction;
         total_weight += (int)(fraction*weights[max_index]);
         capacity -= (int)(fraction*weights[max_index]);
      }
      else {
         taken[max_index] = 1;
         total_weight += weights[max_index];
         capacity -= weights[max_index];
      }
   }

   printf("Selected items:\n");
   for(i = 0; i< n; i++) {
      if(taken[i]) {
         printf("%d: weight=%d, value=%d\n", i+1, weights[i], values[i]);
      }
   }
   printf("Total value=%d, total weight=%d\n", max_value, total_weight);
}

int main() {
   int i, n, capacity, weights[MAX_ELEMENTS], values[MAX_ELEMENTS];

   // Reading input parameters
   printf("Enter number of items:\n");
   scanf("%d", &n);
   printf("Enter maximum capacity:\n");
   scanf("%d", &capacity);

   printf("Enter weight and value of each item:\n");
   for(i = 0; i < n; i++) {
      printf("Item %d:\n", i+1);
      scanf("%d %d", &weights[i], &values[i]);
   }

   greedy_algorithm(n, weights, values, capacity);

   return 0;
}
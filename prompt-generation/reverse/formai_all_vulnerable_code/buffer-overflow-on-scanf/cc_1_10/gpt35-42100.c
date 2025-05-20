//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Linus Torvalds
#include <stdio.h>

int main() {
   int i, max_weight, num_items;
   float max_profit = 0.0, total_weight = 0.0;
   int weight[10], profit[10];
   float ratio[10], fraction[10];

   printf("Enter the maximum weight of the knapsack: ");
   scanf("%d", &max_weight);
   printf("Enter the number of items to choose from: ");
   scanf("%d", &num_items);

   // Input the items' weight and profits
   for(i=0; i<num_items; i++) {
      printf("\nEnter the weight of item #%d: ", (i+1));
      scanf("%d", &weight[i]);
      printf("Enter the profit of item #%d: ", (i+1));
      scanf("%d", &profit[i]);
   }

   // Calculate the ratio of profit to weight for each item
   for(i=0; i<num_items; i++) {
      ratio[i] = (float) profit[i] / (float) weight[i];
   }

   // Sort the items in decreasing order of their ratio
   for(i=0; i<num_items; i++) {
      int j;
      for(j=i+1; j<num_items; j++) {
         if(ratio[i] < ratio[j]) {
            float temp_ratio = ratio[i];
            ratio[i] = ratio[j];
            ratio[j] = temp_ratio;

            int temp_weight = weight[i];
            weight[i] = weight[j];
            weight[j] = temp_weight;

            int temp_profit = profit[i];
            profit[i] = profit[j];
            profit[j] = temp_profit;
         }
      }
   }

   // Calculate the maximum profit by adding items to the knapsack
   for(i=0; i<num_items; i++) {
      if(total_weight + weight[i] <= max_weight) {
         fraction[i] = 1.0;
         total_weight += weight[i];
         max_profit += profit[i];
      }
      else {
         fraction[i] = (max_weight - total_weight) / weight[i];
         max_profit += fraction[i] * profit[i];
         break;
      }
   }

   // Display the final result
   printf("\nItems in the knapsack with their fractions and final profit:\n");
   for(i=0; i<num_items; i++) {
      printf("Item #%d: weight=%d, profit=%d, fraction=%.2f\n", (i+1), weight[i], profit[i], fraction[i]);
   }
   printf("\nMaximum profit: %.2f\n", max_profit);

   return 0;
}
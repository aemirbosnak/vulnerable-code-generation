//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: standalone
#include <stdio.h>

#define MAX_ITEMS 100

struct Item {
   int weight;
   float value;
};

float calculate_density(struct Item item) {
   return item.value/item.weight;
}

void swap(struct Item *a, struct Item *b) {
   struct Item temp = *a;
   *a = *b;
   *b = temp;
}

void sort_by_density(struct Item items[], int n) {

   int i, j, max_idx;

   for(i=0;i<n-1;i++) {
      max_idx = i;
      for(j=i+1;j<n;j++) {
         if(calculate_density(items[j]) > calculate_density(items[max_idx])) {
            max_idx = j;
         }
      }
      swap(&items[i], &items[max_idx]);
   }
}

float knapsack(int weight_limit, struct Item items[], int n) {

   sort_by_density(items, n);

   int i, current_weight = 0;
   float current_value = 0.0;

   for(i=0;i<n;i++) {
      if(current_weight + items[i].weight <= weight_limit) {
         current_weight += items[i].weight;
         current_value += items[i].value;
      }
      else {
         int remaining_weight = weight_limit - current_weight;
         current_value += remaining_weight * calculate_density(items[i]);
         break;
      }

   }

   return current_value;
}

int main() {

   struct Item items[MAX_ITEMS];
   int n, i, weight_limit;

   printf("Enter the number of items: ");
   scanf("%d", &n);

   for(i=0;i<n;i++) {
      printf("\nEnter the weight and value of item %d: ", i+1);
      scanf("%d %f", &items[i].weight, &items[i].value);
   }

   printf("\nEnter the weight limit of the knapsack: ");
   scanf("%d", &weight_limit);

   printf("\nThe maximum value that can be put in the knapsack is: %.2f", knapsack(weight_limit, items, n));

   return 0;
}
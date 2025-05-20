//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: satisfied
#include<stdio.h>
#define MAX_SIZE 100
#define MAX_WEIGHT 1000

// Struct to store item information
struct item {
   char name[15];
   int weight;
   int value;
};

int n; // number of items
int max_weight; // maximum weight the knapsack can carry
int curr_weight; // current weight in knapsack
int curr_value; // current value in knapsack
struct item items[MAX_SIZE];

// Function to compare items based on value/weight ratio
int compare(const void *a, const void *b) {
   struct item *ia = (struct item *)a;
   struct item *ib = (struct item *)b;
   double ratio_a = (double)ia->value / (double)ia->weight;
   double ratio_b = (double)ib->value / (double)ib->weight;
   if (ratio_a > ratio_b) {
      return -1;
   } else if (ratio_a < ratio_b) {
      return 1;
   } else {
      return 0;
   }
}

// Function to add an item to the knapsack
void add_item(struct item *itm) {
   if (curr_weight + itm->weight <= max_weight) {
      curr_weight += itm->weight;
      curr_value += itm->value;
      printf("Added %s (weight=%d, value=%d), Current Weight = %d, Current Value = %d\n",
             itm->name, itm->weight, itm->value, curr_weight, curr_value);
   } else {
      printf("Could not add %s (weight=%d, value=%d) due to weight constraints.\n",
             itm->name, itm->weight, itm->value);
   }
}

int main() {
   printf("Enter the number of items : ");
   scanf("%d",&n);
   printf("Enter the maximum weight : ");
   scanf("%d",&max_weight);
   printf("Enter the name, weight, and value for each item :\n");
   for (int i = 0; i < n; i++) {
      scanf("%s %d %d",items[i].name, &items[i].weight, &items[i].value);
   }

   // sort items by value/weight ratio
   qsort(items, n, sizeof(struct item), compare);

   // add items to knapsack in order until cannot add anymore
   for (int i = 0; i < n; i++) {
      add_item(&items[i]);
   }

   printf("Total Value in the Knapsack = %d", curr_value);

   return 0;
}
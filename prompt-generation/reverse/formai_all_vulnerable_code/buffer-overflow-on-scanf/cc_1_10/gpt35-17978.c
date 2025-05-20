//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: innovative
#include<stdio.h>

// Define struct to hold items
struct Item {
   int value;
   int weight;
};

// Define function for sorting items by their value to weight ratio
int compare (const void *a, const void *b) {
   double ratio1 = ((double) (*(struct Item *)a).value) / ((double) (*(struct Item *)a).weight);
   double ratio2 = ((double) (*(struct Item *)b).value) / ((double) (*(struct Item *)b).weight);
   if (ratio1 > ratio2) {
      return -1;
   } else if (ratio1 < ratio2) {
      return 1;
   } else {
      return 0;
   }
}

// Define the main function
int main() {
   // Define variables for number of items, capacity of knapsack, and a counter
   int capacity, numItems, i;

   // Get user input for number of items and capacity of knapsack
   printf("Enter number of items: ");
   scanf("%d", &numItems);

   printf("Enter capacity of Knapsack: ");
   scanf("%d", &capacity);

   // Define array of items and get user input for value and weight of each item
   struct Item items[numItems];
   for (i=0; i<numItems; i++) {
      printf("\nEnter the weight of item %d: ", i+1);
      scanf("%d", &items[i].weight);

      printf("Enter the value of item %d: ", i+1);
      scanf("%d", &items[i].value);
   }

   // Sort the array of items by value to weight ratio
   qsort(items, numItems, sizeof(struct Item), compare);

   // Define variables for current weight and value of items in knapsack
   double currentWeight = 0.0;
   double currentValue = 0.0;

   // Loop through the items and add them to the knapsack if there is room for them
   for (i=0; i<numItems; i++) {
      if (currentWeight + items[i].weight <= capacity) {
         currentWeight += items[i].weight;
         currentValue += items[i].value;
      } else {
         double remainingCapacity = capacity - currentWeight;
         double fraction = remainingCapacity / (double) items[i].weight;
         currentValue += fraction * (double) items[i].value;
         break;
      }
   }

   // Output the total value of items in knapsack
   printf("\nTotal value in Knapsack: %.2lf\n", currentValue);

   return 0;
}
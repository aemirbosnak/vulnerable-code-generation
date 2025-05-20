//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WEIGHTS 100
#define MAX_VALUES 100

// Structure to represent a single item
typedef struct Item {
  int weight;
  int value;
} Item;

// Function to sort items in decreasing order of value/weight ratio
int compare(const void *a, const void *b) {
  Item *item1 = (Item *)a;
  Item *item2 = (Item *)b;
  double ratio1 = (double)item1->value / item1->weight;
  double ratio2 = (double)item2->value / item2->weight;
  return ratio2 - ratio1;
}

// Function to perform fractional knapsack algorithm
double fractionalKnapsack(Item items[], int n, int capacity) {
  // Sort items in decreasing order of value/weight ratio
  qsort(items, n, sizeof(Item), compare);

  // Initialize current weight and total value
  int currentWeight = 0;
  double totalValue = 0.0;

  // Iterate through items
  for (int i = 0; i < n; i++) {
    // If adding the current item doesn't exceed capacity, add it to the knapsack
    if (currentWeight + items[i].weight <= capacity) {
      currentWeight += items[i].weight;
      totalValue += items[i].value;
    } else {
      // Otherwise, add a fraction of the current item to the knapsack
      int remainingCapacity = capacity - currentWeight;
      totalValue += (double)remainingCapacity / items[i].weight * items[i].value;
      break;
    }
  }

  // Return the total value
  return totalValue;
}

// Generate random test data
void generateTestData(Item items[], int n, int maxWeight, int maxValue) {
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    items[i].weight = rand() % maxWeight + 1;
    items[i].value = rand() % maxValue + 1;
  }
}

// Print the items and their value/weight ratios
void printItems(Item items[], int n) {
  printf("Items:\n");
  for (int i = 0; i < n; i++) {
    printf("Item %d: Weight = %d, Value = %d, Ratio = %.2f\n", i + 1, items[i].weight, items[i].value,
           (double)items[i].value / items[i].weight);
  }
  printf("\n");
}

// Run the fractional knapsack algorithm and print the results
int main() {
  int n, capacity;

  printf("Enter the number of items: ");
  scanf("%d", &n);

  printf("Enter the capacity of the knapsack: ");
  scanf("%d", &capacity);

  Item items[MAX_WEIGHTS];

  generateTestData(items, n, MAX_WEIGHTS, MAX_VALUES);

  printItems(items, n);

  double totalValue = fractionalKnapsack(items, n, capacity);

  printf("Total value of items in the knapsack: %.2f\n", totalValue);

  return 0;
}
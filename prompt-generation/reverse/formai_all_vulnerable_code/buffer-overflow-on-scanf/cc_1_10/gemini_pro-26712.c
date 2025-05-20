//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_WEIGHT 1000

typedef struct {
  int weight;
  int value;
} Item;

int compareItems(const void *a, const void *b) {
  Item *item1 = (Item *)a;
  Item *item2 = (Item *)b;

  double valueDensity1 = (double)item1->value / item1->weight;
  double valueDensity2 = (double)item2->value / item2->weight;

  if (valueDensity1 < valueDensity2) {
    return 1;
  } else if (valueDensity1 > valueDensity2) {
    return -1;
  } else {
    return 0;
  }
}

int main() {
  int numItems, maxWeight;

  printf("Welcome to the Futuristic Knapsack Problem Solver!\n");
  printf("Enter the number of items in your knapsack: ");
  scanf("%d", &numItems);

  printf("Enter the maximum weight of your knapsack: ");
  scanf("%d", &maxWeight);

  Item items[MAX_ITEMS];

  printf("Enter the weight and value of each item:\n");
  for (int i = 0; i < numItems; i++) {
    printf("Item %d: ", i + 1);
    scanf("%d %d", &items[i].weight, &items[i].value);
  }

  qsort(items, numItems, sizeof(Item), compareItems);

  int totalWeight = 0;
  int totalValue = 0;

  for (int i = 0; i < numItems; i++) {
    if (totalWeight + items[i].weight <= maxWeight) {
      totalWeight += items[i].weight;
      totalValue += items[i].value;
    } else {
      break;
    }
  }

  printf("The total weight of the items in your knapsack is: %d\n", totalWeight);
  printf("The total value of the items in your knapsack is: %d\n", totalValue);

  return 0;
}
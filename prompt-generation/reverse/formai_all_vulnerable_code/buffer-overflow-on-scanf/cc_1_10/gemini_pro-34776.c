//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_VALUE 100
#define MAX_WEIGHT 100

typedef struct item {
  int value;
  int weight;
} item_t;

int compare_items(const void *a, const void *b) {
  const item_t *item1 = (const item_t *)a;
  const item_t *item2 = (const item_t *)b;

  return (item1->value / item1->weight) - (item2->value / item2->weight);
}

int main() {
  int n;
  item_t items[MAX_ITEMS];
  int capacity;

  printf("Enter the number of items: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    printf("Enter the value and weight of item %d: ", i + 1);
    scanf("%d %d", &items[i].value, &items[i].weight);
  }

  printf("Enter the capacity of the knapsack: ");
  scanf("%d", &capacity);

  qsort(items, n, sizeof(item_t), compare_items);

  int total_value = 0;
  int current_weight = 0;

  for (int i = 0; i < n; i++) {
    if (current_weight + items[i].weight <= capacity) {
      total_value += items[i].value;
      current_weight += items[i].weight;
    } else {
      int remaining_capacity = capacity - current_weight;
      total_value += (remaining_capacity * items[i].value) / items[i].weight;
      break;
    }
  }

  printf("The maximum value that can be obtained is: %d\n", total_value);

  return 0;
}
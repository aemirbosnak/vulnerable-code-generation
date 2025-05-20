//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: grateful
#include <stdio.h>

#define MAX_ITEMS 100
#define MAX_CAPACITY 1000

struct item {
  int weight;
  int value;
};

int compare_items(const void *a, const void *b) {
  const struct item *ia = (const struct item *)a;
  const struct item *ib = (const struct item *)b;
  double va = (double)ia->value / ia->weight;
  double vb = (double)ib->value / ib->weight;
  return (vb > va) ? 1 : (vb < va) ? -1 : 0;
}

int main() {
  int n, capacity;
  struct item items[MAX_ITEMS];
  double total_value = 0;

  printf("Enter the number of items: ");
  scanf("%d", &n);

  printf("Enter the capacity of the knapsack: ");
  scanf("%d", &capacity);

  printf("Enter the weight and value of each item:\n");
  for (int i = 0; i < n; i++) {
    int weight, value;
    scanf("%d %d", &weight, &value);
    items[i] = (struct item){.weight = weight, .value = value};
  }

  qsort(items, n, sizeof(struct item), compare_items);

  int i = 0;
  while (capacity > 0 && i < n) {
    if (items[i].weight <= capacity) {
      total_value += items[i].value;
      capacity -= items[i].weight;
    } else {
      total_value += (double)capacity / items[i].weight * items[i].value;
      capacity = 0;
    }
    i++;
  }

  printf("The maximum value that can be carried is %.2f\n", total_value);

  return 0;
}
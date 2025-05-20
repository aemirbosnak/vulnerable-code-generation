//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: realistic
#include <stdio.h>

#define MAX_ITEMS 100
#define MAX_WEIGHT 1000

typedef struct item {
  int weight;
  int value;
} Item;

int compare_items(const void *a, const void *b) {
  Item *item_a = (Item *) a;
  Item *item_b = (Item *) b;
  double pa = (double) item_a->value / (double) item_a->weight;
  double pb = (double) item_b->value / (double) item_b->weight;
  return pb > pa ? 1 : (pa > pb ? -1 : 0);
}

int main() {
  Item items[MAX_ITEMS];
  int n_items, total_weight;
  int i, j;
  int solution[MAX_ITEMS];
  int current_weight = 0;
  int current_value = 0;

  printf("Enter the number of items: ");
  scanf("%d", &n_items);

  for (i = 0; i < n_items; i++) {
    printf("Enter weight and value for item #%d: ", i + 1);
    scanf("%d %d", &items[i].weight, &items[i].value);
  }

  printf("Enter the total weight limit: ");
  scanf("%d", &total_weight);

  qsort(items, n_items, sizeof(Item), compare_items);

  for (i = 0; i < n_items; i++) {
    solution[i] = 0;
  }

  for (i = 0; i < n_items && current_weight + items[i].weight <= total_weight; i++) {
    solution[i] = 1;
    current_weight += items[i].weight;
    current_value += items[i].value;
  }

  if (i < n_items) {
    solution[i] = (total_weight - current_weight) * items[i].value / items[i].weight;
    current_value += solution[i] * items[i].value;
    current_weight += solution[i] * items[i].weight;
  }

  printf("The solution is: ");
  for (i = 0; i < n_items; i++) {
    if (solution[i]) {
      printf("%d ", i + 1);
    }
  }
  printf("\n");

  printf("The total weight is %d and the total value is %d\n", current_weight, current_value);

  return 0;
}
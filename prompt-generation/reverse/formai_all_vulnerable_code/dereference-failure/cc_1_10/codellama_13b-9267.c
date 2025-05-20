//Code Llama-13B DATASET v1.0 Category: Greedy Algorithms ; Style: Dennis Ritchie
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <time.h>

  typedef struct {
    int id;
    int weight;
    int value;
  } Item;

  typedef struct {
    Item *items;
    int capacity;
    int n;
  } Knapsack;

  void knapsack_greedy(Knapsack *k, int n, int w) {
    int i, j;
    Item *item;
    int *selected = (int *)malloc(n * sizeof(int));
    memset(selected, 0, n * sizeof(int));

    for (i = 0; i < n; i++) {
      item = &k->items[i];
      if (item->weight <= w && selected[i] == 0) {
        selected[i] = 1;
        w -= item->weight;
      }
    }

    for (i = 0; i < n; i++) {
      item = &k->items[i];
      if (item->weight > w && selected[i] == 0) {
        selected[i] = 1;
        w -= item->weight;
      }
    }

    for (i = 0; i < n; i++) {
      if (selected[i]) {
        printf("%d ", k->items[i].id);
      }
    }

    free(selected);
  }

  int main() {
    Knapsack k;
    k.items = (Item *)malloc(10 * sizeof(Item));
    k.capacity = 100;
    k.n = 10;

    k.items[0].id = 1;
    k.items[0].weight = 5;
    k.items[0].value = 10;

    k.items[1].id = 2;
    k.items[1].weight = 3;
    k.items[1].value = 12;

    k.items[2].id = 3;
    k.items[2].weight = 4;
    k.items[2].value = 15;

    k.items[3].id = 4;
    k.items[3].weight = 2;
    k.items[3].value = 8;

    k.items[4].id = 5;
    k.items[4].weight = 5;
    k.items[4].value = 12;

    k.items[5].id = 6;
    k.items[5].weight = 3;
    k.items[5].value = 16;

    k.items[6].id = 7;
    k.items[6].weight = 6;
    k.items[6].value = 18;

    k.items[7].id = 8;
    k.items[7].weight = 2;
    k.items[7].value = 10;

    k.items[8].id = 9;
    k.items[8].weight = 4;
    k.items[8].value = 15;

    k.items[9].id = 10;
    k.items[9].weight = 3;
    k.items[9].value = 12;

    knapsack_greedy(&k, k.n, k.capacity);

    return 0;
  }
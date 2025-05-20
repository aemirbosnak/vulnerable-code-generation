//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structures
typedef struct item {
  int value;
  int weight;
} Item;

typedef struct knapsack {
  int capacity;
  Item *items;
  int num_items;
} Knapsack;

// Functions
Item *read_items(char *filename, int *num_items) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }

  fscanf(fp, "%d", num_items);

  Item *items = malloc(*num_items * sizeof(Item));
  if (items == NULL) {
    perror("Error allocating memory");
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < *num_items; i++) {
    fscanf(fp, "%d %d", &items[i].value, &items[i].weight);
  }

  fclose(fp);

  return items;
}

Knapsack *create_knapsack(int capacity, Item *items, int num_items) {
  Knapsack *knapsack = malloc(sizeof(Knapsack));
  if (knapsack == NULL) {
    perror("Error allocating memory");
    exit(EXIT_FAILURE);
  }

  knapsack->capacity = capacity;
  knapsack->items = items;
  knapsack->num_items = num_items;

  return knapsack;
}

void free_knapsack(Knapsack *knapsack) {
  free(knapsack->items);
  free(knapsack);
}

// Sort items in decreasing order of value per unit weight
void sort_items(Item *items, int num_items) {
  for (int i = 0; i < num_items - 1; i++) {
    for (int j = i + 1; j < num_items; j++) {
      if ((double)items[i].value / items[i].weight <
          (double)items[j].value / items[j].weight) {
        Item temp = items[i];
        items[i] = items[j];
        items[j] = temp;
      }
    }
  }
}

// Fill the knapsack using the greedy algorithm
void fill_knapsack(Knapsack *knapsack) {
  sort_items(knapsack->items, knapsack->num_items);

  int remaining_capacity = knapsack->capacity;
  for (int i = 0; i < knapsack->num_items; i++) {
    if (knapsack->items[i].weight <= remaining_capacity) {
      remaining_capacity -= knapsack->items[i].weight;
    } else {
      break;
    }
  }
}

// Print the contents of the knapsack
void print_knapsack(Knapsack *knapsack) {
  printf("Knapsack contents:\n");
  for (int i = 0; i < knapsack->num_items; i++) {
    printf("%d %d\n", knapsack->items[i].value, knapsack->items[i].weight);
  }
}

int main() {
  // Read the input data
  char *filename = "input.txt";
  int num_items;
  Item *items = read_items(filename, &num_items);

  // Create the knapsack
  int capacity = 100;
  Knapsack *knapsack = create_knapsack(capacity, items, num_items);

  // Fill the knapsack
  fill_knapsack(knapsack);

  // Print the contents of the knapsack
  print_knapsack(knapsack);

  // Free the memory allocated for the knapsack and items
  free_knapsack(knapsack);

  return 0;
}
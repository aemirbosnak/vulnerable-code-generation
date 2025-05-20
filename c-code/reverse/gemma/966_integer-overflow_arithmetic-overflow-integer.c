#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct Bag {
  int weight_min;
  int weight_max;
} Bag;

int main() {
  int num_bags;
  printf("Enter the number of bags: ");
  scanf("%d", &num_bags);

  Bag *bags = NULL;
  bags = malloc(num_bags * sizeof(Bag));

  for (int i = 0; i < num_bags; i++) {
    printf("Enter the minimum weight of bag %d: ", i + 1);
    scanf("%d", &bags[i].weight_min);

    printf("Enter the maximum weight of bag %d: ", i + 1);
    scanf("%d", &bags[i].weight_max);
  }

  int total_weight = 0;
  for (int i = 0; i < num_bags; i++) {
    total_weight += bags[i].weight_max - bags[i].weight_min;
  }

  printf("Total weight of baggage: %d", total_weight);

  free(bags);

  return 0;
}

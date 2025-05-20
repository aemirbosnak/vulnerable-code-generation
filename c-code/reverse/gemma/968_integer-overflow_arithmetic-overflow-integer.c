#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int num_bags, min_weight, max_weight;
  scanf("Enter the number of bags: ", &num_bags);
  scanf("Enter the minimum weight (in kg): ", &min_weight);
  scanf("Enter the maximum weight (in kg): ", &max_weight);

  int total_weight = 0;
  for (int i = 0; i < num_bags; i++) {
    int bag_weight = rand() % (max_weight - min_weight + 1) + min_weight;
    total_weight += bag_weight;
  }

  printf("Total weight of baggage: %d kg\n", total_weight);

  return 0;
}

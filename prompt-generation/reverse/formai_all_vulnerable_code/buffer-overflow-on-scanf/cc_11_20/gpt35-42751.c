//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main() {
  int num_bags, capacity, i, j, k;
  printf("Welcome to Happy Airlines' Baggage Handling Simulation!\n");
  printf("Please enter the number of bags: ");
  scanf("%d", &num_bags);
  printf("Please enter the capacity of the conveyor belt: ");
  scanf("%d", &capacity);
  if (num_bags <= 0 || capacity <= 0) {
    printf("Invalid input. Please try again.");
    return 0;
  }
  int *bags = (int *)malloc(num_bags * sizeof(int));
  printf("Please enter the weights of the bags:\n");
  for (i = 0; i < num_bags; i++) {
    scanf("%d", &bags[i]);
    if (bags[i] <= 0) {
      printf("Invalid input. Please try again.");
      return 0;
    }
  }
  printf("Let the baggage handling begin!\n");
  int current_weight = 0;
  for (i = 0; i < num_bags; i++) {
    if (current_weight + bags[i] > capacity) {
      printf("Conveyor belt full! Unloading...\n");
      for (j = i - 1; j >= 0; j--) {
        if (bags[j] == -1) continue;
        printf("Bag %d with weight %d removed.\n", j+1, bags[j]);
        current_weight -= bags[j];
        bags[j] = -1;
        if (current_weight + bags[i] <= capacity) {
          printf("Loading bag %d with weight %d.\n", i+1, bags[i]);
          current_weight += bags[i];
          break;
        }
      }
      if (j < 0) {
        printf("No bags can be loaded on the conveyor belt.\n");
        break;
      }
    } else {
      printf("Loading bag %d with weight %d.\n", i+1, bags[i]);
      current_weight += bags[i];
    }
  }
  printf("All bags have been loaded on the conveyor belt. Have a happy flight!\n");
  return 0;
}
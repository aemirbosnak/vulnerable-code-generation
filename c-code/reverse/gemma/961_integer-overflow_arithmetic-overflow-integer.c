#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int numBags, maxWeight, minWeight, totalWeight = 0;
  printf("Enter the number of bags: ");
  scanf("%d", &numBags);

  printf("Enter the maximum weight of the plane: ");
  scanf("%d", &maxWeight);

  printf("Enter the minimum weight of each bag: ");
  scanf("%d", &minWeight);

  srand(time(NULL));

  for (int i = 0; i < numBags; i++) {
    int bagWeight = rand() % (maxWeight - minWeight + 1) + minWeight;
    totalWeight += bagWeight;

    if (bagWeight > maxWeight) {
      printf("Bag %d exceeds the maximum weight limit of 30 units. Please remove this bag.\n", i);
    } else {
      printf("Bag %d has a weight of %d units.\n", i, bagWeight);
    }
  }

  printf("Total weight of bags: %d units.\n", totalWeight);

  return 0;
}

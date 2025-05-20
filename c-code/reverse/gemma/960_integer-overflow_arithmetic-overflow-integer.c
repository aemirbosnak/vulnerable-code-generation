#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <limits.h>

int main() {
  int numBags;
  printf("Enter the number of bags: ");
  scanf("%d", &numBags);

  int bagWeight[numBags];
  for (int i = 0; i < numBags; i++) {
    printf("Enter the weight of each bag (in kilograms): ");
    scanf("%d", &bagWeight[i]);
  }

  int totalWeight = 0;
  for (int i = 0; i < numBags; i++) {
    totalWeight += bagWeight[i];
  }

  if (totalWeight > INT_MAX / 2) {
    printf("Error: The total weight exceeds the airplane's capacity.\n");
  } else {
    printf("Total weight: %d kilograms\n", totalWeight);
  }

  return 0;
}

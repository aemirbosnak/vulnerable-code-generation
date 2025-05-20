#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int numBags;
  printf("Enter the number of bags: ");
  scanf("%d", &numBags);

  int bagWeights[numBags];
  printf("Enter the weight range for each bag (in kg): ");
  for (int i = 0; i < numBags; i++) {
    scanf("%d-%d", &bagWeights[i], &bagWeights[i + 1]);
  }

  int totalWeight = 0;
  for (int i = 0; i < numBags; i++) {
    totalWeight += bagWeights[i + 1] - bagWeights[i];
  }

  int limit = 100;
  int excessBags = 0;
  for (int i = 0; i < numBags; i++) {
    if (bagWeights[i + 1] - bagWeights[i] > limit) {
      excessBags++;
    }
  }

  printf("Total weight: %d kg\n", totalWeight);
  printf("Number of excess bags: %d\n", excessBags);

  return 0;
}

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

  int bagWeight[numBags];
  for (int i = 0; i < numBags; i++) {
    printf("Enter the weight of each bag (in kg): ");
    scanf("%d", &bagWeight[i]);
  }

  int totalWeight = 0;
  for (int i = 0; i < numBags; i++) {
    totalWeight += bagWeight[i];
  }

  printf("The total weight of your baggage is: %d kg", totalWeight);

  return 0;
}

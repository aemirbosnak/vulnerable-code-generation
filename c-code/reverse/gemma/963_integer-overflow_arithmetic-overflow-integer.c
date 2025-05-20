#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_BAGS 10
#define MAX_BAG_WEIGHT 50

typedef struct Bag {
  int weight;
  struct Bag* next;
} Bag;

int main() {
  int numBags;
  printf("Enter the number of bags: ");
  scanf("%d", &numBags);

  if (numBags > MAX_BAGS) {
    printf("Error: Too many bags.\n");
    return 1;
  }

  Bag* head = NULL;
  for (int i = 0; i < numBags; i++) {
    int bagWeight;
    printf("Enter the weight of the bag (in kilograms): ");
    scanf("%d", &bagWeight);

    if (bagWeight > MAX_BAG_WEIGHT) {
      printf("Error: Bag weight too large.\n");
      return 1;
    }

    Bag* newBag = malloc(sizeof(Bag));
    newBag->weight = bagWeight;
    newBag->next = head;
    head = newBag;
  }

  int oversizedBags = 0;
  for (Bag* bag = head; bag; bag = bag->next) {
    if (bag->weight > MAX_BAG_WEIGHT) {
      oversizedBags++;
    }
  }

  if (oversizedBags > 0) {
    printf("Number of oversized bags: %d\n", oversizedBags);
  }

  int timeTaken = 0;
  for (Bag* bag = head; bag; bag = bag->next) {
    timeTaken++;
  }

  printf("Time taken to load bags: %d seconds\n", timeTaken);

  return 0;
}

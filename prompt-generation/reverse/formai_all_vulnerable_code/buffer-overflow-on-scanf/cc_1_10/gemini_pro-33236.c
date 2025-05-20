//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: inquisitive
// Embark on a quest to optimize an inquisitive performance-critical component.

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// A humble function seeking performance enlightenment.
int inquisitiveFunction(int *data, int size) {
  int max = 0;

  // Embark on a meticulous search for the elusive maximum value.
  for (int i = 0; i < size; i++) {
    if (data[i] > max) {
      max = data[i];
    }
  }

  // Behold the wisdom gained from our journey: the maximum value.
  return max;
}

int main() {
  // Set the stage for our performance quest.
  int dataSize;
  printf("Oh, wise adventurer, enter the size of your data array: ");
  scanf("%d", &dataSize);

  int *data = malloc(sizeof(int) * dataSize);

  // Gracefully handle the seeker of wisdom.
  if (data == NULL) {
    printf("Alas, your request cannot be fulfilled. Seek more resources!");
    return 1;
  }

  // Populate the array with data, a reflection of life's complexities.
  srand(time(NULL));
  for (int i = 0; i < dataSize; i++) {
    data[i] = rand() % 1000;
  }

  // Time to unveil the performance secrets of our mysterious function.
  clock_t start = clock();
  int result = inquisitiveFunction(data, dataSize);
  clock_t end = clock();

  // Reveal the secrets: the result and the time it took.
  printf("The peak of your data: %d\n", result);
  printf("The time it took to unveil the truth: %.3f seconds\n",
         (double)(end - start) / CLOCKS_PER_SEC);

  // Bid farewell to the seeker of wisdom, with a touch of intrigue.
  printf("May your future optimizations be as enlightening as these moments.\n");

  free(data);
  return 0;
}
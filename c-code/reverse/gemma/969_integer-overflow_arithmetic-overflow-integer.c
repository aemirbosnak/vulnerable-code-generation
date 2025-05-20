#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <time.h>

int main() {
  int numBags;
  printf("Enter the number of bags: ");
  scanf("%d", &numBags);

  struct Bag {
    int weightMin;
    int weightMax;
    int status;
  } bags[numBags];

  for (int i = 0; i < numBags; i++) {
    printf("Enter the weight range for bag %d (min-max): ", i + 1);
    scanf("%d %d", &bags[i].weightMin, &bags[i].weightMax);
    bags[i].status = 0;
  }

  time_t start = time(NULL);
  while (time(NULL) - start < 60) {
    for (int i = 0; i < numBags; i++) {
      bags[i].status = 1;
      printf("Bag %d status: ", i + 1);
      printf("Processing...\n");
      bags[i].status = 0;
    }
    sleep(1);
  }

  return 0;
}

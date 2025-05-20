//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SORT_MAX 100
#define SORT_MIN 0

void sort_puzzle(int arr[SORT_MAX]) {
  int i, j, k, temp;
  char direction = 'N'; // N for normal, S for reverse

  printf("Welcome to the sorting puzzle! Choose a direction (N/S): ");
  scanf("%c", &direction);

  if (direction == 'N') {
    // Normal sorting
    for (i = 0; i < SORT_MAX; i++) {
      for (j = 0; j < SORT_MAX - i - 1; j++) {
        if (arr[j] > arr[j + 1]) {
          temp = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = temp;
        }
      }
    }
  } else if (direction == 'S') {
    // Reverse sorting
    for (i = SORT_MAX - 1; i >= 0; i--) {
      for (j = i - 1; j >= 0; j--) {
        if (arr[j] > arr[j + 1]) {
          temp = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = temp;
        }
      }
    }
  } else {
    printf("Invalid direction. Exiting...\n");
    return;
  }

  printf("Sorted array: ");
  for (i = 0; i < SORT_MAX; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[SORT_MAX] = {4, 2, 7, 1, 3, 5};
  sort_puzzle(arr);
  return 0;
}
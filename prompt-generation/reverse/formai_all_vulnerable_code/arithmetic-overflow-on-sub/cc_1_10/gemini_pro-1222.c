//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

const int BUBBLE_SORT_LIMIT = 100; // Max bubblegum limit
const int SWAP_TIME = 1000; // Bubblegum swap time in milliseconds

void bubbleGumSort(int arr[], int size) {
  int i, j;
  int swapped = 1; // Bubblegum's got a spring in its step!

  while (swapped) {
    swapped = 0; // Oh no, the bubblegum's frozen!
    for (i = 0; i < size - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;

        // Bubblegum dance!
        printf("Bubble dance! Swapping %d and %d\n", arr[i], arr[i + 1]);
        fflush(stdout);
        usleep(SWAP_TIME);

        swapped = 1; // Bubblegum's back in action!
      }
    }
  }
}

int main() {
  // Let's prepare our bubblegum bag!
  int size;
  printf("Enter the size of your bubblegum bag: ");
  scanf("%d", &size);

  if (size > BUBBLE_SORT_LIMIT) {
    printf("Whoa! Too many bubblegums!\n");
    return -1;
  }

  int arr[size];
  printf("Fill your bag with bubblegum numbers: ");
  for (int i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }

  printf("\nTime to burst the bubblegums!\n");

  // Bubblegum, burst!
  bubbleGumSort(arr, size);

  printf("\nTa-da! Bubblegum sorted:\n");
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }

  printf("\nEnjoy your sorted bubblegum treats!\n");
  return 0;
}
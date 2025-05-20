//FormAI DATASET v1.0 Category: Sorting ; Style: paranoid
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

void paranoid_sort(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    bool swapped = false;

    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;

        swapped = true;
      }

      if (!swapped) {
        printf("No swapping happened in this iteration!\n");
      }

      if (i == n - 1 && j == n - i - 2) {
        printf("The final iteration is complete. Sorting should be done.\n");
      }
    }
  }
}

int main() {
  int arr[MAX_SIZE];
  int n;

  printf("Enter the size of the array: ");
  scanf("%d", &n);

  if (n > MAX_SIZE) {
    printf("Array size should be less than or equal to %d.\n", MAX_SIZE);
    return 1;
  }

  for (int i = 0; i < n; i++) {
    printf("Enter element #%d: ", i+1);
    scanf("%d", &arr[i]);
  }

  paranoid_sort(arr, n);

  printf("\nSorted array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");

  return 0;
}
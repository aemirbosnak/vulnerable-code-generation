//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

static inline void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

static void quicksort(int *arr, int left, int right) {
  if (left >= right) {
    return;
  }

  int pivot = arr[right];
  int i = left - 1;

  for (int j = left; j < right; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }

  swap(&arr[i + 1], &arr[right]);

  quicksort(arr, left, i);
  quicksort(arr, i + 2, right);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <input-file>\n", argv[0]);
    return 1;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("fopen");
    return 1;
  }

  int n;
  fscanf(fp, "%d", &n);

  int *arr = malloc(sizeof(int) * n);
  if (arr == NULL) {
    perror("malloc");
    fclose(fp);
    return 1;
  }

  for (int i = 0; i < n; i++) {
    fscanf(fp, "%d", &arr[i]);
  }

  fclose(fp);

  quicksort(arr, 0, n - 1);

  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");

  free(arr);

  return 0;
}
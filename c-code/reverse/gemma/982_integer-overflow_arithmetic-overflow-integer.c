#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int n;
  scanf("%d", &n);

  char **arr = (char **)malloc(n * sizeof(char *));
  for (int i = 0; i < n; i++) {
    arr[i] = (char *)malloc(1024);
  }

  for (int i = 0; i < n; i++) {
    scanf("%s", arr[i]);
  }

  quicksort(arr, n);

  for (int i = 0; i < n; i++) {
    printf("%s\n", arr[i]);
  }

  for (int i = 0; i < n; i++) {
    free(arr[i]);
  }
  free(arr);

  return 0;
}

void quicksort(char **arr, int n) {
  quicksort_recur(arr, 0, n - 1);
}

void quicksort_recur(char **arr, int low, int high) {
  if (low < high) {
    int partition_index = partition(arr, low, high);
    quicksort_recur(arr, low, partition_index - 1);
    quicksort_recur(arr, partition_index + 1, high);
  }
}

int partition(char **arr, int low, int high) {
  char pivot_element = arr[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (strcmp(arr[j], pivot_element) < 0) {
      i++;
      char *temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  char *temp = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = temp;
  return i + 1;
}

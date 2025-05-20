#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  scanf("%d", &n);

  int *arr = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    arr[i] = 0;
  }

  arr[n - 1] = 1;

  printf("%d", arr[n - 1]);

  free(arr);

  return 0;
}

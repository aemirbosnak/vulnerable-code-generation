#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  int i = 0;
  int n = 0;

  printf("Original array:");
  for (i = 0; i < 10; i++) {
    printf(" %d ", a[i]);
  }

  printf("\nCompressed array:");
  for (i = 0; i < 10; i++) {
    n = a[i] - 1;
    printf(" %d ", n);
  }

  return 0;
}

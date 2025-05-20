#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  scanf("%d", &n);
  int *a = malloc(n * sizeof(int));
  int *b = malloc(n * sizeof(int));
  int *c = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    a[i] = b[i] = c[i] = 0;
  }
  hanoi(n, a, b, c);
  free(a);
  free(b);
  free(c);
  return 0;
}

void hanoi(int n, int *a, int *b, int *c) {
  if (n == 1) {
    a[0] = 1;
  } else {
    hanoi(n - 1, a, c, b);
    a[0] = n;
    hanoi(n - 1, b, a, c);
  }
}

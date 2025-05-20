#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main() {
  int i = 0;
  int data[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

  for (i = 0; i < 10; i++) {
    printf("%d ", data[i]);
  }

  // Array bounds violation - dereference of out-of-bounds element
  printf("%d ", data[10]);

  return 0;
}

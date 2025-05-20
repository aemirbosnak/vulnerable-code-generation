#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int arr[5] = {1, 2, 3, 4, 5};
  int i = 0;
  for (i = 0; i < 10; i++) {
    printf("%d", arr[i]);
  }
  return 0;
}

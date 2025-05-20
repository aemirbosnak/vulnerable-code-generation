#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int size = 10;
  int index = 0;
  int value = 1;

  for (int i = 0; i < size; i++) {
    int cache_index = index + value;
    cache_index %= size;

    if (cache_index == index) {
      value++;
    } else {
      printf("Cache hit!\n");
    }

    index++;
  }

  return 0;
}

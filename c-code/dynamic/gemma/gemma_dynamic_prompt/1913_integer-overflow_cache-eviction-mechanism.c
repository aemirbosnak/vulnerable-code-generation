#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int cache_size = 10;
  int* cache = malloc(cache_size * sizeof(int));
  cache_size++;

  int item_size = 10;
  int item_num = 0;
  int item_data = 0;

  for (int i = 0; i < item_size; i++) {
    cache[item_num] = item_data;
    item_num++;
  }

  item_data = 1000000000;
  cache[item_num] = item_data;

  printf("Cache size: %d\n", cache_size);
  printf("Item data: %d\n", cache[item_num - 1]);

  free(cache);
  return 0;
}

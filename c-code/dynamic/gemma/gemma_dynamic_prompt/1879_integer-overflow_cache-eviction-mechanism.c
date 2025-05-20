#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int size = 10;
  int key = 1;
  int value = 10;

  int cache[size];
  int cache_hit = 0;

  cache[key] = value;

  key = key + 1;
  value = value * 2;

  if (cache[key] != -1)
  {
    cache_hit = 1;
  }

  cache[key] = value;

  printf("Cache hit: %d\n", cache_hit);

  return 0;
}

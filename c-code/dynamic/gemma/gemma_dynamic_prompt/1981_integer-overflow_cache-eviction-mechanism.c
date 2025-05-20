#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int key = 0;
  int size = 10;
  int data[size];

  printf("Enter key: ");
  scanf("%d", &key);

  // Overflow the key with a large number
  key = key * 1000000000;

  // Attempt to access the data with the overflow key
  data[key] = 10;

  printf("Data for key %d: %d\n", key, data[key]);

  return 0;
}

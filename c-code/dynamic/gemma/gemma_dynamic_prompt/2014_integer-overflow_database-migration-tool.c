#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int number_of_records = 0;
  int record_size = 0;
  int total_size = 0;

  // Overflow-prone calculation
  number_of_records = 1000000000;
  record_size = 10;
  total_size = number_of_records * record_size;

  // Print the total size
  printf("Total size: %d bytes\n", total_size);

  return 0;
}

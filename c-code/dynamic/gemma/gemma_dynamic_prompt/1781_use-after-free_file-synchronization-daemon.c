#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE* file_ptr = fopen("test.txt", "w");
  fclose(file_ptr);
  free(file_ptr); // Use after free vulnerability

  return 0;
}

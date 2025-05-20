#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE* file = fopen("periodic_table.txt", "r");
  if (file == NULL) {
    return 1;
  }

  char* line = NULL;
  size_t line_size = 0;
  getline(line, &line_size, file);

  if (line == NULL) {
    fclose(file);
    return 1;
  }

  // Vulnerable code: dereference of a null pointer
  int element_number = atoi(line);
  printf("Element number: %d", element_number);

  fclose(file);
  return 0;
}

#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *file = fopen("file.txt", "w");
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  arr[10] = 11; // Array bounds violation

  fprintf(file, "Hello, world!");
  fclose(file);

  return 0;
}

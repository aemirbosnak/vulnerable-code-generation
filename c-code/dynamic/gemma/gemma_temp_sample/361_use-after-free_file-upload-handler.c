#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char* file_data = NULL;
  int file_size = 0;

  // Allocate memory for file data
  file_data = malloc(1024);

  // Receive file data from client
  file_size = read(0, file_data, 1024);

  // Use after free vulnerability
  free(file_data);
  FILE* file = fopen("test.txt", "w");
  fwrite(file_data, file_size, 1, file);
  fclose(file);

  return 0;
}

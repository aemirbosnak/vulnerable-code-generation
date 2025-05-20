#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *file = fopen("/path/to/file.txt", "w");
  int size = 1024 * 1024;
  char *buffer = malloc(size);

  if (file == NULL || buffer == NULL) {
    perror("Error");
    exit(1);
  }

  // Read data from the client
  size_t read_size = read(fileno(file), buffer, size);

  // Write data to the file
  fwrite(buffer, read_size, 1, file);

  fclose(file);
  free(buffer);

  return 0;
}

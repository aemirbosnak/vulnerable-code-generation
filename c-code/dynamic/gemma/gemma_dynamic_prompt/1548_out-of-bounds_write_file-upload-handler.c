#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *buffer = NULL;
  int size = 0;

  // Allocate memory for the file data
  buffer = malloc(1024);

  // Read the file data from the client
  FILE *file = fopen("myfile.txt", "r");
  if (file) {
    size = fread(buffer, 1, 1024, file);
  }

  // Write the file data to the server
  FILE *out = fopen("uploaded_file.txt", "w");
  if (out) {
    fwrite(buffer, 1, size, out);
  }

  // Free the memory allocated for the file data
  free(buffer);

  return 0;
}

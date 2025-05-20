#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

void encrypt_file(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return;
  }

  char *buffer = NULL;
  size_t buffer_size = 0;
  size_t read_size = 0;

  while ((read_size = fread(buffer, 1, buffer_size, fp)) > 0) {
    buffer_size *= 2;
    buffer = realloc(buffer, buffer_size);
    buffer[read_size - 1] = '\0';
  }

  fclose(fp);

  // Deliberate null pointer dereference
  char **ptr = NULL;
  *ptr = buffer;
  free(buffer);
}

int main() {
  encrypt_file("my_secret.txt");
  return 0;
}

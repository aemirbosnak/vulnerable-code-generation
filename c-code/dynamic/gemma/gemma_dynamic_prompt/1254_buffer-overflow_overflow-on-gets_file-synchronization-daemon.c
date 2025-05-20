#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *buffer = NULL;
  int size = 0;

  // Get the file contents
  FILE *file = fopen("test.txt", "r");
  if (file) {
    char line[1024];
    while (fgets(line, 1024, file) != NULL) {
      size += strlen(line) + 1;
    }
    fclose(file);
  }

  // Allocate memory for the buffer
  buffer = malloc(size);

  // Read the file contents again and store them in the buffer
  file = fopen("test.txt", "r");
  if (file) {
    char line[1024];
    while (fgets(line, 1024, file) != NULL) {
      strcpy(buffer, line);
    }
    fclose(file);
  }

  // Print the contents of the buffer
  printf("%s", buffer);

  // Free the memory allocated for the buffer
  free(buffer);

  return 0;
}

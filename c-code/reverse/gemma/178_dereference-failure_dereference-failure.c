#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char filename[256];
  printf("Enter filename: ");
  scanf("%s", filename);

  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file: %s", filename);
    return 1;
  }

  char buffer[1024];
  size_t read_size = fread(buffer, 1, 1024, file);
  fclose(file);

  buffer[read_size - 1] = '\0';

  char *processed_buffer = strchr(buffer, '\0') - 1;
  processed_buffer = strcspn(processed_buffer, " \r\n");

  if (processed_buffer == buffer) {
    printf("No data found.");
  } else {
    printf("Data recovered: %s", processed_buffer);
  }

  return 0;
}

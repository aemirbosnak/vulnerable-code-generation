#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char buffer[1024];
  char filename[256];

  printf("Enter file name: ");
  scanf("%s", filename);

  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening file");
    exit(1);
  }

  int read_size = fread(buffer, 1, 1024, file);
  fclose(file);

  if (read_size > 0) {
    printf("Data from file:\n");
    printf("%s", buffer);
  } else {
    printf("File is empty");
  }

  return 0;
}

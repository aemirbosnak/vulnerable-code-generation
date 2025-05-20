#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char buffer[1024];
  FILE *file = fopen("user_file.txt", "r");
  if (file == NULL) {
    printf("Error opening file!");
    return 1;
  }

  int read_size = fread(buffer, 1, 1024, file);
  if (read_size == 0) {
    printf("File is empty!");
    fclose(file);
    return 1;
  }

  fclose(file);

  printf("You have recovered the data from 'user_file.txt':\n");
  printf("%s", buffer);

  return 0;
}

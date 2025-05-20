#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char filename[256];
  FILE *file;
  char data[1024];
  int data_size = 0;

  printf("Enter the name of the file you want to recover data from: ");
  scanf("%s", filename);

  file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file: %s", filename);
    return 1;
  }

  data_size = fread(data, 1, 1024, file);
  fclose(file);

  if (data_size == 0) {
    printf("File is empty");
  } else {
    printf("Recovered data from %s:", filename);
    printf("\n%s", data);
  }

  return 0;
}

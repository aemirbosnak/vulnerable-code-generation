#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char filename[256];
  FILE *file;
  char data[1024];

  printf("Enter filename: ");
  scanf("%s", filename);

  file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  fscanf(file, "%s", data);
  fclose(file);

  for (int i = 0; data[i] != '\0'; i++) {
    if (data[i] < 32 || data[i] > 126) {
      printf("Error: non-ASCII character found.\n");
      return 1;
    }
  }

  printf("File contents are valid.\n");
  return 0;
}

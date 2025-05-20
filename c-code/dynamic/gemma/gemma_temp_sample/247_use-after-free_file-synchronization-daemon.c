#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
  char *filename = malloc(1024);
  FILE *fp = fopen("test.txt", "w");
  filename = "test.txt";

  // Write data to the file
  fprintf(fp, "Hello, world!");

  // Close the file
  fclose(fp);

  // Free the memory
  free(filename);

  return 0;
}

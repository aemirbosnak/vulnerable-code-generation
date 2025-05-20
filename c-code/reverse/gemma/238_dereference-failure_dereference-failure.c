#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *fp;
  char **data = NULL;
  int num_elements = 0;
  char line[1024];

  fp = fopen("periodic_table.txt", "r");
  if (fp == NULL) {
    fprintf(stderr, "Error opening file: %s", "periodic_table.txt");
    return 1;
  }

  // Count the number of elements in the file
  while (fgets(line, 1024, fp) != NULL) {
    num_elements++;
  }

  // Allocate memory for the data
  data = malloc(num_elements * sizeof(char *));
  if (data == NULL) {
    fprintf(stderr, "Error allocating memory: %s", "data");
    fclose(fp);
    return 1;
  }

  // Read the data from the file
  rewind(fp);
  for (int i = 0; i < num_elements; i++) {
    fgets(line, 1024, fp);
    data[i] = strdup(line);
  }

  fclose(fp);

  // Print the questions
  for (int i = 0; i < 10; i++) {
    printf("%s\n", data[i]);
  }

  return 0;
}

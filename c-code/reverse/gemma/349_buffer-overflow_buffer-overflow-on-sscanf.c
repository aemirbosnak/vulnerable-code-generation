#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char key[256], value[256], data[1024];
  int i, data_size = 0, found = 0;
  FILE *fp = fopen("data.txt", "r");

  // Read data from file
  if (fp) {
    while (fscanf(fp, "%s: %s\n", key, value) != EOF) {
      data[data_size++] = malloc(strlen(key) + strlen(value) + 1);
      strcpy(data[data_size - 1], key);
      strcpy(data[data_size - 1] + strlen(key) + 1, value);
    }
    fclose(fp);
  }

  // Get user input
  printf("Enter key-value pair query: ");
  scanf("%s: %s", key, value);

  // Search for data
  for (i = 0; i < data_size; i++) {
    if (strcmp(key, data[i]) == 0) {
      printf("Value: %s\n", data[i] + strlen(key) + 1);
      found = 1;
    }
  }

  // Print result
  if (!found) {
    printf("No data found.\n");
  }

  return 0;
}

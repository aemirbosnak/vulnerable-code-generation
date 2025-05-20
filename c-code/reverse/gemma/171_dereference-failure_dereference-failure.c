#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *filename;
  FILE *fp;
  char data[1024];
  int i, valid_ascii = 1;

  // Get the file name from the user
  printf("Enter the file name: ");
  scanf("%s", filename);

  // Open the file
  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  // Read the file data
  fread(data, 1, 1024, fp);

  // Close the file
  fclose(fp);

  // Remove spaces and nulls from the data
  for (i = 0; data[i] != '\0'; i++) {
    if (data[i] == ' ' || data[i] == '\0') {
      data[i] = '\0';
    }
  }

  // Check if the remaining data is valid ASCII
  for (i = 0; data[i] != '\0'; i++) {
    if (data[i] < 32 || data[i] > 126) {
      valid_ascii = 0;
    }
  }

  // Print the results
  if (valid_ascii) {
    printf("The data is valid ASCII.\n");
  } else {
    printf("The data is not valid ASCII.\n");
  }

  return 0;
}

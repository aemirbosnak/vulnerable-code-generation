//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

int main() {
  // Declare variables
  char *filename, *buffer, *metadata;
  FILE *file;
  int size, i, j;

  // Get the filename from the user
  printf("Enter the name of the file you wish to extract metadata from: ");
  scanf("%s", filename);

  // Open the file
  file = fopen(filename, "rb");
  if (file == NULL) {
    printf("Error opening file %s\n", filename);
    return 1;
  }

  // Get the size of the file
  fseek(file, 0, SEEK_END);
  size = ftell(file);
  fseek(file, 0, SEEK_SET);

  // Allocate memory for the buffer
  buffer = (char *)malloc(size);
  if (buffer == NULL) {
    printf("Error allocating memory for buffer\n");
    fclose(file);
    return 1;
  }

  // Read the file into the buffer
  fread(buffer, 1, size, file);
  fclose(file);

  // Search for the metadata
  metadata = strstr(buffer, "Metadata:");
  if (metadata == NULL) {
    printf("No metadata found in file %s\n", filename);
    free(buffer);
    return 1;
  }

  // Print the metadata
  printf("Metadata:\n");
  for (i = 0; i < size; i++) {
    if (buffer[i] == '\n') {
      printf("\n");
    } else {
      printf("%c", buffer[i]);
    }
  }

  // Free the memory
  free(buffer);

  return 0;
}
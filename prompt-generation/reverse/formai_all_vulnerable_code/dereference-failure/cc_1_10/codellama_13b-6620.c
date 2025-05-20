//Code Llama-13B DATASET v1.0 Category: Metadata Extractor ; Style: imaginative
// C Metadata Extractor
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct {
  char name[MAX_LEN];
  char type[MAX_LEN];
  int size;
  int offset;
} Metadata;

void extractMetadata(Metadata *metadata, char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening file %s\n", filename);
    return;
  }

  // Read the first line of the file
  char line[MAX_LEN];
  if (fgets(line, MAX_LEN, fp) == NULL) {
    printf("Error reading from file %s\n", filename);
    fclose(fp);
    return;
  }

  // Split the line into tokens based on whitespace
  char *token = strtok(line, " ");
  if (token == NULL) {
    printf("Error splitting line into tokens\n");
    fclose(fp);
    return;
  }

  // Parse the tokens to extract the metadata
  int i = 0;
  while (token != NULL) {
    if (i == 0) {
      strcpy(metadata[i].name, token);
    } else if (i == 1) {
      strcpy(metadata[i].type, token);
    } else if (i == 2) {
      metadata[i].size = atoi(token);
    } else if (i == 3) {
      metadata[i].offset = atoi(token);
    }
    token = strtok(NULL, " ");
    i++;
  }

  // Close the file
  fclose(fp);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  // Extract the metadata from the file
  Metadata metadata;
  extractMetadata(&metadata, argv[1]);

  // Print the metadata
  printf("Name: %s\n", metadata.name);
  printf("Type: %s\n", metadata.type);
  printf("Size: %d\n", metadata.size);
  printf("Offset: %d\n", metadata.offset);

  return 0;
}
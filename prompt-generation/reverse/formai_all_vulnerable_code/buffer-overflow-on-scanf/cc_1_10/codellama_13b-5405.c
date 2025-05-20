//Code Llama-13B DATASET v1.0 Category: Metadata Extractor ; Style: rigorous
// A unique C Metadata Extractor example program in a rigorous style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store metadata information
typedef struct {
  char title[256];
  char author[256];
  char year[4];
  char genre[256];
} Metadata;

// Function to extract metadata from a file
void extractMetadata(char *filename, Metadata *metadata) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file %s\n", filename);
    exit(1);
  }

  char line[256];
  while (fgets(line, sizeof(line), file) != NULL) {
    // Check if line contains metadata
    if (strstr(line, "Title:") != NULL) {
      strcpy(metadata->title, line + 6);
    } else if (strstr(line, "Author:") != NULL) {
      strcpy(metadata->author, line + 7);
    } else if (strstr(line, "Year:") != NULL) {
      strcpy(metadata->year, line + 5);
    } else if (strstr(line, "Genre:") != NULL) {
      strcpy(metadata->genre, line + 6);
    }
  }

  fclose(file);
}

int main() {
  // Read file name from command line
  char filename[256];
  printf("Enter file name: ");
  scanf("%s", filename);

  // Extract metadata from file
  Metadata metadata;
  extractMetadata(filename, &metadata);

  // Print metadata
  printf("Title: %s\n", metadata.title);
  printf("Author: %s\n", metadata.author);
  printf("Year: %s\n", metadata.year);
  printf("Genre: %s\n", metadata.genre);

  return 0;
}
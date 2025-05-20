//Code Llama-13B DATASET v1.0 Category: Metadata Extractor ; Style: dynamic
// Metadata Extractor Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store metadata information
struct metadata {
  char *title;
  char *author;
  char *year;
  char *publisher;
};

// Function to extract metadata from a file
void extract_metadata(struct metadata *md, char *filename) {
  FILE *fp = fopen(filename, "r");
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  while ((read = getline(&line, &len, fp)) != -1) {
    // Check for title
    if (strstr(line, "title") != NULL) {
      md->title = strtok(line, "\"");
      md->title = strtok(NULL, "\"");
    }
    // Check for author
    if (strstr(line, "author") != NULL) {
      md->author = strtok(line, "\"");
      md->author = strtok(NULL, "\"");
    }
    // Check for year
    if (strstr(line, "year") != NULL) {
      md->year = strtok(line, "\"");
      md->year = strtok(NULL, "\"");
    }
    // Check for publisher
    if (strstr(line, "publisher") != NULL) {
      md->publisher = strtok(line, "\"");
      md->publisher = strtok(NULL, "\"");
    }
  }

  fclose(fp);
}

// Function to print metadata information
void print_metadata(struct metadata *md) {
  printf("Title: %s\n", md->title);
  printf("Author: %s\n", md->author);
  printf("Year: %s\n", md->year);
  printf("Publisher: %s\n", md->publisher);
}

int main(int argc, char *argv[]) {
  // Check for filename argument
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  // Create metadata structure
  struct metadata md;

  // Extract metadata from file
  extract_metadata(&md, argv[1]);

  // Print metadata information
  print_metadata(&md);

  return 0;
}
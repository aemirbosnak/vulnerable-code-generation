//Code Llama-13B DATASET v1.0 Category: Metadata Extractor ; Style: curious
// Curious C Metadata Extractor Example Program
#include <stdio.h>
#include <stdlib.h>

// Define metadata struct
typedef struct {
  char* title;
  char* author;
  char* description;
  int num_pages;
} Metadata;

// Function to extract metadata from a file
Metadata extract_metadata(char* filepath) {
  FILE* fp = fopen(filepath, "r");
  char* line = NULL;
  size_t len = 0;
  ssize_t read;

  // Read the first line of the file
  read = getline(&line, &len, fp);
  if (read == -1) {
    printf("Error reading file.\n");
    exit(1);
  }

  // Parse the first line to extract metadata
  char* title = strtok(line, " ");
  char* author = strtok(NULL, " ");
  char* description = strtok(NULL, " ");
  int num_pages = atoi(strtok(NULL, " "));

  // Create a new metadata struct
  Metadata metadata = {
    .title = title,
    .author = author,
    .description = description,
    .num_pages = num_pages,
  };

  // Close the file
  fclose(fp);

  return metadata;
}

// Function to print metadata
void print_metadata(Metadata metadata) {
  printf("Title: %s\n", metadata.title);
  printf("Author: %s\n", metadata.author);
  printf("Description: %s\n", metadata.description);
  printf("Number of pages: %d\n", metadata.num_pages);
}

int main(int argc, char* argv[]) {
  // Check if the file path is provided
  if (argc < 2) {
    printf("Please provide a file path.\n");
    exit(1);
  }

  // Extract metadata from the file
  Metadata metadata = extract_metadata(argv[1]);

  // Print the metadata
  print_metadata(metadata);

  return 0;
}
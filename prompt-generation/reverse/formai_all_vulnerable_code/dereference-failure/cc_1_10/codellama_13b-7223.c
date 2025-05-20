//Code Llama-13B DATASET v1.0 Category: Metadata Extractor ; Style: Donald Knuth
// C Metadata Extractor Example Program
// Author: [Your Name]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure to store metadata
typedef struct {
  char* name;
  char* value;
} metadata;

// Function to extract metadata from a file
void extract_metadata(char* filename, metadata* metadata_list, int* num_metadata) {
  // Open the file
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file: %s\n", filename);
    exit(1);
  }

  // Read the file line by line
  char* line = NULL;
  size_t len = 0;
  ssize_t read;
  int line_num = 1;
  while ((read = getline(&line, &len, file)) != -1) {
    // Check if the line contains metadata
    char* colon_pos = strchr(line, ':');
    if (colon_pos != NULL) {
      // Extract the name and value
      char* name = strndup(line, colon_pos - line);
      char* value = strdup(colon_pos + 1);

      // Add the metadata to the list
      metadata_list[*num_metadata].name = name;
      metadata_list[*num_metadata].value = value;
      *num_metadata += 1;
    }

    // Increment the line number
    line_num += 1;
  }

  // Close the file
  fclose(file);
}

// Function to print the metadata
void print_metadata(metadata* metadata_list, int num_metadata) {
  for (int i = 0; i < num_metadata; i++) {
    printf("%s: %s\n", metadata_list[i].name, metadata_list[i].value);
  }
}

// Main function
int main(int argc, char* argv[]) {
  // Check if a filename was provided
  if (argc < 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    exit(1);
  }

  // Extract the metadata
  char* filename = argv[1];
  metadata* metadata_list = malloc(sizeof(metadata) * 100);
  int num_metadata = 0;
  extract_metadata(filename, metadata_list, &num_metadata);

  // Print the metadata
  print_metadata(metadata_list, num_metadata);

  // Free the memory
  for (int i = 0; i < num_metadata; i++) {
    free(metadata_list[i].name);
    free(metadata_list[i].value);
  }
  free(metadata_list);

  return 0;
}
//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Function to extract metadata from a file
void extract_metadata(char *filename) {
  FILE *fp;
  char ch;
  int lines = 0, words = 0, characters = 0;
  fp = fopen(filename, "r");

  // If file does not exist or cannot be opened
  if (fp == NULL) {
    printf("Unable to open file!\n");
    exit(0);
  }

  // Count lines, words and characters
  while ((ch = fgetc(fp)) != EOF) {
    characters++;

    // Count words when a space or newline is encountered
    if (ch == ' ' || ch == '\n')
      words++;

    // Count lines when a newline is encountered
    if (ch == '\n')
      lines++;
  }

  // Close file
  fclose(fp);

  // Print the metadata
  printf("Metadata for file '%s':\n", filename);
  printf("Lines: %d\n", lines);
  printf("Words: %d\n", words);
  printf("Characters: %d\n", characters);
}

// Main function
int main() {
  char filename[100];

  // Get filename from user
  printf("Enter the filename: ");
  scanf("%s", filename);

  // Call function to extract metadata
  extract_metadata(filename);

  return 0;
}
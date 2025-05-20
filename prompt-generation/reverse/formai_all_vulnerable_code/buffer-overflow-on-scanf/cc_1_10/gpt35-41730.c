//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: funny
// Welcome to the "Metadata Mayhem" program!
// This program will extract metadata from a file
// and hopefully not cause too much chaos along the way

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_METADATA_LENGTH 512

int main() {

  // Let's start by asking the user for the filename
  char filename[MAX_FILENAME_LENGTH];
  printf("Enter the name of the file you want to extract metadata from: ");
  scanf("%s", filename);

  // Next, let's open the file and read in its contents
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    printf("Oops, there was an error opening the file. Please try again.\n");
    return 1;
  }

  char contents[MAX_METADATA_LENGTH] = "";
  char line[MAX_METADATA_LENGTH];

  while (fgets(line, sizeof(line), file)) {
    strcat(contents, line);
  }

  fclose(file);

  // Now let's extract the metadata
  char metadata[MAX_METADATA_LENGTH] = "";
  int is_in_metadata = 0;
  int i = 0;

  while (contents[i] != '\0') {
    char c = contents[i];

    if (c == '[') {
      is_in_metadata = 1;
    } else if (c == ']') {
      is_in_metadata = 0;
    } else if (is_in_metadata) {
      strncat(metadata, &c, 1);
    }

    i++;
  }

  // Finally, let's output the metadata to the user
  if (strlen(metadata) > 0) {
    printf("The metadata in the file is:\n%s\n", metadata);
  } else {
    printf("Oops, it looks like there was no metadata in the file.\n");
  }

  return 0;
}
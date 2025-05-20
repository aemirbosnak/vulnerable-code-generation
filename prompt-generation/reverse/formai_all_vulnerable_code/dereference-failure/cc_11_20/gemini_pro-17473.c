//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <regex.h>

#define MAX_LINE_LENGTH 1024
#define MAX_METADATA_KEY_LENGTH 1024
#define MAX_METADATA_VALUE_LENGTH 1024
#define MAX_METADATA_COUNT 1024

struct metadata {
  char *key;
  char *value;
};

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Open the file
  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  // Read the file line by line
  char line[MAX_LINE_LENGTH];
  while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
    // Remove trailing whitespace
    size_t line_length = strlen(line);
    while (line_length > 0 && isspace(line[line_length - 1])) {
      line_length--;
    }
    line[line_length] = '\0';

    // Find the first colon in the line
    char *colon_position = strchr(line, ':');
    if (colon_position == NULL) {
      continue;
    }

    // Extract the metadata key and value
    char *key = strndup(line, colon_position - line);
    char *value = strdup(colon_position + 1);

    // Remove leading and trailing whitespace from the key and value
    while (*key != '\0' && isspace(*key)) {
      key++;
    }
    while (*value != '\0' && isspace(*value)) {
      value++;
    }

    // Print the metadata key and value
    printf("%s: %s\n", key, value);

    // Free the memory allocated for the key and value
    free(key);
    free(value);
  }

  // Close the file
  fclose(fp);

  return EXIT_SUCCESS;
}
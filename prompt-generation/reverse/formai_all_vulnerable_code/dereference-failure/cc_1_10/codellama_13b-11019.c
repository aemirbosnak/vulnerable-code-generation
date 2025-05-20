//Code Llama-13B DATASET v1.0 Category: HTML beautifier ; Style: ultraprecise
/*
 * HTML Beautifier
 *
 * This program takes an HTML file as input and outputs a
 * beautified version of the HTML code.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  // Check command-line arguments
  if (argc != 2) {
    printf("Usage: %s <html-file>\n", argv[0]);
    return 1;
  }

  // Open input file
  FILE *in = fopen(argv[1], "r");
  if (!in) {
    perror("fopen");
    return 1;
  }

  // Open output file
  FILE *out = fopen("beautified.html", "w");
  if (!out) {
    perror("fopen");
    fclose(in);
    return 1;
  }

  // Read input file line by line
  char line[BUFFER_SIZE];
  while (fgets(line, BUFFER_SIZE, in)) {
    // Remove leading and trailing whitespace
    char *start = line;
    while (*start == ' ') {
      start++;
    }
    char *end = start + strlen(start) - 1;
    while (*end == ' ') {
      end--;
    }
    *(end + 1) = '\0';

    // Add indentation for nested elements
    if (strstr(start, "</")) {
      // Outdent for closing tags
      fputs("  ", out);
    } else {
      // Indent for opening tags
      fputs("  ", out);
    }

    // Write line to output file
    fputs(start, out);
  }

  // Close files
  fclose(in);
  fclose(out);

  return 0;
}
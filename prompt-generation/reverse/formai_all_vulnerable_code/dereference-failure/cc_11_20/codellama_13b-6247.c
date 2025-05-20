//Code Llama-13B DATASET v1.0 Category: HTML beautifier ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Declare variables
  char* html = NULL;
  char* output = NULL;
  int i, j, k, l;
  int num_spaces;
  int num_newlines;
  int num_tabs;

  // Get HTML code from user
  printf("Enter HTML code: ");
  scanf("%s", &html);

  // Initialize output string
  output = (char*)malloc(sizeof(char) * (strlen(html) + 1));
  output[0] = '\0';

  // Loop through HTML code
  for (i = 0; html[i] != '\0'; i++) {
    // Check if character is a space
    if (html[i] == ' ') {
      // Count number of spaces
      num_spaces = 1;
      for (j = i + 1; html[j] == ' ' && j < strlen(html); j++) {
        num_spaces++;
      }

      // Add appropriate number of spaces to output
      for (k = 0; k < num_spaces; k++) {
        output[strlen(output)] = ' ';
      }

      // Move past spaces in HTML code
      i += num_spaces - 1;
    }

    // Check if character is a newline
    else if (html[i] == '\n') {
      // Count number of newlines
      num_newlines = 1;
      for (j = i + 1; html[j] == '\n' && j < strlen(html); j++) {
        num_newlines++;
      }

      // Add appropriate number of newlines to output
      for (k = 0; k < num_newlines; k++) {
        output[strlen(output)] = '\n';
      }

      // Move past newlines in HTML code
      i += num_newlines - 1;
    }

    // Check if character is a tab
    else if (html[i] == '\t') {
      // Count number of tabs
      num_tabs = 1;
      for (j = i + 1; html[j] == '\t' && j < strlen(html); j++) {
        num_tabs++;
      }

      // Add appropriate number of tabs to output
      for (k = 0; k < num_tabs; k++) {
        output[strlen(output)] = '\t';
      }

      // Move past tabs in HTML code
      i += num_tabs - 1;
    }

    // Otherwise, add character to output
    else {
      output[strlen(output)] = html[i];
    }
  }

  // Print output
  printf("%s", output);

  // Free memory
  free(output);

  return 0;
}
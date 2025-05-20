//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to beautify HTML code
char *beautify_html(char *html) {
  // Allocate memory for the beautified HTML code
  char *beautified_html = malloc(strlen(html) * 2);

  // Initialize the beautified HTML code
  beautified_html[0] = '\0';

  // Initialize the current line length
  int line_length = 0;

  // Iterate over the HTML code
  for (char *p = html; *p != '\0'; p++) {
    // If the current line length is greater than the maximum line length,
    // start a new line
    if (line_length > 80) {
      strcat(beautified_html, "\n");
      line_length = 0;
    }

    // Append the current character to the beautified HTML code
    strncat(beautified_html, p, 1);

    // If the current character is a newline character, reset the line length
    if (*p == '\n') {
      line_length = 0;
    }

    // Otherwise, increment the line length
    else {
      line_length++;
    }
  }

  // Return the beautified HTML code
  return beautified_html;
}

// Main function
int main() {
  // Get the HTML code from the user
  char *html = malloc(1024);
  printf("Enter HTML code: ");
  gets(html);

  // Beautify the HTML code
  char *beautified_html = beautify_html(html);

  // Print the beautified HTML code
  printf("\nBeautified HTML code:\n\n%s", beautified_html);

  // Free the allocated memory
  free(html);
  free(beautified_html);

  return 0;
}
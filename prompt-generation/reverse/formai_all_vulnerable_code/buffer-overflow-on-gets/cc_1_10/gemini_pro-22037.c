//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to beautify HTML code
char *beautify_html(char *html) {
  // Allocate memory for the beautified HTML code
  char *beautified_html = malloc(strlen(html) * 2);

  // Initialize the beautified HTML code
  strcpy(beautified_html, "");

  // Beautify the HTML code
  int i = 0;
  int indent_level = 0;
  while (html[i] != '\0') {
    // Check if the current character is a newline character
    if (html[i] == '\n') {
      // If the current character is a newline character, increment the indent level
      indent_level++;
    }

    // Add the current character to the beautified HTML code
    strcat(beautified_html, &html[i]);

    // Check if the current character is a closing bracket
    if (html[i] == '>') {
      // If the current character is a closing bracket, decrement the indent level
      indent_level--;
    }

    // Add indentation to the beautified HTML code
    for (int j = 0; j < indent_level; j++) {
      strcat(beautified_html, "  ");
    }

    // Increment the index of the current character
    i++;
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
  printf("Beautified HTML code:\n%s", beautified_html);

  // Free the memory allocated for the beautified HTML code
  free(beautified_html);

  // Free the memory allocated for the HTML code
  free(html);

  return 0;
}
//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to beautify HTML code
char *beautify_html(char *html) {
  // Allocate memory for the beautified HTML code
  char *beautified_html = malloc(strlen(html) * 2);

  // Initialize the beautified HTML code
  strcpy(beautified_html, "");

  // Iterate over the HTML code
  for (int i = 0; i < strlen(html); i++) {
    // If the current character is a '<' or '>', add it to the beautified HTML code
    if (html[i] == '<' || html[i] == '>') {
      strcat(beautified_html, &html[i]);
    }
    // If the current character is a whitespace character, add a newline character to the beautified HTML code
    else if (isspace(html[i])) {
      strcat(beautified_html, "\n");
    }
    // Otherwise, add the current character to the beautified HTML code
    else {
      strncat(beautified_html, &html[i], 1);
    }
  }

  // Return the beautified HTML code
  return beautified_html;
}

// Main function
int main() {
  // Get the HTML code from the user
  char *html = malloc(1024);
  printf("Enter the HTML code to beautify: ");
  gets(html);

  // Beautify the HTML code
  char *beautified_html = beautify_html(html);

  // Print the beautified HTML code
  printf("Beautified HTML code:\n%s", beautified_html);

  // Free the allocated memory
  free(html);
  free(beautified_html);

  return 0;
}
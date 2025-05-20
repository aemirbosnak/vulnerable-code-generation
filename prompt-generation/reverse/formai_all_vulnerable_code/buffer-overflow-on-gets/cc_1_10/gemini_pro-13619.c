//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to beautify HTML code
void beautify_html(char *html) {
  // Initialize variables
  int i = 0;
  int indent_level = 0;
  int in_tag = 0;
  char *output = malloc(MAX_LINE_LENGTH);

  // Loop through each character in the HTML code
  while (html[i] != '\0') {
    // Check if we are in a tag
    if (html[i] == '<') {
      in_tag = 1;
    } else if (html[i] == '>') {
      in_tag = 0;
    }

    // Check if we need to indent
    if (!in_tag && html[i] != '\n' && html[i] != '\r') {
      for (int j = 0; j < indent_level; j++) {
        output[strlen(output)] = ' ';
      }
    }

    // Check if we need to add a newline
    if (html[i] == '\n' || html[i] == '\r') {
      output[strlen(output)] = '\n';
      if (!in_tag) {
        indent_level++;
      }
    }

    // Add the character to the output string
    output[strlen(output)] = html[i];

    // Increment the index
    i++;
  }

  // Print the beautified HTML code
  printf("%s", output);

  // Free the output string
  free(output);
}

// Main function
int main() {
  // Get the HTML code from the user
  char *html = malloc(MAX_LINE_LENGTH);
  printf("Enter your HTML code:\n");
  gets(html);

  // Beautify the HTML code
  beautify_html(html);

  // Free the HTML code
  free(html);

  return 0;
}
//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to beautify HTML code
char * beautify_html(char *html) {
  // Allocate memory for the beautified HTML code
  char *beautified_html = malloc(strlen(html) * 2);

  // Initialize the beautified HTML code
  beautified_html[0] = '\0';

  // Loop through each character in the HTML code
  for (int i = 0; i < strlen(html); i++) {
    // If the current character is a '<' character, then start a new line
    if (html[i] == '<') {
      strcat(beautified_html, "\n");
    }

    // If the current character is a '>' character, then end the current line
    if (html[i] == '>') {
      strcat(beautified_html, "\n");
    }

    // If the current character is a space character, then add a space to the beautified HTML code
    if (html[i] == ' ') {
      strcat(beautified_html, " ");
    }

    // If the current character is a tab character, then add a tab to the beautified HTML code
    if (html[i] == '\t') {
      strcat(beautified_html, "\t");
    }

    // If the current character is a newline character, then add a newline to the beautified HTML code
    if (html[i] == '\n') {
      strcat(beautified_html, "\n");
    }

    // Otherwise, add the current character to the beautified HTML code
    else {
      char c[2];
      c[0] = html[i];
      c[1] = '\0';
      strcat(beautified_html, c);
    }
  }

  // Return the beautified HTML code
  return beautified_html;
}

// Main function
int main() {
  // Get the HTML code from the user
  char *html = malloc(10000);
  printf("Enter the HTML code: ");
  scanf("%s", html);

  // Beautify the HTML code
  char *beautified_html = beautify_html(html);

  // Print the beautified HTML code
  printf("Beautified HTML code:\n%s", beautified_html);

  // Free the memory allocated for the beautified HTML code
  free(beautified_html);

  // Return 0
  return 0;
}
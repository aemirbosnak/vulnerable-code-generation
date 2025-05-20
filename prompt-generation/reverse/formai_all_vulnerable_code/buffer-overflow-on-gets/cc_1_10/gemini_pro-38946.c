//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our custom HTML beautifier function
char *beautify_html(char *html) {
  // Allocate memory for the beautified HTML
  char *beautified_html = malloc(strlen(html) * 2);

  // Initialize the beautified HTML string
  strcpy(beautified_html, "");

  // Iterate over the characters in the HTML string
  for (int i = 0; i < strlen(html); i++) {
    // If the current character is a newline character, add a newline character and two spaces to the beautified HTML string
    if (html[i] == '\n') {
      strcat(beautified_html, "\n  ");
    }
    // If the current character is a less than sign (<), add a less than sign and a newline character to the beautified HTML string
    else if (html[i] == '<') {
      strcat(beautified_html, "<\n");
    }
    // If the current character is a greater than sign (>), add a greater than sign and a newline character to the beautified HTML string
    else if (html[i] == '>') {
      strcat(beautified_html, ">\n");
    }
    // Otherwise, add the current character to the beautified HTML string
    else {
      char c[2];
      c[0] = html[i];
      c[1] = '\0';
      strcat(beautified_html, c);
    }
  }

  // Return the beautified HTML string
  return beautified_html;
}

// Our main function
int main() {
  // Get the HTML from the user
  char *html = malloc(1000);
  printf("Enter the HTML to be beautified:\n");
  gets(html);

  // Beautify the HTML
  char *beautified_html = beautify_html(html);

  // Print the beautified HTML
  printf("\nBeautified HTML:\n");
  printf("%s", beautified_html);

  // Free the memory allocated for the beautified HTML
  free(beautified_html);

  // Return 0
  return 0;
}
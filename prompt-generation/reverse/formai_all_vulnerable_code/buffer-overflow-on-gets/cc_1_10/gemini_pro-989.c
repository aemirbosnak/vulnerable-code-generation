//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to beautify HTML code
char *beautify_html(char *html) {
  // Allocate memory for the beautified HTML code
  char *beautified_html = malloc(strlen(html) * 2);
  if (beautified_html == NULL) {
    return NULL;
  }

  // Initialize the beautified HTML code
  beautified_html[0] = '\0';

  // Iterate over each character in the HTML code
  for (int i = 0; i < strlen(html); i++) {
    // Check if the current character is a '<' character
    if (html[i] == '<') {
      // Check if the next character is a '/' character
      if (html[i + 1] == '/') {
        // Add the closing tag to the beautified HTML code
        strcat(beautified_html, "  ");
        strcat(beautified_html, &html[i]);
        strcat(beautified_html, "\n");

        // Skip the next character
        i++;
      } else {
        // Add the opening tag to the beautified HTML code
        strcat(beautified_html, "  ");
        strcat(beautified_html, &html[i]);
        strcat(beautified_html, "\n");
      }
    } else {
      // Add the current character to the beautified HTML code
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
  if (html == NULL) {
    return 1;
  }
  printf("Enter the HTML code:\n");
  gets(html);

  // Beautify the HTML code
  char *beautified_html = beautify_html(html);
  if (beautified_html == NULL) {
    return 1;
  }

  // Print the beautified HTML code
  printf("\nBeautified HTML code:\n");
  printf("%s", beautified_html);

  // Free the allocated memory
  free(html);
  free(beautified_html);

  return 0;
}
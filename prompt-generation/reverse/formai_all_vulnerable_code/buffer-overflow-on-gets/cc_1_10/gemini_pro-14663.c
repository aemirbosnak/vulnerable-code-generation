//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: enthusiastic
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
  strcpy(beautified_html, "");

  // Iterate over the HTML code
  int i = 0;
  while (html[i] != '\0') {
    // If the current character is a '<' character, then it is the start of a tag
    if (html[i] == '<') {
      // Copy the tag to the beautified HTML code
      int j = i + 1;
      while (html[j] != '>' && html[j] != '\0') {
        beautified_html[j - i] = html[j];
        j++;
      }
      beautified_html[j - i] = html[j];
      i = j + 1;

      // If the tag is a self-closing tag, then add a newline character to the beautified HTML code
      if (html[j] == '/') {
        beautified_html[j - i + 1] = '\n';
        i++;
      }
    }
    // If the current character is a '>' character, then it is the end of a tag
    else if (html[i] == '>') {
      // Add a newline character to the beautified HTML code
      beautified_html[i - 1] = '\n';
      i++;
    }
    // If the current character is not a '<' or '>' character, then it is text
    else {
      // Copy the text to the beautified HTML code
      int j = i;
      while (html[j] != '<' && html[j] != '\0') {
        beautified_html[j - i] = html[j];
        j++;
      }
      i = j;

      // If the text is not empty, then add a newline character to the beautified HTML code
      if (j - i > 0) {
        beautified_html[j - i] = '\n';
      }
    }
  }

  // Return the beautified HTML code
  return beautified_html;
}

// Function to print the beautified HTML code
void print_beautified_html(char *html) {
  // Print the beautified HTML code
  printf("%s", html);

  // Free the memory allocated for the beautified HTML code
  free(html);
}

// Main function
int main() {
  // Get the HTML code from the user
  char *html = malloc(10000);
  printf("Enter the HTML code:\n");
  gets(html);

  // Beautify the HTML code
  char *beautified_html = beautify_html(html);

  // Print the beautified HTML code
  print_beautified_html(beautified_html);

  return 0;
}
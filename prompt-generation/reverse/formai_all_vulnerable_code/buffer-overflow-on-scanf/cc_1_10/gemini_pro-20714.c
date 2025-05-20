//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to beautify HTML code
char *beautify_html(char *html) {
  // Allocate memory for the beautified HTML code
  char *beautified_html = malloc(strlen(html) * 2);

  // Initialize the beautified HTML code
  strcpy(beautified_html, "");

  // Iterate over the HTML code
  int i = 0;
  while (html[i] != '\0') {
    // If the current character is a '<' character, then it is the start of a tag
    if (html[i] == '<') {
      // Add a newline character to the beautified HTML code
      strcat(beautified_html, "\n");

      // Copy the tag to the beautified HTML code
      int j = i + 1;
      while (html[j] != '>' && html[j] != '\0') {
        strcat(beautified_html, &html[j]);
        j++;
      }
      strcat(beautified_html, ">\n");

      // Increment the index
      i = j + 1;
    }
    // If the current character is a '>' character, then it is the end of a tag
    else if (html[i] == '>') {
      // Add a newline character to the beautified HTML code
      strcat(beautified_html, "\n");

      // Increment the index
      i++;
    }
    // If the current character is a newline character, then it is the end of a line
    else if (html[i] == '\n') {
      // Add a newline character to the beautified HTML code
      strcat(beautified_html, "\n");

      // Increment the index
      i++;
    }
    // If the current character is a space character, then it is the end of a word
    else if (html[i] == ' ') {
      // Add a space character to the beautified HTML code
      strcat(beautified_html, " ");

      // Increment the index
      i++;
    }
    // If the current character is any other character, then it is part of a word
    else {
      // Copy the character to the beautified HTML code
      strcat(beautified_html, &html[i]);

      // Increment the index
      i++;
    }
  }

  // Return the beautified HTML code
  return beautified_html;
}

// Main function
int main() {
  // Get the HTML code from the user
  char *html = malloc(1000);
  printf("Enter the HTML code: ");
  scanf("%s", html);

  // Beautify the HTML code
  char *beautified_html = beautify_html(html);

  // Print the beautified HTML code
  printf("The beautified HTML code is: %s\n", beautified_html);

  // Free the allocated memory
  free(html);
  free(beautified_html);

  return 0;
}
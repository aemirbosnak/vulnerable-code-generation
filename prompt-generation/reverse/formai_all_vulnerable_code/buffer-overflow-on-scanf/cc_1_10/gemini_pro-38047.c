//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to beautify HTML code
char *beautify_html(char *html) {
  // Allocate memory for the beautified HTML code
  char *beautified_html = malloc(strlen(html) * 2);

  // Initialize the beautified HTML code
  strcpy(beautified_html, "");

  // Iterate over each character in the HTML code
  int i = 0;
  while (html[i] != '\0') {
    // If the current character is a '<', then it is the start of a tag
    if (html[i] == '<') {
      // Copy the tag to the beautified HTML code
      strcat(beautified_html, "<");

      // Skip to the end of the tag
      i++;
      while (html[i] != '>') {
        i++;
      }

      // Copy the end of the tag to the beautified HTML code
      strcat(beautified_html, ">");
    }
    // If the current character is a '>', then it is the end of a tag
    else if (html[i] == '>') {
      // Copy the end of the tag to the beautified HTML code
      strcat(beautified_html, ">");
    }
    // If the current character is a newline, then it is the end of a line
    else if (html[i] == '\n') {
      // Copy the newline to the beautified HTML code
      strcat(beautified_html, "\n");
    }
    // If the current character is a space, then it is the end of a word
    else if (html[i] == ' ') {
      // Copy the space to the beautified HTML code
      strcat(beautified_html, " ");
    }
    // If the current character is any other character, then it is part of a word
    else {
      // Copy the character to the beautified HTML code
      char c[2];
      c[0] = html[i];
      c[1] = '\0';
      strcat(beautified_html, c);
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
  char *html = malloc(1000);
  printf("Enter the HTML code:\n");
  scanf("%s", html);

  // Beautify the HTML code
  char *beautified_html = beautify_html(html);

  // Print the beautified HTML code
  printf("The beautified HTML code is:\n%s", beautified_html);

  // Free the memory allocated for the HTML code and the beautified HTML code
  free(html);
  free(beautified_html);

  return 0;
}
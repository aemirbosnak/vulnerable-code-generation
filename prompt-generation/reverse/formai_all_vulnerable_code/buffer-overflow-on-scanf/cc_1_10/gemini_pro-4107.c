//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Indentation level
int indentLevel = 0;

// Beautify HTML
void beautifyHTML(char *html) {
  // Loop through the HTML
  for (int i = 0; i < strlen(html); i++) {
    // If the current character is a newline
    if (html[i] == '\n') {
      // Indent the next line
      for (int j = 0; j < indentLevel; j++) {
        printf("  ");
      }
    }

    // If the current character is a '<'
    else if (html[i] == '<') {
      // If the next character is a '/'
      if (html[i + 1] == '/') {
        // Decrease the indentation level
        indentLevel--;
      }

      // If the next character is not a '/'
      else {
        // Increase the indentation level
        indentLevel++;
      }
    }

    // Print the current character
    printf("%c", html[i]);
  }
}

int main() {
  // Get the HTML from the user
  char *html = malloc(1000);
  printf("Enter HTML: ");
  scanf("%s", html);

  // Beautify the HTML
  beautifyHTML(html);

  return 0;
}
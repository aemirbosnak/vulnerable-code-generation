//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to beautify HTML code
char *beautify_html(char *html) {
  // Initialize variables
  int len = strlen(html);
  char *new_html = malloc(len * 2);
  int new_index = 0;
  int indent_level = 0;
  int in_tag = 0;
  int in_attr = 0;
  int in_script = 0;
  int in_style = 0;
  int in_comment = 0;

  // Iterate over the HTML code
  for (int i = 0; i < len; i++) {
    char c = html[i];

    // Handle comments
    if (in_comment) {
      if (c == '*' && html[i + 1] == '/') {
        in_comment = 0;
        i++;
        continue;
      }
    } else if (c == '<' && html[i + 1] == '!') {
      in_comment = 1;
      continue;
    }

    // Handle scripts
    if (in_script) {
      if (c == '<' && html[i + 1] == '/') {
        in_script = 0;
        i++;
        continue;
      }
    } else if (c == '<' && strncmp(html + i, "<script", 7) == 0) {
      in_script = 1;
      continue;
    }

    // Handle styles
    if (in_style) {
      if (c == '<' && html[i + 1] == '/') {
        in_style = 0;
        i++;
        continue;
      }
    } else if (c == '<' && strncmp(html + i, "<style", 6) == 0) {
      in_style = 1;
      continue;
    }

    // Handle tags
    if (in_tag) {
      // Handle attributes
      if (in_attr) {
        if (c == '=') {
          new_html[new_index++] = ' ';
        } else if (c == '"' || c == '\'') {
          in_attr = 0;
        }
      } else if (c == '>' || c == '/') {
        in_tag = 0;
      } else if (c == ' ') {
        in_attr = 1;
      }
    } else if (c == '<') {
      in_tag = 1;
      new_html[new_index++] = c;
      for (int j = 0; j < indent_level; j++) {
        new_html[new_index++] = ' ';
      }
    }

    // Handle newlines
    if (c == '\n') {
      new_html[new_index++] = '\n';
      for (int j = 0; j < indent_level; j++) {
        new_html[new_index++] = ' ';
      }
    }

    // Indent the code
    if (c == '<' && html[i + 1] != '/') {
      indent_level++;
    } else if (c == '<' && html[i + 1] == '/' || c == '\n') {
      indent_level--;
    }

    // Add the character to the new HTML code
    new_html[new_index++] = c;
  }

  // Terminate the new HTML code
  new_html[new_index] = '\0';

  // Return the new HTML code
  return new_html;
}

// Main function
int main() {
  // Get the HTML code from the user
  char *html = malloc(1024);
  printf("Enter HTML code:\n");
  fgets(html, 1024, stdin);

  // Beautify the HTML code
  char *new_html = beautify_html(html);

  // Print the beautified HTML code
  printf("\nBeautified HTML code:\n");
  printf("%s", new_html);

  // Free the allocated memory
  free(html);
  free(new_html);

  return 0;
}
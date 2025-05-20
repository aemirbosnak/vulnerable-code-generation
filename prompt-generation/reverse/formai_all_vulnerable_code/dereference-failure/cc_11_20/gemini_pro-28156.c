//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A mind-bending HTML beautifier
int main() {
  // Get the HTML input
  char *html = malloc(10000);
  printf("Enter your HTML:\n");
  fgets(html, 10000, stdin);

  // Remove all whitespace characters
  char *newHtml = malloc(10000);
  int newHtmlIndex = 0;
  for (int i = 0; i < strlen(html); i++) {
    if (html[i] != ' ' && html[i] != '\n' && html[i] != '\t') {
      newHtml[newHtmlIndex++] = html[i];
    }
  }

  // Convert all tags to lowercase
  for (int i = 0; i < strlen(newHtml); i++) {
    if (newHtml[i] == '<') {
      for (int j = i + 1; j < strlen(newHtml); j++) {
        if (newHtml[j] == '>') {
          for (int k = i + 1; k < j; k++) {
            newHtml[k] = tolower(newHtml[k]);
          }
          break;
        }
      }
    }
  }

  // Add indentation to the HTML
  int indentationLevel = 0;
  for (int i = 0; i < strlen(newHtml); i++) {
    if (newHtml[i] == '<') {
      for (int j = i + 1; j < strlen(newHtml); j++) {
        if (newHtml[j] == '>') {
          for (int k = 0; k < indentationLevel; k++) {
            printf("  ");
          }
          break;
        }
      }
      indentationLevel++;
    } else if (newHtml[i] == '/') {
      indentationLevel--;
    }
    printf("%c", newHtml[i]);
  }

  printf("\n");

  // Free the allocated memory
  free(html);
  free(newHtml);

  return 0;
}
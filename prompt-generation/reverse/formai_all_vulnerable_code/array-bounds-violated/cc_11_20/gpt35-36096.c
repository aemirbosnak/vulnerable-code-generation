//FormAI DATASET v1.0 Category: HTML beautifier ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  
  // Input the HTML code
  char html[1000];
  printf("Enter the HTML code: ");
  fgets(html, 1000, stdin);
  
  // Normalize the HTML code
  char normalized_html[1000];
  int index = 0;
  for (int i = 0; i < strlen(html); i++) {
    if (html[i] == '\n' || html[i] == '\t') {
      continue;
    } else if (html[i] == ' ' && (html[i - 1] == '>' || html[i + 1] == '<')) {
      continue;
    } else {
      normalized_html[index] = html[i];
      index++;
    }
  }
  
  // Beautify the HTML code
  int indent_level = 0;
  char beautified_html[1000] = "";
  for (int i = 0; i < strlen(normalized_html); i++) {
    beautified_html[i] = normalized_html[i];
    if (normalized_html[i] == '<') {
      if (normalized_html[i + 1] == '/') {
        indent_level--;
      }
      for (int j = 0; j < indent_level; j++) {
        strcat(beautified_html, "  ");
      }
      if (normalized_html[i + 1] != '!') {
        indent_level++;
      }
    }
    if (normalized_html[i] == '>') {
      if (normalized_html[i - 1] == '/') {
        indent_level--;
      }
      strcat(beautified_html, "\n");
      if (normalized_html[i - 1] != '/') {
        for (int j = 0; j < indent_level; j++) {
          strcat(beautified_html, "  ");
        }
      }
    }
  }
  
  // Output the beautified HTML code
  printf("\n");
  printf("Beautified HTML code:\n");
  printf("%s", beautified_html);
  
  return 0;
}
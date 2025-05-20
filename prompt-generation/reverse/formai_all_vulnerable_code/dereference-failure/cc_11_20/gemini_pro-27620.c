//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *html = "<html>\n<body>\n<h1>Hello, world!</h1>\n</body>\n</html>";
  char *beautified_html = (char *)malloc(strlen(html) * 2);
  int i, j, k;
  int in_tag = 0;
  int in_attribute = 0;
  int in_string = 0;
  int indent_level = 0;
  for (i = 0, j = 0, k = 0; html[i] != '\0'; i++) {
    if (html[i] == '<') {
      in_tag = 1;
      beautified_html[j++] = '<';
      if (html[i + 1] == '/') {
        indent_level--;
        for (k = 0; k < indent_level; k++) {
          beautified_html[j++] = ' ';
        }
        j++;
      } else {
        indent_level++;
        for (k = 0; k < indent_level; k++) {
          beautified_html[j++] = ' ';
        }
      }
    } else if (html[i] == '>') {
      in_tag = 0;
      beautified_html[j++] = '>';
      if (html[i - 1] != '/') {
        beautified_html[j++] = '\n';
      }
    } else if (in_tag && html[i] == '=') {
      in_attribute = 1;
      beautified_html[j++] = '=';
      beautified_html[j++] = '"';
    } else if (in_attribute && html[i] == '"') {
      in_attribute = 0;
      beautified_html[j++] = '"';
    } else if (in_string && html[i] == '"') {
      in_string = 0;
      beautified_html[j++] = '"';
    } else if (!in_tag && !in_attribute && !in_string && html[i] == '\n') {
      beautified_html[j++] = '\n';
    } else {
      beautified_html[j++] = html[i];
    }
  }
  beautified_html[j] = '\0';
  printf("%s\n", beautified_html);
  free(beautified_html);
  return 0;
}
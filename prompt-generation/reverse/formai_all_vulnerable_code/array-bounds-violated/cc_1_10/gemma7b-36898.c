//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void beautify_html(char **html_str) {
  int i, j, k, indent = 0, state = 0;
  char buffer[MAX_BUFFER_SIZE];

  for (i = 0; html_str[i] != '\0'; i++) {
    switch (state) {
      case 0:
        if (html_str[i] == '<') {
          state = 1;
          buffer[k++] = '\n';
          buffer[k++] = ' ';
        } else {
          buffer[k++] = html_str[i];
        }
        break;
      case 1:
        if (html_str[i] == '>' && html_str[i - 1] != '/') {
          buffer[k++] = '\n';
          buffer[k++] = ' ';
          indent++;
        } else {
          buffer[k++] = html_str[i];
          if (html_str[i] == '/' && html_str[i - 1] == '>' && indent > 0) {
            indent--;
          }
        }
        break;
    }
  }

  *html_str = malloc(k);
  memcpy(*html_str, buffer, k);
  *html_str = realloc(*html_str, k);
}

int main() {
  char *html_str = "<p>This is a <b>bold</b> sentence.</p>\n";

  beautify_html(&html_str);

  printf("%s", html_str);

  free(html_str);

  return 0;
}
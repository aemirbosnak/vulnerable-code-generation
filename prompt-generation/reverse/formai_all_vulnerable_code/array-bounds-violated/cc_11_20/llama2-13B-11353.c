//LLAMA2-13B DATASET v1.0 Category: HTML beautifier ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAB_WIDTH 4
#define LINE_LENGTH 80

void html_beautify(char *html) {
  char *line = html;
  char *next = html;
  char *prev = html;
  char tab[TAB_WIDTH];
  int tab_count = 0;
  int line_count = 0;

  while (*next != '\0') {
    if (*next == '<') {
      next++;
      if (*next == '/') {
        // Handle self-closing tag
        next++;
        if (*next == '>') {
          *next = '\0';
          line = prev;
          while (line < next) {
            tab[tab_count] = *line;
            line_count++;
            line++;
            tab_count++;
            if (tab_count >= TAB_WIDTH) {
              break;
            }
          }
          next++;
          continue;
        } else {
          // Handle start of tag
          next++;
          while (*next != '>') {
            if (*next == '\0') {
              break;
            }
            next++;
          }
          line = prev;
          while (line < next) {
            tab[tab_count] = *line;
            line_count++;
            line++;
            tab_count++;
            if (tab_count >= TAB_WIDTH) {
              break;
            }
          }
          next++;
          continue;
        }
      } else {
        // Handle attribute
        while (*next != '>') {
          if (*next == '>') {
            break;
          }
          next++;
        }
        line = prev;
        while (line < next) {
          tab[tab_count] = *line;
          line_count++;
          line++;
          tab_count++;
          if (tab_count >= TAB_WIDTH) {
            break;
          }
        }
        next++;
        continue;
      }
    } else {
      // Handle text
      while (*next != '\0') {
        tab[tab_count] = *next;
        line_count++;
        next++;
        tab_count++;
        if (tab_count >= TAB_WIDTH) {
          break;
        }
      }
    }
  }

  // Beautify the HTML
  for (int i = 0; i < line_count; i++) {
    if (tab_count > 0) {
      // Remove trailing tabs
      while (tab_count > 0) {
        tab_count--;
        if (tab_count < TAB_WIDTH) {
          break;
        }
      }
    }
    // Add spaces before and after tags
    if (i > 0) {
      if (tab_count > 0) {
        printf(" ");
      }
      for (int j = 0; j < tab_count; j++) {
        printf(" ");
      }
    }
    printf("%s", line);
    if (i < line_count - 1) {
      printf("\n");
    }
  }
}

int main() {
  char html[] = "<html><body>Hello World!<p>This is a paragraph.</p><ul><li>Item 1</li><li>Item 2</li></ul></body></html>";
  html_beautify(html);
  return 0;
}
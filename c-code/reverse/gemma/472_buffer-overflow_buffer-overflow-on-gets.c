#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  char search_str[100], replace_str[100], text[1000];

  printf("Enter search string: ");
  gets(search_str);

  printf("Enter replacement string: ");
  gets(replace_str);

  printf("Enter text: ");
  gets(text);

  char *p = text;
  while (*p) {
    if (strstr(p, search_str) != NULL) {
      char *q = strstr(p, search_str);
      int len_search = strlen(search_str);
      int len_replace = strlen(replace_str);
      memcpy(q, replace_str, len_replace);
      p = q + len_replace;
    } else {
      p++;
    }
  }

  printf("Updated text: \n");
  printf("%s", text);

  return 0;
}

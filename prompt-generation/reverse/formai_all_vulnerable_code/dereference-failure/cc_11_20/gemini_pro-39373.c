//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: all-encompassing
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

void sanitize_url(char *url) {
  // Remove leading and trailing whitespace
  while (isspace(*url)) {
    url++;
  }
  while (isspace(*(url + strlen(url) - 1))) {
    *(url + strlen(url) - 1) = '\0';
  }

  // Escape special characters
  int i, j;
  for (i = 0, j = 0; i < strlen(url); i++, j++) {
    switch (url[i]) {
      case '&':
        url[j++] = '\\';
        url[j] = '&';
        break;
      case '+':
        url[j++] = '\\';
        url[j] = '+';
        break;
      case '<':
        url[j++] = '\\';
        url[j] = '<';
        break;
      case '>':
        url[j++] = '\\';
        url[j] = '>';
        break;
      case '"':
        url[j++] = '\\';
        url[j] = '"';
        break;
      case '\'':
        url[j++] = '\\';
        url[j] = '\'';
        break;
      case '\\':
        url[j++] = '\\';
        url[j] = '\\';
        break;
      default:
        url[j] = url[i];
        break;
    }
  }
  url[j] = '\0';

  // Remove invalid characters
  for (i = 0; i < strlen(url); i++) {
    if (!isalnum(url[i]) && url[i] != '.' && url[i] != '-' && url[i] != '_' &&
      url[i] != ':' && url[i] != '/' && url[i] != '?' && url[i] != '=' &&
      url[i] != '&')
    {
      url[i] = '_';
    }
  }
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <url>\n", argv[0]);
    return 1;
  }

  char *url = argv[1];
  if (strlen(url) > MAX_URL_LENGTH) {
    fprintf(stderr, "URL too long\n");
    return 1;
  }

  sanitize_url(url);
  printf("%s\n", url);
  return 0;
}
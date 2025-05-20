//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 255

void sanitize_url(char *url) {
  char *p = url;
  char *q = url;

  // Remove leading and trailing spaces
  while (*p == ' ') {
    p++;
  }
  while (*q && *q != ' ') {
    q++;
  }

  // Convert all uppercase letters to lowercase
  for (p = q; *p; p++) {
    *p = tolower(*p);
  }

  // Replace all special characters with underscores
  for (p = q; *p; p++) {
    if (!isalnum(*p)) {
      *p = '_';
    }
  }

  // Trim trailing underscores
  while (*q && *q == '_') {
    q--;
  }

  // Null-terminate the sanitized URL
  *q = '\0';
}

int main() {
  char url[MAX_URL_LENGTH];

  printf("Enter a URL: ");
  scanf("%s", url);

  sanitize_url(url);

  printf("Sanitized URL: %s\n", url);

  return 0;
}
//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 255

void sanitize_url(char *url) {
  char *p = url;
  char *start = NULL;
  char *end = NULL;

  // Strip leading and trailing spaces
  while (*p && isspace(*p)) {
    p++;
  }

  // Find the start of the actual URL
  while (*p && !isalnum(*p)) {
    p++;
  }

  // Find the end of the URL
  while (*p && isalnum(*p)) {
    end = p;
    p++;
  }

  // If the URL is valid, replace all spaces with plus signs
  if (start && end) {
    char *new_url = malloc((end - start) + 1);
    memcpy(new_url, start, end - start);
    new_url[end - start] = '\0';

    printf("Sanitized URL: %s\n", new_url);

    free(new_url);
  } else {
    printf("Invalid URL.\n");
  }
}

int main() {
  char url[MAX_URL_LENGTH];

  printf("Enter an URL: ");
  scanf("%s", url);

  sanitize_url(url);

  return 0;
}
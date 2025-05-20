//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 2048

int is_valid_url_char(char c) {
  if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
    return 1;
  }
  return 0;
}

int is_valid_url(char *url) {
  int i;
  for (i = 0; i < strlen(url); i++) {
    if (!is_valid_url_char(url[i])) {
      return 0;
    }
  }
  return 1;
}

char *sanitize_url(char *url) {
  int i, j;
  char *sanitized_url = malloc(MAX_LENGTH);
  if (sanitized_url == NULL) {
    return NULL;
  }
  for (i = 0, j = 0; i < strlen(url); i++) {
    if (is_valid_url_char(url[i])) {
      sanitized_url[j++] = tolower(url[i]);
    }
  }
  sanitized_url[j] = '\0';
  return sanitized_url;
}

int main() {
  char *url;
  printf("Enter a URL: ");
  scanf("%s", url);
  char *sanitized_url = sanitize_url(url);
  if (sanitized_url!= NULL) {
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
  }
  return 0;
}
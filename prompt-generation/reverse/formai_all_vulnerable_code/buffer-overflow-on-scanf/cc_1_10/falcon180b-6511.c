//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_character(char c) {
  if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~' || c == '/' || c == '?' || c == '&' || c == '=' || c == '+' || c == '%') {
    return 1;
  }
  return 0;
}

int is_valid_url(char *url) {
  int i;
  for (i = 0; i < strlen(url); i++) {
    if (!is_valid_url_character(url[i])) {
      return 0;
    }
  }
  return 1;
}

char *sanitize_url(char *url) {
  char *sanitized_url = malloc(MAX_URL_LENGTH);
  int i, j;
  for (i = 0, j = 0; i < strlen(url); i++) {
    if (is_valid_url_character(url[i])) {
      sanitized_url[j++] = url[i];
    }
  }
  sanitized_url[j] = '\0';
  return sanitized_url;
}

int main() {
  char *url;
  printf("Enter a URL: ");
  scanf("%s", url);

  if (is_valid_url(url)) {
    printf("The URL is valid.\n");
  } else {
    char *sanitized_url = sanitize_url(url);
    printf("The sanitized URL is: %s\n", sanitized_url);
    free(sanitized_url);
  }

  return 0;
}
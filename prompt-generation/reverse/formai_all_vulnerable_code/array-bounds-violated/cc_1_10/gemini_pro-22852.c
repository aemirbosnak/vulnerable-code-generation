//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 1024

void sanitize_url(char *url) {
  int i, j;
  char sanitized_url[MAX_URL_LENGTH];

  // Convert the URL to lowercase.
  for (i = 0; i < strlen(url); i++) {
    url[i] = tolower(url[i]);
  }

  // Remove all non-alphanumeric characters from the URL.
  j = 0;
  for (i = 0; i < strlen(url); i++) {
    if (isalnum(url[i])) {
      sanitized_url[j++] = url[i];
    }
  }

  // Add a trailing slash to the URL if it doesn't already have one.
  if (sanitized_url[j - 1] != '/') {
    sanitized_url[j++] = '/';
  }

  // Terminate the sanitized URL with a null character.
  sanitized_url[j] = '\0';

  // Copy the sanitized URL back to the original URL.
  strcpy(url, sanitized_url);
}

int main() {
  char url[MAX_URL_LENGTH];

  // Get the URL from the user.
  printf("Enter a URL: ");
  scanf("%s", url);

  // Sanitize the URL.
  sanitize_url(url);

  // Print the sanitized URL.
  printf("Sanitized URL: %s\n", url);

  return 0;
}
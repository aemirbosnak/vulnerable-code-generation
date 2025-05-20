//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: systematic
#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This function sanitizes a URL by removing any characters that are not allowed in a URL.
// Allowed characters include letters, numbers, underscores, hyphens, and periods.
char *sanitize_url(char *url) {
  // Allocate memory for the sanitized URL.
  char *sanitized_url = malloc(strlen(url) + 1);

  // Copy the first character of the URL to the sanitized URL.
  sanitized_url[0] = url[0];

  // Loop through the remaining characters in the URL.
  for (int i = 1; i < strlen(url); i++) {
    // If the current character is allowed in a URL, append it to the sanitized URL.
    if (isalnum(url[i]) || url[i] == '_' || url[i] == '-' || url[i] == '.') {
      sanitized_url[i] = url[i];
    }
    // Otherwise, replace the current character with an underscore.
    else {
      sanitized_url[i] = '_';
    }
  }

  // Null-terminate the sanitized URL.
  sanitized_url[strlen(url)] = '\0';

  // Return the sanitized URL.
  return sanitized_url;
}

int main() {
  // Get the URL from the user.
  char *url = malloc(1024);
  printf("Enter the URL: ");
  scanf("%s", url);

  // Sanitize the URL.
  char *sanitized_url = sanitize_url(url);

  // Print the sanitized URL.
  printf("Sanitized URL: %s\n", sanitized_url);

  // Free the memory allocated for the URL and the sanitized URL.
  free(url);
  free(sanitized_url);

  return 0;
}
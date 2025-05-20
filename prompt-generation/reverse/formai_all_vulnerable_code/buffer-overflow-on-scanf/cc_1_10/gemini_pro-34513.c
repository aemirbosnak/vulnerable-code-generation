//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Check if a URL is valid
int is_valid_url(char *url) {
  // Check if the URL is empty
  if (strlen(url) == 0) {
    return 0;
  }

  // Check if the URL starts with "http://" or "https://"
  if (strncmp(url, "http://", 7) != 0 && strncmp(url, "https://", 8) != 0) {
    return 0;
  }

  // Check if the URL contains any invalid characters
  for (int i = 0; i < strlen(url); i++) {
    if (!isalnum(url[i]) && url[i] != '.' && url[i] != '/' && url[i] != '?' && url[i] != '&' && url[i] != '=') {
      return 0;
    }
  }

  // The URL is valid
  return 1;
}

// Sanitize a URL
char *sanitize_url(char *url) {
  // Allocate memory for the sanitized URL
  char *sanitized_url = malloc(strlen(url) + 1);

  // Copy the sanitized URL into the allocated memory
  strcpy(sanitized_url, url);

  // Replace all invalid characters with underscores
  for (int i = 0; i < strlen(sanitized_url); i++) {
    if (!isalnum(sanitized_url[i]) && sanitized_url[i] != '.' && sanitized_url[i] != '/' && sanitized_url[i] != '?' && sanitized_url[i] != '&' && sanitized_url[i] != '=') {
      sanitized_url[i] = '_';
    }
  }

  // Return the sanitized URL
  return sanitized_url;
}

int main() {
  // Get the URL from the user
  char url[1024];
  printf("Enter the URL: ");
  scanf("%s", url);

  // Check if the URL is valid
  if (!is_valid_url(url)) {
    printf("Error: The URL is invalid.\n");
    return 1;
  }

  // Sanitize the URL
  char *sanitized_url = sanitize_url(url);

  // Print the sanitized URL
  printf("The sanitized URL is: %s\n", sanitized_url);

  // Free the memory allocated for the sanitized URL
  free(sanitized_url);

  return 0;
}
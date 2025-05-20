//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SAFE_STRLEN 1024

// Function to sanitize a URL
char *sanitizeURL(const char *url) {
  // Allocate memory for the sanitized URL
  char *sanitizedURL = malloc(SAFE_STRLEN);
  if (sanitizedURL == NULL) {
    return NULL; // Error: Out of memory
  }

  // Initialize the sanitized URL
  memset(sanitizedURL, 0, SAFE_STRLEN);

  // Copy the first part of the URL (up to the first '?' or '#')
  int i = 0;
  while (url[i] != '?' && url[i] != '#' && url[i] != '\0') {
    sanitizedURL[i] = url[i];
    i++;
  }

  // Check if the URL contains any unsafe characters
  int foundUnsafeCharacter = 0;
  while (url[i] != '\0') {
    if (!isalnum(url[i]) && url[i] != '.' && url[i] != '_' && url[i] != '-') {
      foundUnsafeCharacter = 1;
      break;
    }
    i++;
  }

  // If any unsafe characters were found, return NULL
  if (foundUnsafeCharacter) {
    free(sanitizedURL);
    return NULL; // Error: Unsafe characters found
  }

  // Return the sanitized URL
  return sanitizedURL;
}

// Main function
int main() {
  // Get the input URL from the user
  char url[SAFE_STRLEN];
  printf("Enter the URL to be sanitized: ");
  scanf("%s", url);

  // Sanitize the URL
  char *sanitizedURL = sanitizeURL(url);

  // Check if the URL was sanitized successfully
  if (sanitizedURL == NULL) {
    printf("Error: Unable to sanitize the URL.\n");
  } else {
    printf("Sanitized URL: %s\n", sanitizedURL);
  }

  // Free the memory allocated for the sanitized URL
  free(sanitizedURL);

  return 0;
}
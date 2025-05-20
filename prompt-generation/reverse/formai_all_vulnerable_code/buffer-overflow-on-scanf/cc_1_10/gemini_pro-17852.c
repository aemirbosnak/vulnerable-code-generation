//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: romantic
#include <curl/curl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a character is a valid URL character
bool is_valid_url_char(char c) {
  // Valid URL characters:
  // - Alphanumeric characters (A-Z, a-z, 0-9)
  // - Special characters: /, ?, :, &, =, +, %, #, ., -, _, ~
  return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') ||
         c == '/' || c == '?' || c == ':' || c == '&' || c == '=' || c == '+' || c == '%' ||
         c == '#' || c == '.' || c == '-' || c == '_' || c == '~';
}

// Function to sanitize a URL string
char *sanitize_url(const char *url) {
  // Allocate memory for the sanitized URL
  size_t len = strlen(url) + 1;
  char *sanitized_url = malloc(len);
  if (sanitized_url == NULL) {
    return NULL;
  }

  // Sanitize the URL
  char *dst = sanitized_url;
  for (const char *src = url; *src != '\0'; src++) {
    // If the character is valid, copy it to the sanitized URL
    if (is_valid_url_char(*src)) {
      *dst++ = *src;
    }
  }
  *dst = '\0';

  // Return the sanitized URL
  return sanitized_url;
}

int main(void) {
  // Get the URL from the user
  char url[256];
  printf("Enter the URL to sanitize: ");
  scanf("%s", url);

  // Sanitize the URL
  char *sanitized_url = sanitize_url(url);
  if (sanitized_url == NULL) {
    printf("Error allocating memory for sanitized URL.\n");
    return EXIT_FAILURE;
  }

  // Print the sanitized URL
  printf("Sanitized URL: %s\n", sanitized_url);

  // Free the allocated memory
  free(sanitized_url);

  return EXIT_SUCCESS;
}
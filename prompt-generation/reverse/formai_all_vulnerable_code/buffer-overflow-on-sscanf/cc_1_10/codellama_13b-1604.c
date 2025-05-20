//Code Llama-13B DATASET v1.0 Category: URL Sanitizer ; Style: complex
/*
* Unique C URL Sanitizer example program in a complex style
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 256
#define MAX_HOSTNAME_LENGTH 256

// Function to sanitize a URL
char* sanitize_url(char* url) {
  // Check if the URL is NULL or empty
  if (url == NULL || strlen(url) == 0) {
    return NULL;
  }

  // Initialize variables
  char hostname[MAX_HOSTNAME_LENGTH];
  char path[MAX_URL_LENGTH];
  char sanitized_url[MAX_URL_LENGTH];
  int hostname_len = 0;
  int path_len = 0;

  // Parse the URL
  if (sscanf(url, "http://%s/%s", hostname, path) != 2) {
    return NULL;
  }

  // Get the length of the hostname and path
  hostname_len = strlen(hostname);
  path_len = strlen(path);

  // Check if the hostname is valid
  if (hostname_len == 0) {
    return NULL;
  }

  // Check if the path is valid
  if (path_len == 0) {
    return NULL;
  }

  // Check if the path is a directory
  if (path[path_len - 1] != '/') {
    path[path_len] = '/';
    path_len++;
  }

  // Build the sanitized URL
  snprintf(sanitized_url, MAX_URL_LENGTH, "http://%s%s", hostname, path);

  // Return the sanitized URL
  return sanitized_url;
}

// Main function
int main() {
  // Test the sanitizer
  char* url = "http://example.com/path/to/resource";
  char* sanitized_url = sanitize_url(url);
  if (sanitized_url != NULL) {
    printf("Sanitized URL: %s\n", sanitized_url);
  } else {
    printf("Invalid URL: %s\n", url);
  }

  // Test the sanitizer with an invalid URL
  url = "invalid.url";
  sanitized_url = sanitize_url(url);
  if (sanitized_url != NULL) {
    printf("Sanitized URL: %s\n", sanitized_url);
  } else {
    printf("Invalid URL: %s\n", url);
  }

  return 0;
}
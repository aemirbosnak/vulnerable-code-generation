//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 2048

// Function to sanitize a URL
char *sanitize_url(char *url) {
  // Check if the URL is valid
  if (url == NULL || strlen(url) == 0) {
    return NULL;
  }

  // Check if the URL is too long
  if (strlen(url) > MAX_URL_LENGTH) {
    return NULL;
  }

  // Copy the URL to a new buffer
  char *sanitized_url = malloc(strlen(url) + 1);
  if (sanitized_url == NULL) {
    return NULL;
  }
  strcpy(sanitized_url, url);

  // Remove any spaces from the URL
  for (int i = 0; i < strlen(sanitized_url); i++) {
    if (sanitized_url[i] == ' ') {
      sanitized_url[i] = '%';
      sanitized_url[i+1] = '2';
      sanitized_url[i+2] = '0';
      i += 2;
    }
  }

  // Remove any special characters from the URL
  for (int i = 0; i < strlen(sanitized_url); i++) {
    char c = url[i];
    if (!isalnum(c) && c != '.' && c != '-' && c != '_' && c != '/' && c != ':'){
        sprintf(sanitized_url + i, "%%%02X", c);
        i += strnlen("%%%02X", 4);
    }
  }
  // Return the sanitized URL
  return sanitized_url;
}

// Main function
int main() {
  // Get the URL from the user
  printf("Enter the URL to sanitize: ");
  char url[MAX_URL_LENGTH];
  fgets(url, MAX_URL_LENGTH, stdin);

  // Sanitize the URL
  char *sanitized_url = sanitize_url(url);

  // Print the sanitized URL
  printf("Sanitized URL: %s\n", sanitized_url);

  // Free the memory allocated for the sanitized URL
  free(sanitized_url);

  return 0;
}
//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Define the maximum length of the input URL
#define MAX_URL_LENGTH 1024

// Function to sanitize the input URL
char *sanitize_url(char *url) {
  // Allocate memory for the sanitized URL
  char *sanitized_url = malloc(MAX_URL_LENGTH);

  // Initialize the sanitized URL to an empty string
  sanitized_url[0] = '\0';

  // Iterate over the characters in the input URL
  for (int i = 0; i < strlen(url); i++) {
    // Check if the current character is a valid URL character
    if (isalnum(url[i]) || strchr(".-_", url[i])) {
      // If the character is valid, append it to the sanitized URL
      strcat(sanitized_url, &url[i]);
    } else {
      // If the character is not valid, replace it with an underscore
      strcat(sanitized_url, "_");
    }
  }

  // Return the sanitized URL
  return sanitized_url;
}

// Main function
int main() {
  // Get the input URL from the user
  char url[MAX_URL_LENGTH];
  printf("Enter the URL to sanitize: ");
  scanf("%s", url);

  // Sanitize the input URL
  char *sanitized_url = sanitize_url(url);

  // Print the sanitized URL
  printf("Sanitized URL: %s\n", sanitized_url);

  // Free the memory allocated for the sanitized URL
  free(sanitized_url);

  return 0;
}
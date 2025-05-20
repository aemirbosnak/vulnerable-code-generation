//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 1024

// Function to check if a character is valid in a URL
bool is_valid_url_char(char c) {
  // Allow letters, numbers, underscores, hyphens, periods, and slashes
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') ||
         c == '_' || c == '-' || c == '.' || c == '/';
}

// Function to sanitize a URL
char *sanitize_url(char *url) {
  char *sanitized_url = malloc(MAX_URL_LENGTH);
  int sanitized_url_length = 0;

  // Iterate over each character in the URL
  for (int i = 0; i < strlen(url); i++) {
    char c = url[i];

    // If the character is valid, add it to the sanitized URL
    if (is_valid_url_char(c)) {
      sanitized_url[sanitized_url_length++] = c;
    }
    // Otherwise, replace the character with a placeholder character
    else {
      sanitized_url[sanitized_url_length++] = '%';
      char hex_digits[3];
      sprintf(hex_digits, "%02X", c);
      sanitized_url[sanitized_url_length++] = hex_digits[0];
      sanitized_url[sanitized_url_length++] = hex_digits[1];
    }
  }

  // Terminate the sanitized URL with a null character
  sanitized_url[sanitized_url_length] = '\0';

  return sanitized_url;
}

// Main function
int main() {
  // Read the URL from the user
  char url[MAX_URL_LENGTH];
  printf("Enter the URL to be sanitized: ");
  scanf("%s", url);

  // Sanitize the URL
  char *sanitized_url = sanitize_url(url);

  // Print the sanitized URL
  printf("Sanitized URL: %s\n", sanitized_url);

  // Free the allocated memory
  free(sanitized_url);

  return 0;
}
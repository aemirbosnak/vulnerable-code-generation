//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: secure
/* This C Program is a URL Sanitizer that removes any malicious characters from a URL
and makes it safe for use in web applications. */

#include <stdio.h>
#include <string.h>

/* Prototype for sanitize_url function */
void sanitize_url(char url[]);

int main() {
  char url[200];

  printf("Enter the URL to sanitize: ");
  fgets(url, 200, stdin);

  /* Ensure that the URL ends with a null character */
  url[strlen(url) - 1] = '\0';

  /* Call the sanitize_url function to remove any malicious characters from the URL */
  sanitize_url(url);

  /* Print the sanitized URL */
  printf("\nSanitized URL: %s\n", url);

  return 0;
}

void sanitize_url(char url[]) {
  int i, j = 0;
  char sanitized_url[200];

  /* Copy only the allowed characters to the sanitized_url string */
  for (i = 0; url[i] != '\0'; i++) {
    if ((url[i] >= 'a' && url[i] <= 'z') ||
        (url[i] >= 'A' && url[i] <= 'Z') ||
        (url[i] >= '0' && url[i] <= '9') ||
        (url[i] == '.') || (url[i] == '-') ||
        (url[i] == '/') || (url[i] == ':') ||
        (url[i] == '_') || (url[i] == '~') ||
        (url[i] == '?') || (url[i] == '=') ||
        (url[i] == '&')) {
      sanitized_url[j] = url[i];
      j++;
    }
  }

  /* Add a null character at the end of the sanitized_url string */
  sanitized_url[j] = '\0';

  /* Copy the sanitized URL back into the original URL variable */
  strcpy(url, sanitized_url);
}
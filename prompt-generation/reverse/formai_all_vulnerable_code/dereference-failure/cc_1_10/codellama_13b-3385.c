//Code Llama-13B DATASET v1.0 Category: URL Sanitizer ; Style: surprised
/*
 * Unique C URL Sanitizer example program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LEN 1024

int main(int argc, char *argv[]) {
  char url[MAX_URL_LEN];
  char sanitized_url[MAX_URL_LEN];
  int url_len;

  // Get the URL from the command line arguments
  url_len = strlen(argv[1]);
  if (url_len > MAX_URL_LEN) {
    printf("Error: URL too long\n");
    return 1;
  }
  strcpy(url, argv[1]);

  // Sanitize the URL by removing any characters that are not allowed in a URL
  for (int i = 0; i < url_len; i++) {
    if (!isalnum(url[i]) && url[i] != '-' && url[i] != '_' && url[i] != '.') {
      url[i] = '_';
    }
  }

  // Remove any duplicate '_' characters
  int prev = -1;
  int curr = 0;
  while (curr < url_len) {
    if (url[curr] == '_') {
      if (prev != curr - 1) {
        strcpy(&sanitized_url[prev + 1], &url[curr]);
      }
      curr++;
      prev = curr;
    } else {
      curr++;
    }
  }
  sanitized_url[prev + 1] = '\0';

  // Print the sanitized URL
  printf("Sanitized URL: %s\n", sanitized_url);

  return 0;
}
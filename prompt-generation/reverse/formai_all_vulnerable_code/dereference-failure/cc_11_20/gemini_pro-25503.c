//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// The wasteland's URL sanitizer
void sanitize_url(char *url) {
  // Remove leading and trailing whitespace
  while (*url == ' ') url++;
  while (strlen(url) > 0 && url[strlen(url) - 1] == ' ') url[strlen(url) - 1] = '\0';

  // Convert to lowercase
  for (char *p = url; *p; p++) {
    *p = tolower(*p);
  }

  // Replace spaces with underscores
  char *p = url;
  while (*p) {
    if (*p == ' ') *p = '_';
    p++;
  }

  // Remove invalid characters
  p = url;
  while (*p) {
    if (!isalnum(*p) && *p != '_' && *p != '&' && *p != '?' && *p != '/' && *p != ':' && *p != '#' && *p != '~' && *p != '(' && *p != ')' && *p != '!' && *p != '$' && *p != '+' && *p != ',' && *p != ';' && *p != '=') {
      *p = '_';
    }
    p++;
  }

  // Trim to maximum length
  if (strlen(url) > 255) {
    url[255] = '\0';
  }
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
    return 1;
  }

  char *url = argv[1];

  // Sanitize the URL
  sanitize_url(url);

  // Print the sanitized URL
  printf("%s\n", url);

  return 0;
}
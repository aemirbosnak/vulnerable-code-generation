//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 2048

int is_valid_url(char* url);
char* sanitize_url(char* url);

int main(int argc, char** argv) {
  if (argc < 2) {
    printf("Usage: %s [URL]\n", argv[0]);
    return 1;
  }

  char* url = argv[1];
  if (is_valid_url(url)) {
    char* sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
  } else {
    printf("Invalid URL\n");
  }

  return 0;
}

int is_valid_url(char* url) {
  if (strlen(url) > MAX_URL_LENGTH) {
    return 0;
  }

  char* protocol = strtok(url, "://");
  if (protocol == NULL) {
    return 0;
  }

  char* host = strtok(NULL, "/");
  if (host == NULL) {
    return 0;
  }

  return 1;
}

char* sanitize_url(char* url) {
  char* sanitized_url = malloc(MAX_URL_LENGTH);
  strcpy(sanitized_url, "https://");

  char* protocol = strtok(url, "://");
  strcat(sanitized_url, protocol);

  char* host = strtok(NULL, "/");
  strcat(sanitized_url, host);

  strcat(sanitized_url, "/");

  return sanitized_url;
}
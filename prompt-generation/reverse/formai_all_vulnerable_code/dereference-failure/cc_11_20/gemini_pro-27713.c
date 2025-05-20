//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

int main(int argc, char *argv[]) {
  // Check if the user provided a URL.
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Compile the regular expression.
  regex_t regex;
  int regex_error = regcomp(&regex, "^https?://\\S+$", REG_EXTENDED);
  if (regex_error != 0) {
    char error_message[512];
    regerror(regex_error, &regex, error_message, sizeof(error_message));
    fprintf(stderr, "Error compiling regular expression: %s\n", error_message);
    return EXIT_FAILURE;
  }

  // Match the URL against the regular expression.
  regmatch_t match;
  int match_error = regexec(&regex, argv[1], 1, &match, 0);
  if (match_error != 0) {
    if (match_error == REG_NOMATCH) {
      fprintf(stderr, "Invalid URL: %s\n", argv[1]);
    } else {
      char error_message[512];
      regerror(match_error, &regex, error_message, sizeof(error_message));
      fprintf(stderr, "Error matching URL: %s\n", error_message);
    }
    return EXIT_FAILURE;
  }

  // Sanitize the URL.
  char *sanitized_url = malloc(strlen(argv[1]) + 1);
  if (sanitized_url == NULL) {
    fprintf(stderr, "Error allocating memory for sanitized URL.\n");
    return EXIT_FAILURE;
  }
  strcpy(sanitized_url, argv[1]);
  for (int i = 0; i < strlen(sanitized_url); i++) {
    if (sanitized_url[i] == '<' || sanitized_url[i] == '>' || sanitized_url[i] == '&' || sanitized_url[i] == '\"' || sanitized_url[i] == '\'') {
      sanitized_url[i] = '%';
    }
  }

  // Print the sanitized URL.
  printf("Sanitized URL: %s\n", sanitized_url);

  // Free the memory allocated for the sanitized URL.
  free(sanitized_url);

  // Free the memory allocated for the regular expression.
  regfree(&regex);

  return EXIT_SUCCESS;
}
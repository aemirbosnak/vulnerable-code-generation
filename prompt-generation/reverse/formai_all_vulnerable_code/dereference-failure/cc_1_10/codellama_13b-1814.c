//Code Llama-13B DATASET v1.0 Category: URL Sanitizer ; Style: scientific
/*
 * URL Sanitizer Example Program
 *
 * This program takes a URL as input and sanitizes it by
 * removing any invalid characters and encoding any
 * special characters.
 *
 * Example:
 * Input: http://www.example.com/example.php?var=value
 * Output: http://www.example.com/example.php?var=value
 *
 * Usage:
 * $ ./url_sanitizer.c <URL>
 *
 * Author:
 * Samantha Wong
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LEN 1024

int is_valid_url_char(char c) {
  if (c >= 'a' && c <= 'z') {
    return 1;
  } else if (c >= 'A' && c <= 'Z') {
    return 1;
  } else if (c >= '0' && c <= '9') {
    return 1;
  } else if (c == '.' || c == '_' || c == '-') {
    return 1;
  } else {
    return 0;
  }
}

int is_special_char(char c) {
  if (c == ' ' || c == '!' || c == '"' || c == '#' || c == '$' || c == '&' ||
      c == '\'' || c == '(' || c == ')' || c == '*' || c == '+' || c == ',' ||
      c == '/' || c == ':' || c == ';' || c == '<' || c == '=' || c == '>' ||
      c == '?' || c == '@' || c == '[' || c == '\\' || c == ']' || c == '^' ||
      c == '`' || c == '{' || c == '|' || c == '}' || c == '~') {
    return 1;
  } else {
    return 0;
  }
}

char *encode_special_char(char c) {
  char *encoded = malloc(4);
  sprintf(encoded, "%%%02X", c);
  return encoded;
}

char *sanitize_url(char *url) {
  int i, j;
  int len = strlen(url);
  char *sanitized = malloc(len + 1);
  for (i = 0, j = 0; i < len; i++, j++) {
    if (is_valid_url_char(url[i])) {
      sanitized[j] = url[i];
    } else if (is_special_char(url[i])) {
      char *encoded = encode_special_char(url[i]);
      strcpy(&sanitized[j], encoded);
      j += 2;
    } else {
      j--;
    }
  }
  sanitized[j] = '\0';
  return sanitized;
}

int main(int argc, char **argv) {
  char *url = argv[1];
  char *sanitized = sanitize_url(url);
  printf("%s\n", sanitized);
  free(sanitized);
  return 0;
}
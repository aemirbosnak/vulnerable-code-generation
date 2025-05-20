//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* The maximum URL length that we will allow */
#define MAX_URL_LENGTH 2048

/* The main function */
int main(void) {
  /* Declare variables */
  char url[MAX_URL_LENGTH];
  int i, j;
  int len;
  
  /* Get the URL from the user */
  printf("Enter a URL to sanitize:\n");
  fgets(url, MAX_URL_LENGTH, stdin);
  
  /* Remove any trailing newline character */
  len = strlen(url);
  if (url[len - 1] == '\n') {
    url[len - 1] = '\0';
  }
  
  /* Convert any backslashes to forward slashes */
  for (i = 0; i < len; i++) {
    if (url[i] == '\\') {
      url[i] = '/';
    }
  }
  
  /* Remove any leading or trailing spaces */
  for (i = 0; i < len; i++) {
    if (url[i] != ' ') {
      break;
    }
  }
  for (j = len-1; j >= 0; j--) {
    if (url[j] != ' ') {
      break;
    }
  }
  if (i != 0 || j != len-1) {
    memmove(url, url+i, j-i+1);
    url[j-i+1] = '\0';
  }
  
  /* Remove any query string or fragment identifier */
  for (i = 0; i < len; i++) {
    if (url[i] == '?' || url[i] == '#') {
      url[i] = '\0';
      break;
    }
  }
  
  /* Add a trailing slash if there isn't one already */
  len = strlen(url);
  if (url[len-1] != '/') {
    strncat(url, "/", MAX_URL_LENGTH - len);
  }
  
  /* Print the sanitized URL */
  printf("The sanitized URL is:\n%s\n", url);
  
  /* End the program */
  return 0;
}
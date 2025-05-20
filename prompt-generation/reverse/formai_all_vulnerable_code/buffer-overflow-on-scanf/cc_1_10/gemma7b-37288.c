//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 256

int sanitize_url(char *url)
{
  char *p = url;
  char *q = url;
  char *s = "";

  // Remove all leading and trailing spaces
  while (*p && isspace(*p))
  {
    p++;
  }

  // Remove all consecutive spaces
  while (*q && *(q + 1) && isspace(*q) && isspace(*(q + 1)))
  {
    q++;
  }

  // Replace all invalid characters with underscores
  while (*p)
  {
    if (!isalnum(*p) && *p != '-' && *p != '_')
    {
      *p = '_';
    }
    p++;
  }

  // Trim the trailing underscore if it exists
  if (s && s[0] == '_')
  {
    s = strchr(s, '_');
    if (s)
    {
      *s = '\0';
    }
  }

  // Return the sanitized URL
  return strlen(s) + 1;
}

int main()
{
  char url[MAX_URL_LENGTH];

  printf("Enter a URL: ");
  scanf("%s", url);

  int length = sanitize_url(url);

  printf("Sanitized URL: %s\n", url);

  printf("Number of characters: %d\n", length);

  return 0;
}
//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 255

void sanitize_url(char *url)
{
  char *p = url;
  char *q = url;

  // Remove leading and trailing spaces
  while (isspace(*p))
  {
    p++;
  }
  while (isspace(*q))
  {
    q--;
  }

  // Convert all characters to lowercase
  for (; p <= q; p++)
  {
    *p = tolower(*p);
  }

  // Remove invalid characters
  q = p;
  while (*p)
  {
    if (!isalnum(*p) && *p != '-' && *p != '_')
    {
      *p = '\0';
    }
    else
    {
      p++;
    }
  }

  // Normalize special characters
  if (strcmp(url, "") == 0)
  {
    strcpy(url, "/");
  }
  else if (url[0] == '/')
  {
    url++;
  }

  // Return the sanitized URL
  return;
}

int main()
{
  char url[MAX_URL_LENGTH];

  printf("Enter a URL: ");
  scanf("%s", url);

  sanitize_url(url);

  printf("Sanitized URL: %s\n", url);

  return 0;
}
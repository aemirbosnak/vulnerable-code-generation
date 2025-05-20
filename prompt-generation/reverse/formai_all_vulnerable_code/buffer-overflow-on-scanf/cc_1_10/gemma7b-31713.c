//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LEN 256

void sanitize_url(char *url)
{
  char *ptr, *start, *end;
  int len, i;

  len = strlen(url);
  if (len > MAX_URL_LEN)
  {
    printf("Error: URL too long.\n");
    exit(1);
  }

  start = url;
  end = url + len;
  for (ptr = start; ptr < end; ptr++)
  {
    if (!isalnum(*ptr))
    {
      switch (*ptr)
      {
        case '.':
          if (ptr - start > 1 && ptr - start < end - start - 1)
          {
            *ptr = '_';
          }
          break;
        case '/':
          if (ptr - start > 0)
          {
            *ptr = '_';
          }
          break;
        case '?':
          if (ptr - start > 0)
          {
            *ptr = '_';
          }
          break;
        default:
          *ptr = '_';
      }
    }
  }

  printf("Sanitized URL: %s\n", url);
}

int main()
{
  char url[MAX_URL_LEN];

  printf("Enter a URL: ");
  scanf("%s", url);

  sanitize_url(url);

  return 0;
}
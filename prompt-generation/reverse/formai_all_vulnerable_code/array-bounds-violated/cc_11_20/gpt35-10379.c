//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char url[200], sanitized_url[200], protocol[8], domain[100], path[100];
  int i, j, k, flag = 0;

  printf("Enter a URL: ");
  fgets(url, sizeof(url), stdin);

  for(i=0; url[i]!='\0'; i++)
  {
    if(url[i] == ':')
    {
      flag = 1;
      protocol[i] = '\0';
    }
    else if(url[i] == '/')
    {
      if(flag == 1)
      {
        protocol[i] = '\0';
        j = i+1;
        flag = 2;
      }
      else if(flag == 2)
      {
        domain[k] = '\0';
        k = 0;
        flag = 3;
      }
      else if(flag == 3)
      {
        path[k] = '\0';
        k = 0;
      }
    }
    else
    {
      if(flag == 1)
      {
        protocol[i] = url[i];
      }
      else if(flag == 2)
      {
        domain[k++] = url[i];
      }
      else if(flag == 3)
      {
        path[k++] = url[i];
      }
    }
  }

  domain[k] = '\0';
  path[k] = '\0';

  strcat(sanitized_url, protocol);
  strcat(sanitized_url, "://");

  for(i=0; domain[i]!='\0'; i++)
  {
    if(domain[i] == ' ' || domain[i] == '\t')
    {
      continue;
    }
    else
    {
      strncat(sanitized_url, &domain[i], 1);
    }
  }

  strcat(sanitized_url, "/");
  strcat(sanitized_url, path);

  printf("Sanitized URL: %s", sanitized_url);

  return 0;
}
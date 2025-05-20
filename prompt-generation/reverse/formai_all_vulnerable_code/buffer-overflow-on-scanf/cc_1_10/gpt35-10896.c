//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: artistic
#include <stdio.h>
#include <string.h>

void sanitizeURL(char url[])
{
  if(strncmp(url, "http://", 7) != 0 && strncmp(url, "https://", 8) != 0)
  {
    printf("Input URL is not valid. Please enter a URL starting with 'http://' or 'https://'\n");
  }
  else
  {
    char baseUrl[100] = "";
    int i = 0, j = 0, flag = 0;
    while(i < strlen(url))
    {
      if(flag == 0 && url[i] == '/')//Find the end of the base URL
      {
        flag = 1;
        baseUrl[j] = '/';
        j++;
      }
      else if(flag == 0)
      {
        baseUrl[j] = url[i];
        j++;
      }
      else
      {
        if(url[i] == ':')//Remove port number if any
        {
          i++;
          while(url[i] >= '0' && url[i] <= '9')
          {
            i++;
          }
        }
        if(url[i] == '/')//Remove all parameters and keep only the base URL
        {
          baseUrl[j] = '/';
          j++;
        }
        i++;
      }    
    }
    strcpy(url, baseUrl);//Copy the sanitized URL to the original variable
  }
}

int main()
{
  char url[100] = "";
  printf("Please enter a URL to be sanitized: ");
  scanf("%s", url);

  sanitizeURL(url);

  printf("Sanitized URL: %s\n", url);
  return 0;
}